//
//  TCICUICustomMgr.h
//  TCICSDK
//
//  Created by 陈耀武 on 2020/9/4.
//  Copyright © 2020 AlexiChen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import "TCICUIRenderDef.h"
#import "TCICCustomDef.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TCICUICustomMgr<TCICUIRenderSource, TCICCustomMsgRecver, TCICCustomMsgSender>

@required

@property (nonatomic, assign, nonnull) Class renderViewClass;   // 用于渲染TRTC视频的控件类
/**
 * 主线程回调: H5通知UI层做好UI相关的初始化工作
 * @param extInfo H5下发的业务信息，业务侧自行解析
 * @param view 当前ViewController.view 外部拿到时可向其添加子控件
 */
- (void)onInitUserLayout:(NSDictionary *_Nullable)extInfo controllerView:(UIView *_Nonnull)view;

/**
* 主线程回调: H5通知UI添加或更新userId对应的信息，建议业务侧做好信息搜集管理
* @param userId H5下发的业务信息中的userId
* @param avType H5下发的业务信息中的viewType
* @param extInfo H5下发的业务信息，业务侧自行解析
* @param offset 收到消息时，底层webView的偏移。在webView有输入时，会发生偏移，收到回调后视业务需要处理
* @param view 当前ViewController.view 外部拿到时可向其添加子控件
* @param stubView 锚点view(父控件为view), 如果添加的控件的父控件也为view的话，建议insert below stubView
*/
- (void)onAddOrUpdateUserLayout:(NSString *_Nullable)userId viewType:(TCICUIRenderType)avType extInfo:(NSDictionary *_Nullable)extInfo offset:(CGPoint)offset controllerView:(UIView *_Nonnull)view stubView:(UIView *_Nonnull)stubView;

/**
* 主线程回调: H5通知UI移除userId对应的信息，建议业务侧做好信息搜集管理
* @param userId H5下发的业务信息中的userId
* @param avType H5下发的业务信息中的viewType
* @param extInfo H5下发的业务信息，业务侧自行解析
* @param view 当前ViewController.view 外部拿到时可向其添加子控件
*/
- (void)onRemoveUserLayout:(NSString *_Nullable)userId viewType:(TCICUIRenderType)avType extInfo:(NSDictionary *_Nullable)extInfo controllerView:(UIView *_Nonnull)view;

@optional

/**
* 主线程回调: UI发生旋转时，通知定制UI旋转
* @param landscape true 横屏， false ： 竖屏
*/
- (void)onShouldAutoRotateAndLayout:(BOOL)landscape;



@end


NS_ASSUME_NONNULL_END
