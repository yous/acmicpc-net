# encoding: utf-8
n=$<.map(&:to_i).select &:odd?;n[0]?p(n.reduce(:+),n.min):p(-1)

# nums = []
# 7.times do
#   nums << gets.to_i
# end
# nums.select!(&:odd?)
# p nums.reduce(:+)
# p nums.min
