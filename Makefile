STD=c++14
FLAGS=-O3 -Wall -Werror
COMPILER=clang++
LINKS=-lcurl

compile: compile_filter compile_settings compile_curl_custom
	$(COMPILER) build/*.o src/main.cpp -std=$(STD) $(FLAGS) -o build/wallpapers-only $(LINKS)

compile_filter:
	$(COMPILER) -c src/filter.cpp -std=$(STD) $(FLAGS) -o build/filter.o

compile_settings:
	$(COMPILER) -c src/settings.cpp -std=$(STD) $(FLAGS) -o build/settings.o

compile_curl_custom:
	$(COMPILER) -c src/curl_custom.cpp -std=$(STD) $(FLAGS) -o build/curl_custom.o


run:
	build/wallpapers-only "wallpapers-only.cfg"
