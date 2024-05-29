#include <rice/rice.hpp>
#include <rice/stl.hpp>
#include "ap.h"

using namespace Rice;

alglib::real_1d_array ruby_array_to_real_1d_array(Array ruby_array);

// Experimental implementations - do not expect this to work!

alglib::integer_1d_array ruby_array_to_integer_1d_array(Array ruby_array);
alglib::real_2d_array ruby_array_to_real_2d_array(Array ruby_array, int &rows, int &cols);
Array real_2d_array_to_ruby_array(alglib::real_2d_array real_array);
