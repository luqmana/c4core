# c4core - C++ core utilities

[![MIT Licensed](https://img.shields.io/badge/License-MIT-green.svg)](https://github.com/biojppm/c4core/blob/master/LICENSE.txt)
[![Build Status](https://travis-ci.org/biojppm/c4core.svg?branch=master)](https://travis-ci.org/biojppm/c4core)
[![Build status](https://ci.appveyor.com/api/projects/status/github/biojppm/c4core?branch=master&svg=true)](https://ci.appveyor.com/project/biojppm/c4core)
[![Coverage: coveralls](https://coveralls.io/repos/github/biojppm/c4core/badge.svg)](https://coveralls.io/github/biojppm/c4core)
[![Coverage: codecov](https://codecov.io/gh/biojppm/c4core/branch/master/graph/badge.svg)](https://codecov.io/gh/biojppm/c4core)
[![LGTM alerts](https://img.shields.io/lgtm/alerts/g/biojppm/c4core.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/biojppm/c4core/alerts/)
[![LGTM grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/biojppm/c4core.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/biojppm/c4core/context:cpp)


c4core is a library of low-level C++ utilities, written with low-latency
projects in mind.

Some of the utilities provided by c4core have already equivalent
functionality in the C++ standard, but they are provided as the existing C++
equivalent may be inefficient (eg, std::string), heavy (eg streams), or
plainly unusable on some platforms, eg exceptions); some other utilities have
equivalents under consideration for C++ standardisation; and yet some other
utilities have (to my knowledge) no equivalent under consideration. Be that
as it may, I've been using these utilities in this or similar forms for some
years now, and I've found them incredibly useful in my projects. I'm packing
these as a separate library, as all of my projects use it.


## Obtaining c4core

c4core uses git submodules. It is best to clone c4core with the `--recursive`
option:

```bash
# using --recursive makes sure git submodules are also cloned at the same time
git clone --recursive https://github.com/biojppm/c4core
```

If you ommit the `--recursive` option, then after cloning you will have to
make git checkout the current version of the submodules, using `git submodule
init` followed by `git submodule update`.


## Using c4core in your project

c4core is built with cmake, and assumes you also use cmake. Although c4core
is NOT header-only, and currently has no install target, you can very easily
use c4core in your project by using
`add_subdirectory(${path_to_c4core_root})` in your CMakeLists.txt; this will
add c4core as a subproject of your project. Doing this is not intrusive to
your cmake project because c4core is fast to build (typically under 10s), and
it also prefixes every cmake variable with `C4CORE_`. But more importantly
this will enable you to compile c4core with the exact same compile settings
used by your project.

Here's a very quick complete example of setting up your project to use
c4core:

```cmake
project(foo)

add_subdirectory(c4core)

add_library(foo foo.cpp)
target_link_libraries(foo PUBLIC c4core) # that's it!
```

Note above that the call to `target_link_libraries()` is using PUBLIC
linking. This is required to make sure the include directories from `c4core`
are transitively used.


## Quick tour

All of the utilities in this library are under the namespace `c4`; any
exposed macros use the prefix `C4_`: eg `C4_ASSERT()`.

### Multi-platform / multi-compiler utilities

```c++
// TODO: elaborate on the topics:
#include <c4/error.hpp>

C4_LIKELY()/C4_UNLIKELY()

C4_RESTRICT, $, c$, $$, c$$
#include <c4/restrict.hpp>
#include <c4/unrestrict.hpp>

#include <c4/windows_push.hpp>
#include <c4/windows_pop.hpp>

C4_UNREACHABLE()
```

### Runtime assertions and error handling

```c++
// TODO: elaborate on the topics:

error callback

C4_ASSERT()
C4_XASSERT()
C4_CHECK()

C4_ERROR()
C4_NOT_IMPLEMENTED()
```

### Memory allocation

```c++
// TODO: elaborate on the topics:

c4::aalloc(), c4::afree() // aligned allocation

c4::MemoryResource // global and scope

c4::Allocator
```

### Writeable string views: c4::substr and c4::csubstr

```c++
// TODO: elaborate on the topics:

disadvantages of having low-level algorithms force ownership models, eg std::to_string()

c4::itoa(), c4::utoa(), c4::ftoa()

c4::to_chars(), c4::from_chars()
```


### Value <-> character interoperation

```c++
// TODO: elaborate on the topics:

c4::itoa(), c4::utoa(), c4::ftoa()

c4::to_chars(), c4::from_chars()
```

### String formatting and parsing

```c++
// TODO: elaborate on the topics:

c4::cat(), c4::uncat()

c4::catsep(), c4::uncatsep()

c4::format(), c4::unformat()
```
