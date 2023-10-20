require_relative 'test_helper'

class AlglibTest < Test::Unit::TestCase
  def test_that_it_has_a_version_number
    refute_nil ::Alglib::VERSION
  end

  def test_sample_mean
    assert_equal 1.5, Alglib.sample_mean([1, 2])
    assert_equal 2.0, Alglib.sample_mean([1, 2, 3])
    assert_equal 2.75, Alglib.sample_mean([1.1, 2.2, 3.3, 4.4])
  end

  def test_sample_variance
    assert_equal 0.5, Alglib.sample_variance([1, 2])
    assert_equal 1.0, Alglib.sample_variance([1, 2, 3])
    assert_in_delta 2.016666666666667, Alglib.sample_variance([1.1, 2.2, 3.3, 4.4]), 0.0001
  end
end
