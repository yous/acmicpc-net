# encoding: utf-8
r=i=0;$<.map{|g|r+=(i%2..7).step(2).count{|v|g[v]==?F};i+=1};p r

# result = 0
# 8.times do |line_idx|
#   line = gets.chomp
#   result += (line_idx % 2...line.size).step(2).count { |i| line[i] == "F" }
# end
# p result
