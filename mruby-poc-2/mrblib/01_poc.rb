module PocMod2
  def add_bar
    self + "foo"
  end
end

class String
  include PocMod2
end
