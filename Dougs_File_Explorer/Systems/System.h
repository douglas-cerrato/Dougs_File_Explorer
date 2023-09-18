//Header Guard: Making it so only one instance on the functions are made
#pragma once

#include <filesystem>
#include <vector>
#include <unordered_map>
#include <iostream>


class System{
    private:
    public:
        System(){getDrives();}
        void getDrives();
        std::vector<std::string> currentDrives;

        
        
};
//TODO: Understanding Classes

class Pathing{
    public:
        Pathing(std::string Path) : Path(Path){}
        std::string Path;
        std::unordered_multimap<bool, Pathing> cachedPath;
        void cachePaths();
};

class File : public Pathing{
    private:
    public:
        std::string Name;
        int size;
        File(std::filesystem::path& filePath) : Pathing(filePath.string()){
            this->Name = filePath.filename().string();
            this->size = file_size(filePath);
        }
        
        
};

class Folder : public Pathing{
    private:
    public:
        std::string Name;
        int size;
        Folder(std::filesystem::path& folderPath) : Pathing(folderPath.string()){
            this->Name = folderPath.filename().string();
            this->size = file_size(folderPath);
        }
};