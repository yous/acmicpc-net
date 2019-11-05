# frozen_string_literal: true

def get_time(w, rels, times, results)
  return results[w] if results.has_key?(w)
  if rels[w].empty?
    results[w] = times[w - 1]
    return results[w]
  end
  results[w] = times[w - 1] + rels[w].map { |b| get_time(b, rels, times, results) }.max
  results[w]
end

gets.to_i.times do
  n, k = gets.split.map(&:to_i)
  times = gets.split.map(&:to_i)
  rels = Hash.new { |hash, key| hash[key] = [] }
  k.times do
    before, after = gets.split.map(&:to_i)
    rels[after] << before
  end
  w = gets.to_i
  results = {}
  puts get_time(w, rels, times, results)
end
