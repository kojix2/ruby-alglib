require_relative 'test_helper'

class AlglibTest < Test::Unit::TestCase
  def test_that_it_has_a_version_number
    refute_nil ::Alglib::VERSION
  end

  def test_sample_mean
    assert_equal r('mean(c(1, 2))').to_f, Alglib.sample_mean([1, 2])
    assert_equal r('mean(c(1, 2, 3))').to_f, Alglib.sample_mean([1, 2, 3])
    assert_equal r('mean(c(1.1, 2.2, 3.3, 4.4))').to_f, Alglib.sample_mean([1.1, 2.2, 3.3, 4.4])
  end

  def test_sample_mean_vs_rlang
    arr = Array.new(10) { rand(100) }
    assert_equal r("mean(c(#{arr.join(',')}))").to_f, Alglib.sample_mean(arr)
  end

  def test_sample_variance
    assert_equal r('var(c(1, 2))').to_f, Alglib.sample_variance([1, 2])
    assert_equal r('var(c(1, 2, 3))').to_f, Alglib.sample_variance([1, 2, 3])
    assert_in_delta r('var(c(1.1, 2.2, 3.3, 4.4))').to_f, Alglib.sample_variance([1.1, 2.2, 3.3, 4.4]), 0.0001
  end

  def test_sample_variance_vs_rlang
    arr = Array.new(10) { rand(100) }
    assert_in_delta r("var(c(#{arr.join(',')}))").to_f, Alglib.sample_variance(arr), 0.001
  end
end
