#include "SV_Country.h"

int main()
{
	SV_Country* Kor;

	Kor = new SV_Country();

	Kor->CollectTaxes();
	Kor->PrintState();
	Kor->CollectTaxes();
	Kor->PrintState();
	Kor->CollectTaxes();
	Kor->PrintState();
	Kor->CollectTaxes();
	Kor->PrintState();

	delete Kor;

	return 0;
}