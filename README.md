# ruby-alglib

statistics.h of [ALGLIB](https://www.alglib.net/) for Ruby.

## Installation

```
git clone https://github.com/kojix2/ruby-alglib
cd ruby-alglib
bundle install
rake ext:alglib # Download ALGLIB from https://www.alglib.net/ and extract to ext/alglib.
rake compile
rake install
```

## License

The code for ruby-arglib itself is distributed under the MIT license.
Please note that ALGLIB is under the **GPL** license.

- [ALGLIB Free Edition](https://www.alglib.net/) GPL or Personal/Academic license

ALGLIB is also available in a commercial version, but this project has not tested working with the commercial version.
