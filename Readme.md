Boost.Beast + OpenMP crash
==========================

Minimal program to demonstrate clang crashing when linking a [Boost.Beast](https://github.com/boostorg/beast) program
with OpenMP.

Tested with Boost 1.72.0 and Clang 9 on Ubuntu 18.04 LTS

## Build

1. `mkdir build`
2. `CXX=clang cmake .. -DBOOST_ROOT=<path to boost>`
3. `cmake --build .`

Clang crashes at this point trying to generate code for `boost::beast::http::detail::is_token_char`
