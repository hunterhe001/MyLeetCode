#pragma once
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//������
//������
//21.�������������ʾTreeNode
//22.�������ݹ��������
//23.�������ݹ��������
//24.�������ݹ�������
//25.�������ķǵݹ��������
//26.�������Ĳ������
//27.�����������Ҷ�ڵ�
//28.��������߶�
//����������
//29.��������������Find�ݹ�
//30.�������������ҷǵݹ�IterFind
//31.�������ֵFindBinTreeMax
//32.������СֵFindBinTreeMin
//33.��������InsertBinTree
//34.ɾ������DeleteBinTree
//ƽ�������
//35.ƽ���������㶨��AVLTreeNode
//36.LL��תSingleLeftRotation
//37.RR��תSingleRightRotation
//38.LR��תDoubleLeftRightRotation
//39.RL��תDoubleRightLeftRotation
//40.ƽ��������Ĳ���AVLInsertion
//41.ƽ��������ĸ߶�
//��
//42.���ѵĽṹ����MaxHeap
//43.���ѽ���MaxHeapCreat
//44.���ѵĲ���MaxHeapInsert
//45.���ѵ�ɾ��MaxHeapDelete


//21.�������������ʾTreeNode
struct TreeNode {
	TreeNode* Left;
	TreeNode* Right;
	int Data;
};
//22.�������ݹ��������
void MiddlePrint(TreeNode* T1)
{
	if (T1 == NULL)
		return;
	MiddlePrint(T1->Left);
	cout << T1->Data << "\t";
	MiddlePrint(T1->Right);
}

//23.�������ݹ��������
void FrontPrint(TreeNode* T1)
{
	if (T1 == NULL)
		return;
	cout << T1->Data << "\t";
	FrontPrint(T1->Left);
	FrontPrint(T1->Right);
}

//24.�������ݹ�������
void LastPrint(TreeNode* T1)
{
	if (T1 == NULL)
		return;
	LastPrint(T1->Left);
	LastPrint(T1->Right);
	cout << T1->Data << "\t";
}

//25.�������ķǵݹ��������
void MiddlePrint_Norecursive(TreeNode* T1)//�ö�ջ
{
 	if (T1 == NULL)
	{
		cout << "��Ϊ�գ�";
	}
	stack<TreeNode*> S1;
	S1.push(T1);
	T1 = T1->Left;
	while (S1.empty() == 0 || T1 != NULL)
	{
		if (T1 != NULL)
		{
			S1.push(T1);
			T1 = T1->Left;
		}
		else {
			cout << (S1.top())->Data << '\t';
			T1 = (S1.top())->Right;
			S1.pop();
			//if (T1 != NULL)
			//	S1.push(T1);
		}
		
	}
}

//26.�������Ĳ������
void LayerPrintBinTree(TreeNode* T1)
{
	queue<TreeNode*> Q1;
	TreeNode* tmp = new(TreeNode);
	if (T1 == NULL)
	{
		cout << "��Ϊ�գ�";
		return;
	}
	Q1.push(T1);
	while (!Q1.empty())
	{
		cout << Q1.front()->Data << '\t';
		tmp = Q1.front();
		Q1.pop();
		if (tmp->Left != NULL)
		{
			Q1.push(tmp->Left);
		}
		if (tmp->Right != NULL)
		{
			Q1.push(tmp->Right);
		}
	}
}

//27.�����������Ҷ�ڵ�
void LeafPrint(TreeNode* T1)
{
	if (T1 == NULL)
		return;
	LeafPrint(T1->Left);
	if(T1->Left == NULL && T1->Right == NULL)
		cout << T1->Data << "\t";
	LeafPrint(T1->Right);
}

//28.��������߶�
int HeightBinTree(TreeNode* T1)//���ݲ��������д
{
	if (T1 == NULL)
		return 0;
	int H1 = HeightBinTree(T1->Left);
	int H2 = HeightBinTree(T1->Right);
	int Height = (H1 > H2 ? H1 : H2) + 1;
	return Height;
}

//29.��������������Find�ݹ�
TreeNode* BinTreeFind(TreeNode* T1, int Data)
{
	if (T1 == NULL)
	{
		cout << "δ�ҵ���";
		return NULL;
	}
	else if (T1->Data == Data)
	{
		return T1;
	}
	else if(T1->Data < Data)
	{
		return BinTreeFind(T1->Right, Data);
	}
	else
	{
		return BinTreeFind(T1->Left, Data);
	}
}

//30.�������������ҷǵݹ�IterFind
TreeNode* IterBinTreeFind(TreeNode* T1, int Data)
{
	while (T1)
	{
		if (T1->Data == Data)
		{
			return T1;
		}
		else if (T1->Data > Data)
		{
			T1 = T1->Left;
		}
		else {
			T1 = T1->Right;
		}
	}
	cout << "δ�ҵ���";
	return NULL;
}

