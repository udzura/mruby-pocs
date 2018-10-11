MRuby::Build.new do |conf|
  toolchain :clang

  conf.gem './'
end
