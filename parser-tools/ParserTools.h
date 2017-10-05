#pragma once

#include <vector>
#include <string>
#include <unordered_map>

namespace parsertools
{
	class ProductionRule
	{
	public:
		explicit ProductionRule(char vn, std::string & rhs)
			: vn_(vn), rhs_(rhs), valid_(true) {}
		~ProductionRule() {}

		char Vn() const;
		std::string Rhs();
		bool IsValid() const;
		void Invalidate();

	private:
		char vn_;
		std::string rhs_;
		bool valid_ = false;
	};	

	class ParserTools
	{
	public:
		explicit ParserTools() {}
		~ParserTools() {}

		std::unordered_map<char, std::vector<char>> Compute_FIRST(std::vector<ProductionRule> & rules);
		// TODO: implement Compute_FOLLOW()
		std::vector<char> RingSum(std::vector<char> & lhs, std::vector<char> & rhs);
		std::vector<char> Union(std::vector<char> & lhs, std::vector<char> & rhs);

	private:
		bool IsEpsilon(char v);
		bool IsTerminalSymbol(char v);
	};	
}
