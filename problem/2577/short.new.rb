# encoding: utf-8
n=1;3.times{n*=gets.to_i};r=Hash.new(0);n.to_s.each_char{|c|r[c.to_i]+=1};10.times{|i|p r[i]}

# nums = []
# 3.times do
#   nums << gets.to_i
# end
# result = Hash.new(0)
# nums.reduce(:*).to_s.each_char do |ch|
#   result[ch.to_i] += 1
# end
# 10.times do |num|
#   p result[num]
# end
