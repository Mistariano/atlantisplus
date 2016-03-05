#include"stdafx.h"
#include"gene.h"
using namespace::atlantis;
using std::cout;

int Gene::next_id = 0;

Gene::Gene(const Gene & g) : 
	id(next_id++)
{
	int * par = g.parameters;
	float * bas = g.bases;
	int l_par = g.len_bas;
	int l_bas = g.len_par;
	int * res_par = new int[l_par];
	float * res_bas = new float[l_bas];
	for (int i = 0; i < l_par; i++)
	{
		res_par[i] = par[i];
	}
	for (int i = 0; i < l_bas; i++)
	{
		res_bas[i] = bas[i];
	}
	parameters = res_par;
	bases = res_bas;
	len_par = l_par;
	len_bas = l_bas;
	cout << "Gene <" << id << "> has been created.\n";
}

Gene::Gene(int * par, float * bas,const int & l_par,const int & l_bas) :
	id(next_id++)
{
	int * res_par = new int[l_par];
	float * res_bas = new float[l_bas];
	for (int i = 0; i < l_par; i++)
	{
		res_par[i] = par[i];
	}
	for (int i = 0; i < l_bas; i++)
	{
		res_bas[i] = bas[i];
	}
	parameters = res_par;
	bases = res_bas;
	len_par = l_par;
	len_bas = l_bas;
	cout << "Gene <" << id << "> has been created.\n";
}

Gene::~Gene()
{
	delete[len_par] parameters;
	delete[len_bas] bases;
	cout << "Gene <" << id << "> has been deleted.\n";
}
