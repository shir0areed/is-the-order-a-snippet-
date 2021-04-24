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
inline SImpl::SSImpl<T, size>::~SSImpl()
{
	reinterpret_cast<T*>(buf)->~T();
}

template<typename T, size_t size>
inline T& SImpl::SSImpl<T, size>::get()
{
	static_assert(sizeof(SSImpl<T, size>) >= sizeof(T), "SImpl too small");
	return *reinterpret_cast<T*>(buf);
}
#endif
