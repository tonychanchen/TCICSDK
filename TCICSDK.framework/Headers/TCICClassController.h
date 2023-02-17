//
//  TCICClassController.h
//  TIC_Web_SaaS_SDK
//
// TCICSDKDebugVersion : <:TCICSDKDebugVersion:>
// TCICSDKGitCommitID : <:TCICSDKGitCommitID:>

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
 * 调测型接口：设置本地课堂语言
 * @param lang : 只支持两种zh/en，填其他无效。底层默认为zh;
 */
+ (void)setClassLanuage:(NSString * _Nullable)lang;
/**
* 进课堂前预加载环境，以便快速进房;
* @param env : 环境参数, SDK默认加载正式环境，env 为空表示正式环境, env : test 测试环境; dev 开发环境; pre 预发布环境，其他参数默认为正式环境
*/
+ (void)preloadClass:(NSString * _Nullable)env;
/**
* 使用H5+Native方式使用，请在主线程中调用
* @param roomConfig : 打开课堂所需要的配置
* 如果参数不合法，会返回nil，外部注意处理
*/
+ (instancetype _Nullable)classRoomWithConfig:(TCICClassConfig * _Nonnull)roomConfig;


/**
* 定制消息：注册自定义消息处理逻辑回调
* @param receiver H5与Native定制消息处理逻辑
* 注意事项:
*  1.在viewDidLoad之前调用即可，一般在 classRoomWithConfig 之后即可;
*  2.内部会强引用该对象，其生命周期同当前TCICClassController(释放时会自动释放receiver);
*  3.外部也可提前释放，setCustomMessageDelegate:nil即可;
*/
- (void)setCustomMessageDelegate:(id<TCICCustomMessageReceiver> _Nullable)receiver;


/**
 * 定制消息：向H5发送自定义消息
 * @param customMsg 要发送的消息，业务侧做好定制格式，以便H5侧解析
 * 注意事项：如果底层没准备好的情况下，SDK会先缓存，待底层处理好之后，再一并发送给H5
 */
- (void)sendCustomMessage:(NSString *_Nullable)customMsg;


@end

NS_ASSUME_NONNULL_END
