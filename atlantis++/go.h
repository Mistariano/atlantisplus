#pragma once
#include"stdafx.h"
#include"net.h"
using std::map;
namespace atlantis
{
	class Go
	{
	private:
		//UFS
		int * father;//���鼯����
		int * size;//���鼯��С�����Ⱥϲ���
		inline int ufsFind(const int &);//�ǵݹ顢��·��ѹ����ʵ��
		inline void ufsUnion(const int &, const int &);//���Ⱥϲ�
		//Go
		const int rank;
		const Net & player_W;
		const Net & player_B;
		int pos_x, pos_y;//��һ��λ��
		bool next_color;//��һ����ɫ
		int * stones;//���̣�1,2,0��Ӧ�ڰ׿�
		int * qi;//������
		int * qi_group;//������
		int total_pass;//�ۼ����д��������ڵ���4��AI���վֵĳ�Ҫ����
		map<int, bool> record;//��¼�ѳ��ֵ����
		inline int * board(const int &, const int &)const;//��άתһά��ֱ�ӷ��ص�ַ
		inline bool checkRealEye(const int &, const int &)const;//��ֹ��������
		inline bool checkRepeat()const;//��ȫ��ͬ��
		bool badMove()const;//����Ƿ��޹ʽ������ƻ�˫�
		inline bool end()const;//�ж��Ƿ��վ�
	public:
		Go(const int &);
		~Go();
		void loop();
	};
}