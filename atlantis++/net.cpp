#include"stdafx.h"
#include"net.h"
using namespace atlantis;
void Net::init()
{
	return;
}
void Net::load(Gene * g)
{
	init();
	Gene * gene = g;
	par = g->parameters;
	bas = g->bases;
	len_bas = g->len_bas;
	len_par = g->len_par;
}
float * Net::workout(float * inputs)const
{
	//init
	float * output;
	float * input;
	int num_cur = par[0];
	int num_last;
	int pos_bas = 0;
	float threshold;
	//sensor
	output = new float[num_cur];
	for (int i = 0; i < num_cur; i++)
	{
		output[i] = inputs[i];
	}
	//hidden & output
	for (int i = 1; i < len_par; i++)
	{
		num_last = num_cur;
		num_cur = par[i];
		input = output;
		output = new float[num_cur];
		for (int j = 0; j < num_cur; j++)
		{
			output[j] = 0;
			threshold = bas[pos_bas++];
			for (int k = 0; k < num_last; k++)
			{
				output[j]+= input[k]*bas[pos_bas++]-threshold;
			}
			output[j] = (float)(1 / (pow(2.7183, -output[j]) + 1));
		}
		delete[num_last]input;
	}
	return output;
}