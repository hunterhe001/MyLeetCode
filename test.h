#pragma once
using namespace std;
#include <iostream>
#define max_num 100
#include <stack>
#include <queue>

struct Graph1
{
	char a[max_num];
	int b[max_num][max_num];
	int n, e;
};

void CreatG1(Graph1* G1)//什么时候需要malloc
{
	int n, e;
	int i, j;
	char ct;
	cout << "有几个顶点和边，请按照 顶点数 边数的格式输入" << endl;
	cin >> n;
	cin >> e;
	G1->n = n;
	G1->e = e;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			G1->b[i][j] = 0;
	cout << "输入顶点字符,空格分开" << endl;
	for (i = 0; i < e; i++) {
		cin >> ct;
		G1->a[i] = ct;
	}
	cout << "输入边，格式为 i j" << endl;
	for (int k = 0; k < e; k++) {
		cin >> i >> j;
		G1->b[i][j] = 1;
	}
	/*int i, j;
	Graph1* G1;
	G1 = (Graph1*)malloc(sizeof(struct Graph1));
	CreatG1(G1);
	for (i = 0; i < G1->n; i++)
		for (j = 0; j < G1->n; j++)
			cout << G1->b[i][j] << "  ";
	return 0;*/
}


struct HeadV {
	char Nodename;
	struct NodeV* FirstNode;
};
struct NodeV {
	int VertexN;
	struct NodeV* Next;
};
struct Graph2 {
	int n, e;
	HeadV Head[max_num];
};
void CreatGraph2(Graph2* G2)
{
	int n, e;
	int i, j, k;
	cout << "输入顶点数和边数，空格分开：";
	cin >> n >> e;
	G2->n = n;
	G2->e = e;
	cout << "输入顶点代号，空格分开：";
	for (i = 0; i < n; i++) {
		cin >> G2->Head[i].Nodename;
		G2->Head[i].FirstNode = NULL;
	}
	cout << "输入边，格式：i j";
	for (k = 0; k < e; k++)
	{
		cin >> i >> j;
		NodeV* newnode;
		newnode = (NodeV*)malloc(sizeof(struct NodeV));
		newnode->VertexN = j;
		newnode->Next = G2->Head[i].FirstNode;
		G2->Head[i].FirstNode = newnode;
	}

}




//深度优先搜索

bool visited[max_num] = { false };

void DFS(Graph2* G2, int ith)
{
	visited[ith] = true;
	NodeV* W;
	for (W = G2->Head[ith].FirstNode; W; W = W->Next)
	{
		if (!visited[W->VertexN])
			DFS(G2, W->VertexN);
	}

}
int i, j;
//Graph2* G2;
//G2 = (Graph2*)malloc(sizeof(struct Graph2));
//CreatGraph2(G2);






int sum = 0;
void hannuo(int n, char A, char B, char C)//汉诺塔
{
	if (n == 1) {
		cout << "从" << A << "拿一个金片到" << C << endl;
		sum = sum + 1;
		cout << "第" << sum << "步" << endl;
	}
	else {
		hannuo(n - 1, A, C, B);
		cout << "从" << A << "拿一个金片到" << C << endl;
		sum = sum + 1;
		cout << "第" << sum << "步" << endl;
		hannuo(n - 1, B, A, C);

		/*int sum = 0, n = 15;
		char A = 'A', B = 'B', C = 'C';
		hannuo(n, A, B, C);*/
	}
}




struct Node {
	int a;
	Node* Next;
};//1.

int Length(Node* Ptr)
{
	Node* P = Ptr;
	int Length = 0;
	while (P)
	{
		P = P->Next;
		Length++;
	}
	return Length;
	//cout << "表长 = "<< Length(node1) << endl;
}//2.


Node* Find(Node* node, int K)
{
	Node* P = node;
	while (P)
	{
		if (P->a == K)
			return P;

		P = P->Next;
	}
	return NULL;
	//	Node* nodet = Find(node1, 8);
	//  cout << nodet->a << endl;
}//4.

