require 'test/unit'

$argv = ARGV.dup

class TestJudge < Test::Unit::TestCase
  def test_judge
    file_path = "problem/#{$argv[-1]}"
    assert_equal %x[ruby #{file_path}/main.rb < #{file_path}/input], File.read("#{file_path}/output")
    if File.exists? "#{file_path}/short.rb"
      assert_equal %x[ruby #{file_path}/short.rb < #{file_path}/input], File.read("#{file_path}/output")
    end
  end
end
