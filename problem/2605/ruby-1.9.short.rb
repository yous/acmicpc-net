# encoding: utf-8
gets;a=gets.split.map &:to_i;s=[];a.each_with_index{|v,i|s.insert i-v,i+1};puts s*" "

# gets.to_i
# orders = gets.split.map(&:to_i)
# stack = []
# orders.each_with_index do |order, idx|
#   stack.insert(idx - order, idx + 1)
# end
# puts stack.join(" ")
