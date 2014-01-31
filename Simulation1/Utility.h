#include "stdafx.h"

#pragma once
class Utility
{
public:
	Utility();

	static bool separateList(vector<string>&, string);
	static vector<string> split(const string& s, const string& delim, const bool keep_empty = true);

	~Utility();
};

