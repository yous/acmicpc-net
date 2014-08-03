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
        assert_equal `ruby #{file} < problem/#{problem}/input`,
                     File.read("problem/#{problem}/output")
      end
    end
  end
end
