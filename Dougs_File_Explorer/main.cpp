#include <iostream>
#include <Windows.h>

#include "Systems\System.h"

int main() {
	System thisComputer;
	int choice;
	//declares drives to pointer of vector of drives
	std::cout << "Grabbing Drives.... Pick one...\n" << "Pick a drive:\n";
	
	for (int i = 0; i < thisComputer.currentDrives.size(); i++) {
		std::cout << "Drive " << i << ": " << thisComputer.currentDrives[i] << std::endl;
	}
	std::cin >> choice;

	Pathing Path(thisComputer.currentDrives.at(choice));
	Path.cachePaths();

	//TODO: Figure out how to access variables from derived Folder and File classes
	for(const auto paths : Path.cachedPath){
		if(paths.first == true){
			std::cout << "Folder " << paths.second.Name << std::endl;
		}
		else{
			std::cout << "File " << paths.second.Name << std::endl;
		}
	}
	
	return 0;
}