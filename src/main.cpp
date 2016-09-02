/*
 * main.cpp
 * Copyright (C) 2016 qingze <qingze@localhost.localdomain>
 *
 * Distributed under terms of the MIT license.
 */

#include "Client.hpp"
#include <iostream>
int main(){
    etcd::Client etcd("http://192.168.184.35:3379", "test", "123456");
    etcd::Response resp = etcd.get("/message").get();

    if (resp.error_code() != 0) {
        std::cout << resp.error_message() << std::endl;
    } else {
        std::cout << resp.value().as_string() << std::endl;
    }


    std::cout << "adding..." << std::endl;
    etcd::Response add_resp = etcd.set("/message", "4").get();
    if (add_resp.error_code() == 0) {
        std::cout << "set successful" << std::endl;
    } else {
        std::cout << add_resp.error_message() << std::endl;
    }

    etcd::Response del_resp = etcd.rm("/message").get();
    if (del_resp.error_code() == 0) {
        std::cout << "del successful" << std::endl;
    } else {
        std::cout << del_resp.error_message() << std::endl;
    }

    // int count = 0;
    // while (1) {
    //     etcd::Response get_resp = etcd.get("/no").get();
    //     if (get_resp.is_ok() && get_resp.action() == "get") {
    //         std::cout << "NO " << count << " get value: " << get_resp.value().as_string() << std::endl;
    //     } else {
    //         std::cout << get_resp.error_message() << std::endl;
    //     }

    //     int etcd_index = get_resp.index();
    //     int modified_index = get_resp.value().modified_index();
    //     std::cout << "ectd_index " << etcd_index << " modified_index " << modified_index << std::endl;

    //     pplx::task<etcd::Response> res = etcd.watch("/no", etcd_index + 1);
    //     std::cout << res.get().value().as_string() << std::endl;
    //     //while(1) {
    //     //}

    //     count++;

    // }
}






