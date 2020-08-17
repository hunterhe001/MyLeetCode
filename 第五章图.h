#pragma once
#include <iostream>
using namespace std;
//第五章 图
//46.图的邻接矩阵表示法的结构定义MGraph
//47.邻接矩阵表示法创建图CreateMGraph()
//48.图的邻接表表示法结构定义EdgeNode、VertexNode、ALGraph
//49.邻接表创建图CreateALGraph
//50.深度优先搜索DFS
//51.广度优先搜索BFS
//52.无权图单源最短路径
//53.Dijkstra算法

//46.图的邻接矩阵表示法的结构定义MGraph

#define MAXSIZE 100
#define INFINITY 32767
enum GT { T1, T2, T3, T4 };
struct MGraph {
	char Node[MAXSIZE];
	int Net[MAXSIZE][MAXSIZE];
	int n, e;
	enum GT gt;
};

void CreateMGraph(MGraph* MG1)
{
	int i, j, k, w = 0;
	MG1->gt = T1;
	cout << "输入节点数和边数，以空格分开" << endl;
	cin >> MG1->n >> MG1->e;
	cout << "输入节点:" << endl;
	for (i = 0; i < MG1->n; i++)
		cin >> MG1->Node[i];
	cout << "输入边和权重,格式为: i,j,w" << endl;
	for (i = 0; i < MG1->n; i++)
		for (j = 0; j < MG1->n; j++)
			MG1->Net[i][j] = INFINITY;
	for (k = 0; k < MG1->e; k++)
	{
		cin >> i >> j >> w;
		MG1->Net[i][j] = w;
		MG1->Net[j][i] = w;
	}
}


//47.邻接表表示法创建图CreateMGraph()
struct ALNode {
	int Data;
	ALNode* Next;
};

struct ALHeadNode{
	char a;
	ALNode* FirstNode;
};

struct ALGraph {
	ALHeadNode MH[MAXSIZE];
	int n, e;
};
void CreateALGraph(ALGraph* AL1)
{
	int i, j, k;
	cout << "请输入节点数及边数，以空格分开：" << endl;
	cin >> AL1->n >> AL1->e ;
	cout << "输入节点代号，以空格分开：" << endl;
	for (j = 0; j < AL1->n; j++)
	{
		cin >> AL1->MH[j].a;
		AL1->MH[j].FirstNode = NULL;
	}
		
	cout << "输入边，格式：i j" << endl;
	for (k = 0; k < AL1->e; k++)
	{
		cin >> i >> j;
		ALNode* NewNode = new(ALNode);
		NewNode->Data = j;
		NewNode->Next = AL1->MH[i].FirstNode;
		AL1->MH[i].FirstNode = NewNode;
	}
}

//50.深度优先搜索DFS
bool Visited[MAXSIZE] = { false };
void DFS(ALGraph* AL1, int Data)
{
	Visited[Data] = true;
	cout << AL1->MH[Data].a << '\t';
	ALNode* W = new(ALNode);
	for (W = AL1->MH[Data].FirstNode; W; W = W->Next)
	{
		if (!Visited[W->Data])
		{
			DFS(AL1, W->Data);
		}
	}
}

//51.广度优先搜索
#include <queue>
void BFS(ALGraph* AL1, int Data)
{
	int tmp;
	ALNode* W = new(ALNode);
	queue<int> Q;
	Q.push(Data);
	while (!Q.empty())
	{
		tmp = Q.front();
		if (!Visited[tmp])
		{
			Visited[tmp] = true;
			cout << AL1->MH[tmp].a << ' ';
			for (W = AL1->MH[tmp].FirstNode; W; W = W->Next)
			{
				if (!Visited[W->Data])
					Q.push(W->Data);
			}
		}
		Q.pop();
		
	}
}


//52.无权图单源最短路径
#include <queue>
int Dist[MAXSIZE];
int Path[MAXSIZE];
void Single_Sourse_Shottest(ALGraph* AL1, int Data)//根据广度优先搜索进行改动
{
	for (int mm = 0; mm < AL1->n; mm++)
		Dist[mm] = -1;
	Path[Data] = -1;
	Dist[Data] = 0;
	//Path[Data] = Data;
	int tmp;
	ALNode* W = new(ALNode);
	queue<int> Q;
	Q.push(Data);
	while (!Q.empty())
	{
		tmp = Q.front();
		if (!Visited[tmp])
		{
			Visited[tmp] = true;
			cout << AL1->MH[tmp].a << ' ';
			for (W = AL1->MH[tmp].FirstNode; W; W = W->Next)
			{
				if (!Visited[W->Data])
				{
					Q.push(W->Data);
					if (Dist[W->Data] == -1)
						Dist[W->Data] = Dist[tmp] + 1;
					Path[W->Data] = tmp;
				}
					
			}
		}
		Q.pop();

	}
}

//53.Dijkstra算法
int Final[MAXSIZE];
void Dijkstra(MGraph* M1, int ith)
{
	int i;
	for (i = 0; i < M1->n; i++)
	{
		Dist[i] = INFINITY;
		Final[i] = false;
	}
	Dist[ith] = 0;
	Path[ith] = -1;
	Final[ith] = true;
	int j = M1->n;
	int tmp;
	while (j)
	{
		int min_value = INFINITY;
		int min_loc = 0;
		for (i = 0; i < M1->n; i++)
		{
			if (Final[i] != true)
			{
				if (M1->Net[ith][i] != INFINITY)
				{
					tmp = Dist[ith] + M1->Net[ith][i];
					if (tmp < Dist[i])
					{
						Dist[i] = tmp;
					}
				}
				if (Dist[i] < min_value)
				{
					min_value = Dist[i];
					min_loc = i;
				}
			}
		}
		//cout << min_value << ' ';
		if (min_value < INFINITY)//这里要有一个非连通图的判断
		{
			Final[min_loc] = true;
			ith = min_loc;
		}
		else {
			break;
		}
		
		j--;
	}
}