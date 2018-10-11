module PocMod
  def add_foo
    self + "foo"
  end
end

String.send :include, PocMod
