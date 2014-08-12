# encoding: utf-8
$<.map{|g|m,n=g.split.map &:to_i;m|n==0&&exit;puts m>n ?"Yes":"No"}

# m, n = gets.split.map(&:to_i)
# until m == 0 && n == 0
#   if m > n
#     puts "Yes"
#   else
#     puts "No"
#   end
#   m, n = gets.split.map(&:to_i)
# end
