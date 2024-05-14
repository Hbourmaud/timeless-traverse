#pragma once
#include <string>
#include <windows.data.json.h>

class JSONTool
{
public :
	JSONTool() = default;
	~JSONTool() = default;
	ABI::Windows::Data::Json::JsonObject JSONParser(std::string* JSONstring);
private:

};