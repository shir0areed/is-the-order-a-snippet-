#include "SImpl.h"

namespace Hoge
{
	class CHoge
	{
	public:
		CHoge();
		~CHoge();
		int Func(int a);
	private:
		struct Impl;
		SImpl::SSImpl<Impl, 24> impl;
	};
}
