# encoding: utf-8
g=->{gets.split.map(&:to_i).sort};g[];a=g[].reverse;b=g[];p a.zip(b).map{|v|v.reduce:*}.reduce:+

# gets.to_i
# a = gets.split.map(&:to_i).sort.reverse
# b = gets.split.map(&:to_i).sort
# p a.zip(b).map { |v| v.reduce(:*) }.reduce(:+)
