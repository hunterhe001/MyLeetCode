#pragma once
using namespace std;
//1.冒泡排序
//2.选择排序
//3.插入排序
//4.希尔排序
//5.堆排序
//6.归并排序
//7.快速排序
//8.桶排序
//9.基数排序
//10.
//
//

void Bubble_Sort_Test(int a[], int n)
{
	int i, j, temp;
	for(i = 0; i < n; i++)
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
}//1.

void Select_Sort_Test(int a[], int n)
{
	int i, j, min, temp;
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
}

void Insert_Sort_Test(int a[], int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		temp = a[i];
		for (j = i; j >= 0; j--)
		{
			if (temp < a[j - 1])
				a[j] = a[j - 1];
			else
				break;
		}
		a[j] = temp;
	}
}

void Hilt_Sort_Test(int a[], int n)
{
	int i, j, k, l, increament, temp;
	for (increament = n / 2; increament > 0; increament = increament / 2)
	{
		for (i = increament; i < n; i++)
		{
			temp = a[i];
			for (k = i; k >= increament; k -= increament)
			{
				if (a[k - increament] > temp)
				{
					a[k] = a[k - increament];
				}
				else
					break;
			}
			a[k] = temp;
			/*for (l = 0; l < n; l++)
				cout << a[l] << endl;
			cout << endl;*/
		}
	}
}

void Merge_Test(int a[], int left, int right, int right_end)
{
	int left_end = right - 1;
	int i = left, j = right;
	int* temp = new int[right_end - left + 1];
	int k = 0;
	while (i <= left_end && j <= right_end)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= left_end)
		temp[k++] = a[i++];
	while (j <= right_end)
		temp[k++] = a[j++];
	for (i = right_end, j = right_end - left; j >= 0; i--, j--)
		a[i] = temp[j];
}

void Merge_Sort_Test_in(int a[], int left, int right_end)
{
	if (left >= right_end)
		return;
	int middle = (left + right_end) / 2;
	int left_end = middle;
	int right = middle + 1;
	Merge_Sort_Test_in(a, left, left_end);
	Merge_Sort_Test_in(a, right, right_end);
	Merge_Test(a, left, right, right_end);
}

void Merge_Sort_Test(int a[], int n)
{
	Merge_Sort_Test_in(a, 0, n - 1);
}

void Swap_Test(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void Quick_Test(int a[], int left, int right_end)
{
	if (left >= right_end)
		return;
	int qurk = a[left];
	Swap_Test(&a[left], &a[right_end]);
	int i = left, j = right_end;
	while (1)
	{
		while (i < j && a[i] < qurk) i++;
		while (i < j && a[j] > qurk) j--;//一定要是 >=, 否则被交换过去了
		if (i < j)
			Swap_Test(&a[i], &a[j]);
		else
			break;
	}
	Swap_Test(&a[i], &a[right_end]);
	Quick_Test(a, left, i - 1);
	Quick_Test(a, i + 1, right_end);
}
void Quick_Sort_Test(int a[], int n)
{
	Quick_Test(a, 0, n - 1);
}


void quick_sort(int a[], int left, int right)//另一种算法
{
	if (left >= right)
		return;
	int qurk = a[left];
	int i = left, j = right;
	while (i < j)
	{
		while (i < j && a[j] >= qurk) j--;
		if (i < j)
		{
			a[i++] = a[j];
		}
		while (i < j && a[i] < qurk) i++;
		if (i < j)
		{
			a[j--] = a[i];
		}
	}
	a[i] = qurk;
	quick_sort(a, left, i - 1);
	quick_sort(a, i + 1, right);
}
void quick_sort_test(int a[], int n)
{
	quick_sort(a, 0, n - 1);
}//7.


void Heap_Sort_pre(int a[], int n)
{
	int i, child, dad, temp;
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		dad = i;
		child = 2 * i + 1;
		temp = a[dad];
		while (child < n)
		{
			if (child + 1 < n && a[child] < a[child + 1])
				child = child + 1;
			if (a[child] < temp)
				break;
			else
			{
				/*temp1 = a[child];
				a[child] = a[dad];
				a[dad] = temp1;*/
				a[dad] = a[child];
				dad = child;
				child = 2 * child + 1;
			}

		}
		a[dad] = temp;
	}
}

void Heap_Sort_Test(int a[], int n)
{
	int i;
	Heap_Sort_pre(a, n);
	for (i = n; i > 0; i--)
	{
		Heap_Sort_pre(a, i);
		Swap_Test(&a[0], &a[i - 1]);
	}
	
}//5.


