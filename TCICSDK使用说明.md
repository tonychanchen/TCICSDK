# TCICSDK 使用说明

## 功能介绍

`TCICSDK` 为 腾云互动课堂开放的SaaS方案SDK简称

## iOS 集成

### pod 集成方式


1. 在工程`Poddile` 文件中，如果想集成**静态库**，添加依赖 `pod 'TCICSDK'`, `TCICSDK` 依赖以下 pod 库，在执行pod install命令时会自动安装；

	```
	pod 'Masonry'
	pod 'YYModel'
     pod 'Bugly'
	pod 'TXLiteAVSDK_TRTC'
     pod 'TIWLogger_iOS'
	```
    
    如果要添加**动态库**：在工程`Poddile` 文件中添加依赖 `pod 'TCICSDK_Dyn'`，在工程`Poddile` 文件中添加依赖     `pod 'TCICSDK_Dyn'`, `TCICSDK_Dyn` 依赖以下 pod 库，在执行pod install命令时会自动安装。

    ```
    pod 'Masonry'
    pod 'YYModel'
    pod 'Bugly'
    pod 'TXLiteAVSDK_TRTC'
    pod 'TIWLogger_iOS'
    ```

2.  在终端中跳到`Podfile`所在目录，`pod install` 即可自动安装所需要的依赖;


### 使用说明

1. 在使用处引用 `#import  <TCICSDK/TCICClassController.h>` 即可

2. `TCICClassConfig`说明 

	| 字段 | 类型 | 描述 | 必传 | 
	| ---- | ---- | ---- | ---- |
	| userId |  string |  进教室用户的userId，可参考 [云 API - 学生老师注册](https://classroom-docs.qcloudtrtc.com/#/business/Class?id=3%e5%ad%a6%e7%94%9f%e8%80%81%e5%b8%88%e6%b3%a8%e5%86%8c) | 必传 |
	| token | string | 可参考 [云 API - 换取票据](https://classroom-docs.qcloudtrtc.com/#/business/Class?id=4-%e6%8d%a2%e5%8f%96%e7%a5%a8%e6%8d%ae)，返回的token信息 | 必传 |
	| userSig | string | 可参考 [云 API - 换取票据](https://classroom-docs.qcloudtrtc.com/#/business/Class?id=4-%e6%8d%a2%e5%8f%96%e7%a5%a8%e6%8d%ae)，返回的userSig信息 | 必传 |
	| schoolId | uint32 | 学校ID，可参考 [云 API - 创建机构](https://classroom-docs.qcloudtrtc.com/#/business/Class?id=1%e5%88%9b%e5%bb%ba%e6%9c%ba%e6%9e%84) | 必传 |
	| classId | uint32 | 课堂编号，可参考 [云 API- 创建课堂](https://classroom-docs.qcloudtrtc.com/#/business/Class?id=12-%e5%88%9b%e5%bb%ba%e8%af%be%e5%a0%82)| 必传 | 
	
	**如何更新课堂地址**：
	1. 使用KVC修改 `htmlUrl` 值 ，如  ` [roomConfig setValue:@"http://xx/yy/index.html" forKey:@"htmlUrl"];`
	2. 使用KVC修改课堂页时，`value` 必须满足以下条件：
		*  `Value`必须是 	`NSString` 类型，传入其他类型或`nil`，不会生效;
		*  `Value`必须能正确构造出`NSURL`对象, 即 `[NSURL URLWithString:value]` 或 `[NSURL fileURLWithPath:value]`  ，否则不会生效;
		*  若传入与SDK逻辑未调试的地址，比如传入的地址为 `https://v.qq.com/`，虽然能满足上两项条件，使用SDK也会正常打开，但SDK内部仍然会出示提示框，要求退出;

2. `TCICClassController `说明

	| API | 说明 | 
	| --- | ---- | 
	| TCIC_SDK_Version | SDK版本号 | 
	|  + (instancetype)classRoomWithConfig:(TCICClassConfig *)roomConfig | 主线程调用；创建上课页面viewcontroller方法，roomConfig必传，如果roomConfig参数不合法（主要是是空），会返回空 |
	

	示例代码如下:
	
	```
	TCICClassConfig *roomConfig = [[TCICClassConfig alloc] init];
	roomConfig.userId = "test";
	roomConfig.userSig = "test_usersig";
	roomConfig.token = "test_token";
	roomConfig.classId = 123454;
	roomConfig.schoolId = xxxxx;
	
	// 如何更新测试地址：详见注意事项2
	// 	[roomConfig setValue:@"http://xx/yy/index.html" forKey:@"htmlUrl"];
	           
	TCICClassController *vc = [TCICClassController classRoomWithConfig:roomConfig];
	if (vc) {
		[(UINavigationController *)self.window.rootViewController pushViewController:vc animated:YES];
	} else {
		NSLog(@"参数有误");
	}    
	```
	
	
    


	**注意事项**：
	1. 如果的你App（iPad）配置类似下面：
		* 需要支持iPad ;
		* 需要支持所有方向；
		
		**那么请勾选上 `Requires full screen` 选项 (该选项对现有App不影响)**，否则 ` TCICClassController ` 无法正常旋转至横屏
	
	![](https://main.qcloudimg.com/raw/26926026e4a4ed5d565ede21258a47ab.png)
	

    		
    		
	
	

