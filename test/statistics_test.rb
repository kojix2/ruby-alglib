require_relative 'test_helper'

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

  # --- 2D array/matrix statistical functions ---

  def test_covm
    mat = [[1, 2], [3, 4], [5, 6]]
    r_cov = r('cov(matrix(c(1,3,5,2,4,6), ncol=2))')
    alglib_cov = Alglib.covm(mat)
    assert_in_delta r_cov[0][0].to_f, alglib_cov[0][0], DELTA
    assert_in_delta r_cov[0][1].to_f, alglib_cov[0][1], DELTA
    assert_in_delta r_cov[1][0].to_f, alglib_cov[1][0], DELTA
    assert_in_delta r_cov[1][1].to_f, alglib_cov[1][1], DELTA

    # with_size version
    alglib_cov2 = Alglib.covm_with_size(mat, 3, 2)
    assert_in_delta r_cov[0][0].to_f, alglib_cov2[0][0], DELTA
    assert_in_delta r_cov[0][1].to_f, alglib_cov2[0][1], DELTA
    assert_in_delta r_cov[1][0].to_f, alglib_cov2[1][0], DELTA
    assert_in_delta r_cov[1][1].to_f, alglib_cov2[1][1], DELTA
  end

  def test_pearsoncorrm
    mat = [[1, 2], [3, 4], [5, 6]]
    r_cor = r('cor(matrix(c(1,3,5,2,4,6), ncol=2))')
    alglib_cor = Alglib.pearsoncorrm(mat)
    assert_in_delta r_cor[0][0].to_f, alglib_cor[0][0], DELTA
    assert_in_delta r_cor[0][1].to_f, alglib_cor[0][1], DELTA
    assert_in_delta r_cor[1][0].to_f, alglib_cor[1][0], DELTA
    assert_in_delta r_cor[1][1].to_f, alglib_cor[1][1], DELTA

    # with_size version
    alglib_cor2 = Alglib.pearsoncorrm_with_size(mat, 3, 2)
    assert_in_delta r_cor[0][0].to_f, alglib_cor2[0][0], DELTA
    assert_in_delta r_cor[0][1].to_f, alglib_cor2[0][1], DELTA
    assert_in_delta r_cor[1][0].to_f, alglib_cor2[1][0], DELTA
    assert_in_delta r_cor[1][1].to_f, alglib_cor2[1][1], DELTA
  end

  def test_spearmancorrm
    mat = [[1, 2], [3, 4], [5, 6]]
    r_cor = r('cor(matrix(c(1,3,5,2,4,6), ncol=2), method="spearman")')
    alglib_cor = Alglib.spearmancorrm(mat)
    assert_in_delta r_cor[0][0].to_f, alglib_cor[0][0], DELTA
    assert_in_delta r_cor[0][1].to_f, alglib_cor[0][1], DELTA
    assert_in_delta r_cor[1][0].to_f, alglib_cor[1][0], DELTA
    assert_in_delta r_cor[1][1].to_f, alglib_cor[1][1], DELTA

    # with_size version
    alglib_cor2 = Alglib.spearmancorrm_with_size(mat, 3, 2)
    assert_in_delta r_cor[0][0].to_f, alglib_cor2[0][0], DELTA
    assert_in_delta r_cor[0][1].to_f, alglib_cor2[0][1], DELTA
    assert_in_delta r_cor[1][0].to_f, alglib_cor2[1][0], DELTA
    assert_in_delta r_cor[1][1].to_f, alglib_cor2[1][1], DELTA
  end

  def test_covm2
    x = [[1, 2], [3, 4], [5, 6]]
    y = [[7, 8], [9, 10], [11, 12]]
    r_cov = r('cov(matrix(c(1,3,5,2,4,6), ncol=2), matrix(c(7,9,11,8,10,12), ncol=2))')
    alglib_cov = Alglib.covm2(x, y)
    2.times do |i|
      2.times do |j|
        assert_in_delta r_cov[i][j].to_f, alglib_cov[i][j], DELTA
      end
    end

    # with_size version
    alglib_cov2 = Alglib.covm2_with_size(x, y, 3, 2, 2)
    2.times do |i|
      2.times do |j|
        assert_in_delta r_cov[i][j].to_f, alglib_cov2[i][j], DELTA
      end
    end
  end

  def test_pearsoncorrm2
    x = [[1, 2], [3, 4], [5, 6]]
    y = [[7, 8], [9, 10], [11, 12]]
    r_cor = r('cor(matrix(c(1,3,5,2,4,6), ncol=2), matrix(c(7,9,11,8,10,12), ncol=2))')
    alglib_cor = Alglib.pearsoncorrm2(x, y)
    2.times do |i|
      2.times do |j|
        assert_in_delta r_cor[i][j].to_f, alglib_cor[i][j], DELTA
      end
    end

    # with_size version
    alglib_cor2 = Alglib.pearsoncorrm2_with_size(x, y, 3, 2, 2)
    2.times do |i|
      2.times do |j|
        assert_in_delta r_cor[i][j].to_f, alglib_cor2[i][j], DELTA
      end
    end
  end

  def test_spearmancorrm2
    x = [[1, 2], [3, 4], [5, 6]]
    y = [[7, 8], [9, 10], [11, 12]]
    r_cor = r('cor(matrix(c(1,3,5,2,4,6), ncol=2), matrix(c(7,9,11,8,10,12), ncol=2), method="spearman")')
    alglib_cor = Alglib.spearmancorrm2(x, y)
    2.times do |i|
      2.times do |j|
        assert_in_delta r_cor[i][j].to_f, alglib_cor[i][j], DELTA
      end
    end

    # with_size version
    alglib_cor2 = Alglib.spearmancorrm2_with_size(x, y, 3, 2, 2)
    2.times do |i|
      2.times do |j|
        assert_in_delta r_cor[i][j].to_f, alglib_cor2[i][j], DELTA
      end
    end
  end

  def test_rankdata
    mat = [[10, 20, 30], [30, 10, 20]]
    r_rank = r('t(apply(matrix(c(10,30,20,20,10,30), nrow=2, byrow=TRUE), 1, rank))')
    # Adjust R's 1-based rank to 0-based for ALGLIB
    r_rank = r_rank.map { |row| row.map { |v| v.to_f - 1 } }
    alglib_mat = Alglib.rankdata(mat)
    2.times do |i|
      assert_equal r_rank[i].sort, alglib_mat[i].sort
    end

    # with_size version
    alglib_mat2 = Alglib.rankdata_with_size(mat, 2, 3)
    2.times do |i|
      assert_equal r_rank[i].sort, alglib_mat2[i].sort
    end
  end

  def test_rankdatacentered
    mat = [[10, 20, 30], [30, 10, 20]]
    r_rank_raw = r('t(apply(matrix(c(10,30,20,20,10,30), nrow=2, byrow=TRUE), 1, rank))')
    # Adjust R's 1-based rank to 0-based, then center
    r_rank = r_rank_raw.map do |row|
      row = row.map { |v| v.to_f - 1 }
      mean = row.sum / row.size
      row.map { |v| v - mean }
    end
    alglib_mat = Alglib.rankdatacentered(mat)
    2.times do |i|
      assert_equal r_rank[i].sort, alglib_mat[i].sort
    end

    # with_size version
    alglib_mat2 = Alglib.rankdatacentered_with_size(mat, 2, 3)
    2.times do |i|
      assert_equal r_rank[i].sort, alglib_mat2[i].sort
    end
  end
end
