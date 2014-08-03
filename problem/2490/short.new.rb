# encoding: utf-8
3.times{puts (69+gets.split.count("0")%-5).chr}

# 3.times do
#   status = gets.split.map(&:to_i)
#   case status.count(0)
#   when 0
#     puts "E"
#   when 1
#     puts "A"
#   when 2
#     puts "B"
#   when 3
#     puts "C"
#   when 4
#     puts "D"
#   end
# end
