# encoding: utf-8
p 2.upto(gets.to_i).reduce(1){|a,e|a*=e;a/=10while a%10==0;a}%100000

# result = 2.upto(gets.to_i).reduce(1) do |fac, item|
#   fac *= item
#   fac /= 10 while fac % 10 == 0
#   fac
# end
# p result % 100_000
