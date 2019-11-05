# encoding: utf-8
gets.to_i.times{a,b=gets.split.map &:to_i;p (1..a).reduce(1.to_r){|r,e|r*(e+b-a)/e}.to_i}

# gets.to_i.times do
#   west, east = gets.split.map(&:to_i)
#   p (1..west).reduce(1.to_r) { |a, e| a * (e + east - west) / west }.to_i
# end
