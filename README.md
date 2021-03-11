# 腾云互动课堂 TCICSDK 

## [TCICSDK集成说明](TCICSDK使用说明.md)

## 版本历史

| 日期 | 版本号 |  更新说明 |
|:---------:|:--------:|:-------- |
| 20200923 | 1.0.0.50 | 更新pod |
| 20200923 | 1.0.0.51 | 更新对外接口以及使用文档 |
| 20200923 | 1.0.0.52 | 更新文档 |
| 20200924 | 1.0.0.53 | 更新SDK：内部固定测试地址 |
| 20200924 | 1.0.0.54 | 更新SDK：内部固定测试地址 |
| 20200924 | 1.0.0.56 | 修复Image加载不到问题 |
| 20200925 | 1.0.0.59 | 增加webview弹窗逻辑 |
| 20200925 | 1.0.0.60 | 更新弹窗逻辑 |
| 20200927 | 1.0.0.62 | 更新课堂页html地址由外部配置 |
| 20200927 | 1.0.0.64 | 打开相机/麦克风前增加提示以及权限上报 |
| 20201027 | 1.0.0.130 | 更新上报逻辑,以便排查线上问题 |
| 20201027 | 1.0.0.131 | 更新依赖的LiteAVSDK_TRTC版本 |
| 20201112 | 1.0.0.164 | 添加Bugly |
| 20201113 | 1.0.0.171 | 去掉tcicimage.bundle依赖 |
| 20201116 | 1.0.0.172 | 改成共享式集成bugly |
| 20201117 | 1.0.0.179 | 集成TICCache，优化加载速度 |
| 20201118 | 1.0.0.194 | 更新SDK的符号表配置，以及共享时转发crash至SDK侧 |
| 20201127 | 1.0.0.202 | 去掉userSig相关的说明 |
| 20201127 | 1.0.0.204 | 修复视频播件播放问题 |
| 20201201 | 1.0.0.206 | 更新Pod |
| 20201201 | 1.0.0.207 | 修复因脚本问题，导致pod安装包不对问题 |
| 20201203 | 1.0.0.210 | 更新渲染控件在有输入情况下位置变动问题 |
| 20201222 | 1.0.0.235 | 暴露定制接口 |
| 20201223 | 1.0.0.236 | 更新依赖库版本 |
| 20201225 | 1.0.0.248 | ./buildAllPod.sh |
| 20201225 | 1.0.0.251 | ./buildAllPod.sh |
| 20201225 | 1.0.0.254 | 改动统一脚本构建 |
| 20201229 | 1.0.0.263 | 更新TRTC至8.2 |
| 20201230 | 1.0.0.268 | 添加屏幕分享相关 |
| 20201230 | 1.0.0.270 | 支持屏幕分享 |
| 20201230 | 1.0.0.271 | 添加屏幕分享 |
| 20201230 | 1.0.0.272 | 添加屏幕分享 |
| 20210101 | 1.0.0.282 | 修复键盘收起时crash |
| 20210104 | 1.0.0.290 | 更新自定义UI接口以及文档 |
| 20210104 | 1.0.0.291 | 添加事件通知 |
| 20210104 | 1.0.0.292 | 添加事件通知 |
| 20210104 | 1.0.0.293 | 增加隐式的事件通知，方便外部监听 |
| 20210106 | 1.0.0.296 | 简化UI定制接入流程 |
| 20210107 | 1.0.0.300 | 优化WebView缓存池逻辑，修复加载过慢问题 |
| 20210112 | 1.0.0.320 | 修复一些小bug |
| 20210114 | 1.0.0.330 | 优化屏幕分享逻辑 |
| 20210118 | 1.0.0.334 | 更新屏幕分享 |
| 20210120 | 1.0.0.342 | 增加同层渲染逻辑 |
| 20210121 | 1.0.0.345 | 添加同层渲染 |
| 20210121 | 1.0.0.347 | 添加同层渲染 |
| 20210125 | 1.0.0.352 | 将自定义消息通道与自定义渲染逻辑分离 |
| 20210125 | 1.0.0.353 | 更新正式环境地址 |
| 20210129 | 1.0.0.356 | 修复同层渲染问题 |
| 20210129 | 1.0.0.358 | 更新资源包 |
| 20210204 | 1.0.0.366 | 修复coreVersion未同步更新htmlurl |
| 20210204 | 1.0.0.368 | 修改coreVersion时，同步更新htmlUrl |
| 20210204 | 1.0.0.370 | 回滚旋转问题改动 |
| 20210205 | 1.0.0.375 | 添加日志，方便排查问题 |
| 20210207 | 1.0.0.377 | WebContent |
| 20210207 | 1.0.0.382 | 回滚白屏报错退出逻辑 |
| 20210207 | 1.0.0.383 | onWebContentProcessTerminater时提示 |
| 20210208 | 1.0.0.384 | iOS13以下不开缓存 |
| 20210311 | 1.0.0.404 | 更新1.1.0缓存包 |
