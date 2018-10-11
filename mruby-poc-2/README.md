# mruby-poc-2

Shows wrong information about line of code where exception occurred

```
$ rake
$ ./mruby/bin/mruby -e '1 + 1'
trace (most recent call last):
        [0] /usr/local/ghq/github.com/udzura/mruby-pocs/mruby-poc-2/mrblib/01.rb:1
/usr/local/ghq/github.com/udzura/mruby-pocs/mruby-poc-2/mrblib/01.rb:1: undefined method 'send' (NoMethodError)
```

## Details

* `mrblib/00.rb`

```
module PocMod
  def add_foo
    self + "foo"
  end
end

String.send :include, PocMod # L6
```

* `mrblib/01.rb`

```
module PocMod2
  def add_bar
    self + "foo"
  end
end

class String
  include PocMod2
end
```

The mgem initializer process loads files in order 00.rb -> 01.rb.

L6 @ `mrblib/00.rb` makes NoMethodError (because mruby-metaprog is splitted). But with `conf.enable_debug`, exception info shows that L1 @ `mrblib/01.rb` has error.

```
$ ./mruby/bin/mruby -e '1 + 1'
trace (most recent call last):
        [0] /usr/local/ghq/github.com/udzura/mruby-pocs/mruby-poc-2/mrblib/01.rb:1
/usr/local/ghq/github.com/udzura/mruby-pocs/mruby-poc-2/mrblib/01.rb:1: undefined method 'send' (NoMethodError)
```

If you add 7th line to `00.rb`, mruby shows that error is occurred in L7 @ `mrblib/00.rb`. This is undesirable to developers.
