# encoding: utf-8
require"prime";n,m=gets.split.map &:to_i;p (n..m).count{|c|Prime.each{|p|break 1if c==1;(c/=p;break 0if c%p==0)if c%p==0}>0}

# require "prime"
# min, max = gets.split.map(&:to_i)
# count = (min..max).count do |num|
#   Prime.each do |p|
#     break true if num == 1
#     if num % p == 0
#       num /= p
#       break false if num % p == 0
#     end
#   end
# end
# p count
