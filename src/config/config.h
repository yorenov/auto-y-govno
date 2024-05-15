#pragma once 

#include <fstream>
#include <filesystem>

#include "json.hpp"

class config {
public:
	explicit config(const char* filename);

	bool save();
	nlohmann::json data{};
private:
	const char* filename;
};

extern config* gConfig;