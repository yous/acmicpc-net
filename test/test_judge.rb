# encoding: utf-8
require "test/unit"

class TestJudge < Test::Unit::TestCase
  def test_judge
    problems = if ENV["PROBLEM"]
                 ENV["PROBLEM"].split(",")
               else
                 Dir["problem/*"].map { |v| v.sub(/^problem\//, "") }
               end
    old_ruby = RUBY_VERSION == "1.8.7"
    problems.each do |problem|
      Dir["problem/#{problem}/*.#{old_ruby ? "old" : "new"}.rb"].each do |file|
        inputs = Dir["problem/#{problem}/input*"].sort
        outputs = Dir["problem/#{problem}/output*"].sort
        inputs.zip(outputs).each do |input, output|
          assert_equal `ruby #{file} < #{input}`, File.read(output)
        end
      end
    end
  end
end
