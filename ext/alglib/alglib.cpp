// https://github.com/kojix2/ruby-alglib

#include <rice/rice.hpp>
#include <rice/stl.hpp>
#include "numo.hpp"
#include "statistics.h"

using namespace Rice;


extern "C" void Init_alglib()
{
  Module rb_mAlglib =
      define_module("Alglib");
}