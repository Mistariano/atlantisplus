#pragma once
namespace atlantis
{
	class Gene
	{
	private:
		const int id;
		static int next_id;
	public:
		int len_par;
		int len_bas;
		int * parameters;
		float * bases;
		Gene(const Gene &);
		Gene(int *, float *,const int &,const int &);
		~Gene();
	};
}