//Header Guard: Making it so only one instance on the functions are made
#pragma once

#include <filesystem>
#include <vector>
#include <Windows.h>
#include <iostream>

class System{
    private:
    public:
        System(){
            getDrives();
            std::cout << currentDrives.size() << std::endl;
        }
        std::vector<std::string> currentDrives;
        void getDrives();
        
        
};
//TODO: Understanding Classes

class File{
    private:
    public:
};

class Folder{
    private:
    public:
};