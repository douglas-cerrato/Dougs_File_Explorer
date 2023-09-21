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
    private:
        //TODO: Figure out how to do this right right or replace with a different idea
        std::unordered_multimap<bool, std::filesystem::path> *previousPath;    
    public:
        Pathing(std::string Path) : Path(Path){}
        std::string Path;
        std::unordered_multimap<bool, std::filesystem::path> cachedPath;
        void cachePaths();
};

class File{
    private:
    public:
        std::string name;
        long size;
        File(std::filesystem::path& filePath){
            this->name = filePath.filename().string();
            this->size = file_size(filePath);
        }
        
        
};

class Folder{
    private:
    public:
        std::string name;
        long size;
        Folder(std::filesystem::path& folderPath){
            this->name = folderPath.filename().string();
            this->size = file_size(folderPath);
        }
};