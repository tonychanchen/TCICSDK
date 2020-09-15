
Pod::Spec.new do |s|


  s.name         = "TYIC_SaaS_SDK"
  s.version      = "3.0.14"
  s.summary      = "TYIC_SaaS_SDK"
  s.description  = <<-DESC
                      腾讯云互动教育极简单接入SaaS方案
                   DESC
  s.homepage     = "https://github.com/JamesChenGithub/tyic_saas_sdk"
  s.license      = "MIT"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = "alexichen"
  s.platform     = :ios
  s.platform     = :ios, "9.0"

  valid_archs = ['armv7','arm64', 'x86_64']
  s.xcconfig = {
    'VALID_ARCHS' =>  valid_archs.join(' '),
  }


  s.source       = { :git => "https://github.com/JamesChenGithub/tyic_saas_sdk.git", :tag => "#{s.version}" }
  
  # s.resource = 'tyicimage.bundle'
  # the framework upload to Cocoa Pods

  s.vendored_frameworks = 'TYIC_SaaS_SDK.framework'
  s.frameworks = 'Foundation', 'Accelerate'
  s.dependency 'Masonry'
  s.dependency 'YYModel'
  s.dependency 'TXLiteAVSDK_TRTC', '7.6.9355'

end
