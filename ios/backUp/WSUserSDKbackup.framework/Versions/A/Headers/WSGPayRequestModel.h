//
//  WSGPayRequestModel.h
//  WSUserSDK_Example
//
//  Created by houli on 2018/4/19.
//  Copyright © 2018年 leohou. All rights reserved.
//

#import <Foundation/Foundation.h>
/*
 *  支付方式
 */
typedef NS_ENUM (NSInteger, WSGPayType) {
    WSGPaymentTypeWX          = 1,    /**< 微信支付     */
    WSGPaymentTypeAli         = 2,    /**< 支付宝支付   */
    WSGPaymentTypeAliH5       = 3,    /**< 支付宝H5支付 */
    WSGPaymentTypeIAP         = 4,    /**< 苹果内购支付  */
};

@interface WSGPayRequestModel : NSObject
/*
 *  appId
    appKey
    channleId
    添加 到 工程的plist 中
 */
@property(nonatomic,strong) NSString *productId;            //商品id 必传字段
@property(nonatomic,strong) NSString *userID;               //用户id 必传字段
@property(nonatomic,assign) WSGPayType payMentType;         //支付方式 必传字段
@property(nonatomic,strong) NSString *phoneNumber;          //手机号 选填字段
@property(nonatomic,strong) NSString *passback;             //透传字段
@property(nonatomic,strong) NSString *ext_a;                //备用字段

+ (instancetype)shardInstance;

@end
