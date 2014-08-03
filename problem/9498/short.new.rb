# encoding: utf-8
puts ((a=gets.to_i)<60?70:a>99?65:74-a/10).chr

# case gets.to_i
# when 90..100
#   puts "A"
# when 80..89
#   puts "B"
# when 70..79
#   puts "C"
# when 60..69
#   puts "D"
# else
#   puts "F"
# end
