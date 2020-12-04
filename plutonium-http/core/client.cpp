#include "client.hpp"

auto Client::Get(const char* url, const char* route, const httplib::Headers headers) -> httplib::Result
{
	httplib::Client cli(url);
	return cli.Get(route, headers);
}

auto Client::Post(const char* url, const char* route, const std::string body, const httplib::Headers headers, const char* content_type) -> httplib::Result
{
	httplib::Client cli(url);
	return cli.Post(route, headers, body, content_type);
}

auto Client::Put(const char* url, const char* route, const std::string body, const httplib::Headers headers, const char* content_type) -> httplib::Result
{
	httplib::Client cli(url);
	return cli.Put(route, headers, body, content_type);
}

auto Client::Delete(const char* url, const char* route, const std::string body, const httplib::Headers headers, const char* content_type) -> httplib::Result
{
	httplib::Client cli(url);
	return cli.Delete(route, headers, body, content_type);
}