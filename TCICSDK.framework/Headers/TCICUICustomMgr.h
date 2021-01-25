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

NS_ASSUME_NONNULL_BEGIN

@protocol TCICUICustomMgr<TCICUIRenderSource>

@required
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


@required
/**
* 主线程回调: 同层渲染相关, H5添加用userId添加渲染div时，native对应生成渲染UI
* @param userId 用户Id
* @param avType 渲染类型
* @param renderView 最终渲染的view
* 注意：业务仅将这些信息记录即可，无须作额外处理；
*/
- (void)onAddRenderItem:(NSString *_Nullable)userId viewType:(TCICUIRenderType)avType renderView:(UIView *_Nonnull)renderView;

/**
* 主线程回调: 同层渲染相关, 查询本地是否已记录userId对应渲染UI
* @param userId 用户Id
* @param avType 渲染类型
*/
- (UIView *_Nullable)userRenderItemOf:(NSString *_Nullable)userId viewType:(TCICUIRenderType)avType;

/**
* 主线程回调: 同层渲染相关, H5移除userId对应渲染div时，native对应删除记录的渲染UI
* @param userId 用户Id
* @param avType 渲染类型
*/
- (void)onRemoveRenderItem:(NSString *_Nullable)userId viewType:(TCICUIRenderType)avType;

@optional

/**
* 主线程回调: UI发生旋转时，通知定制UI旋转
* @param landscape true 横屏， false ： 竖屏
*/
- (void)onShouldAutoRotateAndLayout:(BOOL)landscape;



@end


NS_ASSUME_NONNULL_END
