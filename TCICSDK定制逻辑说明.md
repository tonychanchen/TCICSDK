# TCICSDK定制说明

背景：

1. 因TCICSDK属于aPass方案，其提供了简单快速的接入方式，让业务方能快速使用腾云互动课堂能力。
2. 对于接入方在课中页的一些定制逻辑，也提供了推荐的定制方式，<font color="red">如果有定制需求的业务方，建议在接入前，先与SDK侧研发同学对齐</font>；

定制内容主要包括以下两方面：
 
 1. UI定制 : 
 	1. 音视频通信相关的UI逻辑：接入方根据自身音视频UI逻辑，扩展课中页默认UI展现，具体可参考[视频渲染UI定制说明](#tcicsdk_customui)；
 	2. 其他非音视频通信相关的UI，如答题签到等能力，建议使用H5实现，具体可参考（[H5 UI调试逻辑JS/CSS指定](#tcicsdk_custimui_h5)）。
 	
 2. 信令定制 : `UI定制` 中若有与H5交互相关的逻辑，建议走定制逻辑（目前TCICSDK所有的控制逻辑均由H5侧发起，这样做的好处是逻辑统一，后续好统一维护）：由业务侧通过自定义接口，向H5发送自定义消息至业务的JS，再由业务JS调用 `tcic-sdk.js` 中相关的方法来达到相应的要求；具体参考[自定义信令通道使用说明](#tcicsdk_customcmd)
    





## <a name="tcicsdk_customui"> 视频渲染UI定制说明</a>

与定制相关文件说明:

| 文件名 | 内容 |说明  |
| ---- | ---- | ---- | 
| TCICUIRenderDef | TCICUIRenderView, TCICUIRenderSource | 视频渲染子控件相关协议描述 |
| TCICTRTCVideoView | TCICTRTCVideoView | SDK默认的渲染控件 |
| TCICUICustomMgr | TCICUICustomMgr | 视频渲染控件管理协议描述 |
| TCICCustomDef | TCICCustomMsgSender, TCICCustomMsgRecver | 自定义信令收发消息协议说明 |
| TCICVideoContainerMgr | TCICVideoContainerMgr | SDK默认的 视频渲染控件管理以及自定义消息通道管理类|
| TCICClassController | TCICClassController | 课中页ViewController |
| TCICClassConfig | TCICClassConfig | 进课中页要使用的配置 |

类图说明：

![](https://main.qcloudimg.com/raw/87f4885a821e310e2b32b80449aa52e8.png)

| 方案 | 说明 | 备注 |
| ---- | ---- | ---- |
| 方案1 | 指定渲染控件 | 较简单：在认同SDK当前提供的默认布局方式（所有控件按层级关系，添加到 `TCICClassController.view上` ）的前提下，修改单个渲染控件的样式| 
| 方案2 | 重写默认类的方法，自行管理渲染相关的控件 | 难度一般 : 业务侧可以自行实现相关的协议，或重写相关的类 |      
| 方案3 | 创建子类继承`TCICClassController `，添加要其他非渲染相关的控件的展示，同时结合方案1,2 来处理渲染相关的View; | 较复杂 : 可能需要结合H5侧一同修改布局样式以及信令的定制，同时需要对SDK整体实现流程较熟悉 |

### 方案1 : 指定渲染控件
1. 创建自己的渲染控件，有以下两种方式：
    *  添加新类，自行实现`TCICUIRenderView`;
  
    	```
    	@interface ARenderView : UIView<TCICUIRenderView>
    	// add your own code
    	@end
    	
    	@implementation ARenderView 
    	// add your own code
    	@end
    	```
    *  继承默认控件 `TCICTRTCVideoView`;
    
    	```
    	@interface ARenderView : TCICTRTCVideoView
    	// add your own code
    	@end
    	
    	@implementation ARenderView 
    	// add your own code
    	@end
    	```
2. 在初始化后`TCICClassController`，指定渲染控件类型：调用 `TCICClassController`中的`registerUIRenderViewClass`方法即可，使用时注意阅读注释；

	示例代码：
	
		```
		TCICClassConfig *roomConfig = [[TCICClassConfig alloc] init];
		roomConfig.userId = "test";
		roomConfig.token = "test_token";
		roomConfig.classId = 123454;
		roomConfig.schoolId = xxxxx;
		    
		// 如何更新测试地址：详见注意事项2
		//     [roomConfig setValue:@"http://xx/yy/index.html" forKey:@"htmlUrl"];
		           
		TCICClassController *vc = [TCICClassController classRoomWithConfig:roomConfig];
		if (vc) {
		    // 指定渲染控件，ARenderView 为新增的已实现TCICUIRenderView的控件类或TCICTRTCVideoView派生类
		    [vc    registerUIRenderViewClass:[ARenderView class]];
		    [(UINavigationController *)self.window.rootViewController pushViewController:vc animated:YES];
		} else {
		    NSLog(@"参数有误");
		}    
		```


### 方案2 ：自行管理渲染逻辑

1. 创建自己的管理类，有以下两种方式：
	 * 自行实现`TCICUICustomMgr`协议，业务自行管理布局；

	 ```
    	@interface AVideoContainerMgr : NSObject<TCICUICustomMgr>
    	// add your own code
    	@end
    	
    	@implementation AVideoContainerMgr 
    	// add your own code
    	@end
	```
	  
    * 继承`TCICVideoContainerMgr`，使用默认的管理方式：在子类指定渲染控件(`renderViewClass`)，根据需要重写UI相关的方法（主要是下列四个接口，重写时若不想修改默认逻辑，建议调用super对应的方法）；
    
        ```
		  @interface AVideoContainerMgr : TCICVideoContainerMgr
		  // add your own code
		  @end
				
		  @implementation AVideoContainerMgr 
		  // add your own code
		  @end
        
	        以下为可重写有方法 
	        - (UIView<TCICUIRenderView> *_Nullable)renderViewOf:(NSString * _Nullable)userid viewType:(TCICUIRenderType)avType;
	        - (void)onInitUserLayout:(NSDictionary *_Nullable)extInfo controllerView:(UIView *_Nonnull)view;
	        - (void)onAddOrUpdateUserLayout:(NSString *_Nullable)userId viewType:(TCICUIRenderType)avType extInfo:(NSDictionary *_Nullable)extInfo offset:(CGPoint)offset controllerView:(UIView *_Nonnull)view stubView:(UIView *_Nonnull)stubView;
	        - (void)onRemoveUserLayout:(NSString *_Nullable)userId viewType:(TCICUIRenderType)avType extInfo:(NSDictionary *_Nullable)extInfo controllerView:(UIView *_Nonnull)view;
        ```
    
2. 在初始化后`TCICClassController `，指定渲染管理类：调用 `TCICClassController`中的`registerCustomUIHandler`方法即可，使用时注意阅读注释；

	示例代码：

		```
		TCICClassConfig *roomConfig = [[TCICClassConfig alloc] init];
		roomConfig.userId = "test";
		roomConfig.token = "test_token";
		roomConfig.classId = 123454;
		roomConfig.schoolId = xxxxx;
		    
		// 如何更新测试地址：详见注意事项2
		//     [roomConfig setValue:@"http://xx/yy/index.html" forKey:@"htmlUrl"];
		           
		TCICClassController *vc = [TCICClassController classRoomWithConfig:roomConfig];
		if (vc) {
		    // 指定渲染管理逻辑，AVideoContainerMgr 为新增的已实现TCICUICustomMgr协议的类或TCICVideoContainerMgr派生类
		    AVideoContainerMgr *mgr = [[AVideoContainerMgr alloc]  init];
		    [vc    registerCustomUIHandler: mgr]];
		    [(UINavigationController *)self.window.rootViewController pushViewController:vc animated:YES];
		} else {
		    NSLog(@"参数有误");
		}    
		```
    
### 方案3: 创建子类继承`TCICClassController`

1. 创建子类继承`TCICClassController`，在`viewDidLoad` 中添加业务控件，并控制好控件的显示/隐藏/区域的展示（防止点击事件拦截）
2. 视频渲染相关的逻辑，再参考 方案1/ 方案2来处理;


示例代码：

		```
		
		 @interface AClassController : TCICClassController
		  // add your own code
		  @end
				
		  @implementation AVideoContainerMgr 
		  // add your own code
		  - (void)viewDidLoad {
		  	[super viewDidLoad];
		  	// add you own views;
		  }
		  @end	
		
		TCICClassConfig *roomConfig = [[TCICClassConfig alloc] init];
		roomConfig.userId = "test";
		roomConfig.token = "test_token";
		roomConfig.classId = 123454;
		roomConfig.schoolId = xxxxx;
		    
		// 如何更新测试地址：详见注意事项2
		//     [roomConfig setValue:@"http://xx/yy/index.html" forKey:@"htmlUrl"];
		           
		AClassController *vc = [AClassController classRoomWithConfig:roomConfig];
		if (vc) {
			 // 结合本身逻辑，再参考方案1/方案2调用以下逻辑
			 // 指定渲染控件，ARenderView 为新增的已实现TCICUIRenderView的控件类或TCICTRTCVideoView派生类
		    // [vc registerUIRenderViewClass:[ARenderView class]];
		    // 指定渲染管理逻辑，AVideoContainerMgr 为新增的已实现TCICUICustomMgr协议的类或TCICVideoContainerMgr派生类
		    // AVideoContainerMgr *mgr = [[AVideoContainerMgr alloc]  init];
		    // [vc registerCustomUIHandler: mgr]];
		    [(UINavigationController *)self.window.rootViewController pushViewController:vc animated:YES];
		} else {
		    NSLog(@"参数有误");
		}    
		```


## <a name="tcicsdk_custimui_h5">H5 UI调试逻辑JS/CSS指定</a>

目前接入方如果想修改默认的H5 UI ，目前`TCICClassConfig`除提供[必填参数](./TCICSDK使用说明.md#tcicclassconfig)外，还可以使用`KVC`修改以下非必填参数来调试H5 UI；

| 字段 | 类型 | 描述 | 必传 | 
| ---- | ---- | ---- | ---- |
| htmlUrl |  string |  课堂html地址 | 非必填 |
| scene | string | 场景参数 | 非必填 |
| debugJSUrl | string | 在调试H5 UI 时，要用的js地址 | 非必传 |
| debugCSSUrl | string | 在调试H5 UI 时，要用的css地址 | 非必传 | 
| appGroup | string | 屏幕分享时，由外享传入的appGroup | 非必传 | 
| tiwCacheConfigPath | string | 外部传入缓存配置文件本地地址 | 非必传 |
| tiwCacheResourcePath | string | 外部传入缓存配置zip本地地址 | 非必传 |
| tiwCacheConfigUrl | string | 外部传入缓存配置网络地址 | 非必传 |

示例 

```
TCICClassConfig *roomConfig = [[TCICClassConfig alloc] init];
roomConfig.userId = "test";
roomConfig.token = "test_token";
roomConfig.classId = 123454;
roomConfig.schoolId = xxxxx;
    
// 通过KVC方式修改
[roomConfig setValue:@"http://xx/yy/index.html" forKey:@"htmlUrl"];
[roomConfig setValue:@"tv" forKey:@"scene"];
[roomConfig setValue:@"http://xx/yy/js/index.js" forKey:@"debugJSUrl"];
[roomConfig setValue:@"http://xx/yy/css/index.css" forKey:@"debugCSSUrl"];
[roomConfig setValue:@"group.com.xx.xxxx" forKey:@"appGroup"];
```



## <a name="tcicsdk_customcmd">自定义信令通道使用说明</a>

### 使用方式

自定义通道相关的逻辑，对外暴露均在默认渲染管理`TCICVideoContainerMgr` 或 `TCICUICustomMgr`协议中，使用时结合中UI定制逻辑同时使用;

1.  自定义消息通道使用时，H5先要向Native进行注册（注册回调为`TCICCustomMsgRecver` 的 `- (void)onRegistSender:(id<TCICCustomMsgSender> _Nonnull)sender` 方法），之后仅支持向注册过的通道进行通信；只有在收到该回调之后，才可以进行Native向H5发消息；
2.  H5向Native发消息时，Native会通过回调（`TCICCustomMsgRecver` 中的 `- (void)onRecvMsgFrom:(id<TCICCustomMsgSender> _Nonnull)sender customMsg:(NSString *_Nonnull)jsonMsg` ）收到相应的消息；
3. Native向H5发消息, Native可调用发送消息方法（`TCICCustomMsgSender`中的`- (BOOL)sendCustomMsg:(NSString *_Nullable)customMsg`）向业务的JS模块发消息



