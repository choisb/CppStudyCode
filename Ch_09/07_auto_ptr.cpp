//#include <memory>
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData() { cout << "CMyData()" << endl; }
	~CMyData() { cout << "~CMyData()" << endl; }
};

int main()
{
	cout << "******Begin*******" << endl;
	
	{
		//auto_ptr<CMyData> ptrTest(new CMyData);
		auto_ptr<CMyData> ptrTest(new CMyData[3]);
	}

	cout << "*******End********" << endl;

	return 0;
}