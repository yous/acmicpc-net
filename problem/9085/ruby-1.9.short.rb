# encoding: utf-8
gets.to_i.times{gets;p gets.split.map(&:to_i).reduce:+}

# gets.to_i.times do
#   gets
#   p gets.split.map(&:to_i).reduce(:+)
# end
