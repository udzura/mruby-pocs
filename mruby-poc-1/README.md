# [Fixed] mruby-poc-1

This bug fixed after commit [fdd5ce8fac8f306f71f336f07f0a537b8626e6d6](https://github.com/mruby/mruby/commit/fdd5ce8fac8f306f71f336f07f0a537b8626e6d6).

----

Strange behavior in nil-guard assign to attribute

```console
$ rake
$ ./mruby/bin/mruby -e 'PocPoc.run'

trace (most recent call last):
        [0] -e:1
-e:1: undefined method 'attr1=' (NoMethodError)
```

---

```ruby
class PocObj
  attr_accessor :attr1

  def fill_attr_if_nil
    self.attr1 ||= :OK
  end

  def fill_attr_if_nil_2
    unless self.attr1
      self.attr1 = :OK
    end
  end
end

class PocPoc
  def self.run
    obj = PocObj.new
    p obj.fill_attr_if_nil # Broken
  end

  def self.run2
    obj = PocObj.new
    p obj.fill_attr_if_nil_2 # OK
  end
end
```
