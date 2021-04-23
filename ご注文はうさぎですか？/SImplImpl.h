template<typename T, size_t size>
void Func()
{
	char temp[size]{};
	new(temp)SImpl::SSImpl<T, size>();
	reinterpret_cast<SImpl::SSImpl<T, size>*>(temp)->~SSImpl();
}

template<typename T, size_t size>
SImpl::SSImpl<T, size>::operator T& ()
{
	static_assert(sizeof(SSImpl<T, size>) >= sizeof(T), "SBuf too small");
	return *reinterpret_cast<T*>(this);
	Func<T, size>();
}

template<typename T, size_t size>
SImpl::SSImpl<T, size>::SSImpl()
{
	new(&buf)T;
}

template<typename T, size_t size>
SImpl::SSImpl<T, size>::~SSImpl()
{
	reinterpret_cast<T&>(buf).~T();
}
