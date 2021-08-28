# frozen_string_literal: true

require "tmpdir"

TEST_RUBY = case RUBY_VERSION
            when "1.8.7"
              "ruby-1.8"
            when "1.9.3"
              "ruby-1.9"
            else
              "ruby-2.5"
            end
DELTAS = {
  "1007" => 1e-6,
  "1008" => 1e-9,
  "1546" => 1e-2,
  "3053" => 0.0001,
  "4386" => 1e-2,
  "20149" => 1e-9
}.freeze

RSpec.shared_examples "a problem" do |problem|
  inputs = Dir["problem/#{problem}/input*"].sort
  outputs = Dir["problem/#{problem}/output*"].sort
  if DELTAS.key?(problem)
    delta = DELTAS[problem]
    inputs.zip(outputs).each do |input, output|
      it "prints #{output} for #{input} within #{delta}" do
        result = `{ #{command} < #{input}; } 2>&1`
        File.readlines(output).zip(result.lines).each do |expected, actual|
          expect(actual.to_f).to be_within(delta).of(expected.to_f)
        end
      end
    end
  else
    inputs.zip(outputs).each do |input, output|
      it "prints #{output} for #{input}" do
        expect(`{ #{command} < #{input}; } 2>&1`).to eq(File.read(output))
      end
    end
  end
end

Dir["problem/*"].each do |problem|
  problem.sub!(%r{^problem/}, "")
  RSpec.describe problem do
    Dir["problem/#{problem}/#{TEST_RUBY}*.rb"].each do |file|
      filename = File.basename(file)
      context filename do
        include_examples "a problem", problem do
          let(:command) { "ruby #{file}" }
        end
      end
    end
    Dir["problem/#{problem}/main.cpp"].each do |file|
      filename = File.basename(file)
      basename = File.basename(filename, File.extname(filename))
      context filename do
        before(:context) do
          @dir = Dir.mktmpdir
          system "g++ #{file} -o #{@dir}/#{basename} -O2 -Wall -lm -std=c++17"
        end
        after(:context) do
          FileUtils.rm_r @dir
        end
        include_examples "a problem", problem do
          let(:command) { "#{@dir}/#{basename}" }
        end
      end
    end
  end
end
