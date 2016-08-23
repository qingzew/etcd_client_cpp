def tf_etcd_workspace():
    native.new_http_archive(
        name = "boost_archive",
        url = "http://pilotfiber.dl.sourceforge.net/project/boost/boost/1.61.0/boost_1_61_0.tar.gz",
        sha256 = "a77c7cc660ec02704c6884fbb20c552d52d60a18f26573c9cee0788bf00ed7e6",
        build_file = 'boost.BUILD',
    )
    
    native.bind(
        name = 'boost',
        actual = '@boost_archive//:boost'
    )
    
    native.bind(
        name = 'system',
        actual = '@boost_archive//:system'
    )

    native.new_local_repository(
        name = 'ssl',
        path = '/export/wangqingze/openssl/',
        build_file = 'ssl.BUILD'
    )
    
    # native.new_git_repository(
    #     name = 'cpprestsdk_git',
    #     tag = 'v2.8.0',
    #     init_submodules = True,
    #     remote = 'https://github.com/Microsoft/cpprestsdk.git',
    #     build_file = 'cpprestsdk.BUILD'
    # )

    # native.bind(
    #     name = 'cpprestsdk',
    #     actual = '@cpprestsdk_git//:cpprestsdk'
    # )

    native.new_local_repository(
        name = 'cpprestsdk',
        path = '/export/wangqingze/casablanca/Release/',
        build_file = 'cpprestsdk.BUILD'
    )

    native.new_git_repository(
        name = 'googletest_git',
        tag = 'release-1.7.0',
        init_submodules = True,
        remote = 'https://github.com/google/googletest.git',
        build_file = 'googletest.BUILD'
    )
    
    native.bind(
        name = 'gtest',
        actual = '@googletest_git//:gtest'
    )

