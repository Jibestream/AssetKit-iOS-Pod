Pod::Spec.new do |s|
  s.name             = 'AssetKit-iOS-Pod'
  s.version          = '1.0'
  s.summary          = 'The AssetKit-iOS-Pod for the Jibestream iOS SDK.'

  s.description      = 'This CocoaPod provides the release version of the AssetKit for the Jibestream iOS SDK.'

  s.homepage         = 'http://www.jibestream.com/'
  s.author           = { 'louieyune' => 'lyuen@jibestream.com' }
  s.source           = { :git => 'https://github.com/louieyune/AssetKit-iOS-Pod.git', :tag => "#{s.version}" }

  s.ios.deployment_target = '9.0'
  s.platform = :ios, '9.0'
  s.vendored_frameworks = 'AssetKit-iOS-Pod/Frameworks/*.framework'

end
