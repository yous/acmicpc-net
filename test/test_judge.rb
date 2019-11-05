# encoding: utf-8
# frozen_string_literal: true

require "test/unit"

class TestJudge < Test::Unit::TestCase
  PROBLEMS = if ENV["PROBLEM"]
               [ENV["PROBLEM"]]
             else
               Dir["problem/*"].map { |v| v.sub(%r{^problem/}, "") }
             end
  TEST_RUBY = case RUBY_VERSION
              when "1.8.7"
                "ruby-1.8"
              when "1.9.3"
                "ruby-1.9"
              when /^2\.(?:5|6)\.\d+$/
                "ruby-2.5"
              end
  PROBLEMS.each do |problem|
    Dir["problem/#{problem}/#{TEST_RUBY}*.rb"].each do |file|
      filename = File.basename(file)
      define_method :"test_#{problem}_#{filename}" do
        inputs = Dir["problem/#{problem}/input*"].sort
        outputs = Dir["problem/#{problem}/output*"].sort
        inputs.zip(outputs).each do |input, output|
          assert_equal `ruby #{file} < #{input}`, File.read(output)
        end
      end
    end
  end
end
