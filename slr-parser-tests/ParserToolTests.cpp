//#include "gtest\gtest.h"
#include "gmock\gmock.h"
#include "..\slr-parser\ProductionRule.h"
#include "..\slr-parser\ParserTools.h"

TEST(ParserToolsTests, Compute_FIRST)
{
	slrparser::ProductionRule rule1(std::string("S"), std::vector<std::string>{"ABe"});
	slrparser::ProductionRule rule2(std::string("A"), std::vector<std::string>{"dB", "aS", "c"});
	slrparser::ProductionRule rule3(std::string("B"), std::vector<std::string>{"AS", "b"});

	slrparser::ProductionRules rules;
	rules.Add(rule1);
	rules.Add(rule2);
	rules.Add(rule3);

	slrparser::ParserTools tools;
	tools.Compute_FIRST(rules);

	EXPECT_FALSE(true);



}