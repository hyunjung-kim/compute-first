#include "ParserTools.h"
#include "ProductionRule.h"

#include <unordered_map>
#include <set>

namespace slrparser
{
	// null : '#' which represents 'epsilon'
	std::unordered_map<char, std::vector<char>> ParserTools::Compute_FIRST(std::vector<ProductionRule> & rules)
	{
		// Step 1: initialize FIRSTs
		// e.g.) {A -> aA | B | C}  =>  A: [aA, B, C]		
		std::unordered_map<char, std::vector<char>> firsts;

		// Step 1-1: handle single terminal symbol rule
		for (auto & rule : rules)
		{
			if (rule.Rhs().size() == 1 && IsTerminalSymbol(rule.Rhs()[0]))
			{
				firsts.insert({ rule.Vn(), std::vector<char>{rule.Rhs()[0]} });
				rule.Invalidate();
			}
		}

		// Step 2: handle Vn -> aX where a is a terminal symbol
		for (auto & rule : rules)
		{
			if (!rule.IsValid())
				continue;

			std::vector<char> tmpFirsts = {};
			if (rule.Rhs().size() >= 2 && IsTerminalSymbol(rule.Rhs()[0]))
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

		// Step 3: handle all remaining rules
		bool modified = false;
		do
		{
			modified = false;
			for (auto & rule : rules)
			{
				if (!rule.IsValid())
					continue;

				std::vector<char> existingFirst = {};
				if (firsts.count(rule.Vn()) > 0)
				{
					existingFirst = firsts[rule.Vn()];
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
					else if (IsTerminalSymbol(rule.Rhs()[i]))
					{
						currFirsts = std::vector<char>{ rule.Rhs()[i] };
					}
					
					ringSum = RingSum(ringSum, currFirsts);
				}

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

				if (updatedFirsts.size() != existingFirst.size())
				{
					firsts[rule.Vn()] = existingFirst;
					modified = true;
				}
				else
				{
					rule.Invalidate();
					modified = false;
				}
			}
		} while (modified);

		return firsts;
	}

	std::vector<char> ParserTools::RingSum(std::vector<char> & lhs, std::vector<char> & rhs)
	{
		std::vector<char> ringSum;

		auto ret = std::find(lhs.begin(), lhs.end(), '#');
		if (ret != lhs.end())
		{
			lhs.erase(std::remove(lhs.begin(), lhs.end(), '#'), lhs.end());
			ringSum = Union(lhs, rhs);
		}
		else
		{
			ringSum = lhs;
		}

		return std::move(ringSum);
	}

	std::vector<char> ParserTools::Union(std::vector<char> & lhs, std::vector<char> & rhs)
	{
		std::set<char> tmpSet;
		for (auto i : lhs)
		{
			tmpSet.insert(i);
		}

		for (auto i : rhs)
		{
			tmpSet.insert(i);
		}

		std::vector<char> unionSum;
		for (auto i : tmpSet)
		{
			unionSum.push_back(i);
		}

		return unionSum;
	}
}


