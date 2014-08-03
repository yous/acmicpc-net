# encoding: utf-8
require"prime";a=(gets.to_i..gets.to_i).select(&:prime?);p a.reduce:+;p a.min

# require "prime"
#
# m = gets.to_i
# n = gets.to_i
# primes = (m..n).select { |v| v.prime? }
# p primes.reduce(:+)
# p primes.min
