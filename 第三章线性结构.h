#pragma once
#include <iostream>
using namespace std;
//������ ���Խṹ
//���Ա����ʽ�洢ʵ��
//1.������Node
//2.�����󳤶�Length
//8.��ת����Reverse
//3.���ҵ�K��ֵFindKth
//4.��ֵ����Find
//5.����Insert
//6.ɾ��Delete
//7.��������Print

//1.������Node
struct Node {
	int Value;
	Node* Next;
};

////2.�����󳤶�Length
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

//8.��ת����
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

//7.��������
void PrintNode(Node* a)
{
	if (a == NULL) {
		cout << "Ϊ������";
		return;
	}
	while (a)
	{
		cout << a->Value << "\t";
		a = a->Next;
	}
}

//3.���ҵ�K��ֵFindKth
Node* FindKth(Node* a, int K)
{
	if (K < 0)
	{
		cout << "�Ƿ�ֵ";
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
		cout << "������������Ȳ���";
		return NULL;
	}
	else
	{
		return a;
	}
}

//4.��ֵ����Find
Node* FindValue(Node* N1, int K)
{
	while (N1)
	{
		if (N1->Value == K)
			return N1;
		N1 = N1->Next;
	}
	cout << "δ�ҵ���";
	return NULL;
}

//5.����Insert
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
		cout << "�ڵ㲻���ڣ��޷����룡";
		return NULL;
	}
}

//��ջ��˳��洢��ʾ
//8.˳��洢�ṹ����Stack1
//9.��ջPush1
//10.��ջPop1

//��ջ����ʽ�洢��ʾ
//11.�洢�ṹ��ʾStack2
//12.����һ����ջCreatStack
//13.��ջ�Ƿ�Ϊ��IsEmpty
//13.��ջPush2
//14.��ջPop2

//���е�˳��洢ʵ��
//15.�ṹ����Queue
//16.����
//17.ɾ��

//���е���ʽ�洢ʵ��
//18.�ṹ����LinkQueue
//19.����
//20.ɾ��



//8.��ջ˳��洢�ṹ����Stack1
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

//9.��ջPush1
void PushStackSeq(StackSeq* S1, int Data)
{
	if (S1->Top >= MaxStackSize - 1) {
		cout << "��ջ������";
		return;
	}
	S1->Data[++(S1->Top)] = Data;
}
//10.��ջ
int PopStackSeq(StackSeq* S1)
{
	if (S1->Top < 0)
	{
		cout << "��ջ�գ�";
		return ERROR;
	}
	return S1->Data[(S1->Top)--];
}

//��ջ����ʽ�洢��ʾ
//11.�洢�ṹ��ʾStack2
//12.����һ����ջCreatStack
//13.��ջ�Ƿ�Ϊ��IsEmpty
//13.��ջPush2
//14.��ջPop2

//11.��ջ��ʽ�洢

struct StackLink {
	int Data;
	StackLink* Next;
};
//12. ����һ����ջ
StackLink* InitialStackLink()
{
	StackLink* S1 = new(StackLink);
	S1->Next = NULL;
	return S1;
}

//13.��ջPush2
void PushStackLink(StackLink* S1, int Data)
{
	StackLink* St = new(StackLink);
	St->Data = Data;
	St->Next = S1->Next;
	S1->Next = St;
}

//14.��ջPop2
int PopStackLink(StackLink* S1)
{
	if (S1->Next == NULL)
	{
		cout << "��ջ�գ�";
		return ERROR;
	}
	int Data = S1->Next->Data;
	StackLink* tmp = S1->Next;
	S1->Next = tmp->Next;
	delete(tmp);
	return Data;
}


//���е�˳��洢ʵ��
//15.�ṹ����Queue
//16.����
//17.ɾ��

#define MaxQueueSize 100

//15.���е�˳��洢ʵ��
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

//16.�������
void InsertQueueSeq(QueueSeq* Q1,int Data)
{
	if (Q1->Size >= MaxQueueSize)
	{
		cout << "��������";
		return;
	}
	Q1->Data[++(Q1->Top) % MaxQueueSize] = Data;
	Q1->Size++;
}

//17.����
int DeleteQueueSeq(QueueSeq* Q1)
{
	if (Q1->Size <= 0)
	{
		cout << "���пգ�";
		return ERROR;
	}
	int Data = Q1->Data[++(Q1->Rear) % MaxQueueSize];
	Q1->Size--;
	return Data;
}

//���е���ʽ�洢ʵ��
//18.�ṹ����LinkQueue
//19.����
//20.ɾ��

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
		cout << "���пգ�";
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