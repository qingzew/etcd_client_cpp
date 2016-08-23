/*
 * etcd_test.cpp
 * Copyright (C) 2016 qingze <qingze@localhost.localdomain>
 *
 * Distributed under terms of the MIT license.
 */

#include "gtest/gtest.h"
#include "src/Client.hpp"

TEST(EtcdTest, Setup) {
    etcd::Client etcd("http://127.0.0.1:4001");
    etcd.rmdir("/test", true).wait();
}





