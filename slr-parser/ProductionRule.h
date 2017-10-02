#pragma once

#include <unordered_map>
#include <string>
#include <algorithm>

namespace slrparser
{
	class ProductionRule
	{
	public:
		ProductionRule(char vn, std::string & rhs)
			: vn_(vn), rhs_(rhs), valid_(true)
		{}

		~ProductionRule()
		{}
		
		char Vn()
		{
			return vn_;
		}

		std::string Rhs()
		{
			return rhs_;
		}

		bool IsValid() const
		{
			return valid_;
		}

		void Invalidate()
		{
			valid_ = false;
		}

	private:
		char vn_;
		std::string rhs_;
		bool valid_ = false;
	};
}

