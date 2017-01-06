#ifndef FILTER_H
#define FILTER_H
#include <string>
#include <map>
#include <fstream>
#include <exception>
#include <iostream> //TODO: Remove

class Filter{
	public:
	Filter(std::string filename);
	bool checkTags(std::string buffer);
	private:
	void Parse(std::string line);
	std::map<std::string,std::string> internal_tag_map;
};

#endif
