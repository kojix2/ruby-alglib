require_relative 'test_helper'

class AlglibStaticsTest < Test::Unit::TestCase
  def test_that_it_has_a_version_number
    refute_nil ::Alglib::VERSION
  end
end
