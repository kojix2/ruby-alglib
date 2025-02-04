#include <rice/rice.hpp>
#include <rice/stl.hpp>
#include "ap.h"

using namespace Rice;

extern "C"
{
  alglib::real_1d_array ruby_array_to_real_1d_array(Array ruby_array);
  alglib::integer_1d_array ruby_array_to_integer_1d_array(Array ruby_array);
  alglib::real_2d_array ruby_array_to_real_2d_array(Array ruby_array);
  Array real_1d_array_to_ruby_array(const alglib::real_1d_array &arr);
  Array real_2d_array_to_ruby_array(const alglib::real_2d_array &real_array);
  Array integer_1d_array_to_ruby_array(const alglib::integer_1d_array &arr);
}