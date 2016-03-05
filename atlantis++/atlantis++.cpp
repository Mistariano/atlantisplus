// atlantis++.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <amp.h>
using namespace concurrency;
int MAXN = 100000;
void test_array()
{
	//��������  
	std::vector<int> data(MAXN);
	for (int count = 0; count < MAXN; count++)
	{
		data[count] = count;
	}

	//����arrayʵ��  
	array<int, 1> a(MAXN, data.begin(), data.end());

	parallel_for_each(
		a.extent,
		[=, &a](index<1> idx) restrict(amp)
		{
			a[idx] = a[idx] * 10;
		}
	);

	//arrayʵ��a����Ҫ����ͬ������  
	//������Ҫ��ֵ��data  
	data = a;

	//���0,10,20,30,40  
	for (int i = 0; i < MAXN; i++)
	{
		std::cout << data[i] << "\n";
	}
}

int main()
{
	std::ios::sync_with_stdio(0);
	//test_array();
	return 0;
}

