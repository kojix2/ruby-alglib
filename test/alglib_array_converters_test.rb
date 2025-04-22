# frozen_string_literal: true

require 'test/unit'
require_relative 'test_helper'

class AlglibArrayConvertersTest < Test::Unit::TestCase
  def test_ruby_array_to_real_1d_array
    ruby_array = [1.0, 2.0, 3.0]
    alglib_array = Alglib.ruby_array_to_real_1d_array(ruby_array)
    assert_equal(ruby_array, Alglib.real_1d_array_to_ruby_array(alglib_array))
  end

  def test_ruby_array_to_integer_1d_array
    ruby_array = [1, 2, 3]
    alglib_array = Alglib.ruby_array_to_integer_1d_array(ruby_array)
    assert_equal(ruby_array, Alglib.integer_1d_array_to_ruby_array(alglib_array))
  end

  def test_ruby_array_to_real_2d_array
    ruby_array = [[1.0, 2.0], [3.0, 4.0]]
    alglib_array = Alglib.ruby_array_to_real_2d_array(ruby_array)
    assert_equal(ruby_array, Alglib.real_2d_array_to_ruby_array(alglib_array))
  end

  def test_empty_array
    ruby_array = []
    alglib_array = Alglib.ruby_array_to_real_1d_array(ruby_array)
    assert_equal(ruby_array, Alglib.real_1d_array_to_ruby_array(alglib_array))
  end

  def test_ruby_array_to_integer_2d_array
    ruby_array = [[1, 2], [3, 4]]
    alglib_array = Alglib.ruby_array_to_integer_2d_array(ruby_array)
    assert_equal(ruby_array, Alglib.integer_2d_array_to_ruby_array(alglib_array))
  end

  def test_empty_integer_2d_array
    ruby_array = []
    alglib_array = Alglib.ruby_array_to_integer_2d_array(ruby_array)
    assert_equal(ruby_array, Alglib.integer_2d_array_to_ruby_array(alglib_array))
  end

  def test_single_element_integer_2d_array
    ruby_array = [[42]]
    alglib_array = Alglib.ruby_array_to_integer_2d_array(ruby_array)
    assert_equal(ruby_array, Alglib.integer_2d_array_to_ruby_array(alglib_array))
  end

  def test_inconsistent_row_sizes
    ruby_array = [[1.0, 2.0], [3.0]]
    assert_raise(ArgumentError) do
      Alglib.ruby_array_to_real_2d_array(ruby_array)
    end
  end

  def test_large_array
    ruby_array = Array.new(1000) { |i| i.to_f }
    alglib_array = Alglib.ruby_array_to_real_1d_array(ruby_array)
    assert_equal(ruby_array, Alglib.real_1d_array_to_ruby_array(alglib_array))
  end

  def test_array_with_negative_numbers
    ruby_array = [-1.0, -2.0, 0.0, 3.0]
    alglib_array = Alglib.ruby_array_to_real_1d_array(ruby_array)
    assert_equal(ruby_array, Alglib.real_1d_array_to_ruby_array(alglib_array))
  end

  def test_array_with_non_numeric_values
    ruby_array = [1.0, 'a', 3.0]
    assert_raise(ArgumentError) do
      Alglib.ruby_array_to_real_1d_array(ruby_array)
    end
  end

  def test_single_element_array
    ruby_array = [42.0]
    alglib_array = Alglib.ruby_array_to_real_1d_array(ruby_array)
    assert_equal(ruby_array, Alglib.real_1d_array_to_ruby_array(alglib_array))
  end
end
