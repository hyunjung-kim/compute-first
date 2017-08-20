#pragma once

#include <vector>
#include <unordered_map>
#include <string>

namespace slrparser
{
	class ProductionRule
	{
	public:
		ProductionRule() {};

		ProductionRule(const ProductionRule &) = delete;
		ProductionRule & operator=(const ProductionRule &) = delete;

		void AddRule(const std::string & lhs, std::vector<std::string> & rhs);
		size_t RuleCount();
		std::vector<std::string> Vn(std::string);


		std::vector<std::string> operator[](const std::string & V_N)
		{
			return rules_[V_N];
		}

	private:
		std::unordered_map<std::string, std::vector<std::string>> rules_;
	};
}

