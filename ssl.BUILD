# Description:
#   The Boost library collection (http://www.boost.org)
#
# Most Boost libraries are header-only, in which case you only need to depend
# on :boost. If you need one of the libraries that has a separately-compiled
# implementation, depend on the appropriate libs rule.

package(default_visibility = ['//visibility:public'])

licenses(['notice'])  # Boost software license

cc_library(
    name = 'ssl',
    srcs =  glob([
        '*.so',
    ]),
    hdrs = glob([
        'include/**/*.h'
    ]),
    includes =[
        'include'
    ]
)
