/*
 * main.cpp
 * Copyright (C) 2016 qingze <qingze@localhost.localdomain>
 *
 * Distributed under terms of the MIT license.
 */

#include "Client.hpp"
#include <iostream>
int main(){
    std::cout << "call etcd..." << std::endl;
    etcd::Client etcd("http://127.0.0.1:4001");
    etcd.rmdir("/test", true).wait();
}






