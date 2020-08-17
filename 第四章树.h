#pragma once
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//第四章
//二叉树
//21.二叉树的链表表示TreeNode
//22.二叉树递归中序遍历
//23.二叉树递归先序遍历
//24.二叉树递归后序遍历
//25.二叉树的非递归中序遍历
//26.二叉树的层序遍历
//27.输出二叉树的叶节点
//28.求二叉树高度
//二叉搜索树
//29.二叉搜索树查找Find递归
//30.二叉搜索树查找非递归IterFind
//31.查找最大值FindBinTreeMax
//32.查找最小值FindBinTreeMin
//33.插入数据InsertBinTree
//34.删除数据DeleteBinTree
//平衡二叉树
//35.平衡二叉树结点定义AVLTreeNode
//36.LL旋转SingleLeftRotation
//37.RR旋转SingleRightRotation
//38.LR旋转DoubleLeftRightRotation
//39.RL旋转DoubleRightLeftRotation
//40.平衡二叉树的插入AVLInsertion
//41.平衡二叉树的高度
//堆
//42.最大堆的结构定义MaxHeap
//43.最大堆建立MaxHeapCreat
//44.最大堆的插入MaxHeapInsert
//45.最大堆的删除MaxHeapDelete


//21.二叉树的链表表示TreeNode
struct TreeNode {
	TreeNode* Left;
	TreeNode* Right;
	int Data;
};
//22.二叉树递归中序遍历
void MiddlePrint(TreeNode* T1)
{
	if (T1 == NULL)
		return;
	MiddlePrint(T1->Left);
	cout << T1->Data << "\t";
	MiddlePrint(T1->Right);
}

//23.二叉树递归先序遍历
void FrontPrint(TreeNode* T1)
{
	if (T1 == NULL)
		return;
	cout << T1->Data << "\t";
	FrontPrint(T1->Left);
	FrontPrint(T1->Right);
}

//24.二叉树递归后序遍历
void LastPrint(TreeNode* T1)
{
	if (T1 == NULL)
		return;
	LastPrint(T1->Left);
	LastPrint(T1->Right);
	cout << T1->Data << "\t";
}

//25.二叉树的非递归中序遍历
void MiddlePrint_Norecursive(TreeNode* T1)//用堆栈
{
 	if (T1 == NULL)
	{
		cout << "树为空！";
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

//26.二叉树的层序遍历
void LayerPrintBinTree(TreeNode* T1)
{
	queue<TreeNode*> Q1;
	TreeNode* tmp = new(TreeNode);
	if (T1 == NULL)
	{
		cout << "树为空！";
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

//27.输出二叉树的叶节点
void LeafPrint(TreeNode* T1)
{
	if (T1 == NULL)
		return;
	LeafPrint(T1->Left);
	if(T1->Left == NULL && T1->Right == NULL)
		cout << T1->Data << "\t";
	LeafPrint(T1->Right);
}

//28.求二叉树高度
int HeightBinTree(TreeNode* T1)//根据层序遍历改写
{
	if (T1 == NULL)
		return 0;
	int H1 = HeightBinTree(T1->Left);
	int H2 = HeightBinTree(T1->Right);
	int Height = (H1 > H2 ? H1 : H2) + 1;
	return Height;
}

//29.二叉搜索树查找Find递归
TreeNode* BinTreeFind(TreeNode* T1, int Data)
{
	if (T1 == NULL)
	{
		cout << "未找到！";
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

//30.二叉搜索树查找非递归IterFind
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
	cout << "未找到！";
	return NULL;
}

//31.查找最大值FindBinTreeMax
TreeNode* FindBinTreeMax(TreeNode* T1)
{
	if (T1 == NULL)
	{
		cout << "空树！";
		return NULL;
	}
	while (T1->Right != NULL)
	{
		T1 = T1->Right;
	}
	return T1;
}

//32.查找最小值FindBinTreeMin   略
TreeNode* FindBinTreeMin(TreeNode* T1)
{
	if (T1 == NULL)
	{
		cout << "空树！";
		return NULL;
	}
	while (T1->Left != NULL)
	{
		T1 = T1->Left;
	}
	return T1;
}
//33.插入数据InsertBinTree
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
			cout << "已存在该值的节点";
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

//34.删除数据DeleteBinTree///注意了！！
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
					T1 = T1->Left;/////////////这里有一个问题，当只有一个节点时，如何正确的返回NULL(考虑可以改成返回数节点)
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

//平衡二叉树
//35.平衡二叉树结点定义AVLTreeNode
//36.LL旋转SingleLeftRotation
//37.RR旋转SingleRightRotation
//38.LR旋转DoubleLeftRightRotation
//39.RL旋转DoubleRightLeftRotation
//40.平衡二叉树的插入AVLInsertion
//41.平衡二叉树的高度
//堆
//42.最大堆的结构定义MaxHeap
//43.最大堆建立MaxHeapCreat
//44.最大堆的插入MaxHeapInsert
//45.最大堆的删除MaxHeapDelete


//35.平衡二叉树结点定义AVLTreeNode

struct AVLTreeNode {
	int Data;
	AVLTreeNode* Left;
	AVLTreeNode* Right;
	int Height;
};

int HeightAVLBinTree(AVLTreeNode* T1)//根据层序遍历改写
{
	if (T1 == NULL)
		return 0;
	int H1 = HeightAVLBinTree(T1->Left);
	int H2 = HeightAVLBinTree(T1->Right);
	int Height = (H1 > H2 ? H1 : H2) + 1;
	return Height;
}

//36.LL旋转SingleLeftRotation
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



//38.LR旋转DoubleLeftRightRotation
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

//37.RR旋转SingleRightRotation
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

//39.RL旋转DoubleRightLeftRotation
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
//40.平衡二叉树的插入AVLInsertion
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




//堆
//42.最大堆的结构定义MaxHeap
//43.最大堆建立MaxHeapCreate
//44.最大堆的插入MaxHeapInsert
//45.最大堆的删除MaxHeapDelete
//46.最大堆的建立BuildMaxHeap

//42.最大堆的结构定义MaxHeap
struct MaxHeap {
	int* Data;
	int Size;
	int Capacity;
};

//43.最大堆建立MaxHeapCreat
#define MAXVALUE 10000
MaxHeap* MaxHeapCreate(int Capacity)
{
	MaxHeap* MH1 = (MaxHeap*)malloc(sizeof(MaxHeap));//用new报错
	MH1->Capacity = Capacity;
	MH1->Data = (int*)malloc((MH1->Capacity + 1) * sizeof(int));;
	MH1->Size = 0;
	MH1->Data[0] = MAXVALUE;
	return MH1;
}

//44.最大堆的插入MaxHeapInsert
void MaxHeapInsert(MaxHeap* MH1, int Data)
{
	if (MH1->Size + 1 > MH1->Capacity)
	{
		cout << "堆已满！";
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


//45.最大堆的删除MaxHeapDelete
void MaxHeapDelete(MaxHeap* MH1)
{
	if (MH1->Size <= 0)
	{
		cout << "堆空！";
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


//46.最大堆的建立BuildMaxHeap//略，和堆排序差不多