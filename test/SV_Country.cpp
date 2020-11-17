#include "SV_Country.h"
#include "pch.h"

using namespace std;

SV_Country::SV_Country()
{
	name = "KOR";
	budget = 10000;
	gdp = 2000;
	taxRate = 0.10;

	policyCost = 1000;
}

void SV_Country::CollectTaxes()
{
	//�ε� �Ҽ����� ���ϱ� ���ؼ� ����ȭ �ʿ��� �κ�.
	budget = budget + static_cast <long long>  (static_cast<double> (taxRate) * gdp);
}

void SV_Country::EnforcePolicy()
{
	budget -= policyCost;
}

void SV_Country::PrintState()
{
	cout << "***Country Class***" << endl;
	cout << "name:  " << name << endl;
	cout << "budget:     " << budget << endl;
	cout << "taxRate:    " << taxRate << endl;
	cout << "policyCost: " << policyCost << endl;
}