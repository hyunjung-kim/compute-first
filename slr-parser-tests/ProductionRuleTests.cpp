//#include "gtest\gtest.h"
#include "gmock\gmock.h"
#include "..\slr-parser\ProductionRule.h"

//TEST(ProductionRuleTests, CanCreate)
//{
//	slrparser::ProductionRule_deprecated p;
//
//	p.AddRule("A", std::vector<std::string>{"aB", "B"});
//	p.AddRule("B", std::vector<std::string>{"bC", "C"});
//	p.AddRule("C", std::vector<std::string>{"c"});
//
//	EXPECT_EQ(p.RuleCount(), 3);
//	EXPECT_EQ(p.Vn("A")[0], "aB");
//	EXPECT_EQ(p.Vn("A")[1], "B");
//	EXPECT_EQ(p.Vn("B")[0], "bC");
//	EXPECT_EQ(p.Vn("B")[1], "C");
//	EXPECT_EQ(p.Vn("C")[0], "c");
//}

TEST(ProductionRulesTests, CanCreate)
{
	slrparser::ProductionRule rule1(std::string("A"), std::vector<std::string>{"aB", "B"});
	slrparser::ProductionRule rule2(std::string("B"), std::vector<std::string>{"bC", "C"});
	slrparser::ProductionRule rule3(std::string("C"), std::vector<std::string>{"c"});

	slrparser::ProductionRules rules;
	rules.Add(rule1);
	rules.Add(rule2);
	rules.Add(rule3);

	EXPECT_EQ(rules.RuleCount(), 3);
	EXPECT_EQ(rules.Vn("A")[0], "aB");
	EXPECT_EQ(rules.Vn("A")[1], "B");
	EXPECT_EQ(rules.Vn("B")[0], "bC");
	EXPECT_EQ(rules.Vn("B")[1], "C");
	EXPECT_EQ(rules.Vn("C")[0], "c");
}

TEST(ProductionRulesTests, SingleLetterFIRST)
{
	slrparser::ProductionRule rule1(std::string("A"), std::vector<std::string>{"aB", "B"});
	slrparser::ProductionRule rule2(std::string("B"), std::vector<std::string>{"bC", "C"});
	slrparser::ProductionRule rule3(std::string("C"), std::vector<std::string>{"c"});

	slrparser::ProductionRules rules;
	rules.Add(rule1);
	rules.Add(rule2);
	rules.Add(rule3);

	ASSERT_THAT(rules.FIRST("A"), ::testing::ContainerEq(std::vector<std::string>{"a", "b", "c"}));
	ASSERT_THAT(rules.FIRST("B"), ::testing::ContainerEq(std::vector<std::string>{"b", "c"}));
	ASSERT_THAT(rules.FIRST("C"), ::testing::ContainerEq(std::vector<std::string>{"c"}));
}

TEST(ProductionRulesTests, SimpleRingSum)
{
	slrparser::ProductionRules rules;

	ASSERT_THAT(rules.RINGSUM({ "a", "b", "c" }, { "c", "d" }), ::testing::ContainerEq(std::vector<std::string>({ "a", "b", "c" })));
	ASSERT_THAT(rules.RINGSUM({ "a", "b", "c", "#" }, { "c", "d" }), ::testing::ContainerEq(std::vector<std::string>({ "a", "b", "c", "d" })));
	ASSERT_THAT(rules.RINGSUM({ "a", "b", "#" }, { "c", "d", "#" }), ::testing::ContainerEq(std::vector<std::string>({ "a", "b", "c", "d", "#" })));
}

TEST(ProductionRulesTests, MultipleLettersFIRST)
{
	EXPECT_TRUE(false); // implement
}