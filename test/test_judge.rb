# encoding: utf-8
# frozen_string_literal: true

require "test/unit"
require "tmpdir"

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
              when /^2\.\d+\.\d+$/
                "ruby-2.5"
              else
                "ruby-2.5"
              end
  DELTAS = {
    "1008" => 1e-9,
    "3053" => 0.0001
  }.freeze
  PROBLEMS.each do |problem|
    Dir["problem/#{problem}/#{TEST_RUBY}*.rb"].each do |file|
      filename = File.basename(file)
      define_method :"test_#{problem}_#{filename}" do
        inputs = Dir["problem/#{problem}/input*"].sort
        outputs = Dir["problem/#{problem}/output*"].sort
        if DELTAS.key?(problem)
          inputs.zip(outputs).each do |input, output|
            result = `ruby #{file} < #{input}`
            File.readlines(output).zip(result.lines).each do |expected, actual|
              assert_in_delta expected.to_f, actual.to_f, DELTAS[problem]
            end
          end
        else
          inputs.zip(outputs).each do |input, output|
            assert_equal `ruby #{file} < #{input}`, File.read(output)
          end
        end
      end
    end
    Dir["problem/#{problem}/main.cpp"].each do |file|
      filename = File.basename(file)
      define_method :"test_#{problem}_#{filename}" do
        inputs = Dir["problem/#{problem}/input*"].sort
        outputs = Dir["problem/#{problem}/output*"].sort
        Dir.mktmpdir do |dir|
          system "g++ #{file} -o #{dir}/#{filename} -O2 -Wall -lm -std=c++11"
          if DELTAS.key?(problem)
            inputs.zip(outputs).each do |input, output|
              result = `#{dir}/#{filename} < #{input}`
              File.readlines(output).zip(result.lines).each do |expected, actual|
                assert_in_delta expected.to_f, actual.to_f, DELTAS[problem]
              end
            end
          else
            inputs.zip(outputs).each do |input, output|
              assert_equal `#{dir}/#{filename} < #{input}`, File.read(output)
            end
          end
        end
      end
    end
  end
end
