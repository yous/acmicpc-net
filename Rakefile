# encoding: utf-8
# frozen_string_literal: true

require "rake/testtask"

Rake::TestTask.new do |t|
  t.libs << "test"
  t.test_files = FileList["test/test*.rb"]
  t.verbose = true
end
task :default => :test

desc "Initialize a new problem"
task :new do
  print "Enter the ID of the problem: "
  id = $stdin.gets.to_i

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

    print "Enter the number of examples: "
    count = $stdin.gets.to_i

    (1..count).each do |i|
      puts "Enter the input (#{i}/#{count}):"
      input = $stdin.read
      puts
      puts "Enter the output (#{i}/#{count}):"
      output = $stdin.read
      puts

      File.open("input#{i if count > 1}", "w") { |f| f.write(input) }
      File.open("output#{i if count > 1}", "w") { |f| f.write(output) }
    end
  end
end
