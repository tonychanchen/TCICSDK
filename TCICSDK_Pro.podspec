
Pod::Spec.new do |s|


  s.name         = "TCICSDK_Pro"
  s.version      = ENV['LIB_VERSION'] || '1.0.0'
  s.summary      = "TCICSDK"
  s.description  = <<-DESC
                      腾讯云互动教育极简单接入SaaS方案
                   DESC
  s.homepage     = "https://github.com/tonychanchen/TCICSDK"
  s.license      = "MIT"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = "eagleychen"
  s.platform     = :ios
  s.platform     = :ios, "9.0"

#  valid_archs = ['armv7','arm64', 'x86_64']
#  s.xcconfig = {
#    'VALID_ARCHS' =>  valid_archs.join(' '),
#  }


  s.source       = { :git => "https://github.com/tonychanchen/TCICSDK.git", :tag => "v#{s.version}" }
  
  s.resource = 'tcicimage.bundle'
  s.vendored_frameworks = 'TCICSDK.framework'
  s.frameworks = 'Foundation', 'Accelerate'
  s.dependency 'Masonry'
  s.dependency 'YYModel'
  s.dependency 'Bugly'
  s.dependency 'TIWLogger_iOS', '1.0.1.73'
  s.dependency 'TIWCache_iOS', '2.0.0.121'
  s.dependency 'TXLiteAVSDK_Professional', '10.9.13161'
  
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
                            'GENERATE_INFOPLIST_FILE' => 'YES'
}
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
                             'GENERATE_INFOPLIST_FILE' => 'YES'
}
  
end
