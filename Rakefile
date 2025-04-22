require 'bundler/gem_tasks'
require 'rake/testtask'

Rake::TestTask.new(:test) do |t|
  t.libs << 'test'
  t.libs << 'lib'
  t.test_files = FileList['test/**/*_test.rb']
end

desc 'Clean up ext/alglib and restore original files'
namespace :ext do
  task :clean_alglib do
    sh 'rm -rf ext/alglib/* && git checkout ext/alglib'
  end
end

require 'rake/extensiontask'

task build: :compile

Rake::ExtensionTask.new('alglib') do |ext|
  ext.lib_dir = 'lib/alglib'
end

desc 'Download and extract ALGLIB'
namespace :ext do
  task :alglib do
    require 'open-uri'
    require 'zip'
    source_url = 'https://www.alglib.net/translator/re/alglib-4.04.0.cpp.gpl.zip'
    target_dir = './ext/alglib'

    # Download the file to a temporary location
    temp_file = Tempfile.new('alglib')
    URI.open(source_url) do |src|
      temp_file.write(src.read)
      temp_file.flush
    end

    # Extract downloaded file to target directory
    Zip::File.open(temp_file.path) do |zip_file|
      zip_file.each do |entry|
        # Skip test files
        next if entry.name.start_with?('alglib-cpp/tests')

        path_to_extract = File.join(target_dir, File.basename(entry.name))
        case File.extname(entry.name)
        when '.cpp', '.h'
          FileUtils.mkdir_p File.dirname(path_to_extract)
          entry.extract(path_to_extract) { true }
        when '.txt' # LICENCE gpl2.txt gpl3.txt
          entry.extract(File.basename(entry.name)) { true }
        end
      end
    end

    temp_file.close
    temp_file.unlink
  end
end
