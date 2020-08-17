// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "第三章线性结构.h"
#include <iostream>
#include <stack>
#include <queue>
#include "排序算法.h"
#include "哈希表.h"
#include "第四章树.h"
#include "第五章图.h"
#include "LeetCode.h"
#include <unordered_map>


//int main()
//{
	/*string s = longestPalindrome("abcdbbfcba");
	cout << s << endl;*/












	////leetcode 3.
	//cout << lengthOfLongestSubstring_1("aabaab!bb") << endl;
	
	////2.
	//ListNode* node1 = &ListNode(2);
	//node1->next = &ListNode(4);
	//node1->next->next = &ListNode(3);
	//node1->next->next->next = NULL;

	//ListNode* node2 = &ListNode(5);
	//node2->next = &ListNode(6);
	//node2->next->next = &ListNode(4);
	//node2->next->next->next = NULL;
	//
	//ListNode* node3 = addTwoNumbers_1(node1, node2);
	//while (node3)
	//{
	//	cout << node3->val << ' ';
	//	node3 = node3->next;
	//}




	//1.
	//unordered_map<int, int>hashmap;
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << hashmap[i] << endl;
	//}
	/*//leetcode 1.
	vector<int> nums, v2;
	nums.push_back(2); nums.push_back(7); nums.push_back(11); nums.push_back(15);
	v2 = twoSum(nums, 9);
	cout << v2[0] << ' ' << v2[1];
	*//*/

	//建立一个邻接矩阵
	/*
	MGraph* M1 = new(MGraph);
	M1->n = 10;
	M1->e = 10;
	M1->gt = T3;
	char Node[] = { 'a','b','c','d','e','f','g','h','i' };
	M1->Node[0] = 'a'; M1->Node[1] = 'b'; M1->Node[2] = 'c'; M1->Node[3] = 'd'; M1->Node[4] = 'e'; M1->Node[5] = 'f'; M1->Node[6] = 'g'; M1->Node[7] = 'h'; M1->Node[8] = 'i';  M1->Node[9] = 'j';
	for (int i = 0; i < M1->n; i++)
		for (int j = 0; j < M1->n; j++)
			M1->Net[i][j] = INFINITY;
	M1->Net[0][1] = 2;
	M1->Net[0][3] = 5;

	M1->Net[1][0] = 2;
	M1->Net[1][2] = 5;
	M1->Net[1][3] = 2;

	M1->Net[2][1] = 5;
	M1->Net[2][4] = 8;
	M1->Net[2][5] = 4;

	M1->Net[3][0] = 5;
	M1->Net[3][1] = 2;
	M1->Net[3][5] = 4;
	M1->Net[3][6] = 2;

	M1->Net[4][2] = 8;
	M1->Net[4][5] = 2;
	M1->Net[4][7] = 5;

	M1->Net[5][2] = 4;
	M1->Net[5][3] = 4;
	M1->Net[5][4] = 2;
	M1->Net[5][6] = 3;
	M1->Net[5][7] = 9;
	M1->Net[5][8] = 6;

	M1->Net[6][3] = 2;
	M1->Net[6][5] = 3;
	M1->Net[6][8] = 7;

	M1->Net[7][4] = 5;
	M1->Net[7][5] = 9;
	M1->Net[7][8] = 3;
	M1->Net[7][9] = 4;

	M1->Net[8][5] = 6;
	M1->Net[8][6] = 7;
	M1->Net[8][7] = 3;
	M1->Net[8][9] = 8;

	M1->Net[9][7] = 4;
	M1->Net[9][8] = 8;

	Dijkstra(M1, 0);
	for (int i = 0; i < M1->n; i++)
	{
		cout << Dist[i] << ' ';
	}
	*/



	/*邻接表遍历
	ALGraph* AL1 = new(ALGraph);
	CreateALGraph(AL1);
	int i, n = AL1->n;
	for (i = 0; i < n; i++)
	{
		cout << AL1->MH[i].a << '\t';
		ALNode* Node = AL1->MH[i].FirstNode;
		while (Node != NULL)
		{
			cout << Node->Data << '\t';
			Node = Node->Next;
		}
		cout << endl;
	}
	*/
	//建立了一个邻接表的图
	/*ALGraph* AL1 = new(ALGraph);
	AL1->n = 8;
	AL1->e = 8;
	AL1->MH[0].a = 'A';
	AL1->MH[1].a = 'B';
	AL1->MH[2].a = 'C';
	AL1->MH[3].a = 'D';
	AL1->MH[4].a = 'E';
	AL1->MH[5].a = 'F';
	AL1->MH[6].a = 'G';
	AL1->MH[7].a = 'H';
	ALNode* tmp1 = new(ALNode);
	ALNode* tmp2 = new(ALNode);
	ALNode* tmp3 = new(ALNode);
	tmp1->Next = tmp2;
	tmp2->Next = tmp3;
	tmp3->Next = NULL;
	ALNode* tmp4 = new(ALNode);
	ALNode* tmp5 = new(ALNode);
	tmp4->Next = tmp5;
	tmp5->Next = NULL;
	ALNode* tmp6 = new(ALNode);
	ALNode* tmp7 = new(ALNode);
	tmp6->Next = tmp7;
	tmp7->Next = NULL;
	ALNode* tmp8 = new(ALNode);
	ALNode* tmp9 = new(ALNode);
	tmp8->Next = tmp9;
	tmp9->Next = NULL;
	ALNode* tmp10 = new(ALNode);
	ALNode* tmp11 = new(ALNode);
	ALNode* tmp12 = new(ALNode);
	tmp10->Next = tmp11;
	tmp11->Next = tmp12;
	tmp12->Next = NULL;
	ALNode* tmp13 = new(ALNode);
	ALNode* tmp14 = new(ALNode);
	tmp13->Next = tmp14;
	tmp14->Next = NULL;
	ALNode* tmp15 = new(ALNode);
	ALNode* tmp16 = new(ALNode);
	tmp15->Next = tmp16;
	tmp16->Next = NULL;
	ALNode* tmp17 = new(ALNode);
	ALNode* tmp18 = new(ALNode);
	tmp17->Next = tmp18;
	AL1->MH[0].FirstNode = tmp1;
	AL1->MH[0].FirstNode->Data = 1;
	AL1->MH[0].FirstNode->Next->Data = 3;
	AL1->MH[0].FirstNode->Next->Next->Data = 4;
	AL1->MH[0].FirstNode->Next->Next->Next = NULL;

	AL1->MH[1].FirstNode = tmp4;
	AL1->MH[1].FirstNode->Data = 0;
	AL1->MH[1].FirstNode->Next->Data = 2;
	AL1->MH[1].FirstNode->Next->Next = NULL;

	AL1->MH[2].FirstNode = tmp6;
	AL1->MH[2].FirstNode->Data = 1;
	AL1->MH[2].FirstNode->Next->Data = 3;
	AL1->MH[2].FirstNode->Next->Next = NULL;

	AL1->MH[3].FirstNode = tmp8;
	AL1->MH[3].FirstNode->Data = 0;
	AL1->MH[3].FirstNode->Next->Data = 2;
	AL1->MH[3].FirstNode->Next->Next = NULL;

	AL1->MH[4].FirstNode = tmp10;
	AL1->MH[4].FirstNode->Data = 0;
	AL1->MH[4].FirstNode->Next->Data = 5;
	AL1->MH[4].FirstNode->Next->Next->Data = 7;
	AL1->MH[4].FirstNode->Next->Next->Next = NULL;

	AL1->MH[5].FirstNode = tmp13;
	AL1->MH[5].FirstNode->Data = 4;
	AL1->MH[5].FirstNode->Next->Data = 6;
	AL1->MH[5].FirstNode->Next->Next = NULL;

	AL1->MH[6].FirstNode = tmp15;
	AL1->MH[6].FirstNode->Data = 5;
	AL1->MH[6].FirstNode->Next->Data = 7;
	AL1->MH[6].FirstNode->Next->Next = NULL;

	AL1->MH[7].FirstNode = tmp17;
	AL1->MH[7].FirstNode->Data = 4;
	AL1->MH[7].FirstNode->Next->Data = 6;
	AL1->MH[7].FirstNode->Next->Next = NULL;
	*/

	//DFS(AL1, 4);
	//BFS(AL1, 0);
