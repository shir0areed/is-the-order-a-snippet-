template<typename T, size_t size>
int Func()
{
	char temp[size]{};
	new(temp)SImpl::SSImpl<T, size>;
	reinterpret_cast<SImpl::SSImpl<T, size>*>(temp)->~SSImpl();
	return 0;
}

template<typename T, size_t size>
SImpl::SSImpl<T, size>::operator T& ()
{
	//static int a = Func<T, size>();
	static_assert(sizeof(SSImpl<T, size>) >= sizeof(T), "SImpl too small");
	return *reinterpret_cast<T*>(this);
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
