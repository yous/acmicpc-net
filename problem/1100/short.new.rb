r=i=0;8.times{r+=(i..(l=gets).length-2).step(2).count{|v|l[v]=="F"};i=i==0?1:0};p r

# result = 0
# offset = 0
# 8.times do
#   line = gets.chomp
#   result += (offset...line.length).step(2).count { |i| line[i] == "F" }
#   offset = offset.zero? ? 1 : 0
# end
# p result
