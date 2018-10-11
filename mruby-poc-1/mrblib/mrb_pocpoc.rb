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
    p obj.fill_attr_if_nil
  end

  def self.run2
    obj = PocObj.new
    p obj.fill_attr_if_nil_2
  end
end
