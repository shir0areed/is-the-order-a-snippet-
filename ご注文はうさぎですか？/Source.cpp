#include "Header.h"

#include <vector>

namespace Hoge
{
	using namespace std;

	class CHoge::SHogeImpl
	{
	public:
		vector<int>z{ 1800, 8 };
	};

	CHoge::SHoge::operator CHoge::SHogeImpl& ()
	{
		static_assert(sizeof(CHoge::SHoge) >= sizeof(CHoge::SHogeImpl), "SHoge too small");
		return *reinterpret_cast<CHoge::SHogeImpl*>(this);
	}

	CHoge::CHoge()
	{
		new(&shoge)CHoge::SHogeImpl;
	}

	CHoge::~CHoge()
	{
		static_cast<SHogeImpl&>(shoge).~SHogeImpl();
	}

	int CHoge::Func(int a) const
	{
		return a * shoge.get().z[0] * shoge.get().z[1];
	}
}
