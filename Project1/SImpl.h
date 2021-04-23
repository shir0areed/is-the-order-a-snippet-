#include <cstddef>

namespace SImpl
{
	template<typename T, size_t size>
	struct SSImpl
	{
		SSImpl();
		~SSImpl();
		char buf[size]{};
		operator T& ();
		operator const T& () const { return const_cast<SSImpl*>(this)->operator T & (); }
		T& get() { return this->operator T & (); }
		const T& get() const { return this->operator const T & (); }
	};
}
