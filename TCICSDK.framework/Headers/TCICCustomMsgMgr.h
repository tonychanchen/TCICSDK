//
//  TCICCustomMsgMgr.h
//  TYIC_SaaS_SDK
//
//  Created by 陈耀武 on 2021/1/22.
//  Copyright © 2021 陈耀武. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TCICCustomDef.h"

NS_ASSUME_NONNULL_BEGIN

@interface TCICCustomMsgMgr : NSObject<TCICCustomMsgSender, TCICCustomMsgRecver>

@end

NS_ASSUME_NONNULL_END
