require 'test/unit'

class TestJudge < Test::Unit::TestCase
  def test_judge
    problems = if ENV["PROBLEM"]
                 ENV["PROBLEM"].split(",")
               else
                 Dir["problem/*"].map { |v| v.sub(/^problem\//, "") }
               end
    problems.each do |problem|
      file_path = "problem/#{problem}"
      assert_equal %x[ruby #{file_path}/main.rb < #{file_path}/input], File.read("#{file_path}/output")
      if File.exist? "#{file_path}/short.rb"
        assert_equal %x[ruby #{file_path}/short.rb < #{file_path}/input], File.read("#{file_path}/output")
      end
    end
  end
end
