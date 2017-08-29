#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

namespace slrparser
{
	class ProductionRule
	{
	public:
		ProductionRule(std::string & vn, std::vector<std::string> vt)
			: 
			vn_(vn),
			rhs_(std::move(vt)),
			valid_(true)
		{}

		std::string Vn()
		{
			return vn_;
		}

		std::vector<std::string> Vt()
		{
			return rhs_;
		}

		bool Valid()
		{
			return valid_;
		}

	private:		
		// lhs_        rhs_
		// S     ->    aB | As
		
		std::string vn_;		
		std::vector<std::string> rhs_;
		bool valid_ = false;
	};

	class ProductionRules
	{
	public:
		ProductionRules() {}

		ProductionRules(const ProductionRules &) = delete;
		ProductionRules & operator=(const ProductionRules &) = delete;
		
		size_t RuleCount()
		{
			return productionRules_.size();
		}

		std::vector<std::string> Vn(const std::string & vn)
		{
			return findRuleImpl(vn);
		}

		std::vector<std::string> operator[](const std::string & vn)
		{
			return findRuleImpl(vn);
		}

		void Add(ProductionRule & rule)
		{
			productionRules_.push_back(rule);
		}

	private:
		std::vector<std::string> findRuleImpl(const std::string & vn)
		{
			auto ret = std::find_if(productionRules_.begin(), productionRules_.end(), [&vn](ProductionRule rule)
			{
				return vn == rule.Vn();
			});

			if (ret != productionRules_.end())
			{
				return (*ret).Vt();
			}
			return std::vector<std::string> {};
		}

	private:
		std::vector<ProductionRule> productionRules_;
	};





	class ProductionRule_deprecated
	{
	public:
		ProductionRule_deprecated() {};

		ProductionRule_deprecated(const ProductionRule_deprecated &) = delete;
		ProductionRule_deprecated & operator=(const ProductionRule_deprecated &) = delete;

		void AddRule(const std::string & lhs, std::vector<std::string> & rhs);
		size_t RuleCount();
		std::vector<std::string> Vn(std::string);


		std::vector<std::string> operator[](const std::string & V_N)
		{
			return rules_[V_N];
		}

		std::unordered_map<std::string, std::vector<std::string>> Raw()
		{
			return rules_;
		}

	private:
		std::unordered_map<std::string, std::vector<std::string>> rules_;
	};
}

