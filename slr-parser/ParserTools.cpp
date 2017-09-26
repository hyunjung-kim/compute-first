#include "ParserTools.h"
#include "ProductionRule.h"

#include <unordered_map>
#include <set>

namespace slrparser
{
	// null : '#' which represents 'epsilon'
	std::vector<std::string> ParserTools::Obsolte_Compute_FIRST(Obsolte_ProductionRules & rules)
	{
		// e.g.) {A -> aA | B | C}  =>  A: [aA, B, C]
		std::unordered_map<std::string, std::vector<char>> firsts;

		for (auto rule : rules.AllRules())
		{
			if (!rule.IsValid())
				continue;

			for (auto vt : rule.Rhs())
			{
				if (vt.size() >= 2 && rules.IsTerminal(vt[0]))
				{
					// TODO: 'add' to existing vector list rather than replacing it
					firsts.emplace(rule.Vn(), std::vector<char>{vt[0]});
					rule.Invalidate();
				}
				else if (vt.size() == 1 && rules.IsEpsilon(vt[0]))
				{
					// TODO: 'add' to existing vector list rather than replacing it
					firsts.emplace(rule.Vn(), std::vector<char>{vt[0]});
					rule.Invalidate();
				}
			}
		}

		// TODO: while (modified) { ...
		for (auto rule : rules.AllRules())
		{
			if (!rule.IsValid())
				continue;

			for (auto v : rule.Rhs())
			{

			}
		}
		return {};
	}

	// null : '#' which represents 'epsilon'
	std::unordered_map<char, std::vector<char>> ParserTools::Compute_FIRST(std::vector<ProductionRule> & rules)
	{
		// e.g.) {A -> aA | B | C}  =>  A: [aA, B, C]
		// step 1
		std::unordered_map<char, std::vector<char>> firsts;

		// step 1-1
		for (auto & rule : rules)
		{
			if (rule.Rhs().size() == 1 && IsTerminal(rule.Rhs()[0]))
			{
				firsts.insert({ rule.Vn(), std::vector<char>{rule.Rhs()[0]} });
				rule.Invalidate();
			}
		}

		// step 2 (okay - TODO: unit tests)
		for (auto & rule : rules)
		{
			if (!rule.IsValid())
				continue;

			std::vector<char> tmpFirsts = {};
			if (rule.Rhs().size() >= 2 && IsTerminal(rule.Rhs()[0]))
			{
				if (firsts.count(rule.Vn()) > 0)
				{
					tmpFirsts = firsts[rule.Vn()];
				}

				tmpFirsts.push_back(rule.Rhs()[0]);
				firsts[rule.Vn()] = tmpFirsts;
				rule.Invalidate();
			}
			else
			{
				if (IsEpsilon(rule.Rhs()[0]))
				{
					if (firsts.count(rule.Vn()) > 0)
					{
						tmpFirsts = firsts[rule.Vn()];
					}

					tmpFirsts.push_back(rule.Rhs()[0]);
					firsts[rule.Vn()] = tmpFirsts;
					rule.Invalidate();
				}
			}
		}

		// step 3 (WIP)
		bool modified = false;
		do
		{
			modified = false;
			for (auto & rule : rules)
			{
				if (!rule.IsValid())
					continue;

				size_t existingFirstCnt = 0;
				std::vector<char> existingFirst = {};
				if (firsts.count(rule.Vn()) > 0)
				{
					existingFirst = firsts[rule.Vn()];
					existingFirstCnt = existingFirst.size();
				}

				std::vector<char> ringSum = {};
				if (firsts.count(rule.Rhs()[0]) > 0)
				{
					ringSum = firsts[rule.Rhs()[0]];
				}

				for (int i = 1; i < rule.Rhs().size(); ++i)
				{
					std::vector<char> currFirsts = {};
					if (firsts.count(rule.Rhs()[i]) > 0)
					{
						currFirsts = firsts[rule.Rhs()[i]];
					}
					// TODO: implement
					ringSum = RingSum(ringSum, currFirsts);
				}

				// TODO: update existing 'firsts' for the current Vn
				std::set<char> updatedFirsts;
				for (auto i : ringSum)
				{
					updatedFirsts.insert(i);
				}
				for (auto i : existingFirst)
				{
					updatedFirsts.insert(i);
				}
				existingFirst.clear();
				for (auto i : updatedFirsts)
				{
					existingFirst.push_back(i);
				}

				if (existingFirstCnt != existingFirst.size())
				{
					modified = true;
				}
				else
				{
					modified = false;
				}
			}
		} while (modified);

		return firsts;
	}

	// TODO: start from here
	std::vector<char> ParserTools::RingSum(std::vector<char> & lhs, std::vector<char> & rhs)
	{
		return {};
	}
}


