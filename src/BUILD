package(default_visibility = ["//visibility:public"])

cc_library(
    name = 'etcd_cpp',
    srcs = glob(
        ['*.cpp']
    ),
    hdrs = glob(
        ['*.hpp']
    ),
    copts = [
    ],
    includes = [
        '.',
    ],
    linkopts = [
        '-lcpprest',
    ],
    deps = [
        #'@cpprestsdk//:cpprestsdk',
        #'//external:system',
    ]
) 

cc_binary(
    name = 'main',
    srcs = [
        'main.cpp'
    ],
    copts = [
    ],
    includes = [
        '.',
    ],
    linkopts = [
        '-lssl',
        '-lboost_system',
        '-lcrypto',
    ],
    deps = [
        ':etcd_cpp',
        #'@cpprestsdk//:cpprestsdk',
        #'@ssl//:ssl',
        #'//external:system',
    ]
) 
