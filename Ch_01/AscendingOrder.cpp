#include < iostream>

using namespace std;

/*
void AscendingOrder(int _aList[])
{
	for (auto n : _aList)
		cout << _aList << ' ';
	cout << endl;
}
*/

void printArray(int _aList[], int _size, int _cursor)
{
	cout << _cursor << ' ';

	for (int i = 0; i < _size; ++i)
	{
		if (i == _cursor)
			cout << '<' <<_aList[i]<< '>' <<' ';

		else
			cout << _aList[i] << ' ';
	}
	cout << endl;
}

void AscendingOrder_Selecte(int _aList[], int _size)
{
	int MinNum = numeric_limits<int>::max();
	int MinNumIndex = 0;

	for (int i = 0; i < _size; ++i)
	{
		for (int j = i; j < _size; ++j)
			if (MinNum > _aList[j]) {
				MinNum = _aList[j];
				MinNumIndex = j;
			}

		swap(_aList[i], _aList[MinNumIndex]);
		MinNum = numeric_limits<int>::max();

	}
}

void AscendingOrder_Insert(int _aList[], int _size)
{

	int cursor = 0;

	// for( int n : _aList)


	// printArray(_aList, _size, cursor);

	for (int i = 1; i < _size; ++i)
	{
		cursor = i;

		for (int j = i; j >= 1 ; --j)
		{

			if (_aList[cursor] > _aList[cursor - 1])
				break;

			if (_aList[cursor] < _aList[cursor - 1]) {
				swap(_aList[cursor], _aList[cursor - 1]);
				cursor -= 1;
				//printArray(_aList, _size, cursor);

			}

		}
	}
	
	//printArray(_aList, _size, cursor);


}

int main()
{
	int aList[5] = { 100, 20, 700, 40, 50 };

	int size = sizeof(aList) / sizeof(int);

	AscendingOrder_Insert(aList, size);

	for (int n : aList)
		cout << n << ' ';
	cout << endl;


	return 0;
}