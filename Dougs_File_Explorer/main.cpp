#include <iostream>
#include <Windows.h>

#include "Directory/Directory.h"

int main() {
	Directory directory;
	std::vector<std::string> drives = directory.getDrives();
	
	std::cout << "Grabbing Drives...\n" << "Pick a drive:\n";
	for(int i = 0; i < drives.size();i++){
		std::cout << "Drive " << i << ": " << drives[i] << std::endl;
	}
	
	return 0;
}