#pragma once

#include <vector>
#include <string>

namespace slrparser
{
	class ProductionRule;

	class ParserTools
	{
	public:
		std::vector<std::string> First(const ProductionRule & p, std::string a);		
		std::vector<std::string> RingSum(const std::vector<std::string> & lhs, const std::vector<std::string> & rhs);
	};
}
