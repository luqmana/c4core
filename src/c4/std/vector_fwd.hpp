#ifndef _C4_STD_VECTOR_FWD_HPP_
#define _C4_STD_VECTOR_FWD_HPP_

/** @file vector_fwd.hpp */

#include <cstddef>

// forward declarations for std::vector
#if defined(__GLIBCXX__) || defined(__GLIBCPP__) || defined(_MSC_VER)
namespace std {
template<typename> class allocator;
template<typename T, typename Alloc> class vector;
} // namespace std
#elif defined(_LIBCPP_VERSION) || defined(__APPLE_CC__)
#   if defined(__EMSCRIPTEN__)
namespace std {
template<typename> class allocator;
inline namespace __2 {
template<typename T, typename Alloc> class vector;
} // namespace __2
} // namespace std
#   else // !defined(__EMSCRIPTEN__)
#       if !defined(__APPLE_CC__)
namespace std {
template<typename> class allocator;
inline namespace __1 {
template<typename T, typename Alloc> class vector;
} // namespace __1
} // namespace std
#       else // defined(__APPLE_CC__)
#           if (__clang_major__ >= 13)
namespace std {
template<typename> class allocator;
inline namespace __1 {
template<typename T, typename Alloc> class vector;
} // namespace __1
} // namespace std
#           else // if __clang_major__ < 13
namespace std {
inline namespace __1 {
template<typename> class allocator;
template<typename T, typename Alloc> class vector;
} // namespace __1
} // namespace std
#           endif // __clang_major < 13
#       endif // defined(__APPLE_CC__)
#   endif // !defined(__EMSCRIPTEN__)
#else
#error "unknown standard library"
#endif

#ifndef C4CORE_SINGLE_HEADER
#include "c4/substr_fwd.hpp"
#endif

namespace c4 {

template<class Alloc> c4::substr to_substr(std::vector<char, Alloc> &vec);
template<class Alloc> c4::csubstr to_csubstr(std::vector<char, Alloc> const& vec);

template<class Alloc> bool operator!= (c4::csubstr ss, std::vector<char, Alloc> const& s);
template<class Alloc> bool operator== (c4::csubstr ss, std::vector<char, Alloc> const& s);
template<class Alloc> bool operator>= (c4::csubstr ss, std::vector<char, Alloc> const& s);
template<class Alloc> bool operator>  (c4::csubstr ss, std::vector<char, Alloc> const& s);
template<class Alloc> bool operator<= (c4::csubstr ss, std::vector<char, Alloc> const& s);
template<class Alloc> bool operator<  (c4::csubstr ss, std::vector<char, Alloc> const& s);

template<class Alloc> bool operator!= (std::vector<char, Alloc> const& s, c4::csubstr ss);
template<class Alloc> bool operator== (std::vector<char, Alloc> const& s, c4::csubstr ss);
template<class Alloc> bool operator>= (std::vector<char, Alloc> const& s, c4::csubstr ss);
template<class Alloc> bool operator>  (std::vector<char, Alloc> const& s, c4::csubstr ss);
template<class Alloc> bool operator<= (std::vector<char, Alloc> const& s, c4::csubstr ss);
template<class Alloc> bool operator<  (std::vector<char, Alloc> const& s, c4::csubstr ss);

template<class Alloc> size_t to_chars(c4::substr buf, std::vector<char, Alloc> const& s);
template<class Alloc> bool from_chars(c4::csubstr buf, std::vector<char, Alloc> * s);

} // namespace c4

#endif // _C4_STD_VECTOR_FWD_HPP_
