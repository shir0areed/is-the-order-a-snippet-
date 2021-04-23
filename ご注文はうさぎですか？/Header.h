namespace Hoge
{
	class CHoge
	{
	public:
		CHoge();
		~CHoge();
		int Func(int a) const;
		class SHogeImpl;
	private:
		class SHoge
		{
		public:
			char buf[16];
			operator SHogeImpl& ();
			operator const SHogeImpl& () const { return const_cast<SHoge*>(this)->operator Hoge::CHoge::SHogeImpl &(); }
		};
		SHoge shoge;
	};
}
