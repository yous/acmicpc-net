require 'test/unit'

class TestJudge < Test::Unit::TestCase
  def test_judge
    file_path = "problem/#{ENV["PROBLEM"]}"
    assert_equal %x[ruby #{file_path}/main.rb < #{file_path}/input], File.read("#{file_path}/output")
    if File.exists? "#{file_path}/short.rb"
      assert_equal %x[ruby #{file_path}/short.rb < #{file_path}/input], File.read("#{file_path}/output")
    end
  end
end
