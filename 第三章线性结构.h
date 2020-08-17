#pragma once
#include <iostream>
using namespace std;
//第三章 线性结构
//线性表的链式存储实现
//1.链表定义Node
//2.链表求长度Length
//8.反转链表Reverse
//3.查找第K个值FindKth
//4.按值查找Find
//5.插入Insert
//6.删除Delete
//7.遍历链表Print

//1.链表定义Node
struct Node {
	int Value;
	Node* Next;
};

////2.链表求长度Length
int NodeLength(Node* N1)
{
	int length = 0;
	while (N1 != NULL)
	{
		N1 = N1->Next;
		length++;
	}
	return length;
}

//8.反转链表
Node* Reverse(Node* N1)
{
	Node* p, *q, *t;
	p = N1;
	q = NULL;
	
	while (p != NULL)
	{
		t = p->Next;
		p->Next = q;
		q = p;
		p = t;
	}
	return q;
}

//7.遍历链表
void PrintNode(Node* a)
{
	if (a == NULL) {
		cout << "为空链表！";
		return;
	}
	while (a)
	{
		cout << a->Value << "\t";
		a = a->Next;
	}
}

//3.查找第K个值FindKth
Node* FindKth(Node* a, int K)
{
	if (K < 0)
	{
		cout << "非法值";
		return NULL;
	}
	int i = 1;
	while (i < K)
	{
		a = a->Next;
		if (a == NULL)
			break;
		i++;
	}
	if (i != K)
	{
		cout << "输入错误，链表长度不足";
		return NULL;
	}
	else
	{
		return a;
	}
}

//4.按值查找Find
Node* FindValue(Node* N1, int K)
{
	while (N1)
	{
		if (N1->Value == K)
			return N1;
		N1 = N1->Next;
	}
	cout << "未找到！";
	return NULL;
}

//5.插入Insert
Node* InsertNode(Node* N1, int Kth, int Value)
{
	Node* newnode = new(Node);
	newnode->Value = Value;
	newnode->Next = NULL;
	Node* KthNode = FindKth(N1, Kth);
	if (KthNode != NULL)
	{
		newnode->Next = KthNode->Next;
		KthNode->Next = newnode;
		return newnode;
	}
	else
	{
		cout << "节点不存在，无法插入！";
		return NULL;
	}
}

//堆栈的顺序存储表示
//8.顺序存储结构定义Stack1
//9.入栈Push1
//10.出栈Pop1

//堆栈的链式存储表示
//11.存储结构表示Stack2
//12.创建一个堆栈CreatStack
//13.堆栈是否为空IsEmpty
//13.入栈Push2
//14.出栈Pop2

//队列的顺序存储实现
//15.结构定义Queue
//16.插入
//17.删除

//队列的链式存储实现
//18.结构定义LinkQueue
//19.插入
//20.删除



//8.堆栈顺序存储结构定义Stack1
#define MaxStackSize 100
#define ERROR -10000
struct StackSeq {
	int Data[MaxStackSize];
	int Top;
};
StackSeq* InitialStackSeq()
{
	StackSeq* S1 = new(StackSeq);
	S1->Top = -1;
	return S1;
}

//9.入栈Push1
void PushStackSeq(StackSeq* S1, int Data)
{
	if (S1->Top >= MaxStackSize - 1) {
		cout << "堆栈已满！";
		return;
	}
	S1->Data[++(S1->Top)] = Data;
}
//10.出栈
int PopStackSeq(StackSeq* S1)
{
	if (S1->Top < 0)
	{
		cout << "堆栈空！";
		return ERROR;
	}
	return S1->Data[(S1->Top)--];
}

//堆栈的链式存储表示
//11.存储结构表示Stack2
//12.创建一个堆栈CreatStack
//13.堆栈是否为空IsEmpty
//13.入栈Push2
//14.出栈Pop2

//11.堆栈链式存储

struct StackLink {
	int Data;
	StackLink* Next;
};
//12. 创建一个堆栈
StackLink* InitialStackLink()
{
	StackLink* S1 = new(StackLink);
	S1->Next = NULL;
	return S1;
}

//13.入栈Push2
void PushStackLink(StackLink* S1, int Data)
{
	StackLink* St = new(StackLink);
	St->Data = Data;
	St->Next = S1->Next;
	S1->Next = St;
}

//14.出栈Pop2
int PopStackLink(StackLink* S1)
{
	if (S1->Next == NULL)
	{
		cout << "堆栈空！";
		return ERROR;
	}
	int Data = S1->Next->Data;
	StackLink* tmp = S1->Next;
	S1->Next = tmp->Next;
	delete(tmp);
	return Data;
}


//队列的顺序存储实现
//15.结构定义Queue
//16.插入
//17.删除

#define MaxQueueSize 100

//15.队列的顺序存储实现
struct QueueSeq {
	int Data[MaxQueueSize];
	int Top;
	int Rear;
	int Size;
};

QueueSeq* InitialQueueSeq()
{
	QueueSeq* Q1 = new(QueueSeq);
	Q1->Top = -1;
	Q1->Rear = -1;
	Q1->Size = 0;
	return Q1;
}

//16.插入入队
void InsertQueueSeq(QueueSeq* Q1,int Data)
{
	if (Q1->Size >= MaxQueueSize)
	{
		cout << "队列满！";
		return;
	}
	Q1->Data[++(Q1->Top) % MaxQueueSize] = Data;
	Q1->Size++;
}

//17.出队
int DeleteQueueSeq(QueueSeq* Q1)
{
	if (Q1->Size <= 0)
	{
		cout << "队列空！";
		return ERROR;
	}
	int Data = Q1->Data[++(Q1->Rear) % MaxQueueSize];
	Q1->Size--;
	return Data;
}

//队列的链式存储实现
//18.结构定义LinkQueue
//19.插入
//20.删除

//18.
struct QueueLink {
	Node* Front;
	Node* Rear;
};

QueueLink* InitialQueueLink()
{
	QueueLink* Q1 = new(QueueLink);
	Node* N1 = new(Node);
	N1->Next = NULL;
	Q1->Front = N1;
	Q1->Rear = N1;
	return Q1;
}
//19.
void InsertQueueLink(QueueLink* Q1, int Data)
{
	Node* N2 = new(Node);
	N2->Value = Data;
	N2->Next = NULL;
	Q1->Rear->Next = N2;
	Q1->Rear = N2;
}
//20.
int DeleteQueueLink(QueueLink* Q1)
{
	if (Q1->Front->Next == NULL)
	{
		cout << "队列空！";
		return  ERROR;
	}
	Node* tmp = Q1->Front->Next;
	int Data = tmp->Value;
	if (tmp->Next == NULL)
	{
		Q1->Rear = Q1->Front;
		Q1->Front->Next = NULL;
		delete(tmp);
		return Data;
	}
	else {
		Q1->Front->Next = tmp->Next;
		delete(tmp);
		return Data;
	}
}