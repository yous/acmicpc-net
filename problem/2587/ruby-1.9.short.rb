# encoding: utf-8
n=$<.map &:to_i;p n.reduce(:+)/n.size,n.sort[2]

# nums = []
# 5.times do
#   nums << gets.to_i
# end
# p nums.reduce(:+) / nums.size
# p nums.sort[2]
