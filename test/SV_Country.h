#pragma once
#include "pch.h"
class SV_Country {
private:
	std::string name;
	long long budget;
	long long gdp;
	float taxRate;

	long long policyCost;

public:
	SV_Country();
	/// <summary>
	/// CollectTaxes(): ���� ¡�� �Լ�. ���� �ð� �� ���� ����Ͽ� ���꿡 �ݿ�
	/// </summary>
	void CollectTaxes();
	/// <summary>
	/// DoPolicy(): ��å�����Լ�. ��å ����� ����Ͽ� ���� ���꿡 û��.
	/// </summary>
	void EnforcePolicy();

	/// <summary>
	/// PrintState(): ����� ��Ʃ��� ����ȯ�濡�� Ȱ���ϴ� ����ſ� print �Լ�.
	/// consol�� country�� ���¸� ����Ѵ�.
	/// </summary>
	void PrintState();
};