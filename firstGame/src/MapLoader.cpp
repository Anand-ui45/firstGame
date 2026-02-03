#include "MapLoader.h"
#include <fstream>
#include <string>


void MapLoader::Load(std::string filename){
	
	std::ifstream file(filename);
	std::string line;
	bool mapValid = false;


	if (file.is_open()) {
		while (std::getline(file,line)) {
			if (!mapValid) {
				if (line == "[Map]") {
					mapValid = true;
					continue;
				}
				else {
					std::cout << "the file is courepted i guess(level_1.rmap)" << std::endl;
					break;
				}
			}
	
			if (mapValid) {
				int count = line.find("=");
				std::string variables = line.substr(0, count);
				std::string values = line.substr(count+1, line.length() - count);

				std::cout << variables << std::endl;
				std::cout << values << std::endl;
			}

		}
		file.close();
	}
	else {
		std::cout << "Unable to open the map file" << std::endl;
	}

}

