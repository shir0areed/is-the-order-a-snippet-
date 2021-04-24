#include "Header.h"

#include "SImplImpl.h"
//template class SImpl::SSImpl<decltype(Hoge::CHoge::shoge)::ImplType, decltype(Hoge::CHoge::shoge)::implSize>;

#include <vector>

namespace Hoge
{
	using namespace std;

	struct CHoge::Impl
	{
		vector<int>values{ 1800, 8 };
	};

	int CHoge::Func(int a) const
	{
		//constexpr auto realSize = sizeof(CHoge::Impl);
		return a * impl.get().values[0] * impl.get().values[1];
	}
}
