#include "../lib/curl_custom.hpp"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

curl_custom_return getRequest(CURL *curl , std::string url){
	curl_easy_setopt(curl, CURLOPT_URL,url.c_str());
	curl_easy_setopt(curl, CURLOPT_IPRESOLVE,CURL_IPRESOLVE_V4);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
	curl_custom_return ccr;
	ccr.buffer.clear();
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &(ccr.buffer));
	ccr.code = curl_easy_perform(curl);
	return ccr;
}
