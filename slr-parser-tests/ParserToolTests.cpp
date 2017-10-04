//#include "gtest\gtest.h"
#include "gmock\gmock.h"
#include "..\slr-parser\ParserTools.h"

using namespace parsertools;
using namespace ::testing;

TEST(ParserToolsTests, RingSum)
{
	ParserTools tools;
	
	std::vector<char> lhs1 = { 'a', 'b', 'c' };
	std::vector<char> rhs1 = { 'c', 'd'};
	auto ringSum1 = tools.RingSum(lhs1, rhs1);
	ASSERT_THAT(ringSum1, ContainerEq(std::vector<char>{'a', 'b', 'c'}));

	std::vector<char> lhs2 = { 'a', 'b', 'c', '#' };
	std::vector<char> rhs2 = { 'c', 'd' };
	auto ringSum2 = tools.RingSum(lhs2, rhs2);
	ASSERT_THAT(ringSum2, ContainerEq(std::vector<char>{'a', 'b', 'c', 'd'}));

	std::vector<char> lhs3 = { 'a', 'b', '#' };
	std::vector<char> rhs3 = { 'c', 'd', '#' };
	auto ringSum3 = tools.RingSum(lhs3, rhs3);
	ASSERT_THAT(ringSum3, ContainerEq(std::vector<char>{'#', 'a', 'b', 'c', 'd'}));
}

TEST(ParserToolsTests, Compute_FIRST_Ex1)
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
	
	ParserTools tools;
	auto ret = tools.Compute_FIRST(rules);

	ASSERT_THAT(ret['A'], ContainerEq(std::vector<char>{'a', 'b', 'c'}));
	ASSERT_THAT(ret['B'], ContainerEq(std::vector<char>{'b', 'c'}));
	ASSERT_THAT(ret['C'], ContainerEq(std::vector<char>{'c'}));
}

TEST(ParserToolsTests, Compute_FIRST_Ex2)
{
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
	rules.push_back(rule5);
	rules.push_back(rule6);

	ParserTools tools;
	auto ret = tools.Compute_FIRST(rules);
	
	ASSERT_THAT(ret['S'], ContainerEq(std::vector<char>{'a', 'c', 'd'}));
	ASSERT_THAT(ret['A'], ContainerEq(std::vector<char>{'c', 'd', 'a'}));
	ASSERT_THAT(ret['B'], ContainerEq(std::vector<char>{'a', 'b', 'c', 'd'}));
}