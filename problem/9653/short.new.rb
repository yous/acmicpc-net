# encoding: utf-8
s=" ";r="";"608765;785878987888;6688887885;3898919878<28898589864;<88888776564<888888898788888<8969898788566;978791988848;888888589872".each_char{|t|c=t.ord-58;r<<(c>0?"\n":s*-c);s=c>1?"8":c>0?" ":s==" "?"8":" "};puts r

# result = ""
# ch = " "
# "3 9 1 2 3 4 ; " \
# "2 1 4 1 2 1 0 1 2 1 1 1 ; " \
# "3 3 1 1 1 1 2 1 1 4 ; " \
# "6 1 0 1 0 8 0 1 2 1 < " \
# "7 1 1 0 1 4 1 0 1 3 5 ; " \
# "< " \
# "1 1 1 1 1 2 2 3 4 3 5 < " \
# "1 1 1 1 1 1 1 0 1 2 1 1 1 1 1 < " \
# "1 0 3 0 1 0 1 2 1 1 4 3 3 ; " \
# "0 2 1 2 0 8 0 1 1 1 5 1 ; " \
# "1 1 1 1 1 1 4 1 0 1 2 7".split.each do |token|
#   case token
#   when ";"
#     result << "\n"
#     ch = " "
#   when "<"
#     result << "\n"
#     ch = "8"
#   when "0".."9"
#     result << ch * (token.to_i + 1)
#     ch = if ch == " "
#            "8"
#          else
#            " "
#          end
#   end
# end
# puts result
