#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

namespace slrparser
{
	class NEW_ProductionRule
	{
	public:
		NEW_ProductionRule(char vn, std::string & rhs)
			: vn_(vn), rhs_(rhs), valid_(true)
		{}

		// TODO: complete
		// copy ctor
		// assignment ctor
		// move ctor
		// dtor

		char Vn()
		{
			return vn_;
		}

		std::string Rhs()
		{
			return rhs_;
		}

		bool IsValid() const
		{
			return valid_;
		}

		void Invalidate()
		{
			valid_ = false;
		}

	private:
		char vn_;
		std::string rhs_;
		bool valid_ = false;
	};

	class NEW_ProductionRules
	{
	public:
		explicit NEW_ProductionRules() 
		{}

		void Add(NEW_ProductionRule & rule)
		{
			rules_.push_back(rule);
		}

		std::vector<NEW_ProductionRule> GetRules(char vn)
		{
			std::vector<NEW_ProductionRule> matchedRules;
			for (auto & rule : rules_)
			{
				// TODO: implement
			}
			return std::move(matchedRules);
		}

		size_t Count()
		{
			return rules_.size();
		}

		std::vector<NEW_ProductionRule> AllRules()
		{
			return std::move(rules_);
		}

	private:
		std::vector<NEW_ProductionRule> rules_;
	};



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

		std::vector<std::string> Rhs()
		{
			return rhs_;
		}

		bool IsValid()
		{
			return valid_;
		}

		void Invalidate()
		{
			valid_ = false;
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

		bool IsEpsilon(std::string v)
		{
			if (v.size() == 1 && v[0] == '#')
			{
				return true;
			}
			return false;
		}

		bool IsEpsilon(char v)
		{
			if (v == '#')
			{
				return true;
			}
			return false;
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
				return (*ret).Rhs();
			}
			return std::vector<std::string> {};
		}

	private:
		std::vector<ProductionRule> productionRules_;
	};
}

