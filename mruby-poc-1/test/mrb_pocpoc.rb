##
## PocPoc Test
##

assert("PocPoc#hello") do
  t = PocPoc.new "hello"
  assert_equal("hello", t.hello)
end

assert("PocPoc#bye") do
  t = PocPoc.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("PocPoc.hi") do
  assert_equal("hi!!", PocPoc.hi)
end
