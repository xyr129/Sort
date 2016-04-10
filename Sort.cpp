# include"Sort.h"

void TestInsertSort()
{
	int array[10] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	int array1[3] = { 2,4, 3};
	//InsertSort(array, 10);
	//ShellSort(array, 10);
	//SelectSort(array, 10);
	//HeapSort(array, 10);
	//QuickSort(array, 10);
	//QuickSort2(array, 10);
	MergeSortNonR(array, 10);
	Print(array, 10);
}

int main()
{
	TestInsertSort();
	system("pause");
	return 0;
}