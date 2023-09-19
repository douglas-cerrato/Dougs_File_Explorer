#include "System.h"
#include <Windows.h>

void System::getDrives()
{
    //Buffer Length
    DWORD dw_mydrives = 100;
    //Buffer for drive storage
    char mydrives[100];
    int drives_length = GetLogicalDriveStrings(dw_mydrives, (LPWSTR)mydrives);
    std::vector<std::string> vect_root_dir;
    
    if(mydrives == 0)
    {
        std::cout << "Error Returning Drives or No Drives but.....\n";
        GetLastError();
    }else if(drives_length > dw_mydrives)
    {
        std::cout << "Error, more drives then buffer size!...\n";
        GetLastError();
    }else{
        //counts nulls in a row 
        int nullcounter = 0;
        //string we concatenate to, to build each rooth path name and append it to the vector
        std::string current_drive = "";
        //Grab size of drive vector
        for(int i=0;i<100;i++)
        {
            //Going through nulls in LPWSTR and skipping them
            if(mydrives[i]==NULL)
            {
                nullcounter++;
                if(nullcounter == 4){break;}
                continue;
            }else
            {
                //If not null, reset null counter and append the char to the string
                nullcounter = 0;
                current_drive += mydrives[i];
                //Compares char in LPWSTR to backslash to look for the end of the drive name
                if(mydrives[i]=='\\'){
                    //Drive Name String complete, append to vector and reset
                    //std::cout << "Current Complete Drive: " << current_drive << std::endl;
                    vect_root_dir.push_back(current_drive);
                    current_drive = "";
                }
            }
        }
    }
    //returns pointer to this vector
    this->currentDrives = vect_root_dir;
}

void Pathing::cachePaths(){
    try{ 
        for(const auto& entry : std::filesystem::directory_iterator(this->Path))
        {
            std::filesystem::path pathingDir = entry.path();
            if(entry.is_directory()){
                //std::cout << "Inserting into ordered map a Folder\n";
                this->cachedPath.insert({1, pathingDir});
            }
            else{
                //std::cout << "Inserting into ordered map a File\n";
                this->cachedPath.insert({0, pathingDir});
            }
        }
    }catch(...)
    {
        std::cout << "Error: Access Denied" << std::endl;
    }
}