Node* FindKth(Node* node, int K)
{
	Node* P = node;
	int i = 0;
	while (P != NULL && i < K)
	{
		P = P->Next;
		i++;
	}
	if (i == K) return P;
	else return NULL;
	//	Node* nodet = Find(node1, 8);
	//  cout << nodet->a << endl;
}//3.

Node* Insert(Node* node, int K, int Value)//这个注意K == 1的情况
{
	Node* P = new Node;
	if (K == 1)
	{
		P->a = Value;
		P->Next = node;
		return P;
	}
	Node* T = FindKth(node, K - 1);
	if (T)
	{
		P->a = Value;
		P->Next = T->Next;
		T->Next = P;
		return P;
	}
	else
		return NULL;
}//5.

Node* Delete(Node* P, int i)
{
	Node* temp = new Node;
	Node* P1 = new Node;
	if (i == 1)
	{
		temp = P;
		P = P->Next;
		delete(temp);
		return P;
	}
	P1 = Find(P, i - 1);
	if (P1 == NULL) {
		cout << "第" << i - 1 << "个节点不存在";
		return NULL;
	}
	else if (P1->Next == NULL) {
		cout << "第" << i << "个节点不存在";
		return NULL;
	}
	else {
		temp = P1->Next;
		P1->Next = temp->Next;
		delete(temp);
		return P;
		/*Delete(node1, 2);
		Print(node1);*/
	}
}//6.

void Print(Node* P)
{
	int i = 0;
	while (P)
	{
		cout << "第" << i++ << "个节点存储的值为：" << P->a << endl;
		P = P->Next;
	}
}//7.

#define MaxSize 100
#define ERROR -10000
struct Stack1 {
	int Data[MaxSize];
	int Top;
};//8.

void Push1(Stack1* PtrS, int item)
{
	if (PtrS->Top >= MaxSize - 1)
	{
		cout << "堆栈满！";
		return;
	}
	else {
		PtrS->Data[++(PtrS->Top)] = item;
		return;
	}
}//9.
int Pop1(Stack1* PtrS)
{
	if (PtrS->Top <= 0)
	{
		cout << "堆栈空！";
		return ERROR;
	}
	else {
		return PtrS->Data[(PtrS->Top)--];
	}
}//10.

struct Stack2 {
	int Data;
	Stack2* Next;
};//11.

Stack2* CreakStack()
{
	Stack2* PtrS = new(Stack2);
	PtrS->Next = NULL;
	return PtrS;
}//12.注意这里的PtrS是一个指向堆栈顶的头指针，它是一个头指针，里面没有堆栈的数据

bool IsEmpty(Stack2* PtrS)
{
	return (PtrS->Next == NULL);
}

void Push2(Stack2* PtrS, int item)
{
	Stack2* P = new(Stack2);
	P->Data = item;
	P->Next = PtrS->Next;
	PtrS->Next = P;
}//13.
int Pop2(Stack2* PtrS)
{
	Stack2* temp = new(Stack2);
	int data;
	if (IsEmpty(PtrS))
	{
		cout << "堆栈空！";
		return NULL;
	}
	else {
		temp = PtrS->Next;
		data = temp->Data;
		PtrS->Next = temp->Next;
		delete(temp);
		return data;
	}
}//14.注意判断是否为空

struct Queue {
	int Data[MaxSize];
	int Top = 0;
	int Tail = 0;
};//15.
void InsertQ(Queue* Q, int item)
{
	if ((Q->Tail + 1) % MaxSize == Q->Top) {
		cout << "队列满！";
		return;
	}
	Q->Tail = (Q->Tail + 1) % MaxSize;
	Q->Data[Q->Tail] = item;
}//16.
int PopQ(Queue* PtrQ)
{
	if (PtrQ->Tail == PtrQ->Top) {
		cout << "队列空！";
		return ERROR;
	}
	int data;
	data = PtrQ->Data[PtrQ->Top];
	PtrQ->Top = (PtrQ->Top + 1) % MaxSize;
	return data;
}//17.

