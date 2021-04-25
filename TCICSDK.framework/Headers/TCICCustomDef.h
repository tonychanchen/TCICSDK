//
//  TCICCustomDef.h
//  TCICSDK
//
//  Created by 陈耀武 on 2020/10/29.
//  Copyright © 2020 陈耀武. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 *  自定义通道发送者
 */
@protocol TCICCustomMsgSender<NSObject>

/**
 * 向H5发送自定义消息
 * @param customMsg 要发送的消息，业务侧做好定制格式，以便H5侧解析
 */
- (BOOL)sendCustomMsg:(NSString *_Nullable)customMsg;

@end

/**
 * 自定义通道接收者
 */
@protocol TCICCustomMsgRecver <NSObject>

@required
/**
 * H5向Native注册
 * @param sender : H5模块对应Native本地模块；
 */
- (void)onRegistSender:(id<TCICCustomMsgSender> _Nonnull)sender;

/**
* H5向Native发送消息
* @param sender : H5模块对应Native本地模块;
* @param jsonMsg 发送的定制消息;
* 注意事项：
*   1. 若业务侧接收到消息后，异步调用sendCustomMsg回复；
*/

- (void)onRecvMsgFrom:(id<TCICCustomMsgSender> _Nonnull)sender customMsg:(NSString *_Nonnull)jsonMsg;

@end



NS_ASSUME_NONNULL_END
