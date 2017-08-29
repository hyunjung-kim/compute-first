#include "gtest\gtest.h"
#include "..\slr-parser\ProductionRule.h"
#include "..\slr-parser\ParserTools.h"

TEST(ParserToolTests, SimpleFirst)
{
	slrparser::ProductionRule_deprecated p;

	p.AddRule("A", std::vector<std::string>{"aB", "B"});
	p.AddRule("B", std::vector<std::string>{"bC", "C"});
	p.AddRule("C", std::vector<std::string>{"c"});

	slrparser::ParserTools tools;

	auto firstA = tools.Compute_FIRST(p, "A");
	auto firstB = tools.Compute_FIRST(p, "B");
	auto firstC = tools.Compute_FIRST(p, "C");

	ASSERT_EQ(firstA.size(), 3);
	ASSERT_EQ(firstB.size(), 2);
	ASSERT_EQ(firstC.size(), 1);
	
	EXPECT_EQ(firstA[0], "a");
	EXPECT_EQ(firstA[1], "b");
	EXPECT_EQ(firstA[2], "c");
	EXPECT_EQ(firstB[0], "b");
	EXPECT_EQ(firstB[1], "c");
	EXPECT_EQ(firstC[0], "c");
}

TEST(ParserToolTests, SimpleRingSum)
{
	slrparser::ParserTools tools;

	std::vector<std::string> nullableSetA = { "a", "b", "c", "" };
	std::vector<std::string> nullableSetB = { "a", "b", "" };
	std::vector<std::string> nullableSetC = { "c", "d", "" };
	std::vector<std::string> nonNullableSetA = { "a", "b", "c" };
	std::vector<std::string> nonNullableSetB = { "c", "d" };

	auto retA = tools.RingSum(nonNullableSetA, nonNullableSetB);
	auto retB = tools.RingSum(nullableSetA, nonNullableSetB);
	auto retC = tools.RingSum(nullableSetB, nullableSetC);

	ASSERT_EQ(retA.size(), 3);
	ASSERT_EQ(retB.size(), 4);
	ASSERT_EQ(retC.size(), 5);

	EXPECT_EQ(retA[0], "a");
	EXPECT_EQ(retA[1], "b");
	EXPECT_EQ(retA[2], "c");

	EXPECT_EQ(retB[0], "a");
	EXPECT_EQ(retB[1], "b");
	EXPECT_EQ(retB[2], "c");
	EXPECT_EQ(retB[3], "d");

	EXPECT_EQ(retC[0], "a");
	EXPECT_EQ(retC[1], "b");
	EXPECT_EQ(retC[2], "c");
	EXPECT_EQ(retC[3], "d");
	EXPECT_EQ(retC[4], "");	
}

TEST(ParserToolsTests, FirstCanBeExpressedAsRingSums)
{
	EXPECT_TRUE(false);
}

