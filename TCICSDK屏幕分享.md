## 如何集成

1. 创建`App Group` : 参考 [TRTC 官网文档 > 步骤1：创建 App Group](https://cloud.tencent.com/document/product/647/45750)
2. 创建 `Broadcast Upload Extension`, 参考 [TRTC 官网文档 > 步骤2：创建 Broadcast Upload Extension](https://cloud.tencent.com/document/product/647/45750)，将第6步中的示例代码，贴入新生在`SampleHandler.m`中，并配置好 `APPGROUP `即可; 
3. 为新创建的Target，依赖依赖`TCICSDK_ReplayKit `，如下，之后重新 `pod install` 即可；
	
	```
	target '新target名' do
	# Comment the next line if you don't want to use dynamic frameworks
	# use_frameworks!
	pod 'TCICSDK_ReplayKit'
	end
	```
	
3. 对接主 App 端的接收逻辑 : 目前主App中的使用`TCICSDK`，已支持系统屏幕分享相关逻辑，只需要业务方配置好 `App Group`即可：在进入课堂前，设置`AppGroup` 即可。([`TCICClassConfig`其他配置可看这里](./iOSCustomLayout.md#tcicsdk_custimui_h5/))

	```
	TCICClassConfig *roomConfig = [[TCICClassConfig alloc] init];
	roomConfig.userId = "test";
	roomConfig.token = "test_token";
	roomConfig.classId = 123454;
	roomConfig.schoolId = xxxxx;
	    
	// 通过KVC方式设置AppGroup
	[roomConfig setValue:@"group.com.xx.xxxx" forKey:@"appGroup"];
	
	```
## 注意事项
1.  `TCICSDK` 中已支持`屏幕分享的触发按钮`，具体可参考 [TRTC 官网文档 > 步骤4：增加屏幕分享的触发按钮（可选）](https://cloud.tencent.com/document/product/647/45750)，但该功能有限制条件：
	1.  `屏幕分享的触发按钮`只支持iOS12以上，同时需要创建的工程，不依赖`Scene生命周期`，如果代码中已支持`Scenedelegate `，可参考 [Xcode 11 删除Scenedelegate](https://www.cnblogs.com/Lin-XianSheng/p/11821362.html)，进行移除。以Demo为例，弹出效果如下，点击开始直播即可；
	![](https://main.qcloudimg.com/raw/feb7ad2aa7287c45884dd3be8eba3dd0.jpeg)
	2. 对于iOS11的机型，需要业务侧引导用户从远程控制中`长按录屏`进行触发，并选择业务自创建的`Broadcast Upload Extension`进行触发；下图以`腾讯会议`为例；
	 ![https://main.qcloudimg.com/raw/4082c8bcc7f41328a17f7ede78577bd9.png2.](https://main.qcloudimg.com/raw/4082c8bcc7f41328a17f7ede78577bd9.png)

2. 创建的 `Upload Extension` 的  `Deployment target` 配置在 `iOS 11.0` （`Replay Kit`于iOS11 才开始支持），调试时真机也尽量在 iOS11 之后；
3. 主App要支持系统级屏幕分享，需要添加 `Background Mods`;
	![](https://main.qcloudimg.com/raw/4e7415ff0ecca7eb7471e19470794bb5.png)

