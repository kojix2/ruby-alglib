require_relative 'test_helper'

DELTA = 1e-5

class AlglibDataAnalysisTest < Test::Unit::TestCase
  def test_sample_mean
    s2 = r(<<~R)
      x <- matrix(1:15, nrow = 5, byrow = TRUE)
      pca <- prcomp(x, center = TRUE, scale. = FALSE)
      s2_r <- pca$sdev^2
      s2_r
    R
    expected_s2 = s2.split.map(&:to_f)

    v_sort5 = r(<<~R)
      x <- matrix(1:15, nrow = 5, byrow = TRUE)
      pca <- prcomp(x, center = TRUE, scale. = FALSE)
      v_r <- pca$rotation
      sort(abs(as.vector(v_r)), decreasing = TRUE)[1:6]
    R
    expected_v_sort5 = v_sort5.split.map(&:to_f)

    result = Alglib.pca_build_basis(
      [[1.0, 2.0, 3.0],
       [4.0, 5.0, 6.0],
       [7.0, 8.0, 9.0],
       [10.0, 11.0, 12.0],
       [13.0, 14.0, 15.0]]
    )
    assert_in_delta expected_s2[0], result['s2'][0], DELTA
    assert_in_delta expected_s2[1], result['s2'][1], DELTA
    assert_in_delta expected_s2[2], result['s2'][2], DELTA

    p expected_v_sort5
    p actual_v_sort5 = result['v'].flatten.map(&:abs).sort.reverse[0..5]
    assert_in_delta expected_v_sort5[0], actual_v_sort5[0], DELTA
    assert_in_delta expected_v_sort5[1], actual_v_sort5[1], DELTA
    assert_in_delta expected_v_sort5[2], actual_v_sort5[2], DELTA
    assert_in_delta expected_v_sort5[3], actual_v_sort5[3], DELTA
    assert_in_delta expected_v_sort5[4], actual_v_sort5[4], DELTA
    assert_in_delta expected_v_sort5[5], actual_v_sort5[5], DELTA
  end
end