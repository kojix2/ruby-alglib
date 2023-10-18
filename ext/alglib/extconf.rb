# frozen_string_literal: true

require 'mkmf-rice'
# require 'numo/narray'

vendor = File.expand_path('../../vendor', __dir__)
vendor_src = File.join(vendor, 'alglib-cpp/src')

# apple_clang = RbConfig::CONFIG['CC_VERSION_MESSAGE'] =~ /apple clang/i

# numo-narray
# numo = File.join(Gem.loaded_specs['numo-narray'].require_path, 'numo')
# abort 'Numo header not found' unless find_header('numo/narray.h', numo)
# abort 'Numo library not found' if Gem.win_platform? && !find_library('narray', nil, numo)
# find_header('numo.hpp', File.expand_path('../../include', __dir__))

dir_config 'alglib', vendor_src, vendor_src

$INCFLAGS << " -I#{vendor_src}"
$VPATH << vendor_src

$objs = Dir.glob(vendor_src + '/*.cpp').map { |f| f.sub(/\.cpp$/, ".o") }

create_makefile('alglib/alglib')
