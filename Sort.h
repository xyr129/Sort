# include<iostream>
# include<cassert>
using namespace std;
//InsertSort
//��һ�������뵽һ������������ 
void InsertSort(int *array, size_t size)
{
	assert(array);
	int tmp = 0;
	for (size_t index = 1; index < size; ++index)
	{
		tmp = array[index];
		int end = index - 1;
		while (end>=0 && array[end]>tmp)
		{
			array[end + 1] = array[end];
			--end;
		}
		array[end + 1] = tmp;
	}
}


//ShellSort
void ShellSort(int *array, size_t size)
{
	assert(array);
	//����gap
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;  //��֤���һ�μ��Ϊ1
		for (size_t index = gap; index < size; index += gap)//��gap��ʼ����������������Ϊgap �������
		{
			int end = index - gap;
			int tmp = array[index];
			while (end >= 0 && array[end]>tmp)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = tmp;
		}
	}
	//gap����1��ֱ�Ӳ�������
	for (size_t index = 1; index < size; ++index)
	{
		int tmp = array[index];
		int end = index - gap;
		while (end >= 0 && array[end]>tmp)
		{
			array[end + gap] = array[end];
			end -= gap;
		}
		array[end + gap] = tmp;
	}
}


//SelectSort
void SelectSort(int *array, size_t size)
{
	assert(array);
	int left = 0;
	int right = size - 1;
	while (left<right)
	{
		int min = left;
		int max = left;
		int tmp = 0;
		for (size_t index = left + 1; index < right+1; ++index)
		{
			if (array[index] <= array[min])
			{
				min = index;
			}
			else if (array[index]>=array[max])
			{
				max = index;
			}
		}
		tmp = array[max];
		swap(array[left], array[min]);
		if (array[max] != tmp)
		{
			swap(array[min], array[right]);
		}
		else
		{
			swap(array[max], array[right]);
		}
		++left;
		--right;
	}
}

//HeapSort
void AdjustDown(int *array, size_t root, size_t size)
{
	assert(array);
	int child = 2 * root + 1;
	while (child<size)
	{
		if (child + 1 < size && array[child + 1] > array[child])
		{
			child++;
		}
		if (array[child] > array[root])
		{
			swap(array[child], array[root]);
			root = child;
			child = 2*root + 1;
		}
		else
		{
			break;
		}
	}

}
void HeapSort(int *array, size_t size)
{
	assert(array);
	//1�������һ����Ҷ�ӽڵ㿪ʼ   ����
	int root = (size - 2) / 2;
	while (root >= 0)
	{
		AdjustDown(array, root, size);
		root--;
	}
	//2����ͷ�����һ��Ԫ�ؽ��������޳������һ��(��size--)�����µ���
	for (size_t index = size - 1; index > 0; --index)
	{
		swap(array[0], array[index]);
		AdjustDown(array, 0, index);
	}
}


//QuickSort
//1���ݹ�
int PartSort(int *array,int left, int right)
{
	assert(array);
	int key = array[right];
	int begin = left;
	int end = right-1;
	while (begin < end)   //section
	{
		while (begin < end && array[begin] <= key)//�ҵ����
		{
			++begin;
		}
		while (begin < end && array[end] >= key)//�ҵ�С��
		{
			--end;
		}
		swap(array[begin], array[end]);
	}
	//�������������ֵ����key
	if (array[begin]>key)
	{
		swap(array[begin], array[right]);
		return begin;
	}
	//�������������ֵС��key
	else
	{
		return right;
	}
}
void SectionSort(int *array,int left, int right)
{
	assert(array);
	if (left < right)
	{
		int boundary = PartSort(array, left, right);

		SectionSort(array, left, boundary - 1);
		SectionSort(array, boundary + 1, right);
	}
}


//2����������ݹ��Ż�--����ȡ��   
int GetMiddleIndex(int *array,int left, int right)
{ 
	assert(array);
	int mid = left + (right - left) / 2;
	int min = array[left] > array[right] ? right : left;
	if (array[min] > array[mid])
	{
		return min;
	}
	else
	{
		int second = right + left - min;
		if (array[second] > array[mid])
		{
			return mid;
		}
		else
		{
			return second;
		}
	}
}
int PartSort(int *array, int left, int right)
{
	assert(array);
	int key = array[right];
	int begin = left;
	int end = right-1;
	while (begin < end)   //section
	{
		while (begin < end && array[begin] <= key)//�ҵ����
		{
			++begin;
		}
		while (begin < end && array[end] >= key)//�ҵ�С��
		{
			--end;
		}
		swap(array[begin], array[end]);
	}
	//�������������ֵ����key
	if (array[begin]>key)
	{
		swap(array[begin], array[right]);
		return begin;
	}
	//�������������ֵС��key
	else
	{
		return right;
	}
}
 void SectionSort(int *array, int left, int right)
{
	assert(array);
	if (left < right)
	{
		if (right - left < 10)
		{
			int boundary = PartSort(array, left, right);

			SectionSort(array, left, boundary - 1);
			SectionSort(array, boundary + 1, right);
		}
		else
		{
			InsertSort(array + left, right - left + 1);
		}
	}
}
void QuickSort(int *array, size_t size)
{
	assert(array);
	int left = 0;
	int right = size - 1;
	SectionSort(array, left, right);
}

