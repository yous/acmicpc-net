# encoding: utf-8
n=[];7.times{n<<gets.to_i};n.select!(&:odd?);p n.reduce:+;p n.min

# nums = []
# 7.times do
#   nums << gets.to_i
# end
# nums.select!(&:odd?)
# p nums.reduce(:+)
# p nums.min
