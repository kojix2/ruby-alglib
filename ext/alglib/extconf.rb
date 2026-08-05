# frozen_string_literal: true

require 'mkmf-rice'

# ALGLIB implementation sources live in the same directory as this extconf.rb,
# but rake-compiler copies only the wrapper files into the tmp build directory.
# Use $VPATH to tell mkmf where to find the ALGLIB sources, avoiding reliance
# on rake-compiler's tmp directory structure.
alglib_source_dir = File.expand_path(__dir__)

wrapper_files = %w[
  alglib.cpp
  alglib_alglibmisc.cpp
  alglib_converters.cpp
  alglib_dataanalysis.cpp
  alglib_specialfunctions.cpp
  alglib_statistics.cpp
  alglib_utils.cpp
]

alglib_sources = (Dir.glob(File.join(alglib_source_dir, '*.cpp')) - wrapper_files.map { |f| File.join(alglib_source_dir, f) })
                   .map { |f| File.basename(f) }

$VPATH << alglib_source_dir
$srcs = wrapper_files + alglib_sources

create_makefile('alglib/alglib')
