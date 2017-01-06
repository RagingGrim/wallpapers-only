#ifndef CURL_CUSTOM
#define CURL_CUSTOM
#include <cstddef>
#include <string>
#include <curl/curl.h>
//Structures
typedef struct ccr{
std::string buffer;
CURLcode code;
}curl_custom_return;

//Functions
	//static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
	//--> This function has been removed from the header because it can be explicitly referenced from the source file.
curl_custom_return getRequest(CURL *curl , std::string url);
#endif
