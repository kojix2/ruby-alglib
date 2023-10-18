require 'bundler/gem_tasks'
require 'rake/testtask'

Rake::TestTask.new(:test) do |t|
  t.libs << 'test'
  t.libs << 'lib'
  t.test_files = FileList['test/**/*_test.rb']
end

require 'rake/extensiontask'

task build: :compile

Rake::ExtensionTask.new('alglib') do |ext|
  ext.lib_dir = 'lib/alglib'
end

desc 'Download and extract ALGLIB'
namespace :vendor do
  task :alglib do
    require 'open-uri'
    require 'zip'
    source_url = 'https://www.alglib.net/translator/re/alglib-4.00.0.cpp.gpl.zip'
    target_dir = './vendor'

    # Download the file to a temporary location
    temp_file = Tempfile.new('alglib')
    URI.open(source_url) do |src|
      temp_file.write(src.read)
      temp_file.flush
    end

    # Extract downloaded file to target directory
    Zip::File.open(temp_file.path) do |zip_file|
      zip_file.each do |entry|
        path_to_extract = File.join(target_dir, entry.name)
        if entry.directory?
          FileUtils.mkdir_p path_to_extract
        else
          FileUtils.mkdir_p File.dirname(path_to_extract)
          entry.extract(path_to_extract) unless File.exist?(path_to_extract)
        end
      end
    end

    temp_file.close
    temp_file.unlink
  end
end
