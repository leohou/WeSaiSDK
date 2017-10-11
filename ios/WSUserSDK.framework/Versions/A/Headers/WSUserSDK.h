//
//  WSUserSDK.h
//  WSUserSDK
//
//  Created by houli on 2017/6/9.
//  Copyright © 2017年 leohou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WSLoginConfigModel.h"

/**
 登录 方式
 **/
typedef NS_ENUM(NSInteger, WSUUserLoginType) {
    WSULoginTypePhoneCode = 1,
    WSULoginTypePhonePwd = 2,
    WSULoginTypeWeiXin = 3,
};

/**
 登录 结果
 **/
typedef NS_ENUM(NSInteger,WSLoginResultCode) {
    WSLoginResultSucceed =0,  //登录成功
    WSLoginResultFailed =1, // 登录失败
    WSLoginResultMissingRequiredParameter =2, // 缺少必要参数（手机号or appid）
    WSLoginResultInterfaceError =3,//  接口错误
    WSLoginResutNoChannelIdAndSecret=4  //  缺少channelId或APPSecret
    
};

// 登录结果信息
@class WSUUserModel;
@interface WSUserLoginResultModel : NSObject

@property (nonatomic, strong) NSString * resultMessage; // 登录结果描述
@property (nonatomic, assign) WSLoginResultCode code; // 登录状态码
@property (nonatomic, strong) NSString *userid;
@property (nonatomic, strong) NSString *marketid;
@property (nonatomic, strong) NSString *mobile;
@property (nonatomic, assign) WSUUserLoginType loginType; // 登录方式


@end

typedef void(^LoginResult)(WSUserLoginResultModel * resultModel);
@interface WSUserSDK : NSObject

+ (instancetype)shardInstance;


/**
  横竖屏开关
 **/

+ (void)setSupportedInterfaceOrientations:(BOOL)on;



/**
 注册用户SDK
 @param marketId 渠道ID
 @param  businessId  (商户认证id，一款游戏对应一个商户id)
 @param  callbackUrl string `回调url`
 */
- (void)registerApp:(WSLoginConfigModel *)model;

/**
 登录调取方法
 @param parameters 配置参数 现在传空
 @param controller 是显示UI用
 @param completion 登录完成的回调(成功和失败状态码)
 */
- (void)wsPresentedLoginWithParameters:(NSDictionary *)parameters withController:(UIViewController *)controller completion:(LoginResult) completion;

/**
 获取当前用户ID
*/
+ (NSString *)getCurrentUserID;

/**
 获取IDFA
 */
+ (NSString *)getIDFA;
/**
 获取uuid
 */
+ (NSString *)getUUID;


/**
  tost 提示
 */
+ (void)dimmissInfo:(NSString *)info;

/**
  设置发送验证码时长
 */
+ (void)setCode:(NSInteger )code;

/**
 设置导航栏字体
 */
+ (void)setNavTitle:(NSString * )title;

/**
  取消页面
 */
+ (void)cancelViewController:(UIViewController *)viewController;




@end
