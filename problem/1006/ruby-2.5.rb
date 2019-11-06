# frozen_string_literal: true

def get_min_to_cover(n, w, area1, area2)
  fill_lower = []
  fill_upper = []
  fill_both = []
  n.times do |i|
    vert = area1[i] + area2[i] <= w ? 1 : 2
    if i.zero?
      fill_lower << 1
      fill_upper << 1
      fill_both << vert
      next
    end
    hori1 = area1[i - 1] + area1[i] <= w ? 1 : 2
    hori2 = area2[i - 1] + area2[i] <= w ? 1 : 2
    fill_lower << [fill_both[i - 1] + 1, fill_upper[i - 1] + hori1].min
    fill_upper << [fill_both[i - 1] + 1, fill_lower[i - 1] + hori2].min
    fill_both << if i > 1
                   [fill_both[i - 1] + vert,
                    fill_both[i - 2] + hori1 + hori2,
                    fill_lower[i] + 1,
                    fill_upper[i] + 1].min
                 else
                   [fill_both[i - 1] + vert,
                    hori1 + hori2,
                    fill_lower[i] + 1,
                    fill_upper[i] + 1].min
                 end
  end
  fill_both[n - 1]
end

gets.to_i.times do
  n, w = gets.split.map(&:to_i)
  area1 = [w] + gets.split.map(&:to_i)
  area2 = [w] + gets.split.map(&:to_i)
  results = []
  results << get_min_to_cover(n + 1, w, area1, area2)

  area1[0] = area1[n]
  area1[n] = w
  results << get_min_to_cover(n + 1, w, area1, area2)

  area1[n] = area1[0]
  area1[0] = w
  area2[0] = area2[n]
  area2[n] = w
  results << get_min_to_cover(n + 1, w, area1, area2)

  area1[0] = area1[n]
  area1[n] = w
  results << get_min_to_cover(n + 1, w, area1, area2)
  puts results.min - 2
end
