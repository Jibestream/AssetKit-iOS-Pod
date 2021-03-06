Pod::Spec.new do |s|
  s.name             = 'AssetKit-iOS-Pod'
s.version='2.0.1'
  s.summary          = 'The AssetKit-iOS-Pod for the Jibestream iOS SDK.'

  s.description      = 'This CocoaPod provides the release version of the AssetKit for the Jibestream iOS SDK.'

  s.homepage         = 'http://www.jibestream.com/'
  s.author           = { 'louie' => 'lyuen@jibestream.com' }
  s.source           = { :git => 'https://github.com/Jibestream/AssetKit-iOS-Pod', :tag => "#{s.version}" }

  s.ios.deployment_target = '9.0'
  s.platform = :ios, '9.0'
  s.vendored_frameworks = 'AssetKit-iOS-Pod/Frameworks/*.framework'

end
