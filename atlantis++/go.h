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
		int * father;//并查集父亲
		int * size;//并查集大小，按秩合并用
		inline int ufsFind(const int &);//非递归、有路径压缩的实现
		inline void ufsUnion(const int &, const int &);//按秩合并
		//Go
		const int rank;
		const Net & player_W;
		const Net & player_B;
		int pos_x, pos_y;//下一着位置
		bool next_color;//下一着棋色
		int * stones;//棋盘，1,2,0对应黑白空
		int * qi;//单子气
		int * qi_group;//块子气
		int total_pass;//累计弃行次数，大于等于4是AI间终局的充要条件
		map<int, bool> record;//记录已出现的棋局
		inline int * board(const int &, const int &)const;//二维转一维，直接返回地址
		inline bool checkRealEye(const int &, const int &)const;//禁止自填真眼
		inline bool checkRepeat()const;//禁全局同形
		bool badMove()const;//检查是否无故紧气（破坏双活）
		inline bool end()const;//判断是否终局
	public:
		Go(const int &);
		~Go();
		void loop();
	};
}