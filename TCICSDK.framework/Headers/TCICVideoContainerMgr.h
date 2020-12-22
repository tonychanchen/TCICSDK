//
//  TCICVideoContainerMgr.h
//  TCIC_SaaS_UI_SDK
//
//  Created by 陈耀武 on 2020/9/15.
//  Copyright © 2020 陈耀武. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "TCICUICustomMgr.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCICVideoContainerMgr : NSObject<TCICUICustomMgr>

@property (nonatomic, assign, nonnull) Class renderViewClass;            // 用于渲染TRTC视频的控件类

/**
 * 获取本地已添加的渲染控件信息;
 */
- (NSArray *_Nullable)userRenderViewArray;

@end

NS_ASSUME_NONNULL_END
