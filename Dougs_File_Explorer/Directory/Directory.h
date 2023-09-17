//Header Guard: Making it so only one instance on the functions are made
#pragma once

#include <filesystem>
#include <vector>

class Directory{
    private:
    public:
        std::vector<std::string> getDrives();
    
};