//
//  TCICClassController.h
//  TIC_Web_SaaS_SDK
//
//  Created by AlexiChen on 2020/5/6.
//  Copyright © 2020 AlexiChen. All rights reserved.
//
// TCICSDKDebugVersion : 1.0.0.293
// TCICSDKGitCommitID : 860b4fb0c6d21445e10f59d1d2fbfb8d6f4639a8

#import <UIKit/UIKit.h>
#import "TCICClassConfig.h"


NS_ASSUME_NONNULL_BEGIN

extern NSString *_Nonnull const TCIC_SDK_Version;
extern NSString *_Nonnull const TCIC_SDK_CommitID;

@protocol TCICUICustomMgr;

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

/**
* 定制UI方案1：注册渲染子控件类型, 使用SDK自带的默认逻辑来管理渲染子控件;
* @param uiItemCls 定制的UI处理逻辑，需要实现TCICUIRenderView协议，不能为空，否则抛异常。
* 注意事项:
*  1.在viewDidLoad之前调用即可;
*  2.uiItemCls需要实现init方法：内部使用反射来创建相应的渲染控件;
*/
- (void)registerUIRenderViewClass:(Class)uiItemCls;


/**
* 定制UI方案2：注册UI自定义处理逻辑回调
* @param customUI 定制的UI处理逻辑
* 注意事项:
*  1.在viewDidLoad之前调用即可;
*  2.内部默认为TCICVideoContainerMgr, 如果想自定义可以使用该接口进行控展;
*  3.内部会强引用该对象，其生命周期同当前TCICClassController(释放时会自动释放customUI); 外部也可提前释放，setCustomUIDelegate:nil即可;
*/
- (void)setCustomUIDelegate:(id<TCICUICustomMgr> _Nullable)customUI;

/**
* 定制UI方案3：创建自定义课中页
* @param subcls TCICClassController子类
* 注意事项:
*  1.在classRoomWithConfig之前调用即可;
*/
+ (void)resetInstancetypeClass:(Class)subcls;

@end

NS_ASSUME_NONNULL_END
