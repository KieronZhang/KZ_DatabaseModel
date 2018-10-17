
Pod::Spec.new do |s|

    s.name = 'KZ_DatabaseModel'
    s.version = '0.1.2'
    s.summary = 'iOS & macOS database.'
    s.homepage = 'https://github.com/KieronZhang/KZ_DatabaseModel'
    s.license = {:type => 'MIT', :file => 'LICENSE'}
    s.author = {'KieronZhang' => 'https://github.com/KieronZhang'}

    s.source = {:git => 'https://github.com/KieronZhang/KZ_DatabaseModel.git', :tag => s.version, :submodules => true}
    s.xcconfig = {'OTHER_LDFLAGS' => '-ObjC'}
    s.requires_arc = true

    s.frameworks = 'Foundation'

    s.ios.deployment_target = '8.0'
    s.osx.deployment_target = '10.10'

    s.ios.vendored_frameworks = 'KZ_DatabaseModel/KZ_DatabaseModel_iOS.framework'
    s.osx.vendored_frameworks = 'KZ_DatabaseModel/KZ_DatabaseModel_macOS.framework'

    s.dependency 'KZ_Model'
    s.dependency 'KZ_Database'

end
