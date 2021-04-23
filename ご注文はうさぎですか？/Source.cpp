#include "Header.h"

#include "SImplImpl.h"

#include <vector>

namespace Hoge
{
	using namespace std;

	struct CHoge::Impl
	{
		vector<int>z{ 1800, 8 };
	};

	int CHoge::Func(int a) const
	{
		return a * shoge.get().z[0] * shoge.get().z[1];
	}
}
