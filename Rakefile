# encoding: utf-8
# frozen_string_literal: true

require "rspec/core/rake_task"
RSpec::Core::RakeTask.new(:spec)
task :default => :spec

require "mechanize"
require "tty-prompt"
desc "Initialize a new problem"
task :new do
  prompt = TTY::Prompt.new(help_color: :cyan)
  id = prompt.ask("Enter the ID of the problem:")

  dir = "problem/#{id}"
  mkdir_p dir

  cd dir do
    puts "touch main.cpp"
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

    if id.to_i >= 1000
      a = Mechanize.new
      page = a.get("https://www.acmicpc.net/problem/#{id}")

      i = 1
      loop do
        input = page.at("pre#sample-input-#{i}")
        output = page.at("pre#sample-output-#{i}")
        break unless input && output

        File.open("input#{i if i > 1}", "w") { |f| f.puts(input.text) }
        File.open("output#{i if i > 1}", "w") { |f| f.puts(output.text) }
        i += 1
      end
      if i > 1
        puts "touch input output ... input#{i} output#{i}"
      else
        puts "touch input output"
      end
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
    system("g++ main.cpp -O2 -Wall -lm -std=c++17") && system("./a.out")
  end
  exit 0
end
