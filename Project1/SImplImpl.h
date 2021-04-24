#include <utility>

template<typename T, size_t size>
template<typename... Args>
SImpl::SSImpl<T, size>::SSImpl(Args&&... args)
{
	new(buf)T{ std::forward<Args>(args)... };
}

template<typename T, size_t size>
SImpl::SSImpl<T, size>::~SSImpl()
{
	reinterpret_cast<T*>(buf)->~T();
}

template<typename T, size_t size>
SImpl::SSImpl<T, size>::operator T& ()
{
	static_assert(sizeof(SSImpl<T, size>) >= sizeof(T), "SImpl too small");
	return *reinterpret_cast<T*>(buf);
}
