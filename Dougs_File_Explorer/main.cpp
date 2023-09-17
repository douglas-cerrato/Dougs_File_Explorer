#include <iostream>
#include <Windows.h>

#include "Directory/Directory.h"

int main() {
	Directory directory;
	//declares drives to pointer of vector of drives
	std::vector<std::string>* drives = directory.getDrives();
	
	std::cout << "Grabbing Drives...\n" << "Pick a drive:\n";
	int index = 0;
	for (const std::string &drive : *drives) {
		std::cout << "Drive " << index << ": "<< drive << std::endl;
		index++;
	}
	int response;
	std::cin >> response;

	directory.cacheContents(drives->at(response));

	delete drives;
	return 0;
}