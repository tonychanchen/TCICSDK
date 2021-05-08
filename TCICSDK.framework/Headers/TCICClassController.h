//
//  TCICClassController.h
//  TIC_Web_SaaS_SDK
//
//  Created by AlexiChen on 2020/5/6.
//  Copyright © 2020 AlexiChen. All rights reserved.
//
// TCICSDKDebugVersion : 1.0.0.449
// TCICSDKGitCommitID : 0f3f1a7cfcc7a7bae2fcd2e42e186b0a69907b61

#import <UIKit/UIKit.h>
#import "TCICClassConfig.h"
#import "TCICCustomDef.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *_Nonnull const TCIC_SDK_Version;
extern NSString *_Nonnull const TCIC_SDK_CommitID;

@interface TCICClassController : UIViewController

// 使用+classRoomWithConfig: 进行构建
+ (instancetype)new  __attribute__((unavailable("Use +classRoomWithConfig: instead")));
- (instancetype)init __attribute__((unavailable("Use +classRoomWithConfig: instead")));

/**
* 使用H5+Native方式使用，请在主线程中调用
* @param roomConfig : 打开教室所需要的配置
* 如果参数不合法，会返回nil，外部注意处理
*/

+ (instancetype _Nullable)classRoomWithConfig:(TCICClassConfig * _Nonnull)roomConfig;


/**
* 定制消息：注册自定义消息处理逻辑回调
* @param customMsg H5与Native定制消息处理逻辑
* 注意事项:
*  1.在viewDidLoad之前调用即可，一般在 classRoomWithConfig 之后即可
*  2.内部会强引用该对象，其生命周期同当前TCICClassController(释放时会自动释放customMsg); 外部也可提前释放，setCustomMsgDelegate:nil即可;
*/
- (void)setCustomMsgDelegate:(id<TCICCustomMsgRecver, TCICCustomMsgSender> _Nullable)customMsg;


@end

NS_ASSUME_NONNULL_END
