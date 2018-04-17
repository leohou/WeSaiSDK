//
//  WSUserSDK.h
//  WSUserSDK
//
//  Created by houli on 2017/6/9.
//  Copyright © 2017年 leohou. All rights reserved.
//  v2.0.0

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WSGRequestMode.h"

/*
 *  支付方式
 */
typedef NS_ENUM (NSInteger, WSGPayType) {
    WSGPaymentTypeWX          = 1,    /**< 微信支付     */
    WSGPaymentTypeAli         = 2,    /**< 支付宝支付   */
    WSGPaymentTypeAliH5       = 3,    /**< 支付宝H5支付 */
    WSGPaymentTypeIAP         = 4,    /**< 苹果内购支付  */
};
/*
 *  分享状态码
 */
typedef NS_ENUM (NSInteger, WSGShareStatus) {
    ShareSuccess           = 0,    /**< 分享成功    */
    ShareFail              = 1,    /**< 分享失败    */
};

/**
 * 分享类型
 */
typedef NS_ENUM(NSInteger, ShareType) {
    SHARE_WEBPAGE = 1,  //网页分享
    SHARE_IMGAGE = 2,   //图片分享
    SHARE_TEXT = 3,     //文字分享
    SHARE_MUSIC = 4,    //音乐分享
    SHARE_VIDEO = 5 ,   //视频分享
    
};
/**
 * 分享位置
 */
typedef NS_ENUM(NSInteger, ShareDestination) {
    SHARE_WXSceneSession = 0,         //分享到微信聊天
    SHARE_WXSceneTimeline = 1,   //分享到微信朋友圈
    SHARE_WXSceneFavorite = 2,       //微信收藏
};

//支付类型model
@interface WSPayTypeModel : NSObject
@property (nonatomic, strong) NSString *schemeKey;
@property (nonatomic, assign) WSGPayType payType;
-(id)initWithSchemeKey:(NSString *)schemeKey payType:(WSGPayType)payType;

@end

/**
 *  分享内容状态变更回调处理器
 */
typedef void(^ShareStateChangedHandler) (WSGShareStatus state);

/**
 *  登录返回结果block
 */
typedef void(^LoginResultHandler) (id resultData);

/**
 *  商品列表 以数组里边装对象方式返回
 */
typedef void(^ProductListHandler) (BOOL status, id resultData);


@interface WeSaiSDK : NSObject

+ (instancetype)shardInstance;


-(void)registerPayApp:(NSArray<WSPayTypeModel *> *)payTypeDic;


/**
 注册用户SDK
 @param marketId 渠道ID
 @param  appSecret
 @param  appid
 @param  callbackUrl string `回调url`
 @param  wxappId
 @param  wxappSecret
 */
- (void)registerApp:(NSString *)marketId appSecret:(NSString *)appSecret appid:(NSString *)appid callbackUrl:(NSString *)callbackUrl wxappId:(NSString *)wxappId wxappSecret:(NSString *)wxappSecret;

/**
   手机号登录
 @param model 配置参数 WSGRequestMode 类型
 
 WSGRequestMode *model = [[WSGRequestMode alloc]init];
 model.mobile = @"你的手机号";
 model.validationCode = @"你的验证码";
 model.member_level = @"登录类型"; 参考 WSGUserLoginType
 
 @param completion 登录完成的回调(成功和失败状态码)
 */
- (void)weSaiLogin:(WSGRequestMode *)model WithHidenLoading:(BOOL)hide Completion:(LoginResultHandler)completion;


/**
  发送验证码
 @param model 配置参数 WSGRequestMode 类型
 
 WSGRequestMode *model = [[WSGRequestMode alloc]init];
 model.mobile = @"你的手机号";
 
 @param completion 登录完成的回调(成功和失败状态码)
 */
- (void)weSaiGetCode:(WSGRequestMode *)model WithHidenLoading:(BOOL)hide Completion:(LoginResultHandler)completion;


/**
 注册
 @param model 配置参数 WSGRequestMode 类型
 @param completion 登录完成的回调(成功和失败状态码)
 */
- (void)weSaiRegist:(WSGRequestMode *)model WithHidenLoading:(BOOL)hide Completion:(LoginResultHandler)completion;


/**
 绑定手机号
 @param model 配置参数 WSGRequestMode 类型
 @param completion 登录完成的回调(成功和失败状态码)
 */
- (void)weSaiBindPhone:(WSGRequestMode *)model WithHidenLoading:(BOOL)hide Completion:(LoginResultHandler)completion;

/**
 自动登录接口
 @param model 配置参数 WSGRequestMode 类型
 @param completion 登录完成的回调(成功和失败状态码)
 */
- (void)weSaiAutoLogin:(WSGRequestMode *)model WithHidenLoading:(BOOL)hide Completion:(LoginResultHandler)completion;

/**
 游客登录
 @param model 配置参数 WSGRequestMode 类型
 @param completion 登录完成的回调(成功和失败状态码)
 */

- (void)weSaiVisitorsLogin:(WSGRequestMode *)model WithHidenLoading:(BOOL)hide Completion:(LoginResultHandler)completion;

/**
  微信登录
 @param model 配置参数 WSGRequestMode 类型
 @param completion 登录完成的回调(成功和失败状态码)
 */

- (void)weSaiWXLogin:(WSGRequestMode *)model WithHidenLoading:(BOOL)hide Completion:(LoginResultHandler)completion;


/*
 * 获取商品列表
 * completion  分享回调 结果 以数组方式返回
 */
- (void)weSaiProductListCompletion:(ProductListHandler)completion;

/*
 *  支付统一下单接口
 * productid 商品id
 * type  支付的类型 1 微信 2 支付宝
 * completion  分享回调 结果 字典方式返回
 */
- (void)weSaiPayUnifiedorderProductId:(NSString *)productid withPayType:(WSGPayType )type Completion:(ProductListHandler)completion;

/**
 这个是放到AppDelegate里面，当支付完成接收微信和支付宝回调
 @param url 微信和支付宝的回调URL
 @param completion 处理完成的回调
 @return 返回值，返回NO则App自己处理
 */
+(BOOL)handleOpenURL:(NSURL *)url completion:(void(^)())completion;



/*    分享
 * secen 分享到哪个场景 如 聊天 朋友圈  收藏
 * type   分享内容的类型 如果 网页 文字 视频等
 * title  分享标题
 * desc   分享描述
 * imgStr    分享缩略图片 图片的名称 如weisai.png
 * url    分享的连接地址
 * completion  分享回调 结果
 */
-(void)weSaiShare:(ShareDestination)secen withShareType:(ShareType)type withTitle:(NSString *)title withDesc:(NSString *)desc withThumbImage:(NSString *)imgStr withUrl:(NSString *)url
           completion:(ShareStateChangedHandler)completion;


@end
