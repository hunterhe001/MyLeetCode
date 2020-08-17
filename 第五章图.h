#pragma once
#include <iostream>
using namespace std;
//������ ͼ
//46.ͼ���ڽӾ����ʾ���Ľṹ����MGraph
//47.�ڽӾ����ʾ������ͼCreateMGraph()
//48.ͼ���ڽӱ��ʾ���ṹ����EdgeNode��VertexNode��ALGraph
//49.�ڽӱ���ͼCreateALGraph
//50.�����������DFS
//51.�����������BFS
//52.��Ȩͼ��Դ���·��
//53.Dijkstra�㷨

//46.ͼ���ڽӾ����ʾ���Ľṹ����MGraph

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
	cout << "����ڵ����ͱ������Կո�ֿ�" << endl;
	cin >> MG1->n >> MG1->e;
	cout << "����ڵ�:" << endl;
	for (i = 0; i < MG1->n; i++)
		cin >> MG1->Node[i];
	cout << "����ߺ�Ȩ��,��ʽΪ: i,j,w" << endl;
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


//47.�ڽӱ��ʾ������ͼCreateMGraph()
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
	cout << "������ڵ������������Կո�ֿ���" << endl;
	cin >> AL1->n >> AL1->e ;
	cout << "����ڵ���ţ��Կո�ֿ���" << endl;
	for (j = 0; j < AL1->n; j++)
	{
		cin >> AL1->MH[j].a;
		AL1->MH[j].FirstNode = NULL;
	}
		
	cout << "����ߣ���ʽ��i j" << endl;
	for (k = 0; k < AL1->e; k++)
	{
		cin >> i >> j;
		ALNode* NewNode = new(ALNode);
		NewNode->Data = j;
		NewNode->Next = AL1->MH[i].FirstNode;
		AL1->MH[i].FirstNode = NewNode;
	}
}

//50.�����������DFS
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

//51.�����������
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


//52.��Ȩͼ��Դ���·��
#include <queue>
int Dist[MAXSIZE];
int Path[MAXSIZE];
void Single_Sourse_Shottest(ALGraph* AL1, int Data)//���ݹ�������������иĶ�
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

//53.Dijkstra�㷨
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
		if (min_value < INFINITY)//����Ҫ��һ������ͨͼ���ж�
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