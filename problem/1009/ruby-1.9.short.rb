# encoding: utf-8
gets;$<.map{|g|a,b=g.split.map{|v|v.to_i%20+20};p (a**b-1)%10+1}

# gets.to_i.times do
#   a, b = gets.split.map(&:to_i)
#   p ((a % 10) ** (b % 4 + 4) - 1) % 10 + 1
# end
