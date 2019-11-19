# frozen_string_literal: true

P=%w[..#.. .#.#. #.X.# .#.#. ..#..];W=P.map{|l|l.tr ?#,?*};w=gets.strip;s=w.size;5.times{|i|l=P[i][0..3]*s+P[i][4];(2..s-1).step(3){|j|l[j*4..j*4+4]=W[i]};j=-1;puts l.gsub(?X){j+=1;w[j]}}

# PETERPAN = %w[..#.. .#.#. #.X.# .#.#. ..#..].freeze
# WENDY = %w[..*.. .*.*. *.X.* .*.*. ..*..].freeze
#
# word = gets.strip
# size = word.size
# 5.times do |i|
#   line = PETERPAN[i][0..3] * size + PETERPAN[i][4]
#   (2..size - 1).step(3) do |j|
#     line[j * 4..j * 4 + 4] = WENDY[i]
#   end
#   if i == 2
#     j = 0
#     line.gsub!("X") do
#       j += 1
#       word[j - 1]
#     end
#   end
#   puts line
# end
