# encoding: utf-8
g=->(){gets.split.map &:to_i};gets.to_i;a=g[];b=g[];p a.sort.reverse.zip(b.sort).map{|v|v.reduce:*}.reduce:+

# gets.to_i
# a = gets.split.map(&:to_i)
# b = gets.split.map(&:to_i)
# p a.sort.reverse.zip(b.sort).map { |v| v.reduce(:*) }.reduce(:+)
