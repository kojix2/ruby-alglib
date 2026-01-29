# frozen_string_literal: true

$LOAD_PATH.unshift File.expand_path('../lib', __dir__)
require 'alglib'
require 'open3'
require 'test-unit'
require 'tempfile'

DELTA = 1e-5

# Run code in Rscript via a temporary file for robust quoting
def r(*code)
  Tempfile.create(['rscript', '.R']) do |f|
    # Write all code lines to the temp file
    code.each { |line| f.puts(line) }
    f.flush

    stdout, stderr, status = Open3.capture3("Rscript #{f.path}")
    if ENV['DEBUG_R']
      puts "Rscript file: #{f.path}"
      puts "Rscript code:\n#{File.read(f.path)}"
      puts "Rscript stdout:\n#{stdout}"
      puts "Rscript stderr:\n#{stderr}"
    end
    raise "Rscript failed: #{stderr}" unless status.success?

    lines = stdout.split("\n")
    # Remove only empty lines
    lines.reject! { |l| l.strip.empty? }

    # If the output looks like a matrix, parse it
    if lines.size > 1 && lines[0] =~ /^\s*\[.*,.*\]/
      # Remove header line
      lines.shift
      matrix = lines.map do |line|
        # Remove row label ([1,], [2,], etc)
        line = line.sub(/^\s*\[\d+,\]\s*/, '')
        # Split by whitespace and convert to float
        line.strip.split(/\s+/).map(&:to_f)
      end
      matrix.map!(&:flatten)
      matrix
    else
      # Scalar/vector output: just parse as float if possible
      val = lines.last
      return nil if val.nil? || val.strip.empty?

      val = val.sub(/^\[\d+\]\s+/, '')
      begin
        Float(val)
      rescue ArgumentError
        val
      end
    end
  end
end

# install packages
# backquote is used to show the stderr
`Rscript -e 'if (!requireNamespace("e1071")) install.packages("e1071", repos = "https://cran.rstudio.com/")'`
`Rscript -e 'if (!requireNamespace("DescTools")) install.packages("DescTools", repos = "https://cran.rstudio.com/")'`
