# encoding: utf-8
# frozen_string_literal: true

require "rspec/core/rake_task"
RSpec::Core::RakeTask.new(:spec)
task :default => :spec

require "tty-prompt"
desc "Initialize a new problem"
task :new do
  prompt = TTY::Prompt.new(help_color: :cyan)
  id = prompt.ask("Enter the ID of the problem:")

  dir = "problem/#{id}"
  mkdir_p dir

  cd dir do
    File.open("main.cpp", "w") do |f|
      f.write(<<~MAIN)
        #include <algorithm>
        #include <iostream>
        #include <vector>

        using namespace std;

        int main() {
            ios_base::sync_with_stdio(false);
            cin.tie(nullptr);
            return 0;
        }
      MAIN
    end

    count = prompt.ask("Enter the number of examples:",
                       default: 1, convert: :int)

    (1..count).each do |i|
      input = prompt.multiline("Enter the input (#{i}/#{count}):").join
      output = prompt.multiline("Enter the output (#{i}/#{count}):").join

      File.open("input#{i if i > 1}", "w") { |f| f.write(input) }
      File.open("output#{i if i > 1}", "w") { |f| f.write(output) }
    end
  end
end

require "pathname"
desc "Run a program"
task :run do
  if ARGV.size < 2
    puts "usage: rake run [PROBLEM]"
    exit 1
  end
  problem = Pathname.new(File.join(__dir__, "problem", ARGV[1]))
  relpath = problem.relative_path_from(__dir__)
  cd relpath do
    system("g++ main.cpp -O2 -Wall -lm -std=c++17") &&
      system("bash -c '{ ./a.out < input; } 2>&1'")
  end
  exit 0
end
