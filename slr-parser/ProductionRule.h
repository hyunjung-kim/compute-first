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

		std::vector<ProductionRule> AllRules()
		{
			return productionRules_;
		}

		std::vector<std::string> FIRST(std::string v)
		{
			std::vector<std::string> ret;

			// Step 1: if v is terminal then FIRST(v) = {v} if v belongs to terminal symbols
			if (IsTerminal(v))
			{
				ret.push_back(v);
				return ret;
			}

			// TODO: Step 2
			// TODO: Step 3

			return {};
		}

		bool IsTerminal(std::string v)
		{
			if (v.size() != 1)
			{
				throw std::runtime_error("Symbol size must be one");
			}

			if (v[0] >= 97 && v[0] <= 127) // a - z
			{
				return true;
			}
			else if (v[0] >= 65 && v[0] <= 90) // A - Z
			{
				return false;
			}
			else
			{
				throw std::runtime_error("Symbol must be a letter");
			}
		}

		std::vector<std::string> RINGSUM(std::vector<std::string> lhs, std::vector<std::string> rhs)
		{
			// TODO: implement
			return {};
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
}

