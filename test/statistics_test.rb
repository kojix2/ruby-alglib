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

  def test_sample_mean_random
    arr = Array.new(10) { rand(100) / 10.0 }
    assert_in_delta r("mean(c(#{arr.join(',')}))").to_f, Alglib.sample_mean(arr), 0.001
  end

  def test_sample_variance
    assert_equal r('var(c(1, 2))').to_f, Alglib.sample_variance([1, 2])
    assert_equal r('var(c(1, 2, 3))').to_f, Alglib.sample_variance([1, 2, 3])
    assert_in_delta r('var(c(1.1, 2.2, 3.3, 4.4))').to_f, Alglib.sample_variance([1.1, 2.2, 3.3, 4.4]), 0.001
  end

  def test_sample_variance_random
    5.times do
      arr = Array.new(10) { rand(100) / 10.0 }
      assert_in_delta r("var(c(#{arr.join(',')}))").to_f, Alglib.sample_variance(arr), 0.001
    end
  end

  def test_sample_skewness
    assert_in_delta r('library(e1071)', 'skewness(c(1, 2))').to_f, Alglib.sample_skewness([1, 2]), 0.001
    assert_in_delta r('library(e1071)', 'skewness(c(1, 2, 3))').to_f, Alglib.sample_skewness([1, 2, 3]), 0.001
    assert_in_delta r('library(e1071)', 'skewness(c(1.1, 2.2, 3.3, 4.4))').to_f, Alglib.sample_skewness([1.1, 2.2, 3.3, 4.4]), 0.001
  end

  def test_sample_skewness_random
    5.times do
      arr = Array.new(10) { rand(100) / 10.0 }
      assert_in_delta r('library(e1071)', "skewness(c(#{arr.join(',')}))").to_f, Alglib.sample_skewness(arr), 0.001
    end
  end

  def test_sample_kurtosis
    assert_in_delta r('library(e1071)', 'kurtosis(c(1, 2))').to_f, Alglib.sample_kurtosis([1, 2]), 0.001
    assert_in_delta r('library(e1071)', 'kurtosis(c(1, 2, 3))').to_f, Alglib.sample_kurtosis([1, 2, 3]), 0.001
    assert_in_delta r('library(e1071)', 'kurtosis(c(1.1, 2.2, 3.3, 4.4))').to_f, Alglib.sample_kurtosis([1.1, 2.2, 3.3, 4.4]), 0.001
  end

  def test_sample_kurtosis_random
    5.times do
      arr = Array.new(10) { rand(100) / 10.0 }
      assert_in_delta r('library(e1071)', "kurtosis(c(#{arr.join(',')}))").to_f, Alglib.sample_kurtosis(arr), 0.001
    end
  end
end
