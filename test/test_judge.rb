require 'test/unit'

class TestJudge < Test::Unit::TestCase
  def test_judge
    problems = if ENV["PROBLEM"]
                 ENV["PROBLEM"].split(",")
               else
                 Dir["problem/*"].map { |v| v.sub(/^problem\//, "") }
               end
    old_ruby = RUBY_VERSION == "1.8.7"
    main_file = old_ruby ? "main.old.rb" : "main.rb"
    short_file = old_ruby ? "short.old.rb" : "short.rb"
    problems.each do |problem|
      file_path = "problem/#{problem}"
      if File.exists? "#{file_path}/#{main_file}"
        assert_equal %x[ruby #{file_path}/#{main_file} < #{file_path}/input], File.read("#{file_path}/output")
      end
      if File.exists? "#{file_path}/#{short_file}"
        assert_equal %x[ruby #{file_path}/#{short_file} < #{file_path}/input], File.read("#{file_path}/output")
      end
    end
  end
end
