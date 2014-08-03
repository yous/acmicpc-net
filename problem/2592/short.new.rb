# encoding: utf-8
n=[];10.times{n<<gets.to_i};p n.reduce(:+)/n.size,n.map{|v|[n.count(v),v]}.max[1]

# nums = []
# 10.times do
#   nums << gets.to_i
# end
# p nums.reduce(:+) / nums.size,
#   nums.map { |v| [nums.count(v), v] }.max[1]
