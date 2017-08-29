#include "ParserTools.h"
#include "ProductionRule.h"

namespace slrparser
{
	// null : '#' which represents 'epsilon'



	std::vector<std::string> ParserTools::Compute_FIRST(ProductionRule_deprecated & rules, std::string a)
	{
		// e.g.) {A -> aA | B | C}  =>  A: [aA, B, C]
		std::unordered_map<std::string, std::vector<std::string>> FIRSTS;

		// Initialise FIRST(A), where A is non-terminal symbol
		for (auto & rule : rules.Raw())
		{
			FIRSTS.emplace(rule.first, std::vector<std::string> {});
		}

		// TODO: Compute FIRST(A) from production rules where the first symbol of rhs is terminal
		for (auto & FIRST : FIRSTS)
		{
			// if alpha = ab where a (= Vt then
			if (FIRST.first.size() >= 2)
			{

			}
			else if (FIRST.second[0] == "#")
			{
				FIRST.second.push_back("#");
			}
				
		}


		// TODO: Compute rest of FIRST(A)

		return {};
	}

	std::vector<std::string> ParserTools::RingSum(const std::vector<std::string> & lhs, const std::vector<std::string> & rhs)
	{
		return {};
	}
}


