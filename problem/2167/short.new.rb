# encoding: utf-8
g=->(){gets.split.map(&:to_i)};n=g[][0];m=Array.new(n);n.times{|i|m[i]=g[]};gets.to_i.times{s=0;i,j,x,y=g[];(i-1...x).each{|l|s+=m[l][j-1...y].reduce(:+)};p s}

# n, _m = gets.split.map(&:to_i)
# matrix = Array.new(n)
# n.times do |i|
#   matrix[i] = gets.split.map(&:to_i)
# end
# gets.to_i.times do
#   sum = 0
#   i, j, x, y = gets.split.map(&:to_i)
#   (i - 1..x - 1).each do |line|
#     sum += matrix[line][j - 1..y - 1].reduce(:+)
#   end
#   p sum
# end
