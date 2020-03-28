# frozen_string_literal: true

require'prime';a=(gets.to_i..gets.to_i).select &:prime?;puts a[0]?[a.sum,a[0]]:-1

# require 'prime'
#
# m = gets.to_i
# n = gets.to_i
# primes = (m..n).select(&:prime?)
# if primes.empty?
#   puts -1
# else
#   puts primes.sum
#   puts primes.first
# endif
