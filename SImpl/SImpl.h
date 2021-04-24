#ifndef SIMPL_SIMPL_H
#define SIMPL_SIMPL_H
#include <cstddef>

namespace SImpl
{
	template<typename T, size_t size>
	struct SSImpl
	{
		char buf[size]{};

		SSImpl();
		SSImpl(const SSImpl&);

		template<typename... Args>
		explicit SSImpl(Args&&... args);

		T* get() noexcept;
		const T* get() const noexcept { return const_cast<SSImpl*>(this)->get(); }
		T* operator -> () noexcept { return get(); }
		const T* operator -> () const noexcept { return get(); }

		~SSImpl();

		SSImpl& operator =(const SSImpl&) = delete;
		SSImpl(SSImpl&&) = delete;
		SSImpl& operator =(SSImpl&&) = delete;
	};
}
#endif
