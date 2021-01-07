#include <iostream>
using namespace std;
//
//template<typename T>
//class CMyData
//{
//public:
//
//protected:
//	T m_Data;
//};
//
//template<typename T>
//class CMyDataEx : public CMyData<T>
//{
//public:
//	T GetData() const { return CMyData<T>::m_Data; }
//	void SetData(T param) { CMyData<T>::m_Data = param; }
//};
//
//int main()
//{
//	CMyDataEx<int> a;
//	a.SetData(5);
//	cout << a.GetData() << endl;
//
//	return 0;
//}

int main()
{

	int* pa;
	int* pb;

	pa = new int();

	*pa = 10;

	pb = pa;

	auto_ptr<int> apa (new int);
	auto_ptr<int> apb;

	*apa = 10;

	apb = apa;

}