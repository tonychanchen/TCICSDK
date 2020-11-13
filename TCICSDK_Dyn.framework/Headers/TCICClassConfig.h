//
//  TCICClassConfig.h
//  TCICSDK
//
//  Created by AlexiChen on 2020/5/22.
//  Copyright © 2020 AlexiChen. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TCICClassConfig : NSObject

@property (nonatomic, copy, nonnull) NSString *userId;              // 用户ID,必传
@property (nonatomic, copy, nonnull) NSString *token;               // token,必传
@property (nonatomic, copy, nonnull) NSString *userSig;             // userSig,必传
@property (nonatomic, assign) UInt32 schoolId;                      // 学校Id,必传
@property (nonatomic, assign) UInt32 classId;                       // 课程ID,必传

// 当前config是否有效，主要检查参数userId,token,userSig,newEnterId是否为空串，以及classRoomId>0
- (BOOL)isValied;

@end

NS_ASSUME_NONNULL_END