struct NodeQ {
	int Data;
	NodeQ* Next;
};//18.

struct LinkQ {
	NodeQ* front;
	NodeQ* rear;
};//18.

int DeleteLQ(LinkQ* LQ)
{
	NodeQ* TempCell;
	int data;
	if (LQ->front == NULL)
	{
		cout << "队列空！";
		return ERROR;
	}
	if (LQ->front == LQ->rear)
	{
		data = LQ->front->Data;
		LQ->front = NULL;
		LQ->rear = NULL;
		return data;
	}

	TempCell = LQ->front;
	data = TempCell->Data;
	LQ->front = TempCell->Next;
	delete(TempCell);
	return data;
}//20.注意队列空的情况，链表头为队列front，尾为队列rear，反过来不行
void AddLQ(LinkQ* LQ, int item)
{
	NodeQ* newitem = new(NodeQ);
	newitem->Data = item;
	newitem->Next = NULL;
	LQ->rear->Next = newitem;
	LQ->rear = newitem;
}//19.

struct TreeNode {
	int Data;
	TreeNode* Left;
	TreeNode* Right;
};//21.

void MidR(TreeNode* BinTree)
{
	if (BinTree == NULL) {
		return;
	}
	MidR(BinTree->Left);
	cout << BinTree->Data;
	MidR(BinTree->Right);
}//22.
void PreT(TreeNode* BinTree)
{
	if (BinTree) {
		cout << BinTree->Data;
		PreT(BinTree->Left);
		PreT(BinTree->Right);
	}
}//23.
void PostT(TreeNode* BinTree)
{
	if (BinTree) {
		cout << BinTree->Data;
		PreT(BinTree->Left);
		PreT(BinTree->Right);
	}
}//24.


void MidOrderT(TreeNode* BinTree)
{
	stack<TreeNode*> S1;
	TreeNode* T1 = BinTree;
	while (!S1.empty() || T1)//注意这里是或
	{
		while (T1) {
			S1.push(T1);
			T1 = T1->Left;
		}
		T1 = S1.top();
		S1.pop();
		cout << T1->Data << endl;
		T1 = T1->Right;
	}

}//25.注意是用堆栈实现

void LayerT(TreeNode* BinTree)
{
	queue<TreeNode*> QB;
	TreeNode* T1 = BinTree;
	if (!T1) return;//注意判断空
	QB.push(T1);
	while (!QB.empty())
	{
		T1 = QB.front();
		QB.pop();
		cout << T1->Data << endl;;
		if (T1->Left)
			QB.push(T1->Left);
		if (T1->Right)
			QB.push(T1->Right);
	}
}//26.

void LeafOut(TreeNode* BinTree)
{
	queue<TreeNode*> QB;
	TreeNode* T1 = BinTree;
	if (!T1) return;//注意判断空
	QB.push(T1);
	while (!QB.empty())
	{
		T1 = QB.front();
		QB.pop();
		if (T1->Left == NULL && T1->Right == NULL)
		{
			cout << T1->Data << endl;
		}
		else
		{
			if (T1->Left)
				QB.push(T1->Left);
			if (T1->Right)
				QB.push(T1->Right);
		}
	}
}//27.
int Max2(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}
int PostHeight(TreeNode* BinTree)
{
	int Height = 0;
	TreeNode* T = BinTree;
	if (T)
	{
		return Max2(PostHeight(T->Left), PostHeight(T->Right)) + 1;
	}
	return 0;
}//28.

TreeNode* Find(TreeNode* BinTree, int Value)
{
	if (BinTree)
	{
		if (BinTree->Data == Value)
			return BinTree;
		else if (BinTree->Data > Value)
			return Find(BinTree->Left, Value);
		else
			return Find(BinTree->Right, Value);
	}
	return NULL;
}//29.

