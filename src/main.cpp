#include <iostream>
#include <cmath>
#include <ctime>
#include <sstream>
#include <curl/curl.h>
#include "../lib/settings.hpp"
#include "../lib/filter.hpp"
#include "../lib/curl_custom.hpp"
#include "../lib/wallpaper_apply.hpp"

using namespace std;
int rand_range(int a){
	return rand() % a;
}

int main( int argc , char **argv ){
	if( argc <= 1 ){
		cout << "Expects a configuration-file as argument." << endl;
		exit(1);
	}
	srand(time(NULL));
	CURL *curl = curl_easy_init();
	if(!curl){
		cout << "Error starting curl!" << endl;
		exit(2);
	}

	// This part should be incorporated into a class ( :( )
	int random = rand_range(45000);
	stringstream sstream;
	sstream << "https://alpha.wallhaven.cc/wallpaper/";
	sstream << random;

	curl_custom_return ccr = getRequest(curl, sstream.str());
	if(ccr.code != CURLE_OK){
		cout << "CURL Error " << ccr.code << endl;
		exit(3);
	}
	cout << "Pulled the taglist!" << endl;


	Filter filter(argv[1]);
	if( !filter.checkTags(ccr.buffer) ){
		cout << "Image violated tag list!" << endl;
		exit(4);
	}
	cout << "Pulling and applying the image!" << endl;

	sstream.clear();
	sstream.str("");

	sstream << "https://wallpapers.wallhaven.cc/wallpapers/full/wallhaven-";
	sstream << random;
	sstream << ".jpg";
	cout << sstream.str() << endl;
	ccr = getRequest(curl, sstream.str());
	if(ccr.code != CURLE_OK){
		cout << "CURL Error " << ccr.code << endl;
		exit(3);
	}


	ofstream output;
	output.open("test.jpg",ios::binary);
	output << ccr.buffer;
	output.close();

	apply_wallpaper("test.jpg");


	curl_easy_cleanup(curl);	//This comment is a dummy comment.
  	return 0;
}
