//#include "gtest\gtest.h"
#include "gmock\gmock.h"
#include "..\slr-parser\ProductionRule.h"
#include "..\slr-parser\ParserTools.h"

using namespace slrparser;

TEST(ParserToolsTests, Compute_FIRST)
{
	//slrparser::Obsolte_ProductionRule rule1(std::string("S"), std::vector<std::string>{"ABe"});
	//slrparser::Obsolte_ProductionRule rule2(std::string("A"), std::vector<std::string>{"dB", "aS", "c"});
	//slrparser::Obsolte_ProductionRule rule3(std::string("B"), std::vector<std::string>{"AS", "b"});

	//slrparser::Obsolte_ProductionRules rules;
	//rules.Add(rule1);
	//rules.Add(rule2);
	//rules.Add(rule3);

	//slrparser::ParserTools tools;
	//tools.Obsolte_Compute_FIRST(rules);

	ProductionRule rule1('S', std::string("ABe"));
	ProductionRule rule2('A', std::string("dB"));
	ProductionRule rule3('A', std::string("aS"));
	ProductionRule rule4('A', std::string("c"));
	ProductionRule rule5('B', std::string("AS"));
	ProductionRule rule6('B', std::string("b"));

	std::vector<ProductionRule> rules;
	rules.push_back(rule1);
	rules.push_back(rule2);
	rules.push_back(rule3);
	rules.push_back(rule4);
	rules.push_back(rule6);

	ParserTools tools;
	tools.Compute_FIRST(rules);

	

	EXPECT_FALSE(true);
}