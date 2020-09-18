//
//  TYICUICustom.h
//  TYICSDK
//
//  Created by 陈耀武 on 2020/9/4.
//  Copyright © 2020 AlexiChen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <WebKit/WebKit.h>
#import "TYICTRTCEventListener.h"

@protocol  TYICUICustomMgrTRTCAction <NSObject>
/**
 * 以下6个方法中，userId, view规则均如下
 * @param userId 为nil或当前用户时, 代表本地; 其他则代码远端
 * @param view 渲染的控件, 为空时，底层不处理;
 */

/**
 * 开始预览画面
 * @param front 本地预时有效，YES : 前置摄像头，NO : 后置摄像头
 */
- (void)trtcStartPreview:(NSString * _Nullable)userId fromView:(UIView * _Nonnull)view frontCamera:(BOOL)front;

/**
* 停止预览画面
*/
- (void)trtcStopPreview:(NSString * _Nullable)userId fromView:(UIView * _Nonnull)view;

/**
* 打开本地声音或打开远端声音
*/
- (void)trtcStartAudio:(NSString * _Nullable)userId fromView:(UIView * _Nonnull)view;

/**
* 停止本地声音或停止远端声音
*/
- (void)trtcStopAudio:(NSString *_Nullable)userId fromView:(UIView *_Nonnull)view;

/**
* 开始观看远端辅路, 本地无效
*/
- (void)trtcStartSubStream:(NSString *_Nullable)userId fromView:(UIView *_Nonnull)view;

/**
* 停止观看远端辅路, 本地无效
*/
- (void)trtcStopSubStream:(NSString *_Nullable)userId fromView:(UIView *_Nonnull)view;

/**
* 禁止/开启拉取所有远端视频
* @param mute YES : 禁止，NO : 开启
*/
- (void)trtcMuteAllRemoteVideo:(BOOL)mute;

/**
* 禁止取所有远端视频渲染
*/
- (void)trtcStopAllRemoteVideo;

/**
* 禁止/开启观看所有远端音频
* @param mute YES : 禁止，NO : 开启
*/
- (void)trtcMuteAllRemoteAudio:(BOOL)mute;

@end

@protocol TYICTRTCUIRenderSource <NSObject>

@required
- (UIView *_Nullable)renderViewOf:(NSString * _Nullable)userid viewType:(NSInteger)avType;

@end


@protocol TYICCustomMsgSender<NSObject>

/**
 * 方便业务侧记录sender信息，记录时请不要强引用
 */
- (NSString *_Nullable)senderIdentifier;

/**
 * 发送自定义消息
 * @param customMsg 要发送的消息，具体与
 */
- (BOOL)sendCustomMsg:(NSString *_Nullable)customMsg;

@end


@protocol TYICUICustomMgr<TYICTRTCEventListener, TYICTRTCUIRenderSource>


@required
@property (nonatomic, weak, nullable) id<TYICUICustomMgrTRTCAction> trtcAction;



/**
 * H5通知UI层做好UI相关的初始化工作
 * @param extInfo H5下发的业务信息，业务侧自行解析
 * @param view 当前ViewController.view 外部拿到时可向其添加子控件
 */
- (void)onInitUserLayout:(NSDictionary *_Nullable)extInfo superView:(UIView *_Nonnull)view;

/**
* H5通知UI添加或更新userId对应的信息，建议业务侧做好信息搜集管理
* @param userId H5下发的业务信息，业务侧自行解析
 * @param avType H5下发的业务信息，业务侧自行解析
* @param view 当前ViewController.view 外部拿到时可向其添加子控件
*/
- (void)onAddOrUpdateUserLayout:(NSString *_Nullable)userId viewType:(NSInteger)avType extInfo:(NSDictionary *_Nullable)extInfo superView:(UIView *_Nonnull)view;

/**
* H5通知UI移除userId对应的信息，建议业务侧做好信息搜集管理
* @param userId H5下发的业务信息，业务侧自行解析
 * @param avType H5下发的业务信息，业务侧自行解析
* @param view 当前ViewController.view 外部拿到时可向其添加子控件
*/
- (void)onRemoveUserLayout:(NSString *_Nullable)userId viewType:(NSInteger)avType extInfo:(NSDictionary *_Nullable)extInfo superView:(UIView *_Nonnull)view;

@optional

/**
* UI发生旋转时，通知定制UI旋转
* @param landscape true 横屏， false ： 竖屏
*/
- (void)onShouldAutoRotateAndLayout:(BOOL)landscape;

@optional

/**
 * 收到自定义消息；
 * @param customMsg h5侧发送的自定义Json消息
 * @param recvAndSender 底层收到该消息者，业务侧可通过该对像，回复消息
 */
- (void)onRecvCustomJsMsg:(NSDictionary *_Nullable)customMsg fromSender:(id<TYICCustomMsgSender> _Nonnull)recvAndSender;

@end



