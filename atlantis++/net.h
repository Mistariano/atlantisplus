#pragma once
namespace atlantis
{
	//��������˽ṹ����һ�������޻�ͼ
	class NetStruct
	{
	private:
		int id;//�ṹ�ı��
		static int next_id;
		int size_node;//�ýṹ�нڵ���Ŀ
		int size_edge;//�ýṹ�ı���
		std::pair<int,int> * edges;//�ڽӱ�
	public:
		NetStruct(const int &,const int &, std::pair<int, int> *);
		~NetStruct();
	};
	int NetStruct::next_id = 0;

	//�����Ȩֵ������Ӧ�ṹ��dfs������
	class NetGene
	{
	private:
		int id;//���
		int * values;//����Ȩֵ����ֵ
		int len;//values�ĳ���
		static int next_id;
	public:
		NetGene();
		~NetGene();
	};
	int NetGene::next_id = 0;
	
	//һ������
	class Net
	{
	private:
		NetGene gene;
		int struct_id;
	};
}
