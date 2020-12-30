//
//  TCICTRTCVideoView.h
//  TCIC_SaaS_UI_SDK
//
//  Created by 陈耀武 on 2020/9/15.
//  Copyright © 2020 陈耀武. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TCICUIRenderDef.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCICTRTCVideoView : UIImageView<TCICUIRenderView>

@property (nonatomic, copy) NSString *userId;                 // 用户Id
@property (nonatomic, assign) TCICUIRenderType viewType;      // 显示类型
@property (nonatomic, assign) CGRect rectWithoutKeyboard;     // 在无键盘弹出时，显示的位置；键盘弹出时，渲染控件会跟随整体上移


@end

NS_ASSUME_NONNULL_END
