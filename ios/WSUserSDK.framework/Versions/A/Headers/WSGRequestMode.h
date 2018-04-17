//
//  WSGRequestMode.h
//  WSUserSDK_Example
//
//  Created by houli on 2018/4/13.
//  Copyright © 2018年 leohou. All rights reserved.
//

/**
 * 登录方式
 */
typedef NS_ENUM(NSInteger, WSGUserLoginType) {
    WSGLoginTypePhoneCode = 1,  //手机号
    WSGLoginTypeAccountPwd = 2, //用户密码
    WSGLoginTypeVisitors = 3,   //游客
    WSGLoginTypeWeiXin = 4,     //微信
    
};


#import <Foundation/Foundation.h>



@interface WSGRequestMode : NSObject

@property(nonatomic,strong) NSString *name;     //帐号
@property(nonatomic,strong) NSString *mobile;   //手机号
@property(nonatomic,strong) NSString *validationCode; //验证码
@property(nonatomic,strong) NSString *password;       //密码
@property(nonatomic,strong) NSString *token;       //自动登录使用
@property(nonatomic,assign) WSGUserLoginType loginType;   //登录方式
@end
