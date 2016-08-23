cc_test(
    name = 'etcd_test',
    srcs = [
        'etcd_test.cpp'
    ],
    copts = [
        #"-Iexternal/gtest/include",
        '-L/usr/lib',
        '-lcpprest'
    ],
    deps = [
        '//external:gtest',
        '//src:etcd_cpp',
    ],
)

