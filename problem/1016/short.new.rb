# encoding: utf-8
require"prime";n,m=gets.split.map &:to_i;p (n..m).count{|v|v.prime_division.all?{|_,e|e==1}}

# require "prime"
# min, max = gets.split.map(&:to_i)
# count = (min..max).count { |num| num.prime_division.all? { |_p, n| n == 1 } }
# p count