//31.�������ֵFindBinTreeMax
TreeNode* FindBinTreeMax(TreeNode* T1)
{
	if (T1 == NULL)
	{
		cout << "������";
		return NULL;
	}
	while (T1->Right != NULL)
	{
		T1 = T1->Right;
	}
	return T1;
}

//32.������СֵFindBinTreeMin   ��
TreeNode* FindBinTreeMin(TreeNode* T1)
{
	if (T1 == NULL)
	{
		cout << "������";
		return NULL;
	}
	while (T1->Left != NULL)
	{
		T1 = T1->Left;
	}
	return T1;
}
//33.��������InsertBinTree
TreeNode* InsertBinTree(TreeNode* T1, int Data)
{
	TreeNode* Tn = new(TreeNode);
	Tn->Data = Data;
	Tn->Left = NULL;
	Tn->Right = NULL;
	while (T1)
	{
		if (T1->Data == Data)
		{
			cout << "�Ѵ��ڸ�ֵ�Ľڵ�";
			return T1;
		}
		else if (T1->Data > Data)
		{
			if (!T1->Left) {
				T1->Left = Tn;
				return Tn;
			}	
			T1 = T1->Left;
		}
		else {
			if (!T1->Right) {
				T1->Right = Tn;
				return Tn;
			}
			T1 = T1->Right;
		}
	}
	T1 = Tn;
	return T1;
}

//34.ɾ������DeleteBinTree///ע���ˣ���
bool DeleteBinTree(TreeNode* T1, int Data)
{
	TreeNode* child = T1;
	TreeNode* parent = NULL;
	while(child)
	{
		if (child->Data > Data)
		{
			parent = child;
			child = child->Left;
		}
		else if (child->Data < Data)
		{
			parent = child;
			child = child->Right;
		}
		else
		{
			if (child->Left == NULL && child->Right == NULL)
			{
				if (parent == NULL)
				{
					T1 = T1->Left;/////////////������һ�����⣬��ֻ��һ���ڵ�ʱ�������ȷ�ķ���NULL(���ǿ��Ըĳɷ������ڵ�)
					//delete(child);
					//child = NULL;
					
					//delete(child);
					//child = NULL;
					return true;
				}
				if (parent->Left->Data == Data)
				{
					//delete(child);
					parent->Left = NULL;
				}
				else {
					parent->Right = NULL;
				}
				delete(child);
				return true;
			}
			else if (child->Left == NULL)
			{
				if (parent->Left->Data == Data)
				{
					//delete(child);
					parent->Left = child->Right;
				}
				else {
					parent->Right = child->Right;
				}
				delete(child);
				return true;
			}
			else if (child->Right == NULL)
			{
				if (parent->Left->Data == Data)
				{
					//delete(child);
					parent->Left = child->Left;
				}
				else {
					parent->Right = child->Left;
				}
				delete(child);
				return true;
			}
			else if (child->Left != NULL && child->Right != NULL)
			{
				TreeNode* child2 = child->Left;
				while (child2->Right)
				{
					parent = child2;
					child2 = child2->Right;
				}
				child->Data = child2->Data;
				parent->Right = NULL;
				delete(child2);
				return true;
			}
		}
	}
	return false;
}

//ƽ�������
//35.ƽ���������㶨��AVLTreeNode
//36.LL��תSingleLeftRotation
//37.RR��תSingleRightRotation
//38.LR��תDoubleLeftRightRotation
//39.RL��תDoubleRightLeftRotation
//40.ƽ��������Ĳ���AVLInsertion
//41.ƽ��������ĸ߶�
//��
//42.���ѵĽṹ����MaxHeap
//43.���ѽ���MaxHeapCreat
//44.���ѵĲ���MaxHeapInsert
//45.���ѵ�ɾ��MaxHeapDelete


//35.ƽ���������㶨��AVLTreeNode

struct AVLTreeNode {
	int Data;
	AVLTreeNode* Left;
	AVLTreeNode* Right;
	int Height;
};

int HeightAVLBinTree(AVLTreeNode* T1)//���ݲ��������д
{
	if (T1 == NULL)
		return 0;
	int H1 = HeightAVLBinTree(T1->Left);
	int H2 = HeightAVLBinTree(T1->Right);
	int Height = (H1 > H2 ? H1 : H2) + 1;
	return Height;
}

//36.LL��תSingleLeftRotation
AVLTreeNode* LLRotation(AVLTreeNode* A)
{
	AVLTreeNode* B = A->Left;
	//AVLTreeNode* BL = B->Left;
	AVLTreeNode* BR = B->Right;
	//AVLTreeNode* C = BL->Left;
	//AVLTreeNode* AR = A->Right;
	A->Left = BR;
	B->Right = A;
	return B;
}



