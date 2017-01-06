#include <iostream>
#include <curl/curl.h>
#include "../lib/settings.hpp"
#include "../lib/filter.hpp"
#include "../lib/curl_custom.hpp"

using namespace std;

int main( int argc , char **argv ){
	if( argc <= 1 ){
		cout << "Expects a configuration-file as argument." << endl;
		exit(1);
	}

	CURL *curl = curl_easy_init();
	if(!curl){
		cout << "Error starting curl!" << endl;
		exit(2);
	}

	curl_custom_return ccr = getRequest(curl, "http://www.google.com");
	cout << ccr.buffer << endl;

	curl_easy_cleanup(curl);	//This comment is a dummy comment.
  	return 0;
}
