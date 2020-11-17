//
//  TCICClassController.h
//  TIC_Web_SaaS_SDK
//
//  Created by AlexiChen on 2020/5/6.
//  Copyright © 2020 AlexiChen. All rights reserved.
//
// TCICSDKDebugVersion : 1.0.0.174
// TCICSDKGitCommitID : 27c0820da4dd1f365b92fb4d6ec9b062f3784f7d

#import <UIKit/UIKit.h>
#import "TCICClassConfig.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *_Nonnull const TCIC_SDK_Version;
extern NSString *_Nonnull const TCIC_SDK_CommitID;

@interface TCICClassController : UIViewController

// 使用+classRoomWithConfig: 进行构建
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
