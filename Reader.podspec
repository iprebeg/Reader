Pod::Spec.new do |s|
  s.name     = 'Reader'
  s.version  = '2.7.2'
  s.license  = 'MIT' 
  s.summary  = 'An open source PDF file reader/viewer for iOS.'
  s.homepage = 'http://www.vfr.org/'
  s.author   = { 'Julius Oklamcak' => 'joklamcak@gmail.com' }

  s.source   = { :git => 'https://github.com/iprebeg/Reader.git', :commit => '03ee9900884d1994d99a881c8c691d394c01f1fa' }

  s.platform = :ios

  s.source_files = 'Sources/**/*.{h,m}'

  s.resources = 'Resources/*.{pdf}', 'Graphics/*.png'

  s.exclude_files = 'Graphics/Default-568h@2x.png'

  s.requires_arc = true

  s.frameworks = 'UIKit', 'Foundation', 'CoreGraphics', 'QuartzCore', 'ImageIO', 'MessageUI'

end