TreeNode* IterFind(TreeNode* BinTree, int Value)
{
	while (BinTree)
	{
		if (BinTree->Data == Value)
			return BinTree;
		else if (BinTree->Data > Value)
			BinTree = BinTree->Left;
		else
			BinTree = BinTree->Right;
	}
	return NULL;
}

TreeNode* FindBinTreeMax(TreeNode* BinTree)
{
	if (BinTree) {//注意这里要判断BinTree是否为空否则while语句会报错
		while (BinTree->Right)
		{
			BinTree = BinTree->Right;
		}
	}
	return BinTree;
}//31.

TreeNode* FindBinTreeMin(TreeNode* BinTree)
{
	if (BinTree) {
		while (BinTree->Left)
		{
			BinTree = BinTree->Left;
		}
	}
	return BinTree;
}//32.
TreeNode* InsertBinTree(TreeNode* BinTree, int Value)
{
	if (!BinTree)
	{
		BinTree = new(TreeNode);
		BinTree->Data = Value;
		BinTree->Left = NULL;
		BinTree->Right = NULL;
	}
	else
	{
		if (Value > BinTree->Data)
			BinTree->Right = InsertBinTree(BinTree->Right, Value);
		else if (Value < BinTree->Data)
			BinTree->Left = InsertBinTree(BinTree->Left, Value);
	}
	return BinTree;//注意这里最终返回的是根节点
}//33.递归方法实现（）

TreeNode* DeleteBinTree(TreeNode* BinTree, int Value)
{
	TreeNode* Tmp;
	if (!BinTree)
	{
		cout << "未找到！";
	}
	else
	{
		if (Value > BinTree->Data)
			BinTree->Right = DeleteBinTree(BinTree->Right, Value);
		else
			if (Value < BinTree->Data)
				BinTree->Left = DeleteBinTree(BinTree->Left, Value);
			else
			{
				if (BinTree->Left && BinTree->Right) {
					Tmp = FindBinTreeMin(BinTree->Right);
					BinTree->Data = Tmp->Data;
					BinTree->Right = DeleteBinTree(BinTree->Right, BinTree->Data);
				}

				else {
					Tmp = BinTree;
					if (!BinTree->Left)
						BinTree = BinTree->Right;
					else if (!BinTree->Right)
						BinTree = BinTree->Left;
					free(Tmp);
				}
			}
	}
	return BinTree;
}//34.()

struct AVLTreeNode {
	int Data;
	AVLTreeNode* Left;
	AVLTreeNode* Right;
	int Height;
};//35.

int AVLTreeHeight(AVLTreeNode* AVLTree)
{
	int Height = 0;
	AVLTreeNode* T = AVLTree;
	if (T)
	{
		return Max2(AVLTreeHeight(T->Left), AVLTreeHeight(T->Right)) + 1;
	}
	return 0;
}//41.
AVLTreeNode* SingleLeftRotation(AVLTreeNode* TreeNode)
{
	AVLTreeNode* A = TreeNode;
	AVLTreeNode* B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = AVLTreeHeight(A);
	B->Height = AVLTreeHeight(B);
	return B;
}//36.

AVLTreeNode* SingleRightRotation(AVLTreeNode* TreeNode)
{
	AVLTreeNode* A = TreeNode;
	AVLTreeNode* B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = AVLTreeHeight(A);
	B->Height = AVLTreeHeight(B);
	return B;
}//37.

AVLTreeNode* DoubleLeftRightRotation(AVLTreeNode* TreeNode)
{
	AVLTreeNode* A = TreeNode;
	A->Left = SingleRightRotation(A->Left);
	return SingleLeftRotation(A);//书上这里不严谨，没有对A,B的Height做处理，Insert里面才做
}//38.

