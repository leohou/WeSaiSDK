# WSUserSDK

[![CI Status](http://img.shields.io/travis/leohou/WSUserSDK.svg?style=flat)](https://travis-ci.org/leohou/WSUserSDK)
[![Version](https://img.shields.io/cocoapods/v/WSUserSDK.svg?style=flat)](http://cocoapods.org/pods/WSUserSDK)
[![License](https://img.shields.io/cocoapods/l/WSUserSDK.svg?style=flat)](http://cocoapods.org/pods/WSUserSDK)
[![Platform](https://img.shields.io/cocoapods/p/WSUserSDK.svg?style=flat)](http://cocoapods.org/pods/WSUserSDK)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

## Installation

WSUserSDK is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod "WSUserSDK"
```

## Author

leohou, 18801024669@163.com

## License

WSUserSDK is available under the MIT license. See the LICENSE file for more info.

一、注册应用获取appKey 和 appSecret

1.获取AppKey和AppSecret 等必要信息 需要去微赛后台获取

二、 集成WSUserSDK

通过 CocoaPods进行安装，只需在 Podfile文件中添加：

//************************ 工程说明
Core：工程内一些通用的机制实现类：统一的任务管理，模块管理，服务管理。

General：公用类和方法，包括工程内ViewController,UITableViewCell基类(Base)，公用Category(Category)，公用辅助方法(Helper)和宏定义(Marco)。

Model：公用数据模型

Sections：不同程序单元。如登录，设置等等。其下又可以按照功能分成不同的子目录：当前单元使用的自定义UI组件，管理类，数据模型和ViewController等等。

Vendors：第三方库。
/************************


#pod 'WSUserSDK', :git => 'ssh://git@gitlab.intra.wesai.com:22000/houli/iOS_wesaiUserFramework.git'
添加之后执行 pod install / pod update 命令即可。

三、代码集成

1、初始化 SDK
导入头文件 
#import <WSUserSDK/WSUserSDK.H>

在- (BOOL)application: didFinishLaunchingWithOptions:方法中调用registerApp方法来初始化SDK

/**
注册用户SDK
@param market_id 渠道ID
@param  businessid/appid  (商户认证id，一款游戏对应一个商户id)
@param  callback_url string '回调url'
*/

[[WSUserSDK shardInstance] registerApp:@"markid" businessId:@"businessid" appSecret:@"f335bbfb-d8aa-43e5-8bac-68092058592b" appid:@"fde239351306425f908c764bc10618b5" callbackUrl:@"http://www.weisai.com"];

2、添加实现代码 打开需要登录的视图源码，把如下代码复制并粘贴到你要出现登录界面的视图
#import <WSUserSDK/WSUserSDK.H>

/**
实现登录界面
@param parmeters 添加配置信息 如chnnelid 等 如果没有可以不填
@param  withController  视图控制器
@param  completion string '登录的回调 里边包含 成功和失败的信息 通过resultModel 展示'

*/

/**
 以下是登录回调结果模型 
**/
typedef NS_ENUM(NSInteger,WSLoginResultCode) {
WSLoginResultSucceed =0,  //登录成功
WSLoginResultUserCancel =1,  // 用户取消支付
WSLoginResultFailed =2, // 登录失败
WSLoginResultMissingRequiredParameter =3, // 缺少必要参数（手机号or appid）
WSLoginResultInterfaceError =4,//  接口错误
WSLoginResutNoChannelIdAndSecret=5  //  缺少channelId或APPSecret
};
/**
登录成功后 用户模型
**/
typedef NS_ENUM(NSInteger,WSResultUserInfo) {
WSResultUserPhoneNumber =0,  //手机号
};
// 登录结果
@interface WSUserLoginResultModel : NSObject
@property (nonatomic, strong) NSString * errString; // 登录结果描述
@property (nonatomic, assign) WSLoginResultCode code; // 登录状态码
@property (nonatomic, assign) WSUUserLoginType loginType; // 登录方式
@property (nonatomic, assign) WSResultUserInfo userInfo; // 登录成功后的用户信息（等待后台提供具体信息）


*注  resultModel  这个模型 包含 登录结果的回调 可以根据WSLoginResultCode 判断是否登录成功 或失败

// 集成代码
[[WSUserSDK shardInstance]  wsPresentedLoginWithParameters:nil withController:self completion:^(WSUserLoginResultModel *resultModel) {

     if (resultModel.code == WSLoginResultSucceed) {
           
              NSLog(@"登录成功");

     }else{

         NSLog(@"登录失败");
        //还可以获取失败原因
        NSLog(@"失败是：%@",resultModel.errString);
      }
}];

