cc_library(
    name = 'gtest',
    srcs = glob(
        ['googletest/src/*.cc'],
        exclude = ['googletest/src/gtest-all.cc']
    ),
    hdrs = glob([
        'googletest/include/**/*.h',
        'googletest/src/*.h'
    ]),
    #copts = [
    #    '-I external/googletest/googletest/include'
    #],
    includes = ['include'],
    linkopts = [
        '-pthread'
    ],
    visibility = ['//visibility:public']
)
