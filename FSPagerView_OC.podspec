Pod::Spec.new do |s|
  s.name             = "FSPagerView_OC"
  s.version          = "0.0.1"
  s.summary          = "FSPagerView_OC ios SDK"
  s.homepage         = "https://github.com/skyhome-zhang/FSPagerView_OC.git"
  s.license          = {:type => "MIT", :file => "LICENSE"}
  s.author           = { "skyhome.zhang" => "skyhome.zhang@bestwehotel.com" }
  s.source           = { :git => "https://github.com/skyhome-zhang/FSPagerView_OC.git", :tag => s.version.to_s}
 


  s.platform     = :ios, '8.0'
  s.ios.deployment_target = '8.0'
  s.requires_arc = true
  s.frameworks = 'UIKit', 'Foundation'
  s.module_name = 'FSPagerView_OC'
 
  s.source_files = 'FSPagerView_OC/FSPagerView/**/*.{h,m}'

end

