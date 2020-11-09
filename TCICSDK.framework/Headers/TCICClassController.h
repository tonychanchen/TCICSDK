//
//  TCICClassController.h
//  TIC_Web_SaaS_SDK
//
//  Created by AlexiChen on 2020/5/6.
//  Copyright © 2020 AlexiChen. All rights reserved.
//
// TCICSDKDebugVersion : 1.0.0.149
// TCICSDKGitCommitID : 90ee9fc2c6c4fa221a0621b3a8cb491ddd555d2a

#import <UIKit/UIKit.h>
#import "TCICClassConfig.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *_Nonnull const TCIC_SDK_Version;
extern NSString *_Nonnull const TCIC_SDK_CommitID;
// 开始加载课堂通知
extern NSString *_Nonnull const TCICWebViewStartLoadNotify;
// 加载课堂失败通知
extern NSString *_Nonnull const TCICWebViewLoadFailedNotify;
// 加载课堂H5完成通知
extern NSString *_Nonnull const TCICWebViewLoadCompleteNotify;
// 进入课堂（TRTC enterRoom）完成通知
extern NSString *_Nonnull const TCICEnterClassRoomCompleteNotify;
// 开始退出课堂（TRTC exitRoom）通知
extern NSString *_Nonnull const TCICStartExitClassRoomNotify;
// TCICClassController实例释放，完全退出通知
extern NSString *_Nonnull const TCICExitClassRoomCompleteNotify;

//@protocol TCICUICustomMgr;
@interface TCICClassController : UIViewController

// 使用+classRoomWithConfig:uiOption:webOption 进行构建
+ (instancetype)new  __attribute__((unavailable("Use +classRoomWithConfig:uiOption:webOption instead")));
- (instancetype)init __attribute__((unavailable("Use +classRoomWithConfig:uiOption:webOption instead")));


/**
* 使用H5+Native方式使用，请在主线程中调用
* @param roomConfig : 打开教室所需要的配置
* 如果参数不合法，会返回nil，外部注意处理
*/
+ (instancetype _Nullable)classRoomWithConfig:(TCICClassConfig * _Nonnull)roomConfig;


@end

NS_ASSUME_NONNULL_END
