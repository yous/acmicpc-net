# encoding: utf-8
gets.to_i.times{s=gets.to_i;gets.to_i.times{s+=gets.split.map(&:to_i).reduce(:*)};puts s}

# gets.to_i.times do
#   result = gets.to_i
#   gets.to_i.times do
#     result += gets.split.map(&:to_i).reduce(:*)
#   end
#   puts result
# end
