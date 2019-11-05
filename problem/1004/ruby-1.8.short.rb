# encoding: utf-8
g=proc{gets.split.map &:to_i};g[][0].times{p,q,r,s=g[];puts((1..g[][0]).map{x,y,n=g[];(Math.hypot(p-x,q-y)-n)*(n-Math.hypot(r-x,s-y))>0}.count true)}

# gets.to_i.times do
#   p, q, r, s = gets.split.map(&:to_i)
#   puts(
#     (1..gets.to_i).map do
#       x, y, n = gets.split.map(&:to_i)
#       (Math.hypot(p - x, q - y) - n) * (n - Math.hypot(r - x, s - y)) > 0
#     end.count(true)
#   )
# end
