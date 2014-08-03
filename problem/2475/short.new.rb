# encoding: utf-8
p gets.split.reduce(0){|a,e|e=e.to_i;a+e*e}%10

# ids = gets.split.map(&:to_i)
# result = ids.reduce(0) do |sum, value|
#   sum + value * value
# end
# p result % 10
