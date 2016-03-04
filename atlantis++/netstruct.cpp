#include"stdafx.h"
#include"net.h"
using namespace atlantis;
using std::cout;
using std::endl;

NetStruct::NetStruct
(
	const int & s_n, 
	const int & s_e, 
	std::pair<int, int> * e
)
{
	id = next_id++;
	size_node = s_n;
	size_edge = s_e;
	edges = new std::pair<int, int>[s_e];
	for (int i = 0; i < s_e; i++)
	{
		edges[i] = e[i];
	}
	cout << "Struct " << id << " has been created.\n";
}

NetStruct::~NetStruct()
{
	delete[size_edge] edges;
	cout << "Struct " << id << " has been deleted.\n";
}
