#pragma once
#include "../include.hpp"

namespace Conversion
{
	inline std::array<std::string, 13> error_list = {
		"Success",
		"Unknown",
		"Connection",
		"BindIPAddress",
		"Read",
		"Write",
		"ExceedRedirectCount",
		"Canceled",
		"SSLConnection",
		"SSLLoadingCerts",
		"SSLServerVerification",
		"UnsupportedMultipartBoundaryChars",
		"Compression"
	};
	
	inline auto map_to_headers(std::map<std::string, chaiscript::Boxed_Value> map) -> httplib::Headers
	{
		httplib::Headers headers;

		for (auto const& [key, val] : map) {
			if (key.empty() || chaiscript::boxed_cast<std::string>(val).empty()) continue;
			
			headers.emplace(key, chaiscript::boxed_cast<std::string>(val));
		}
		
		return headers;
	}

	inline auto headers_to_map(httplib::Headers headers) -> std::map<std::string, chaiscript::Boxed_Value>
	{
		std::map<std::string, chaiscript::Boxed_Value> map;

		for (auto const& [key, val] : headers) {
			map.emplace(key, chaiscript::var(val));
		}

		return map;
	}

	inline auto map_to_params(std::map<std::string, chaiscript::Boxed_Value> map) -> httplib::Params
	{
		httplib::Params params;

		for (auto const& [key, val] : map) {
			if (key.empty() || chaiscript::boxed_cast<std::string>(val).empty()) continue;

			params.emplace(key, chaiscript::boxed_cast<std::string>(val));
		}

		return params;
	}

	inline auto result_to_chai(httplib::Result result) -> chaiscript::Boxed_Value
	{
		std::vector<chaiscript::Boxed_Value> values;

		values.push_back(chaiscript::var(result->version));
		values.push_back(chaiscript::var(error_list[result.error()]));
		values.push_back(chaiscript::var(result->status));
		values.push_back(chaiscript::var(result->reason));
		values.push_back(chaiscript::var(result->body));
		values.push_back(chaiscript::var(headers_to_map(result->headers)));

		return chaiscript::Boxed_Value(values);
	}
}
