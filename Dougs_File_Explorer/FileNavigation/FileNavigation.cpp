#include "FileNavigation.h"
#include <Windows.h>
#include <iostream>

using namespace std;

vector<filesystem::path> FileNav::getRootPaths()
{
    //Buffer Length
    DWORD dw_mydrives = 100;
    //Buffer for drive storage
    char mydrives[100];
    GetLogicalDriveStrings(dw_mydrives, (LPWSTR)mydrives);
    vector<filesystem::path> vect_root_dir;

    if(mydrives == 0)
    {
        cout << "Error Returning Drives or No Drives but.....\n";
        GetLastError();
    }else
    {
        for(int i=0;i<100;i++)
        {
            //iterates through char array 
            cout << mydrives[i];
            //TODO: Convert char array from buffer to filesystem path vector in filesystem library
        }
    }
    return vect_root_dir;
}

 