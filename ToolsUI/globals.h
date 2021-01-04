#pragma once
#include <string>

namespace globals 
{
	std::string floatToStringPrecision(float value, int precision)
	{
		std::string floatToString = std::to_string(value);
		std::string rounded = floatToString.substr(0, floatToString.find('.') + precision);
		return rounded;
	}
}