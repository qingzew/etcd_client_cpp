#include "Client.hpp"


etcd::Client::Client(std::string const &address, std::string username, std::string password) {
    std::vector<unsigned char> str;
    for (int i = 0; i < username.length(); ++i) {
        str.push_back(username[i]);
    }
    str.push_back(':');
    for (int i = 0; i < password.length(); ++i) {
         str.push_back(password[i]);
    }

    auth_str = utility::conversions::to_base64(str);

    web::http::client::http_client_config client_config;
    client = std::make_shared<web::http::client::http_client>(address, client_config);

    const unsigned int timeout = 0xFFFFFFFF;
    client_config.set_timeout(std::chrono::seconds(timeout));
    watch_client = std::make_shared<web::http::client::http_client>(address, client_config);
}

pplx::task<etcd::Response> etcd::Client::send_get_request(web::http::uri_builder &uri) {
    web::http::http_request req;
    req.headers().add("Authorization", "Basic " + auth_str);
    req.set_method(web::http::methods::GET);
    req.set_request_uri(uri.to_string());

    return Response::create(client->request(req));
    // return Response::create(client->request(web::http::methods::GET, uri.to_string()));
}

pplx::task<etcd::Response> etcd::Client::send_del_request(web::http::uri_builder &uri) {
    web::http::http_request req;
    req.headers().add("Authorization", "Basic " + auth_str);
    req.set_method(web::http::methods::DEL);
    req.set_request_uri(uri.to_string());

    return Response::create(client->request(req));

    // return Response::create(client->request(web::http::methods::DEL, uri.to_string()));
}

pplx::task<etcd::Response> etcd::Client::send_put_request(web::http::uri_builder &uri, std::string const &key, std::string const &value)
{
    std::string data = key + "=" + value;
    std::string content_type = "application/x-www-form-urlencoded; param=" + key;

    web::http::http_request req;
    req.headers().add("Authorization", "Basic " + auth_str);
    req.set_method(web::http::methods::PUT);
    req.set_request_uri(uri.to_string());
    req.set_body(data.c_str(), content_type.c_str());

    return Response::create(client->request(req));
    // return Response::create(client->request(web::http::methods::PUT, uri.to_string(), data.c_str(), content_type.c_str()));
}

pplx::task<etcd::Response> etcd::Client::get(std::string const &key)
{
    web::http::uri_builder uri("/v2/keys" + key);
    return send_get_request(uri);
}

pplx::task<etcd::Response> etcd::Client::set(std::string const &key, std::string const &value)
{
    web::http::uri_builder uri("/v2/keys" + key);
    return send_put_request(uri, "value", value);
}

pplx::task<etcd::Response> etcd::Client::add(std::string const &key, std::string const &value)
{
    web::http::uri_builder uri("/v2/keys" + key);
    uri.append_query("prevExist=false");
    return send_put_request(uri, "value", value);
}

pplx::task<etcd::Response> etcd::Client::modify(std::string const &key, std::string const &value)
{
    web::http::uri_builder uri("/v2/keys" + key);
    uri.append_query("prevExist=true");
    return send_put_request(uri, "value", value);
}

pplx::task<etcd::Response> etcd::Client::modify_if(std::string const &key, std::string const &value, std::string const &old_value)
{
    web::http::uri_builder uri("/v2/keys" + key);
    uri.append_query("prevValue", old_value);
    return send_put_request(uri, "value", value);
}

pplx::task<etcd::Response> etcd::Client::modify_if(std::string const &key, std::string const &value, int old_index)
{
    web::http::uri_builder uri("/v2/keys" + key);
    uri.append_query("prevIndex", old_index);
    return send_put_request(uri, "value", value);
}

pplx::task<etcd::Response> etcd::Client::rm(std::string const &key)
{
    web::http::uri_builder uri("/v2/keys" + key);
    uri.append_query("dir=false");

    return send_del_request(uri);
    // return Response::create(client->request("DELETE", uri.to_string()));
}

pplx::task<etcd::Response> etcd::Client::rm_if(std::string const &key, std::string const &old_value)
{
    web::http::uri_builder uri("/v2/keys" + key);
    uri.append_query("dir=false");
    uri.append_query("prevValue", old_value);
    return send_del_request(uri);
}

pplx::task<etcd::Response> etcd::Client::rm_if(std::string const &key, int old_index)
{
    web::http::uri_builder uri("/v2/keys" + key);
    uri.append_query("dir=false");
    uri.append_query("prevIndex", old_index);
    return send_del_request(uri);
}

pplx::task<etcd::Response> etcd::Client::mkdir(std::string const &key)
{
    web::http::uri_builder uri("/v2/keys" + key);
    return send_put_request(uri, "dir", "true");
}

pplx::task<etcd::Response> etcd::Client::rmdir(std::string const &key, bool recursive)
{
    web::http::uri_builder uri("/v2/keys" + key);
    uri.append_query("dir=true");
    if (recursive)
        uri.append_query("recursive=true");
    return send_del_request(uri);
}

pplx::task<etcd::Response> etcd::Client::ls(std::string const &key)
{
    web::http::uri_builder uri("/v2/keys" + key);
    uri.append_query("sorted=true");
    return send_get_request(uri);
}

pplx::task<etcd::Response> etcd::Client::watch(std::string const &key, bool recursive)
{
    web::http::uri_builder uri("/v2/keys" + key);
    uri.append_query("wait=true");
    if (recursive)
        uri.append_query("recursive=true");
    //return send_get_request(uri);
    return Response::create(watch_client->request(web::http::methods::GET, uri.to_string()));
}

pplx::task<etcd::Response> etcd::Client::watch(std::string const &key, int fromIndex, bool recursive)
{
    web::http::uri_builder uri("/v2/keys" + key);
    uri.append_query("wait=true");
    uri.append_query("waitIndex", fromIndex);
    if (recursive)
        uri.append_query("recursive=true");

    return Response::create(watch_client->request(web::http::methods::GET, uri.to_string()));
}
