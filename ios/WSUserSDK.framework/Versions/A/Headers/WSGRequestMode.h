//
//  WSGRequestMode.h
//  WSUserSDK_Example
//
//  Created by houli on 2018/4/13.
//  Copyright © 2018年 leohou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WSGRequestMode : NSObject

@property(nonatomic,strong) NSString *name;     //帐号
@property(nonatomic,strong) NSString *mobile;   //手机号
@property(nonatomic,strong) NSString *validationCode; //验证码
@property(nonatomic,strong) NSString *password;       //密码
@property(nonatomic,strong) NSString *token;       //自动登录使用
/*
登录方式:
1: 手机号登录
2 :帐号密码登录
3 :游客登录
4: 微信登录
*/
@property(nonatomic,strong) NSString *member_level;   //登录方式
@end
