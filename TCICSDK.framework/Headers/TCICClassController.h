//
//  TCICClassController.h
//  TIC_Web_SaaS_SDK
//
//  Created by AlexiChen on 2020/5/6.
//  Copyright © 2020 AlexiChen. All rights reserved.
//
// TCICSDKDebugVersion : 1.0.375
// TCICSDKGitCommitID : ac382188340aaf2d42d086d858f4b365461de8e8

#import <UIKit/UIKit.h>
#import "TCICClassConfig.h"


NS_ASSUME_NONNULL_BEGIN

extern NSString *_Nonnull const TCIC_SDK_Version;
extern NSString *_Nonnull const TCIC_SDK_CommitID;

@protocol TCICUICustomMgr, TCICCustomMsgRecver, TCICCustomMsgSender;

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

//==================================================================================
//
// 定制UI相关接口 : 文档可参考 https://tcic-docs.qcloudtiw.com/#/layout/iOSCustomLayout
//
//==================================================================================
/**
* 定制UI：第一步：在classRoomWithConfig之前调用，设置自定义UI课中页的类名
* @param subcls TCICClassController或TCICClassController子类
*/
+ (void)resetInstancetypeClass:(Class)subcls;

/**
* 定制UI：第二步：注册定制UI自定义处理逻辑回调
* @param customUI 定制的UI处理逻辑
* 注意事项:
*  1.在viewDidLoad之前调用即可，一般在 classRoomWithConfig 之后即可
*  2.内部默认为TCICVideoContainerMgr, 可以继承该类或者自行实现TCICUICustomMgr协议;
*  3.内部会强引用该对象，其生命周期同当前TCICClassController(释放时会自动释放customUI); 外部也可提前释放，setCustomUIDelegate:nil即可;
*/
- (void)setCustomUIDelegate:(id<TCICUICustomMgr> _Nullable)customUI;

//==================================================================================
//
// 定制UI相关接口 : 文档可参考 https://tcic-docs.qcloudtiw.com/#/layout/iOSCustomLayout
//
//==================================================================================
/**
* 定制消息：第步：注册定制UI自定义处理逻辑回调
* @param customMsg H5与Native定制消息处理逻辑
* 注意事项:
*  1.在viewDidLoad之前调用即可，一般在 classRoomWithConfig 之后即可
*  3.内部会强引用该对象，其生命周期同当前TCICClassController(释放时会自动释放customMsg); 外部也可提前释放，setCustomMsgDelegate:nil即可;
*/
- (void)setCustomMsgDelegate:(id<TCICCustomMsgRecver, TCICCustomMsgSender> _Nullable)customMsg;


@end

NS_ASSUME_NONNULL_END
