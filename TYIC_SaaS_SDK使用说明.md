# TYIC_SaaS_SDK 使用说明

## 功能介绍

`TYIC_SaaS_SDK` 为 腾云互动课堂开放的SaaS方案SDK简称

## iOS 集成

### pod 集成方式


1. 在工程`Poddile` 文件中，如果想集成**静态库**，添加依赖 `pod 'TYIC_SaaS_SDK'`, `TYIC_SaaS_SDK` 依赖以下 pod 库，在执行pod install命令时会自动安装；

	```
	pod 'Masonry'
	pod 'YYModel'
	pod 'TXLiteAVSDK_TRTC'
	```

	如果要添加**动态库**：在工程`Poddile` 文件中添加依赖 `pod 'TYIC_SaaS_SDK_Dyn'`，在工程`Poddile` 文件中添加依赖 	`pod 'TYIC_SaaS_SDK_Dyn'`, `TYIC_SaaS_SDK` 依赖以下 pod 库，在执行pod install命令时会自动安装。

	```
	pod 'Masonry'
	pod 'YYModel'
	```
	注意：`TYIC_SaaS_SDK_Dyn` 已将 `TXLiteAVSDK_TRTC` 合入，外部不需要显示去 `pod 'TXLiteAVSDK_TRTC'`

2.  在终端中跳到`Podfile`所在目录，`pod install` 即可自动安装所需要的依赖;


### 使用说明

1. 在使用处引用 `#import  <TYIC_SaaS_SDK/TYICClassRoomViewController.h>` 即可

2. `TYICClassRoomConfig`说明

	| 字段 | 类型 | 描述 | 必传 | 
	| ---- | ---- | ---- | ---- |
	| userId |  string |  进教室用户的userId，可参考 [云 API - 学生老师注册](https://classroom-docs.qcloudtrtc.com/#/business/Class?id=3%e5%ad%a6%e7%94%9f%e8%80%81%e5%b8%88%e6%b3%a8%e5%86%8c) | 必传 |
	| token | string | 可参考 [云 API - 换取票据](https://classroom-docs.qcloudtrtc.com/#/business/Class?id=4-%e6%8d%a2%e5%8f%96%e7%a5%a8%e6%8d%ae)，返回的token信息 | 必传 |
	| userSig | string | 可参考 [云 API - 换取票据](https://classroom-docs.qcloudtrtc.com/#/business/Class?id=4-%e6%8d%a2%e5%8f%96%e7%a5%a8%e6%8d%ae)，返回的userSig信息 | 必传 |
	| newEnterId | string | 机构ID，可参考 [云 API - 创建机构](https://classroom-docs.qcloudtrtc.com/#/business/Class?id=1%e5%88%9b%e5%bb%ba%e6%9c%ba%e6%9e%84) | 必传 |
	| classId | uint32 | 课堂编号，可参考 [云 API- 创建课堂](https://classroom-docs.qcloudtrtc.com/#/business/Class?id=12-%e5%88%9b%e5%bb%ba%e8%af%be%e5%a0%82)| 必传 | 

2. `TYICClassRoomViewController `说明

	| API | 说明 | 
	| --- | ---- | 
	| TYIC_SDK_Version | SDK版本号 | 
	| TYICWebViewStartLoadNotify | 开始加载课堂通知 |
	| TYICWebViewLoadFailedNotify | 加载课堂失败通知 |
	| TYICWebViewLoadCompleteNotify | 加载课堂H5完成通知 |
	| TYICWebViewLoadCompleteNotify | 进入课堂（TRTC enterRoom）完成通知 |
	| TYICStartExitClassRoomNotify | 开始退出课堂（TRTC exitRoom）通知 |
	| TYICExitClassRoomCompleteNotify | TYICClassRoomViewController实例释放，完全退出通知 |
	|  + (instancetype)classRoomWithConfig:(TYICClassRoomConfig *)roomConfig <br>uiOption:(NSDictionary *)uiOption <br>webOption:(NSDictionary *)webOption | 创建上课页面viewcontroller方法，roomConfig必传，如果roomConfig参数不合法（主要是是空），会返回空, uiOption/webOption 非必传填nil即可，主要方便后续扩展 |

	示例代码如下:
	
	```
	TYICClassRoomConfig *roomConfig = [[TYICClassRoomConfig alloc] init];
	roomConfig.userId = "test";
	roomConfig.userSig = "test_usersig";
	roomConfig.token = "test_token";
	roomConfig.classId = 123454;
	roomConfig.newEnterId = xxxxx;
	            
	TYICClassRoomViewController *vc = [TYICClassRoomViewController classRoomWithConfig:roomConfig uiOption:nil webOption:nil];
	if (vc) {
		[(UINavigationController *)self.window.rootViewController pushViewController:vc animated:YES];
	} else {
		NSLog(@"参数有误");
	}
	```

	**注意事项**：
	1. 如果的你App（iPad）配置类似下面: 1. 需要支持iPad ,  2. 需要支持所有方向；**那么请勾选上 `Requires full screen` 选项 (该选项对现有App不影响)**，否则 ` TYICClassRoomViewController ` 无法正常旋转至横屏
	
	![](https://main.qcloudimg.com/raw/26926026e4a4ed5d565ede21258a47ab.png)
	
	

