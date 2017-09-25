#include "gmock\gmock.h"
#include "..\slr-parser\ProductionRule.h"

using namespace ::testing;
using namespace slrparser;

// TODO: make this as an utility func
std::vector<ProductionRule> GetRules(std::vector<ProductionRule> & rules, char vn)
{
	// TODO: implement
	return {};
}

TEST(ProductionRulesTests, CanCreate)
{
	ProductionRule rule1('A', std::string("aB"));
	ProductionRule rule2('A', std::string("B"));
	ProductionRule rule3('B', std::string("bC"));
	ProductionRule rule4('B', std::string("C"));
	ProductionRule rule5('C', std::string("c"));

	std::vector<ProductionRule> rules;
	rules.push_back(rule1);
	rules.push_back(rule2);
	rules.push_back(rule3);
	rules.push_back(rule4);
	rules.push_back(rule5);	

	auto rulesA = GetRules(rules, 'A');
	auto rulesB = GetRules(rules, 'B');
	auto rulesC = GetRules(rules, 'C');
	
	EXPECT_EQ(rulesA.size(), 2);
	EXPECT_EQ(rulesB.size(), 2);
	EXPECT_EQ(rulesC.size(), 1);	
		
	
}

//TEST(ProductionRulesTests, SingleLetterFIRST)
//{
//	slrparser::ProductionRule rule1(std::string("A"), std::vector<std::string>{"aB", "B"});
//	slrparser::ProductionRule rule2(std::string("B"), std::vector<std::string>{"bC", "C"});
//	slrparser::ProductionRule rule3(std::string("C"), std::vector<std::string>{"c"});
//
//	slrparser::ProductionRules rules;
//	rules.Add(rule1);
//	rules.Add(rule2);
//	rules.Add(rule3);
//
//	ASSERT_THAT(rules.FIRST("A"), ::testing::ContainerEq(std::vector<std::string>{"a", "b", "c"}));
//	ASSERT_THAT(rules.FIRST("B"), ::testing::ContainerEq(std::vector<std::string>{"b", "c"}));
//	ASSERT_THAT(rules.FIRST("C"), ::testing::ContainerEq(std::vector<std::string>{"c"}));
//}

TEST(ProductionRulesTests, SimpleRingSum)
{
	slrparser::Obsolte_ProductionRules rules;

	ASSERT_THAT(rules.RINGSUM({ "a", "b", "c" }, { "c", "d" }), ::testing::ContainerEq(std::vector<std::string>({ "a", "b", "c" })));
	ASSERT_THAT(rules.RINGSUM({ "a", "b", "c", "#" }, { "c", "d" }), ::testing::ContainerEq(std::vector<std::string>({ "a", "b", "c", "d" })));
	ASSERT_THAT(rules.RINGSUM({ "a", "b", "#" }, { "c", "d", "#" }), ::testing::ContainerEq(std::vector<std::string>({ "a", "b", "c", "d", "#" })));
}

TEST(ProductionRulesTests, IsTerminalReturnsCorrectly)
{
	slrparser::Obsolte_ProductionRules rules;

	for (int i = 'a'; i <= 'z'; ++i)
	{
		std::string s(1, i);
		EXPECT_TRUE(rules.IsTerminal(s));
	}

	for (int i = 'A'; i <= 'Z'; ++i)
	{
		std::string s(1, i);
		EXPECT_FALSE(rules.IsTerminal(s));
	}

	// TODO: consider a better to test non-letter
	EXPECT_THROW(rules.IsTerminal("0"), std::runtime_error);
	EXPECT_THROW(rules.IsTerminal("9"), std::runtime_error);
}

TEST(ProductionRulesTests, IsEpsilonReturnsCorrectly)
{
	slrparser::Obsolte_ProductionRules rules;

	EXPECT_TRUE(rules.IsEpsilon("#"));
	
}

TEST(ProductionRulesTests, MultipleLettersFIRST)
{
	EXPECT_TRUE(false); // implement
}