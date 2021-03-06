Pod::Spec.new do |s|
  s.name              = 'UserzoomSDK'
  s.module_name       = 'UserzoomSDK'
  s.version           = '1.0.0'
  s.platform          = :ios, '13.0'
  s.summary           = 'UserzoomSDK to integrate Userzoom Experience Consulting platform.'
  s.authors           = { 'Userzoom R&D Team' => 'developers@userzoom.com' }
  s.homepage          = 'http://userzoom.com'
  s.license           = { :type => 'Commercial', :file => 'LICENSE.md'  }
  s.source            = { :git => 'https://github.com/userzoom/UserzoomSDK-iOS.git'}
  s.social_media_url  = 'https://twitter.com/userzoom'
  s.frameworks        = 'AVFoundation', 'CoreMedia', 'QuartzCore', 'SystemConfiguration', 'UserNotifications', 'WebKit'
  s.library           = 'z'
  s.module_map        = 'UserzoomSDK.framework/Modules/module.modulemap'
  s.source_files      = 'UserzoomSDK.framework/**/*.h'
  s.public_header_files = 'UserzoomSDK.framework/Headers/*.h'
  s.ios.vendored_frameworks = 'UserzoomSDK.framework'
  s.dependency        'DatadogSDKObjc', '~> 1.3.1'
end
