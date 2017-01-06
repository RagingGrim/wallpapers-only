#include "../lib/filter.hpp"

Filter::Filter(std::string filename){
	std::fstream inputFile(filename);

	if( inputFile.fail() )
		throw std::runtime_error("File not found.");

	std::string line("");
	while(std::getline(inputFile, line))
		Parse(line);
	inputFile.close();
}

void Filter::Parse(std::string line){
	size_t tagOne , tagTwo;
	size_t identOne , identTwo;

	tagOne = line.find('"');
	if(tagOne == std::string::npos)
		return;

	tagTwo = line.find('"',tagOne + 1);
	if(tagTwo == std::string::npos)
		return;

	identOne = line.find('"',tagTwo + 1 );
	if(identOne == std::string::npos)
		return;

	identTwo = line.find('"',identOne + 1 );
	if(identTwo == std::string::npos)
		return;

	std::string tag,ident;
	tag = line.substr(tagOne + 1,tagTwo - tagOne - 1);
	ident = line.substr(identOne + 1,identTwo - identOne - 1);

	internal_tag_map.insert({tag,ident});
}

bool Filter::checkTags(std::string buffer){
	//std::map::end() == entry not found
	size_t tagsPresent = 0;
	for( std::map<std::string,std::string>::iterator it = internal_tag_map.begin() ; it != internal_tag_map.end() ; it++)
		if(buffer.find(it->second) != std::string::npos)
			tagsPresent++;

	if(tagsPresent)
		return false;
	else
		return true;
}
