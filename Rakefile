require 'rake/testtask'

task :test, [:number] do |t, args|
  ENV["PROBLEM"] ||= args[:number]
  ruby "test/test_judge.rb"
end