/*
	Single_Sourse_Shottest(AL1, 0);
	for (int kk = 0; kk < AL1->n; kk++)
		cout << Dist[kk] << ' ';
	cout << endl;
	for (int kk = 0; kk < AL1->n; kk++)
		cout << Path[kk] << ' ';
		*/
	//for (int i = 0; i < AL1->n; i++)
	//{
	//	cout << AL1->MH[i].a << '\t';
	//	ALNode* Node = AL1->MH[i].FirstNode;
	//	while (Node != NULL)
	//	{
	//		cout << Node->Data << '\t';
	//		Node = Node->Next;
	//	}
	//	cout << endl;
	//}















	/*遍历邻接矩阵
	MGraph* MG1 = new(MGraph);
	CreateMGraph(MG1);
	cout << MG1->n << endl;
	cout << MG1->e << endl;
	cout << MG1->n << endl;
	for (int i = 0; i < MG1->n; i++)
	{
		for (int j = 0; j < MG1->n; j++)
			cout << MG1->Net[i][j] << '\t';
		cout << endl;
	}
	*/
		




















	//MaxHeap* MH1 = MaxHeapCreate(10);
	/*MH1->Data[1] = 91;
	MH1->Data[2] = 83;
	MH1->Data[3] = 87;
	MH1->Data[4] = 79;
	MH1->Data[5] = 72;
	MH1->Data[6] = 43;
	MH1->Data[7] = 38;
	MH1->Data[8] = 55;
	MH1->Data[9] = 66;*/
	/*
	MaxHeapInsert(MH1, 91);
	MaxHeapInsert(MH1, 83);
	MaxHeapInsert(MH1, 87);
	MaxHeapInsert(MH1, 79);
	MaxHeapInsert(MH1, 72);
	MaxHeapInsert(MH1, 43);
	MaxHeapInsert(MH1, 38);
	MaxHeapInsert(MH1, 55);
	MaxHeapInsert(MH1, 66);
	MaxHeapInsert(MH1, 85);
	MaxHeapDelete(MH1);
	for (int i = 0; i < MH1->Size + 1; i++)
	{
		cout << MH1->Data[i] << '\t';
	}
	*/































	/*
	TreeNode* N1 = new(TreeNode);
	TreeNode* N2 = new(TreeNode);
	TreeNode* N3 = new(TreeNode);
	TreeNode* N4 = new(TreeNode);
	TreeNode* N5 = new(TreeNode);
	TreeNode* N6 = new(TreeNode);
	TreeNode* N7 = new(TreeNode);
	TreeNode* N8 = new(TreeNode);
	TreeNode* N9 = new(TreeNode);

	N1->Data = 91;
	N2->Data = 83;
	N3->Data = 87;
	N4->Data = 79;
	N5->Data = 72;
	N6->Data = 43;
	N7->Data = 55;
	N9->Data = 66;

	N1->Left = N2;
	N1->Right = N3;
	N2->Left = N4;
	N2->Right = N5;
	N3->Left = N6;
	N3->Right = N7;
	N4->Left = N8;
	N4->Right = N9;
	
	N5->Left = NULL;
	N5->Right = NULL;
	N6->Left = NULL;
	N6->Right = NULL;
	N7->Left = NULL;
	N7->Right = NULL;
	N8->Left = NULL;
	N8->Right = NULL;
	N9->Left = NULL;
	N9->Right = NULL;
	cout << DeleteBinTree(N9, 3) << endl;
	cout << (N9 == NULL) << endl;
	LayerPrintBinTree(N9);
	*/


















	/*
	QueueLink* Q1 = InitialQueueLink();
	InsertQueueLink(Q1, 5);
	InsertQueueLink(Q1, 56);
	cout << DeleteQueueLink(Q1) << endl;
	cout << DeleteQueueLink(Q1) << endl;
	cout << DeleteQueueLink(Q1) << endl;
	*/












	/*16.17
	QueueSeq* Q1 = InitialQueueSeq();
	InsertQueueSeq(Q1, 5);
	InsertQueueSeq(Q1, 4);
	InsertQueueSeq(Q1, 3);
	InsertQueueSeq(Q1, 2);
	InsertQueueSeq(Q1, 1);
	InsertQueueSeq(Q1, 0);
	cout << DeleteQueueSeq(Q1) << endl;
	cout << DeleteQueueSeq(Q1) << endl;
	cout << DeleteQueueSeq(Q1) << endl;
	cout << DeleteQueueSeq(Q1) << endl;
	cout << DeleteQueueSeq(Q1) << endl;
	cout << DeleteQueueSeq(Q1) << endl;
	cout << DeleteQueueSeq(Q1) << endl;
	*/













	/*13.14
	StackLink* S1 = InitialStackLink();
	PushStackLink(S1, 5);
	PushStackLink(S1, 4);
	PushStackLink(S1, 3);
	PushStackLink(S1, 2);
	PushStackLink(S1, 1);
	PushStackLink(S1, 0);
	cout << PopStackLink(S1) << endl;
	cout << PopStackLink(S1) << endl;
	cout << PopStackLink(S1) << endl;
	cout << PopStackLink(S1) << endl;
	cout << PopStackLink(S1) << endl;
	cout << PopStackLink(S1) << endl;
	cout << PopStackLink(S1) << endl;
	*/












	/*
	StackSeq* S1 = InitialStackSeq();
	PushStackSeq(S1, 5);
	PushStackSeq(S1, 4);
	PushStackSeq(S1, 3);
	PushStackSeq(S1, 2);
	PushStackSeq(S1, 1);
	PushStackSeq(S1, 0);
	cout << PopStackSeq(S1) << endl;
	cout << PopStackSeq(S1) << endl;
	cout << PopStackSeq(S1) << endl;
	cout << PopStackSeq(S1) << endl;
	cout << PopStackSeq(S1) << endl;
	cout << PopStackSeq(S1) << endl;
	cout << PopStackSeq(S1) << endl;
	*/

























	/*新建链表
	Node* node1 = new Node;
	Node* node2 = new Node;
	Node* node3 = new Node;
	Node* node4 = new Node;
	Node* node5 = new Node;
	Node* node6 = new Node;
	node1->Value = 1;
	node1->Next = node2;
	node2->Value = 2;
	node2->Next = node3;
	node3->Value = 3;
	node3->Next = node4;
	node4->Value = 4;
	node4->Next = node5;
	node5->Value = 5;
	node5->Next = node6;
	node6->Value = 6;
	node6->Next = NULL;

	//PrintNode(node1);
	//cout << FindValue(node1, 6)->Value << endl;

	InsertNode(node1, 7, 8);
	PrintNode(node1);
	*/































	/*哈希表插入数据
	int n = 11;
	HashTable* H1 = InitializeHashTable(n);
	InserTable(47, H1);
	InserTable(7, H1);
	InserTable(29, H1);
	InserTable(11, H1);
	InserTable(9, H1);
	InserTable(84, H1);
	InserTable(54, H1);
	InserTable(20, H1);
	InserTable(30, H1);

	for (int i = 0; i < n; i++)
	{
		cout << i << "   " << H1->TheCells[i].value << "    " <<H1->TheCells[i].Info << endl;
	}
	*/

	//cout << H1->TheCells[14].Info << endl;


	
	/*int A[] = { 5, 8, 6, 7, 3, 8, 1, 9, 7, 6, 10 };
	int n = 11;
	Heap_Sort_Test(A, n);
	for (int i = 0; i < n; i++)
		cout << A[i] << endl;*/

	
	//int A[] = { 3, 5, 9, 18, 24, 33, 1, 6, 22, 23, 56 };
	//int L = 0, R = 6, RightEnd = 10;
	//int TmpA[11];
	//Merge_Test(A, L, R, RightEnd);
	//for (int i = 0; i < 11; i++)
	//	cout << A[i] << endl;

	/*cout << "NextPrime = " << NextPrime(27) << endl;*/








	/*//生成了一个二叉树
	TreeNode* BinTree = new(TreeNode);
	BinTree->Data = 79;
	TreeNode* TreeNode1 = new(TreeNode);
	TreeNode1->Data = 56;
	TreeNode* TreeNode2 = new(TreeNode);
	TreeNode2->Data = 87;
	TreeNode* TreeNode3 = new(TreeNode);
	TreeNode3->Data = 53;
	TreeNode* TreeNode4 = new(TreeNode);
	TreeNode4->Data = 61;
	TreeNode* TreeNode5 = new(TreeNode);
	TreeNode5->Data = 82;
	TreeNode* TreeNode6 = new(TreeNode);
	TreeNode6->Data = 91;
	TreeNode* TreeNode7 = new(TreeNode);
	TreeNode7->Data = 9;
	TreeNode* TreeNode8 = new(TreeNode);
	TreeNode8->Data = 55;
	TreeNode* TreeNode9 = new(TreeNode);
	TreeNode9->Data = 58;
	TreeNode* TreeNode10 = new(TreeNode);
	TreeNode10->Data = 69;
	TreeNode* TreeNode11 = new(TreeNode);  
	TreeNode11->Data = 81;
	BinTree->Left = TreeNode1;
	BinTree->Right = TreeNode2;
	TreeNode1->Left = TreeNode3;
	TreeNode1->Right = TreeNode4;
	TreeNode2->Left = TreeNode5;
	TreeNode2->Right = TreeNode6;
	TreeNode3->Left = TreeNode7;
	TreeNode3->Right = TreeNode8;
	TreeNode4->Left = TreeNode9;
	TreeNode4->Right = TreeNode10;
	TreeNode5->Left = TreeNode11;
	TreeNode5->Right = NULL;
	TreeNode6->Left = NULL;
	TreeNode6->Right = NULL;
	TreeNode7->Left = NULL;
	TreeNode7->Right = NULL;
	TreeNode8->Left = NULL;
	TreeNode8->Right = NULL;
	TreeNode9->Left = NULL;
	TreeNode9->Right = NULL;
	TreeNode10->Left = NULL;
	TreeNode10->Right = NULL;
	TreeNode11->Left = NULL;
	TreeNode11->Right = NULL;
	*///生成了一个二叉树































/*



	return 0;


}
*/


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
