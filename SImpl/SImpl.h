#ifndef SIMPL_SIMPL_H
#define SIMPL_SIMPL_H
#include <cstddef>

namespace SImpl
{
	template<typename T, size_t size>
	struct SSImpl
	{
		char buf[size]{};

		template<typename... Args>
		explicit SSImpl(Args&&... args);
		~SSImpl();

		T& get();
		const T& get() const { return const_cast<SSImpl*>(this)->get(); }
	};
}
#endif
