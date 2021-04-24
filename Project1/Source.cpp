#include "Header.h"

#include "SImpl.inl"

#include <vector>

namespace Hoge
{
	using namespace std;

	struct CHoge::Impl
	{
		Impl()
			: values{ 1200, 8 }
		{

		}
		Impl(int v1, int v2)
			: values{ v1, v2 }
		{

		}
		~Impl()
		{

		}
		vector<int>values;
	};

	CHoge::CHoge()
		: impl{ 1800, 8 }
	{
	}

	CHoge::~CHoge() = default;

	int CHoge::Func(int a) const
	{
		//constexpr auto realSize = sizeof(CHoge::Impl);
		return a * impl.get().values[0] * impl.get().values[1];
	}
}
