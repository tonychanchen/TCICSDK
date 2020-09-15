//
//  TYICTRTCEventListener.h
//  TIC_Web_SaaS
//
//  Created by AlexiChen on 2020/4/2.
//  Copyright © 2020 AlexiChen. All rights reserved.
//

#import <Foundation/Foundation.h>
@class TRTCStatistics;
@class TRTCQualityInfo;
@class TRTCVolumeInfo;
/*********************************************************************************************************
 *
 *                                             事件回调
 *
 ********************************************************************************************************/
@protocol TYICTRTCEventListener <NSObject>
@optional

/// @name 房间事件回调
/// @{
/**
 * 2.1 已加入房间的回调
 *
 * 调用 TRTCCloud 中的 enterRoom() 接口执行进房操作后，会收到来自 SDK 的 onEnterRoom(result) 回调：
 *
 * - 如果加入成功，result 会是一个正数（result > 0），代表加入房间的时间消耗，单位是毫秒（ms）。
 * - 如果加入失败，result 会是一个负数（result < 0），代表进房失败的错误码。
 * 进房失败的错误码含义请参见[错误码](https://cloud.tencent.com/document/product/647/32257)。
 *
 * @note 在 Ver6.6 之前的版本，只有进房成功会抛出 onEnterRoom(result) 回调，进房失败由 onError() 回调抛出。
 *       在 Ver6.6 及之后改为：进房成功返回正的 result，进房失败返回负的 result，同时进房失败也会有 onError() 回调抛出。
 *
 * @param result result > 0 时为进房耗时（ms），result < 0 时为进房错误码。
 */
- (void)onTICEnterRoom:(NSInteger)result selfId:(NSString *)selfid;

/**
 * 2.2 离开房间的事件回调
 *
 * 调用 TRTCCloud 中的 exitRoom() 接口会执行退出房间的相关逻辑，例如释放音视频设备资源和编解码器资源等。
 * 待资源释放完毕，SDK 会通过 onExitRoom() 回调通知到您。
 *
 * 如果您要再次调用 enterRoom() 或者切换到其他的音视频 SDK，请等待 onExitRoom() 回调到来之后再执行相关操作。
 * 否则可能会遇到音频设备（例如 iOS 里的 AudioSession）被占用等各种异常问题。
 *
 * @param reason 离开房间原因，0：主动调用 exitRoom 退房；1：被服务器踢出当前房间；2：当前房间整个被解散。
 */
- (void)onTICExitRoom:(NSInteger)reason selfId:(NSString *)selfid;

/**
 * 3.5 userId 对应的远端声音的状态通知
 *
 * @param userId 用户标识
 * @param available 声音是否开启
 */
- (void)onTICUserAudioAvailable:(NSString *)userId available:(BOOL)available;
/**
 * userId对应的远端主路（即摄像头）画面的状态通知
 * @param userId    用户标识
 * @param available 画面是否开启
 **/
- (void)onTICUserVideoAvailable:(NSString *)userId available:(BOOL)available;
/**
 * userId对应的远端辅路（屏幕分享等）画面的状态通知
 * @param userId    用户标识
 * @param available 屏幕分享是否开启
 **/
- (void)onTICUserSubStreamAvailable:(NSString *)userId available:(BOOL)available;

/**
 有新的音视频用户加入房间
 */
- (void)onTICRemoteUserEnterRoom:(NSString *)userId;

/**
 有新的音视频用户退出房间
 */
- (void)onTICRemoteUserLeaveRoom:(NSString *)userId reason:(NSInteger)reason;

#if !TARGET_OS_IPHONE && TARGET_OS_MAC
/**
 * 本地设备通断回调
 * @param deviceId 设备id
 * @param deviceType 设备类型 @see TRTCMediaDeviceType
 * @param state   0: 设备断开   1: 设备连接
 */
- (void)onTICDevice:(NSString *)deviceId type:(TRTCMediaDeviceType)deviceType stateChanged:(NSInteger)state;
#endif

/**
 * 网络质量：该回调每2秒触发一次，统计当前网络的上行和下行质量
 *
 * @note userId == nil 代表自己当前的视频质量
 *
 * @param localQuality 上行网络质量
 * @param remoteQuality 下行网络质量
 */
- (void)onTICNetworkQuality: (TRTCQualityInfo*)localQuality remoteQuality:(NSArray<TRTCQualityInfo*>*)remoteQuality;

/**
 * 6.1 SDK 跟服务器的连接断开
 */
- (void)onTICConnectionLost;

/**
 * 6.2 SDK 尝试重新连接到服务器
 */
- (void)onTICTryToReconnect;

/**
 * 6.3 SDK 跟服务器的连接恢复
 */
- (void)onTICConnectionRecovery;
    
/**
 * 技术指标统计回调
 *
 * 如果您是熟悉音视频领域相关术语，可以通过这个回调获取 SDK 的所有技术指标。
 * 如果您是首次开发音视频相关项目，可以只关注 onNetworkQuality 回调。
 *
 * @param statistics 统计数据，包括本地和远程的
 * @note 每2秒回调一次
 */
- (void)onTICStatistics: (TRTCStatistics *)statistics;
    
/**
 * 用于提示音量大小的回调,包括每个 userId 的音量和远端总音量
 *
 * 您可以通过调用 TRTCCloud 中的 enableAudioVolumeEvaluation 接口来开关这个回调或者设置它的触发间隔。
 * 需要注意的是，调用 enableAudioVolumeEvaluation 开启音量回调后，无论频道内是否有人说话，都会按设置的时间间隔调用这个回调;如果没有人说话，则 userVolumes 为空，totalVolume 为0。
 *
 * @param userVolumes 所有正在说话的房间成员的音量（取值范围0 - 100）。即 userVolumes 内仅包含音量不为0（正在说话）的用户音量信息。其中 userId 为 null  表示 local 的音量，也就是自己的音量。
 * @param totalVolume 所有远端成员的总音量, 取值范围0 - 100
 */
- (void)onTICUserVoiceVolume:(NSArray<TRTCVolumeInfo *> *)userVolumes totalVolume:(NSInteger)totalVolume;
    
@end

