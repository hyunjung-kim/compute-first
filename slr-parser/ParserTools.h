#pragma once

#include <vector>
#include <string>

namespace slrparser
{
	class ProductionRule_deprecated;
	class ProductionRules;

	class ParserTools
	{
	public:
		std::vector<std::string> Compute_FIRST(ProductionRules & rules);
	};
}
