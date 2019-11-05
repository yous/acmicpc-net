# encoding: utf-8
a=[];$<.map{|g|a+=g.split.map &:to_i};p m=a.max;i=a.index m;puts [i/9+1,i%9+1]*' '

# matrix = []
# 9.times do
#   matrix += gets.split.map(&:to_i)
# end
# max, index = matrix.each_with_index.max
# p max
# puts "#{index / 9 + 1} #{index % 9 + 1}"
