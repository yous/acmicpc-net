# encoding: utf-8
m=n=gets.to_i;c=0;begin m=m%10*10+(m/10+m)%10;c+=1 end until m==n;p c

# new = num = gets.to_i
# count = 0
# loop do
#   new = new % 10 * 10 + (new / 10 + new % 10) % 10
#   count += 1
#   break if new == num
# end
# p count
