# encoding: utf-8
g=->(){gets.split.map(&:to_i)};m,n=g[];until m==0&&n==0;puts m>n ?"Yes":"No";m,n=g[]end

# m, n = gets.split.map(&:to_i)
# until m == 0 && n == 0
#   if m > n
#     puts "Yes"
#   else
#     puts "No"
#   end
#   m, n = gets.split.map(&:to_i)
# end
