# encoding: utf-8
gets.to_i.times{a=Hash.new(0);a[n=gets.to_i]=1;n.downto(2){|i|c=a[i];a[i-1]+=c;a[i-2]+=c};puts "#{a[0]} #{a[1]}"}

# gets.to_i.times do
#   fib = Hash.new(0)
#   n = gets.to_i
#   fib[n] = 1
#   n.downto(2) do |i|
#     fib[i - 1] += fib[i]
#     fib[i - 2] += fib[i]
#   end
#   puts "#{fib[0]} #{fib[1]}"
# end
