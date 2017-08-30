#include "ParserTools.h"
#include "ProductionRule.h"

namespace slrparser
{
	// null : '#' which represents 'epsilon'
	std::vector<std::string> ParserTools::Compute_FIRST(ProductionRules & rules)
	{
		// e.g.) {A -> aA | B | C}  =>  A: [aA, B, C]
		std::vector<std::string> firsts;

		// Initialise FIRST(A), where A is non-terminal symbol
		for (auto rule : rules.AllRules())
		{
			// TODO:
		}

		// Compute FIRST(A) from production rules where the first symbol of rhs is terminal
		for (auto & first : firsts)
		{
			// TODO:
		}

		// TODO:

		return {};
	}
}


