# mruby-poc-1   [![Build Status](https://travis-ci.org/udzura/mruby-poc-1.svg?branch=master)](https://travis-ci.org/udzura/mruby-poc-1)
PocPoc class
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'udzura/mruby-poc-1'
end
```
## example
```ruby
p PocPoc.hi
#=> "hi!!"
t = PocPoc.new "hello"
p t.hello
#=> "hello"
p t.bye
#=> "hello bye"
```

## License
under the MIT License:
- see LICENSE file
