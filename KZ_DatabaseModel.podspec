
Pod::Spec.new do |s|

    s.name = 'KZ_DatabaseModel'
    s.version = '0.1'
    s.summary = 'iOS database.'
    s.homepage = 'https://github.com/KieronZhang/KZ_DatabaseModel'
    s.license = {:type => 'MIT', :file => 'LICENSE'}
    s.author = {'KieronZhang.' => 'https://github.com/KieronZhang'}
    s.platform = :ios, '8.0'
    s.source = {:git => 'https://github.com/KieronZhang/KZ_DatabaseModel.git', :tag => s.version, :submodules => true}
    s.xcconfig = {'OTHER_LDFLAGS' => '-ObjC'}
    s.frameworks = 'Foundation'
    s.vendored_frameworks = 'KZ_DatabaseModel/KZ_DatabaseModelFramework.framework'
    s.requires_arc = true
    
    s.dependency 'KZ_Model'
    s.dependency 'KZ_Database'

end
