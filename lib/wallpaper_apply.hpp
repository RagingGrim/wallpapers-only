#ifndef WALLPAPER_APPLY
#define WALLPAPER_APPLY
#ifdef _WIN64
#include <sstream>
void apply_wallpaper(const char *path){

}
#else
void apply_wallpaper(const char *path){
	std::stringstream ss;
	ss << "feh --bg-scale ";
	ss << path;
	system(ss.str().c_str());
}
#endif
#endif
