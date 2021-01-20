//
//  TCICUIRenderDef.h
//  TCICSDK
//
//  Created by 陈耀武 on 2020/10/29.
//  Copyright © 2020 陈耀武. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TCICUIRenderType) {
    TCICUIRender_Audio          = -1,    // 音频(暂未用到)
    TCICUIRender_Big            = 0,     // 主画面视频流, 对应TRTC TRTCVideoStreamTypeBig
    TCICUIRender_Small          = 1,     // 小画面视频流, 对应TRTC TRTCVideoStreamTypeSmall
    TCICUIRender_Sub            = 2,     // 辅流（屏幕分享）, 对应TRTC TRTCVideoStreamTypeSub
};


@protocol TCICUIRenderView <NSObject>

@required
@property (nonatomic, copy) NSString *userId;                 // 用户Id
@property (nonatomic, assign) TCICUIRenderType viewType;      // 显示类型

@end

@protocol TCICUIRenderSource <NSObject>

@required
/**
 * 查找如何渲染TRTC流的UIView
 * @param userid 用户id;
 * @param avType 渲染类型;
 * @return 返回要渲染的view，可为nil
 */
- (UIView *_Nullable)renderViewOf:(NSString * _Nullable)userid viewType:(TCICUIRenderType)avType;

@end

NS_ASSUME_NONNULL_END
