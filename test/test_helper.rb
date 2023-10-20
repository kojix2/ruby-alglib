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

  stdout.sub(/^\[\d+\]\s+/, '')
end

# install e1071 package if it's not installed
r('if (!requireNamespace("e1071")) install.packages("e1071")')
