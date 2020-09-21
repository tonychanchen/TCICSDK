
# UIOption 配置

主要控制打开的`TYICClassRoomViewController` 的一些常见样式

| key | 类型 |  含义 | 说明  |
| --- | ---- |  ---- |  ---- |
| webId |  string  |  webView唯一标识  |  可为空，默认为main  |
| hideNavBar |  bool | 当使用NavigationController进行显示教室页时，是否隐藏导航栏，  | 可为空，默认NO  |
| title |  string | 有NavigationBar时的标题  | 可为空, 与`hideNavBar`结合使用  |
| openMode |  string | push/present  | viewcontroller打开方式  |
| orientation |  string | landscape : 横屏  portrait : 竖屏 all:横竖屏都支持, 进入时则以当前设备方向进入 | viewcontroller打开时，期望的设备朝向，默认landscape  |
| preferredHome |  string | up : Home上  down : Home下 left:Home左 right:Home右  | viewcontroller打开时，期望的Home键位置 |
| preferredHome |  string | up : Home上  down : Home下 left:Home左 right:Home右  | viewcontroller打开时，期望的Home键位置，默认right |
| rotate |  bool | 是否允许UI发生旋转 YES: 允许 , NO : 不允话  | 可不填，默认NO |
| rotateBackOnExit |  bool | 退出教室页时，是否把UI旋转回进入时方向  | 可不填，默认会检查Info.plist信息进行处理 |



# WebOption 配置

`TYICClassRoomViewController`中webView创建时一些配置项，方便用户进行控制

注意事项：
1. 创建TYICClassRoomViewController时，默认会创建一个webview，简称为主web，主web中通过H5信令创建的web，称为子web;
2. 创建TYICClassRoomViewController时，如果不传WebOption参数，默认 os(YES)/trtc(YES)/trtcui(YES)/Custom(YES)/scroll(YES)，若传刚需要显示指定


| key | 类型 |  含义 | 说明  |
| --- | ---- |  ---- |  ---- |
| os | bool | 是否需要os router | 可不填，默认NO | 
| trtc |  bool | 是否需要trtc router | 可不填，默认NO |
| trtcui |  bool | 是否需要trtcui router | 可不填，默认NO |
| custom |  bool | 是否需要custom router 自定义消息router  | 可不填，默认NO |
| scroll |  bool | webview是否支持滑动，同`scrollView.scrollEnabled`，优先读取`scrollView.scrollEnabled`，若无使用`scroll` | 可不填，主web默认NO， 子web默认NO |
| isDebug |  bool | 是否打印js日志，需要H5端支持才可以  | 可不填，主web默认NO， 子web默认NO |
| exclusiveTouch |  bool | `WKWebView.exclusiveTouch` 属性配置  | 可不填，默认YES |
| multipleTouchEnabled |  bool | `WKWebView.multipleTouchEnabled` 属性配置  | 可不填，默认NO |
| scrollView.bounces |  bool | `WKWebView.scrollView.bounces` 属性配置  | 可不填，默认NO |
| scrollView.scrollEnabled |  bool | `WKWebView.scrollView.scrollEnabled` 属性配置  | 可不填，默认NO |
| scrollView.scrollEnabled |  bool | `WKWebView.scrollView.scrollEnabled` 属性配置  | 可不填，默认NO |
| scrollView.maximumZoomScale |  float | `WKWebView.scrollView.maximumZoomScale` 属性配置  | 可不填，默认1.0 |
| scrollView.minimumZoomScale |  float | `WKWebView.scrollView.minimumZoomScale` 属性配置  | 可不填，默认1.0 |
| opaque |  float | `WKWebView.opaque` 属性配置  | 可不填，默认NO |
| scrollView.contentInsetAdjustmentBehavior |  UIScrollViewContentInsetAdjustmentBehavior | `WKWebView.scrollView.contentInsetAdjustmentBehavior` 属性配置  | 可不填，默认UIScrollViewContentInsetAdjustmentNever |

