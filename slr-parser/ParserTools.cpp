#include "ParserTools.h"
#include "ProductionRule.h"

#include <unordered_map>

namespace slrparser
{
	// null : '#' which represents 'epsilon'
	std::vector<std::string> ParserTools::Compute_FIRST(ProductionRules & rules)
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
}


