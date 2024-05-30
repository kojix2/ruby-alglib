require_relative 'test_helper'

DELTA = 1e-5

class AlglibStatisticsTest < Test::Unit::TestCase
  def test_sample_mean
    assert_equal r('mean(c(1, 2))').to_f, Alglib.sample_mean([1, 2])
    assert_equal r('mean(c(1, 2, 3))').to_f, Alglib.sample_mean([1, 2, 3])
    assert_equal r('mean(c(1.1, 2.2, 3.3, 4.4))').to_f, Alglib.sample_mean([1.1, 2.2, 3.3, 4.4])
  end

  def test_sample_mean_random
    arr = Array.new(10) { rand(100) / 10.0 }
    assert_in_delta r("mean(c(#{arr.join(',')}))").to_f, Alglib.sample_mean(arr), DELTA
  end

  def test_sample_variance
    assert_equal r('var(c(1, 2))').to_f, Alglib.sample_variance([1, 2])
    assert_equal r('var(c(1, 2, 3))').to_f, Alglib.sample_variance([1, 2, 3])
    assert_in_delta r('var(c(1.1, 2.2, 3.3, 4.4))').to_f, Alglib.sample_variance([1.1, 2.2, 3.3, 4.4]), 0.0001
  end

  def test_sample_variance_random
    5.times do
      arr = Array.new(10) { rand(100) / 10.0 }
      assert_in_delta r("var(c(#{arr.join(',')}))").to_f, Alglib.sample_variance(arr), 0.0001
    end
  end

  def test_sample_skewness
    assert_in_delta r('library(e1071)', 'skewness(c(1, 2))').to_f, Alglib.sample_skewness([1, 2]), DELTA
    assert_in_delta r('library(e1071)', 'skewness(c(1, 2, 3))').to_f, Alglib.sample_skewness([1, 2, 3]), DELTA
    assert_in_delta r('library(e1071)', 'skewness(c(1.1, 2.2, 3.3, 4.4))').to_f,
                    Alglib.sample_skewness([1.1, 2.2, 3.3, 4.4]), DELTA
  end

  def test_sample_skewness_random
    5.times do
      arr = Array.new(10) { rand(100) / 10.0 }
      assert_in_delta r('library(e1071)', "skewness(c(#{arr.join(',')}))").to_f, Alglib.sample_skewness(arr), DELTA
    end
  end

  def test_sample_kurtosis
    assert_in_delta r('library(e1071)', 'kurtosis(c(1, 2))').to_f, Alglib.sample_kurtosis([1, 2]), DELTA
    assert_in_delta r('library(e1071)', 'kurtosis(c(1, 2, 3))').to_f, Alglib.sample_kurtosis([1, 2, 3]), DELTA
    assert_in_delta r('library(e1071)', 'kurtosis(c(1.1, 2.2, 3.3, 4.4))').to_f,
                    Alglib.sample_kurtosis([1.1, 2.2, 3.3, 4.4]), DELTA
  end

  def test_sample_kurtosis_random
    5.times do
      arr = Array.new(10) { rand(100) / 10.0 }
      assert_in_delta r('library(e1071)', "kurtosis(c(#{arr.join(',')}))").to_f, Alglib.sample_kurtosis(arr), DELTA
    end
  end

  def test_sample_adev
    assert_in_delta r('library("DescTools")', 'MeanAD(c(1, 2))').to_f, Alglib.sample_adev([1, 2]), DELTA
    assert_in_delta r('library("DescTools")', 'MeanAD(c(1, 2, 3))').to_f, Alglib.sample_adev([1, 2, 3]), DELTA
    assert_in_delta r('library("DescTools")', 'MeanAD(c(1.1, 2.2, 3.3, 4.4))').to_f,
                    Alglib.sample_adev([1.1, 2.2, 3.3, 4.4]), DELTA
  end

  def test_sample_adev_random
    5.times do
      arr = Array.new(10) { rand(100) / 10.0 }
      assert_in_delta r('library("DescTools")', "MeanAD(c(#{arr.join(',')}))").to_f, Alglib.sample_adev(arr), DELTA
    end
  end

  def test_sample_median
    assert_equal r('median(c(1, 2))').to_f, Alglib.sample_median([1, 2])
    assert_equal r('median(c(1, 2, 3))').to_f, Alglib.sample_median([1, 2, 3])
    assert_equal r('median(c(1.1, 2.2, 3.3, 4.4))').to_f, Alglib.sample_median([1.1, 2.2, 3.3, 4.4])
  end

  def test_sample_median_random
    5.times do
      arr = Array.new(10) { rand(100) / 10.0 }
      assert_in_delta r("median(c(#{arr.join(',')}))").to_f, Alglib.sample_median(arr), DELTA
    end
  end

  def test_sample_percentile
    assert_in_delta r('quantile(c(1, 2), c(0.25))').to_f, Alglib.sample_percentile([1, 2], 0.25), DELTA
    assert_in_delta r('quantile(c(1, 2, 3), c(0.25))').to_f, Alglib.sample_percentile([1, 2, 3], 0.25), DELTA
    assert_in_delta r('quantile(c(1.1, 2.2, 3.3, 4.4), c(0.25))').to_f,
                    Alglib.sample_percentile([1.1, 2.2, 3.3, 4.4], 0.25), DELTA
  end

  def test_sample_percentile_random
    5.times do
      arr = Array.new(10) { rand(100) / 10.0 }
      assert_in_delta r("quantile(c(#{arr.join(',')}), c(0.25))").to_f, Alglib.sample_percentile(arr, 0.25), DELTA
    end
  end

  def test_cov2
    assert_in_delta r('cov(c(1, 2), c(4, 3))').to_f, Alglib.cov2([1, 2], [4, 3]), DELTA
    assert_in_delta r('cov(c(1, 2, 3), c(3, 5, 4))').to_f, Alglib.cov2([1, 2, 3], [3, 5, 4]), DELTA
    assert_in_delta r('cov(c(1.1, 2.2, 3.3, 4.4), c(3.3, 4.4, 5.5, 6.6))').to_f,
                    Alglib.cov2([1.1, 2.2, 3.3, 4.4], [3.3, 4.4, 5.5, 6.6]), DELTA
  end

  def test_cov2_random
    5.times do
      arr1 = Array.new(10) { rand(100) / 10.0 }
      arr2 = Array.new(10) { rand(100) / 10.0 }
      assert_in_delta r("cov(c(#{arr1.join(',')}), c(#{arr2.join(',')}))").to_f, Alglib.cov2(arr1, arr2), DELTA
    end
  end

  def test_pearson_corr2
    assert_in_delta r('cor(c(1, 2), c(4, 3))').to_f, Alglib.pearson_corr2([1, 2], [4, 3]), DELTA
    assert_in_delta r('cor(c(1, 2, 3), c(3, 5, 4))').to_f, Alglib.pearson_corr2([1, 2, 3], [3, 5, 4]), DELTA
    assert_in_delta r('cor(c(1.1, 2.2, 3.3, 4.4), c(3.3, 4.4, 5.5, 6.6))').to_f,
                    Alglib.pearson_corr2([1.1, 2.2, 3.3, 4.4], [3.3, 4.4, 5.5, 6.6]), DELTA
  end

  def test_pearson_corr2_random
    5.times do
      arr1 = Array.new(10) { rand(100) / 10.0 }
      arr2 = Array.new(10) { rand(100) / 10.0 }
      assert_in_delta r("cor(c(#{arr1.join(',')}), c(#{arr2.join(',')}))").to_f, Alglib.pearson_corr2(arr1, arr2), DELTA
    end
  end

  def test_spearman_corr2
    assert_in_delta r('cor(c(1, 2), c(4, 3), method = "spearman")').to_f, Alglib.spearman_corr2([1, 2], [4, 3]), DELTA
    assert_in_delta r('cor(c(1, 2, 3), c(3, 5, 4), method = "spearman")').to_f,
                    Alglib.spearman_corr2([1, 2, 3], [3, 5, 4]), DELTA
    assert_in_delta r('cor(c(1.1, 2.2, 3.3, 4.4), c(3.3, 4.4, 5.5, 6.6), method = "spearman")').to_f,
                    Alglib.spearman_corr2([1.1, 2.2, 3.3, 4.4], [3.3, 4.4, 5.5, 6.6]), DELTA
  end

  def test_spearman_corr2_random
    5.times do
      arr1 = Array.new(10) { rand(100) / 10.0 }
      arr2 = Array.new(10) { rand(100) / 10.0 }
      assert_in_delta r("cor(c(#{arr1.join(',')}), c(#{arr2.join(',')}), method = \"spearman\")").to_f,
                      Alglib.spearman_corr2(arr1, arr2), DELTA
    end
  end
end
