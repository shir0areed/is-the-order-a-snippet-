#include "SImpl.h"

namespace Hoge
{
	class CHoge
	{
	public:
		int Func(int a) const;
	private:
		struct Impl;
		SImpl::SSImpl<Impl, 16> shoge;
	};
}
