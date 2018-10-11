MRuby::Build.new do |conf|
  toolchain :gcc

  conf.enable_debug
  conf.gem './'
end
