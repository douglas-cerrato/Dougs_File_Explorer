//Header Guard: Making it so only one instance on the functions are made
#pragma once

#include <filesystem>
#include <vector>

namespace FileNav{
	//TODO: Call Locate all root drives function
	std::vector<std::string> getRootPaths();
}