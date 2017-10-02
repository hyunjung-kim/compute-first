#pragma once

#include <vector>
#include <string>
#include <unordered_map>

namespace slrparser
{
	class ProductionRule;

	class ParserTools
	{
	public:
		std::unordered_map<char, std::vector<char>> Compute_FIRST(std::vector<ProductionRule> & rules);
		std::vector<char> RingSum(std::vector<char> & lhs, std::vector<char> & rhs);
		std::vector<char> Union(std::vector<char> & lhs, std::vector<char> & rhs);

		bool IsEpsilon(char v)
		{
			return v == '#';
		}

		bool IsTerminalSymbol(char v)
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
	};
}
