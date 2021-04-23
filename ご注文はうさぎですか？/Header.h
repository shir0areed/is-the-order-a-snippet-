#include "SImpl.h"

namespace Hoge
{
	class CHoge
	{
	public:
		int Func(int a) const;
	private:
		class SHogeImpl;
		SImpl::SSImpl<SHogeImpl, 16> shoge;
	};
}
