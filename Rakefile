require 'bundler/gem_tasks'
require 'fileutils'
require 'net/http'
require 'openssl'
require 'rake/testtask'
require 'tempfile'
require 'uri'
require 'zip'

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

def fetch_alglib_archive(source_url)
  archive_path = alglib_cache_path(source_url)
  return archive_path if File.exist?(archive_path)

  uri = URI.parse(source_url)
  response = fetch_alglib_response(uri)

  FileUtils.mkdir_p File.dirname(archive_path)
  File.open(archive_path, 'wb') { |file| file.write(response.body) }
  archive_path
end

def alglib_cache_path(source_url)
  cache_dir = ENV.fetch('ALGLIB_CACHE_DIR', File.expand_path('.cache/alglib', __dir__))
  File.join(cache_dir, File.basename(source_url))
end

def fetch_alglib_response(uri)
  response = Net::HTTP.start(
    uri.host,
    uri.port,
    use_ssl: uri.scheme == 'https',
    verify_mode: OpenSSL::SSL::VERIFY_PEER
  ) { |http| http.get(uri.request_uri) }
  raise "Download failed: #{response.code} #{response.message}" unless response.is_a?(Net::HTTPSuccess)

  response
end

def extract_alglib_archive(archive_path, target_dir)
  Zip::File.open(archive_path) do |zip_file|
    zip_file.each do |entry|
      # Skip test files
      next if entry.name.start_with?('alglib-cpp/tests')

      extract_alglib_entry(entry, target_dir)
    end
  end
end

def extract_alglib_entry(entry, target_dir)
  extension = File.extname(entry.name)
  return unless %w[.cpp .h .txt].include?(extension)

  path_to_extract = File.join(target_dir, File.basename(entry.name))
  if extension == '.txt' # LICENCE gpl2.txt gpl3.txt
    entry.extract(File.basename(entry.name)) { true }
    return
  end

  FileUtils.mkdir_p File.dirname(path_to_extract)
  entry.extract(path_to_extract) { true }
end

desc 'Download and extract ALGLIB'
namespace :ext do
  task :alglib do
    source_url = 'https://www.alglib.net/translator/re/alglib-4.07.0.cpp.gpl.zip'
    target_dir = './ext/alglib'

    archive_path = fetch_alglib_archive(source_url)
    extract_alglib_archive(archive_path, target_dir)
  end
end
