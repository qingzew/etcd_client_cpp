# Description:
#   The Boost library collection (http://www.boost.org)
#
# Most Boost libraries are header-only, in which case you only need to depend
# on :boost. If you need one of the libraries that has a separately-compiled
# implementation, depend on the appropriate libs rule.

package(default_visibility = ['//visibility:public'])

licenses(['notice'])  # Boost software license

# prefix_dir = 'Release'
# 
# cc_library(
#     name = "cpprestsdk",
#     srcs = glob([
#         prefix_dir + '/src/http/**/*.cpp',
#         prefix_dir + '/src/json/*.cpp',
#         prefix_dir + '/src/pplx/*.cpp',
#         prefix_dir + '/src/streams/*.cpp',
#         prefix_dir + '/src/uri/*.cpp',
#     ]),
#     hdrs = glob([ 
#         prefix_dir + '/include/**/*.h',
#     ]),
#     includes = [
#         prefix_dir + '/include',
#         prefix_dir + '/src/pch/'
#     ],
# )

cc_library(
    name = 'cpprestsdk',
    srcs =  glob([
        'build/Binaries/*.so',
    ]),
    hdrs = glob([
        'include/**/*.h'
    ]),
    includes =[
        'include'
    ]
)
