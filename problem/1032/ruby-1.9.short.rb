# encoding: utf-8
f=[];gets.to_i.times{f<<gets.chomp.chars.to_a};puts f.transpose.map{|c|c.uniq[1]???:c[0]}.join

# files = []
# gets.to_i.times do
#   files << gets.chomp.chars.to_a
# end
# result = files.transpose.map do |chars|
#   if chars.uniq.size == 1
#     chars[0]
#   else
#     "?"
#   end
# end
# puts result.join
