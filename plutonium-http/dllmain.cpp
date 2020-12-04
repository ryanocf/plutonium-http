#include "include.hpp"

DLL_EXPORT void on_initialize_context(const char* script, chaiscript::ChaiScript* chai)
{
    chai->add(chaiscript::fun([](const std::string& url, const std::string& route, const std::map<std::string, chaiscript::Boxed_Value>& headers)
		{ return Conversion::result_to_chai(client->Get(url.c_str(), route.c_str(), Conversion::map_to_headers(headers))); }), "http_get");
	
    chai->add(chaiscript::fun([](const std::string& url, const std::string& route, const std::string& body, const std::map<std::string, chaiscript::Boxed_Value>& headers, const std::string& content_type)
        { return Conversion::result_to_chai(client->Post(url.c_str(), route.c_str(), body, Conversion::map_to_headers(headers), content_type.c_str())); }), "http_post");
	
    chai->add(chaiscript::fun([](const std::string& url, const std::string& route, const std::string& body, const std::map<std::string, chaiscript::Boxed_Value>& headers, const std::string& content_type)
        { return Conversion::result_to_chai(client->Put(url.c_str(), route.c_str(), body, Conversion::map_to_headers(headers), content_type.c_str())); }), "http_put");
	
    chai->add(chaiscript::fun([](const std::string& url, const std::string& route, const std::string& body, const std::map<std::string, chaiscript::Boxed_Value>& headers, const std::string& content_type)
        { return Conversion::result_to_chai(client->Delete(url.c_str(), route.c_str(), body, Conversion::map_to_headers(headers), content_type.c_str())); }), "http_delete");
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
    switch (dwReason)
    {
	    case DLL_PROCESS_ATTACH:
	    case DLL_THREAD_ATTACH:
	    case DLL_THREAD_DETACH:
	    case DLL_PROCESS_DETACH:
	        break;
    }
	
    return TRUE;
}