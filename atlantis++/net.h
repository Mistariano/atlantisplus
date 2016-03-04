#pragma once
namespace atlantis
{
	//网络的拓扑结构，是一张有向无环图
	class NetStruct
	{
	private:
		int id;//结构的编号
		static int next_id;
		int size_node;//该结构中节点数目
		int size_edge;//该结构的边数
		std::pair<int,int> * edges;//邻接表
	public:
		NetStruct(const int &,const int &, std::pair<int, int> *);
		~NetStruct();
	};
	int NetStruct::next_id = 0;

	//网络的权值表，按对应结构的dfs序排列
	class NetGene
	{
	private:
		int id;//编号
		int * values;//包括权值与阈值
		int len;//values的长度
		static int next_id;
	public:
		NetGene();
		~NetGene();
	};
	int NetGene::next_id = 0;
	
	//一个网络
	class Net
	{
	private:
		NetGene gene;
		int struct_id;
	};
}
