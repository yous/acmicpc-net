# encoding: utf-8
p gets.split.reduce(0){|a,e|a+e.to_i**2}%10

# ids = gets.split.map(&:to_i)
# result = ids.reduce(0) do |sum, value|
#   sum + value ** 2
# end
# p result % 10
