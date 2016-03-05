#pragma once
#include"gene.h"
namespace atlantis
{
	class Net
	{
	private:
		float * bas;
		int * par;
		int len_bas, len_par;
	public:
		void init();
		void load(Gene *);
		float * workout(float *)const;
	};
}
