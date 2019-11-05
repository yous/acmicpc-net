# encoding: utf-8
n=1;$<.map{|x|n*=x.to_i};10.times{|i|p n.to_s.chars.count i.to_s}

# nums = []
# 3.times do
#   nums << gets.to_i
# end
# num_chars = nums.reduce(:*).to_s.chars
# 10.times do |num|
#   p num_chars.count(num.to_s)
# end
