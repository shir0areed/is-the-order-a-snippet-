#ifndef SIMPL_SIMPLIMPL_H
#define SIMPL_SIMPLIMPL_H
#include "SImpl.h"

#include <utility>

template<typename T, size_t size>
template<typename... Args>
inline SImpl::SSImpl<T, size>::SSImpl(Args&&... args)
{
	new(buf)T(std::forward<Args>(args)...);
}

template<typename T, size_t size>
SImpl::SSImpl<T, size>::SSImpl(const SSImpl& a)
{
	new(buf)T(*a.get());
}

template<typename T, size_t size>
inline T* SImpl::SSImpl<T, size>::get() noexcept
{
	static_assert(sizeof(SSImpl<T, size>) >= sizeof(T), "too small size");
	return reinterpret_cast<T*>(buf);
}

template<typename T, size_t size>
inline SImpl::SSImpl<T, size>::~SSImpl()
{
	reinterpret_cast<T*>(buf)->~T();
}
#endif