AVLTreeNode* DoubleRightLeftRotation(AVLTreeNode* TreeNode)
{
	AVLTreeNode* A = TreeNode;
	A->Right = SingleLeftRotation(A->Right);
	return SingleRightRotation(A);//书上这里不严谨，没有对A,B的Height做处理，Insert里面才做
}//39.

AVLTreeNode* AVLInsertion(int Data, AVLTreeNode* A)
{
	if (A == NULL)
	{
		A = new(AVLTreeNode);
		A->Data = Data;
		A->Left = NULL;
		A->Right = NULL;
	}
	else if (Data < A->Data) {
		A->Left = AVLInsertion(Data, A->Left);
		if (AVLTreeHeight(A->Left) - AVLTreeHeight(A->Right) == 2)
			if (Data < A->Left->Data)
				A->Left = SingleLeftRotation(A->Left);
			else
				A->Left = DoubleLeftRightRotation(A->Right);
	}
	else if (Data > A->Data) {
		A->Right = AVLInsertion(Data, A->Right);
		if (AVLTreeHeight(A->Left) - AVLTreeHeight(A->Right) == -2)
			if (Data > A->Right->Data)
				A->Right = SingleRightRotation(A->Right);
			else
				A->Right = DoubleRightLeftRotation(A->Right);
	}
	A->Height = AVLTreeHeight(A);
	return A;
}//40.

struct MaxHeap {
	int Size;
	int* Elements;
	int Capacity;
};//42.
#define MaxData 10000
MaxHeap* MaxHeapCreat(int Size)
{
	MaxHeap* H = new(MaxHeap);
	H->Elements = new int[Size];
	H->Size = 0;
	H->Capacity = Size;
	H->Elements[0] = MaxData;
	return H;
}//43.

MaxHeap* MaxHeapInsert(int Data, MaxHeap* H)
{
	if (H->Capacity == H->Size)
	{
		cout << "堆已满，无法插入！" << endl;
		return NULL;
	}
	int i = ++H->Size;
	for (; H->Elements[i / 2] < Data; i /= 2)
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i] = Data;
	return H;
}//44.

int MaxHeapDelete(MaxHeap* H)
{
	if (H->Size == 0)
	{
		cout << "堆为空！" << endl;
		return -10000;
	}
	int child, parent;
	int MaxItem = H->Elements[1];
	int Data = H->Elements[H->Size--];//H->Elements[0]初始化了最大值，后面还有Size个数据，所以最后一个数是H->Elements[Size]
	int i = --H->Size;
	for (parent = 1; parent * 2 <= H->Size; parent = child) {
		child = parent * 2;
		if ((child * 2 != H->Size) && (H->Elements[child] < H->Elements[child + 1]))
			child++;
		if (Data > H->Elements[child])
			break;
		else
			H->Elements[parent] = H->Elements[child];
	}
	H->Elements[parent] = Data;
	return Data;
}//45.这个没写出

enum GraphType { DG, UG, DN, UN };
struct MGraph {
	char Vertices[100];
	int Edges[100][100];
	int n, e;
	enum GraphType Gtype;
};//46.

void CreatMGraph(MGraph* G)
{
	int i, j, k, w = 0;
	cout << "输入顶点数和边数,以逗号分开" << endl;
	cin >> G->n, G->e;
	G->Gtype = UN;
	cout << "输入顶点信息：" << endl;
	for (i = 0; i < G->n; i++)
		cin >> G->Vertices[i];
	for (i = 0; i < G->n; i++)
		for (j = 0; j < G->n; j++)
			G->Edges[i][j] = 65535;
	cout << "输入每条边对应的顶点号和权值，输入格式: i, j, w" << endl;
	for (k = 0; k < G->e; k++) {
		cin >> i, j, w;
		G->Edges[i][j] = w;
	}
}//47.

