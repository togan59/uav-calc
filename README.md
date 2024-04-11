![uavcalc](docs/img/uavcalc_banner.png)

**A C++ physical calculation library for UAV performance and design parameter calculator tools**

#### General Purposes of This Project ####
- To present together the computational tools necessary for unmanned aerial vehicle design
- Creating a resource for our future projects
- and most importantly: improve and learn new things

## For Use ##

### CMake ###

Clone the whole project

```bash
git clone https://github.com/togan59/uav-calc.git
```

and add the subdirectory to your CMake project:

```cmake
add_subdirectory(uavcalc)
```

When creating your executable, link the library to the targets you want:

```cmake
add_executable(my_target main.cpp)
target_link_libraries(my_target PUBLIC uavcalc)
```

Add this header to your source files:

```cpp
#include <uavcalc/uavcalc.h>
```