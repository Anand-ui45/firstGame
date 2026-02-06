#include "MapLoader.h"
#include <fstream>
#include <string>



void MapLoader::Load(std::string filename, MapData &mapsData){
	
	
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
				try {
					int count = line.find("=");
					std::string variables = line.substr(0, count);
					std::string values = line.substr(count + 1, line.length() - count);

					if (variables == "version") {
						mapsData.version = std::stoi(values);

					}
					else if (variables == "tilesheet") {
						mapsData.tilesheet = values;

					}
					else if (variables == "mapName") {
						mapsData.mapName = values;

					}
					else if (variables == "mapPositionX") {
						mapsData.mapPositionX = std::stoi(values);;

					}
					else if (variables == "mapPositionY") {
						mapsData.mapPositionY = std::stoi(values);;

					}
					else if (variables == "cellSizeX") {
						mapsData.cellSizeX = std::stoi(values);;

					}
					else if (variables == "cellSizeY") {
						mapsData.cellSizeY = std::stoi(values);;

					}
					else if (variables == "totalCellsX") {
						mapsData.totalCellsX = std::stoi(values);;

					}
					else if (variables == "totalCellsY") {
						mapsData.totalCellsY = std::stoi(values);;

					}
					else if (variables == "mapScaleX") {
						mapsData.mapScaleX = std::stoi(values);;

					}
					else if (variables == "mapScaleY") {
						mapsData.mapScaleY = std::stoi(values);;

					}
					else if (variables == "dataLength") {
						mapsData.dataLength = std::stoi(values);;

					}
					else if (variables == "data") {
						
						mapsData.data = new int[mapsData.dataLength];
						int offset = 0;
						

						for (size_t i = 0; i < mapsData.dataLength; i++){

						int index = values.find(",",offset);
						std::string valArr = values.substr(offset, index-offset);
						mapsData.data[i] = std::stoi(valArr);
			            
						
						offset = index + 1;
							
							
						}
					}
				}
				catch (const std::exception&) {
					std::cout << "something went worng when reading the map file " <<filename<< std::endl;
				}
				
			}

		}
		/*std::cout << mapsData.version << std::endl;
		std::cout << mapsData.tilesheet << std::endl;
		std::cout << mapsData.mapName << std::endl;
		std::cout << mapsData.mapPositionX << std::endl;
		std::cout << mapsData.mapPositionY << std::endl;
		std::cout << mapsData.cellSizeX << std::endl;
		std::cout << mapsData.cellSizeY<< std::endl;
		std::cout << mapsData.totalCellsX << std::endl;
		std::cout << mapsData.totalCellsY << std::endl;
		std::cout << mapsData.mapScaleX << std::endl;
		std::cout << mapsData.mapScaleY << std::endl;
		std::cout << mapsData.dataLength << std::endl;
		std::cout << mapsData.data << std::endl;*/
		file.close();
	}
	else {
		std::cout << "Unable to open the map file" << std::endl;
	}
	

}