struct EdgeNode {
	int AdjV;
	EdgeNode* Next;
};
struct VertexNode {
	char Vertex;
	EdgeNode* FirstEdge;
};
struct ALGraph {
	VertexNode Adjlist[100];
	int n, e;
	enum GraphType GType;
};//48.
void CreateALGraph(ALGraph* G)
{
	EdgeNode* edge;
	int i = 0, j = 0, k;
	G->GType = DG;
	cout << "输入顶点数和边数，以逗号分开：" << endl;
	cin >> G->n, G->e;
	cout << "输入顶点代号，以空格分开：";
	for (i = 0; i < G->n; i++) {
		cin >> G->Adjlist[i].Vertex;
		G->Adjlist[i].FirstEdge = NULL;
	}
	cout << "输入边的信息，格式为i, j:";
	for (k = 0; k < G->e; k++)
	{
		cin >> i, j;
		edge = new(EdgeNode);
		edge->AdjV = j;
		edge->Next = G->Adjlist[i].FirstEdge;
		G->Adjlist[i].FirstEdge = edge;
	}
}//49.
bool Visited[100] = { false };
void DFS(ALGraph* G, int i)
{
	EdgeNode* W;
	cout << G->Adjlist[i].Vertex;
	Visited[i] = true;
	for (W = G->Adjlist[i].FirstEdge; W; W = W->Next)
	{
		if (!Visited[W->AdjV])
			DFS(G, W->AdjV);
	}
}//50.
void DFS_ALG(ALGraph* G)
{
	int i;
	for (i = 0; i < G->n; i++)
		Visited[i] = false;
	for (i = 0; i < G->n; i++)
		if (!Visited[i])
			DFS(G, i);
}//50.

void BFS(ALGraph* G)
{
	queue<int> Q;
	int U, V;
	EdgeNode* W;
	for (U = 0; U < G->n; U++)
		Visited[U] = false;
	for (U = 0; U < G->n; U++)
		if (!Visited[U])
		{
			Visited[U] = true;
			cout << G->Adjlist[U].Vertex << endl;//访问U
			Q.push(U);
			while (!Q.empty()) {
				V = Q.front();
				Q.pop();
				for (W = G->Adjlist[V].FirstEdge; W; W = W->Next)
					if (!Visited[W->AdjV])
					{
						Visited[W->AdjV] = true;
						cout << G->Adjlist[W->AdjV].Vertex << endl;
						Q.push(W->AdjV);
					}
			}
		}
}//51.
#define INFINITY 65535
void Dijkstra(MGraph G, int v0, int* P, int* D)
{
	int Final[100], v = 0, w = 0, i, min;
	for (i = 0; v < G.n; v++)
		if (D[w] < INFINITY)
			P[w] = v0;
	D[v0] = 0;
	Final[v0] = true;
	for (i = 0; i < G.n; i++)
	{
		min = INFINITY;
		for (w = 0; w < G.n; w++)
		{
			if (!Final[w])
			{
				if (D[w] < min)
				{
					v = w;
					min = D[w];
				}
			}
		}
		if (min < INFINITY)
			Final[v] = true;
		else
			break;
		for (w = 0; w < G.n; w++)
			if (!Final[w] && (min + G.Edges[v][w] < D[w]))
			{
				D[w] = min + G.Edges[v][w];
				P[w] = v;
			}
	}
}




void Dijkstram(MGraph G, int v0, int* D, int* P)
{
	bool Final[100] = { false };
	int i, j, k;
	for (i = 0; i < G.n; i++)
	{
		D[i] = G.Edges[v0][i];
		if (D[i] < INFINITY)
			P[i] = v0;
	}
	Final[v0] = true;
	D[v0] = 0;

	for (i = 0; i < G.n; i++)
	{
		int min = INFINITY;
		for (j = 0; j < G.n; j++)
		{
			if (!Final[j])
				if (D[j] < INFINITY)
				{
					min = D[j];
					k = j;
				}
		}
		if (min < INFINITY)
		{
			Final[k] = true;
		}
		for (j = 0; j < G.n; j++)
		{
			if (!Final[j] && min + G.Edges[k][j] < D[j])
			{
				D[j] = min + G.Edges[k][j];
				P[j] = k;
			}
		}

	}
}

