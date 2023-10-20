# frozen_string_literal: true

$LOAD_PATH.unshift File.expand_path('../lib', __dir__)
require 'alglib'

require 'test-unit'

# Run code in Rscript
def r(code)
  result = `Rscript -e '#{code}'`.strip
  # Remove line number from the begining of line (e.g. "[1] 1.5")
  result.sub(/^\[\d+\]\s+/, '')
end