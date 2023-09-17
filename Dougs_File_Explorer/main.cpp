#include <iostream>
#include <Windows.h>

#include "Systems\System.h"

int main() {
	System thisComputer;
	//declares drives to pointer of vector of drives
	std::cout << "Grabbing Drives...\n" << "Pick a drive:\n";
	
	for (int i = 0; i < thisComputer.currentDrives.size(); i++) {
		std::cout << "Drive " << i << ": " << thisComputer.currentDrives[i] << std::endl;
	}

	/*
	Sleep(1000*60);
	thisComputer.getDrives();

	for (int i = 0; i < thisComputer.currentDrives.size(); i++) {
		std::cout << "Drive " << i << ": " << thisComputer.currentDrives[i] << std::endl;
	}
	*/
	
	return 0;
}