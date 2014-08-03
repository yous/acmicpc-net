require "rake/testtask"

task :test, [:number] do |_t, args|
  ENV["PROBLEM"] ||= args[:number]
  ruby "test/test_judge.rb"
end