//38.LR��תDoubleLeftRightRotation
AVLTreeNode* LRRotation(AVLTreeNode* A)
{
	AVLTreeNode* B = A->Left;
	//AVLTreeNode* BL = B->Left;
	AVLTreeNode* BR = B->Right;
	AVLTreeNode* BRL = BR->Left;
	AVLTreeNode* BRR = BR->Right;
	//AVLTreeNode* C = BL->Left;
	//AVLTreeNode* AR = A->Right;
	A->Left = BRR;
	B->Right = BRL;
	BRL = B;
	BRR = A;
	return BR;
}

//37.RR��תSingleRightRotation
AVLTreeNode* RRRotation(AVLTreeNode* A)
{
	AVLTreeNode* B = A->Right;
	//AVLTreeNode* BL = B->Left;
	AVLTreeNode* BL = B->Left;
	//AVLTreeNode* C = BL->Left;
	//AVLTreeNode* AR = A->Right;
	A->Right = BL;
	B->Left = A;
	return B;
}

//39.RL��תDoubleRightLeftRotation
AVLTreeNode* RLRotation(AVLTreeNode* A)
{
	AVLTreeNode* B = A->Right;
	//AVLTreeNode* BL = B->Left;
	AVLTreeNode* BL = B->Left;
	AVLTreeNode* BLL = BL->Left;
	AVLTreeNode* BLR = BL->Right;
	//AVLTreeNode* C = BL->Left;
	//AVLTreeNode* AR = A->Right;
	A->Right = BLL;
	B->Left = BLR;
	BLL = A;
	BLR = B;
	return BL;
}
//40.ƽ��������Ĳ���AVLInsertion
AVLTreeNode* AVLTreeInsert(AVLTreeNode* T1, int Data)
{
	AVLTreeNode* NewNode = new(AVLTreeNode);
	NewNode->Data = Data;
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	if (!T1)
	{
		T1 = NewNode;
		return T1;
	}
	else
	{
		if (Data < T1->Data)
		{
			T1->Left = AVLTreeInsert(T1->Left, Data);
			if (HeightAVLBinTree(T1->Left) - HeightAVLBinTree(T1->Right) == 2)
			{
				if (Data < T1->Left->Data)
				{
					T1 = LLRotation(T1);
				}
				else if (Data > T1->Left->Data)
				{
					T1 = LRRotation(T1);
				}
			}
		}
		else if (Data > T1->Data)
		{
			T1->Right = AVLTreeInsert(T1->Right, Data);
			if (HeightAVLBinTree(T1->Right) - HeightAVLBinTree(T1->Left) == 2)
			{
				if (Data > T1->Right->Data)
				{
					T1 = RRRotation(T1);
				}
				else if (Data < T1->Right->Data)
				{
					T1 = RLRotation(T1);
				}
			}
		}
	}
	return T1;
}




//��
//42.���ѵĽṹ����MaxHeap
//43.���ѽ���MaxHeapCreate
//44.���ѵĲ���MaxHeapInsert
//45.���ѵ�ɾ��MaxHeapDelete
//46.���ѵĽ���BuildMaxHeap

//42.���ѵĽṹ����MaxHeap
struct MaxHeap {
	int* Data;
	int Size;
	int Capacity;
};

//43.���ѽ���MaxHeapCreat
#define MAXVALUE 10000
MaxHeap* MaxHeapCreate(int Capacity)
{
	MaxHeap* MH1 = (MaxHeap*)malloc(sizeof(MaxHeap));//��new����
	MH1->Capacity = Capacity;
	MH1->Data = (int*)malloc((MH1->Capacity + 1) * sizeof(int));;
	MH1->Size = 0;
	MH1->Data[0] = MAXVALUE;
	return MH1;
}

//44.���ѵĲ���MaxHeapInsert
void MaxHeapInsert(MaxHeap* MH1, int Data)
{
	if (MH1->Size + 1 > MH1->Capacity)
	{
		cout << "��������";
		return;
	}  
	MH1->Data[++MH1->Size] = Data;
	int child = MH1->Size, parent = MH1->Size / 2;
	while (parent >= 1)
	{
		if (MH1->Data[parent] < Data)
		{
			MH1->Data[child] = MH1->Data[parent];
			child = parent;
			parent /= 2;
		}
		else
		{
			break;
		}
	}
	MH1->Data[child] = Data;
}


//45.���ѵ�ɾ��MaxHeapDelete
void MaxHeapDelete(MaxHeap* MH1)
{
	if (MH1->Size <= 0)
	{
		cout << "�ѿգ�";
		return;
	}
	int tmp = MH1->Data[MH1->Size--];
	int parent = 1, child = parent * 2;
	while (child <= MH1->Size && MH1->Data[child] > tmp)
	{
		if (child + 1 <= MH1->Size && MH1->Data[child] < MH1->Data[child + 1])
		{
			child = child + 1;
		}
		MH1->Data[parent] = MH1->Data[child];
		parent = child;
		child *= 2;
	}
	MH1->Data[parent] = tmp;
}


//46.���ѵĽ���BuildMaxHeap//�ԣ��Ͷ�������