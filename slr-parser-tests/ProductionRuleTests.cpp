#include "gtest\gtest.h"
#include "..\slr-parser\ProductionRule.h"

TEST(ProductionRuleTests, CanCreate)
{
	slrparser::ProductionRule p;

	p.AddRule("A", std::vector<std::string>{"aB", "B"});
	p.AddRule("B", std::vector<std::string>{"bC", "C"});
	p.AddRule("C", std::vector<std::string>{"c"});

	EXPECT_EQ(p.RuleCount(), 3);
	EXPECT_EQ(p.Vn("A")[0], "aB");
	EXPECT_EQ(p.Vn("A")[1], "B");
	EXPECT_EQ(p.Vn("B")[0], "bC");
	EXPECT_EQ(p.Vn("B")[1], "C");
	EXPECT_EQ(p.Vn("C")[0], "c");
}