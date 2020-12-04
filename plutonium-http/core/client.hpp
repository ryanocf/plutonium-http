#pragma once
#include "../include.hpp"

class Client
{
public:
	auto Get(const char* url, const char* route, httplib::Headers headers) -> httplib::Result;
	
	auto Post(const char* url, const char* route, std::string body, httplib::Headers headers, const char* content_type) -> httplib::Result;
	
	auto Put(const char* url, const char* route, std::string body, httplib::Headers headers, const char* content_type) -> httplib::Result;

	auto Delete(const char* url, const char* route, std::string body, httplib::Headers headers, const char* content_type) -> httplib::Result;
};

inline std::unique_ptr<Client> client = std::make_unique<Client>();