#pragma once

#include <vector>
#include <string>

namespace slrparser
{
	class ProductionRule_deprecated;

	class ParserTools
	{
	public:
		std::vector<std::string> Compute_FIRST(ProductionRule_deprecated & p, std::string a);		
		std::vector<std::string> RingSum(const std::vector<std::string> & lhs, const std::vector<std::string> & rhs);
	};
}
