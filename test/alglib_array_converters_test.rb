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
    rows = ruby_array.size
    cols = ruby_array.first.size
    alglib_array = Alglib.ruby_array_to_real_2d_array(ruby_array, rows, cols)
    assert_equal(ruby_array, Alglib.real_2d_array_to_ruby_array(alglib_array))
  end

  def test_empty_array
    ruby_array = []
    alglib_array = Alglib.ruby_array_to_real_1d_array(ruby_array)
    assert_equal(ruby_array, Alglib.real_1d_array_to_ruby_array(alglib_array))
  end

  def test_inconsistent_row_sizes
    ruby_array = [[1.0, 2.0], [3.0]]
    assert_raise(ArgumentError) do
      Alglib.ruby_array_to_real_2d_array(ruby_array)
    end
  end
end
