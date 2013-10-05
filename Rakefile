require 'rake/testtask'

namespace :test do
	Rake::TestTask.new do |t|
		t.libs << "test"
		t.test_files = FileList["test/test_*.rb"]
		t.verbose = true
	end

	rule /^test:/ => lambda {|tn|
		$problem = tn.gsub(/^test:/, '')
		"test"
	} do |t|
		ruby "-I#{File.dirname(__FILE__)} test/test_judge.rb #{$problem}"
	end
end