//3����������ǵݹ�
int PartSort(int *array, int left, int right)
{
	assert(array);
	int key = array[right];
	int begin = left;
	int end = right-1;
	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
		{
			++begin;
		}
		while (begin < end && array[end] >= key)
		{
			--end;
		}
		swap(array[begin], array[end]);
	}
	if (array[begin]>key)
	{
		swap(array[begin], array[right]);
		return left;
	}
	return right;
}

//ÿ�ε����䷶Χѹջ��ȡջ������PartSort����������������ѹջ���൱�������չ���ڵ�
void QuickSort2(int *array, size_t size)
{
	assert(array);
	int left = 0;
	int right = size-1;
	stack<int> s;

	if (left < right)
	{
		int mid = PartSort(array, left, right);
		//keyֵ�зֵ�����ѹջ
		if (left < mid - 1)
		{
			s.push(left);
			s.push(mid-1);
		}
		if (right>mid + 1)
		{
			s.push(mid + 1);
			s.push(right);
		}
	}
	while (!s.empty())
	{
		right = s.top();
		s.pop();
		left = s.top();
		s.pop();
		int mid = PartSort(array, left, right);
		if (left < mid-1)
		{
			s.push(left);
			s.push(mid - 1);
		}
		if (right>mid + 1)
		{
			s.push(mid + 1);
			s.push(right);
		}
	}
}

//�鲢����ݹ�
void SectionSort(int *array, int *tmp, int left1, int right1,int left2,int right2)
{
	assert(array);
	assert(tmp);
	int index = left1;
	while (left1 <= right1 && left2 <= right2)
	{
		if (array[left1] < array[left2])
		{
			tmp[index++] = array[left1++];
		}
		else
		{
			tmp[index++] = array[left2++];
		}
	}
	while (left1 <= right1)
	{
		tmp[index++] = array[left1++];
	}
	while (left2 <= right2)
	{
		tmp[index++] = array[left2++];
	}
	memcpy(array, tmp, index*sizeof(int));
}

void MergeSection(int *array, int *tmp, int left, int right)
{
	assert(array);
	assert(tmp);
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		MergeSection(array, tmp, left, mid);
		MergeSection(array, tmp, mid + 1, right);
		SectionSort(array, tmp, left, mid, mid + 1, right);	
	}
}
void MergeSort(int *array, size_t size)
{
	assert(array);
	int *tmp = new int[size];
	MergeSection(array, tmp, 0, size - 1);
	delete[] tmp;
}


//�鲢����ǵݹ�
void SectionSort1(int *array, int *tmp, int left1, int right1, int left2, int right2)
{
	assert(array);
	assert(tmp);
	int index = left1;
	while (left1 <= right1 && left2 <= right2)
	{
		if (array[left1] < array[left2])
		{
			tmp[index++] = array[left1++];
		}
		else
		{
			tmp[index++] = array[left2++];
		}
	}
	while (left1 <= right1)
	{
		tmp[index++] = array[left1++];
	}
	while (left2 <= right2)
	{
		tmp[index++] = array[left2++];
	}
	memcpy(array, tmp, index*sizeof(int));
}


void MergeSortNonR(int *array, size_t size)
{
	assert(array);
	int *tmp = new int[size];
	assert(tmp);
	int gap = 1;
	while (gap < size)
	{
		int left1 = 0;
		int right1 = left1 + gap - 1;
		int left2 = left1 + gap;
		int right2 = left2 + gap - 1;
		while (right2 < size)
		{
			SectionSort1(array, tmp, left1, right1, left2, right2);
			if (right2 + (2 * gap) < size)
			{
				left1 += 2 * gap;
				right1 += 2 * gap;
				left2 += 2 * gap;
				right2 += 2 * gap;
			}
			else if (right2 == size - 1)
			{
				break;
			}
			else
			{
				SectionSort1(array, tmp, left1, right2, right2 + 1, size - 1);
				break;
			}
		}
		gap *= 2;
	}
}

void Print(int *array, size_t size)
{
	for (size_t index = 0; index < size; ++index)
	{
		cout << array[index] << " ";
	}
	cout << endl;
}