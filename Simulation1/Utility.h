#include "stdafx.h"

#pragma once
class Utility
{
public:
	Utility();

	static bool separateList(std::vector<std::string>&, std::string);
	static std::vector<std::string> split(const std::string& s, const std::string& delim, const bool keep_empty = true);

	~Utility();
};
