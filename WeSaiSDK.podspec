Pod::Spec.new do |s|
  s.name = "WeSaiSDK"
  s.version = "2.0"
  s.summary = "WeSaiSDK"
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"wesaiPublic"=>"houli@wesai.com"}
  s.homepage = "https://github.com/wesaiPublic/WeSaiSDK"
  s.description = "TODO:  Add long description of the pod here."
  s.frameworks = ["UIKit", "Foundation", "SystemConfiguration", "CoreGraphics", "StoreKit",'AdSupport','Security','CoreTelephony','WebKit']
  s.xcconfig = {"OTHER_LDFLAGS"=>"-lObjC"}
  s.source   = { :git => 'https://github.com/wesaiPublic/WeSaiSDK.git'}

  s.ios.deployment_target    = '9.0'
  s.ios.vendored_framework   = 'ios/WSUserSDK.framework'

  s.dependency 'IQKeyboardManager' ,'5.0.6'
  s.dependency 'AlipaySDK-2.0'
  s.dependency 'FMDB', '2.7.2'
  s.dependency 'ShareSDK3/ShareSDKPlatforms/WeChat', '3.3.2'
  s.dependency 'Masonry', '0.6.1'
  s.dependency 'JSONModel', '1.2.0'
  s.ios.resource=['ios/Resource/**/*.{xcassets,wav,mp3,xib,txt,cer,plist}']
end
