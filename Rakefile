# encoding: utf-8
# frozen_string_literal: true

require "rake/testtask"
require "tty-prompt"

Rake::TestTask.new do |t|
  t.libs << "test"
  t.test_files = FileList["test/test*.rb"]
  t.verbose = true
end
task :default => :test

desc "Initialize a new problem"
task :new do
  prompt = TTY::Prompt.new
  id = prompt.ask("Enter the ID of the problem:", convert: :int)

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

    count = prompt.ask("Enter the number of examples:", convert: :int)

    (1..count).each do |i|
      input = prompt.multiline("Enter the input (#{i}/#{count}):").join
      output = prompt.multiline("Enter the output (#{i}/#{count}):").join

      File.open("input#{i if count > 1}", "w") { |f| f.write(input) }
      File.open("output#{i if count > 1}", "w") { |f| f.write(output) }
    end
  end
end
