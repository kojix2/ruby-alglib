# frozen_string_literal: true

$LOAD_PATH.unshift File.expand_path('../lib', __dir__)
require 'alglib'
require 'open3'
require 'test-unit'

# Run code in Rscript
def r(*code)
  cmd = "Rscript #{code.map { |c| "-e '#{c}'" }.join(' ')}"

  stdout, stderr, status = Open3.capture3(cmd)
  unless status.success?
    raise "Rscript failed: #{stderr}"
  end

  # Rscript returns the result in the last line
  # Remove the prefix "[1]" and the space
  stdout.split("\n").last.sub(/^\[\d+\]\s+/, '')
end

# install packages
# backquote is used to show the stderr
`Rscript -e 'if (!requireNamespace("e1071")) install.packages("e1071")'`
`Rscript -e 'if (!requireNamespace("DescTools")) install.packages("DescTools")'`
