# encoding: utf-8
r=0;8.times{|i|r+=(i%2..(l=gets).size-2).step(2).count{|v|l[v]=="F"}};p r

# result = 0
# 8.times do |line_idx|
#   line = gets.chomp
#   result += (line_idx % 2...line.size).step(2).count { |i| line[i] == "F" }
# end
# p result