void Bubble_Sort(int A[], int n)
{
	int i, j, temp, flag;
	for (i = n - 1; i >= 0; i--)
	{
		flag = 0;
		for (j = 0; j < i; j++)
		{
			if (A[j] > A[j + 1])
			{
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}//53.
void Insertion_Sort(int A[], int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		temp = A[i];
		for (j = i; j > 0 && A[j - 1] > temp; j--)
		{
			A[j] = A[j - 1];
		}
		A[j] = temp;
	}
}//54.

void Selection_Sort(int A[], int n)
{
	int i, j, k, min, temp;
	for (i = 0; i < n; i++)
	{
		min = A[i];
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (A[j] < min)
			{
				min = A[j];
				k = j;
			}
		}
		temp = A[k];
		A[k] = A[i];
		A[i] = temp;
	}
}//55.

void Adjust(int A[], int i, int N)
{
	int temp, child;
	//temp = A[i];
	for (temp = A[i]; 2 * i + 1 < N; i = child)
	{
		child = 2 * i + 1;//这里与最大堆的以1为起始下标区别，2i+1，2i+2；最大堆的是2i，2i+1。
		if (child < N - 1 && A[child] < A[child + 1])
			child++;
		if (temp > A[child])
			A[i] = A[child];
		else
			break;
	}
	A[i] = temp;
}

void HeapSort(int A[], int N)
{
	//Adjust(A, 0, N);
	int i, temp;
	for (i = (N - 1) / 2; i > 0; i--)
		Adjust(A, i, N);
	for (i = N - 1; i > 0; i--)
	{
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		Adjust(A, 0, i);
	}
}//57.


void merge(int A[], int TmpA[], int L, int R, int RightEnd)
{
	int LeftEnd = R - 1;
	int i = L, j = R, k = L, l;
	while (i <= LeftEnd && j <= RightEnd)
	{
		if (A[i] <= A[j])
		{
			TmpA[k++] = A[i++];
		}
		else
		{
			TmpA[k++] = A[j++];
		}
	}
	while (i <= LeftEnd)
	{
		TmpA[k++] = A[i++];
	}
	while (j <= RightEnd)
	{
		TmpA[k++] = A[j++];
	}
	for (l = RightEnd - L; l >= 0; l--, RightEnd--)
		A[RightEnd] = TmpA[RightEnd];
}


void merge_sort(int A[], int TmpA[], int L, int R)
{
	if (L >= R)
		return;
	int middle = (L + R) / 2;
	merge_sort(A, TmpA, L, middle);
	merge_sort(A, TmpA, middle + 1, R);
	merge(A, TmpA, L, middle + 1, R);
}

void MergeSort(int A[], int n)
{
	//int* TmpA;
	//TmpA = (int*)(malloc(n * sizeof(int)));
	int* TmpA = new int[n];
	merge_sort(A, TmpA, 0, n - 1);
	delete(TmpA);
}//58.

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Quick_Sort(int A[], int Low, int High)
{
	if (Low >= High)
		return;
	int Left = Low;
	int Right = High;
	int privot = A[Low];
	Swap(&A[Low], &A[Right]);
	while (1)
	{
		while ((Left < High) && (A[Left] <= privot)) Left++;
		while ((Left < High) && (A[Right] >= privot)) Right--;
		if (Left < Right)
			Swap(&A[Left], &A[Right]);
		else
			break;
	}
	Swap(&A[High], &A[Left]);
	Quick_Sort(A, Low, Left - 1);
	Quick_Sort(A, Left + 1, High);
}

void QuickSort(int A[], int n)
{
	Quick_Sort(A, 0, n - 1);
}
