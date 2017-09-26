#pragma once

#include <vector>
#include <string>
#include <unordered_map>

namespace slrparser
{
	class ProductionRule_deprecated;
	class Obsolte_ProductionRules;
	class ProductionRule;

	class ParserTools
	{
	public:
		std::vector<std::string> Obsolte_Compute_FIRST(Obsolte_ProductionRules & rules);
		std::unordered_map<char, std::vector<char>> Compute_FIRST(std::vector<ProductionRule> & rules);

	private:
		bool IsEpsilon(char v)
		{
			return v == '#';
		}

		bool IsTerminal(char v)
		{
			if (v >= 97 && v <= 127) // a - z
			{
				return true;
			}
			else if (v >= 65 && v <= 90) // A - Z
			{
				return false;
			}
			else
			{
				throw std::runtime_error("Symbol must be a letter");
			}
		}

		std::vector<char> RingSum(std::vector<char> & lhs, std::vector<char> & rhs);
	};
}
