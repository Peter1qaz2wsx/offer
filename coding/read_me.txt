 本次程序是学习测试主要的排序算法，并且把算法的主要思路总结，以便于自己的理解。
基础的排序算法：
1, 插入排序
主要的思路:
每次把对应需要排序位置的元素调整到前面对应的位置。从第二个位置开始，把序列分成两个主要的部分，左边是排好序的元素，右边是原始的序列。
插入的意思是，每次找到需要排序的元素的位置，把他后面的元素向后移动一位，然后把该元素插入。
void InsertSort(int a[], int k){
	for (int i = 1; i < k; ++i){
		int temp = a[i]; 
		int k = i-1;
		while(a[k]>=temp && k>=0){
			a[k+1] = a[k];
			k--;
		}
		a[k+1] = temp;	
	}

}
2, shell排序
主要的思路:
希尔排序实质上是一种分组插入方法。它的基本思想是：对于n个待排序的数列，取一个小于n的整数gap(gap被称为步长)将待排序元素分成若干个组子序列，所有距离为gap的倍数的记录放在同一个组中；然后，对各组内的元素进行直接插入排序。 这一趟排序完成之后，每一个组的元素都是有序的。然后减小gap的值，并重复执行上述的分组和排序。重复这样的操作，当gap=1时，整个数列就是有序的。
void ShellSort(int a[], int n){
	for(int grap = n/2; grap >0; grap/=2){
		
		for(int i = 0; i<grap; i++){

			for(int j =i+grap; j<n; j+=grap){
				int k = j-grap;
				int temp = a[j];
				while(a[k]>=temp && k>=0){
					a[k+grap] = a[k];
					k-=grap;
				}
				a[k+grap] = temp;
			}

		}
	}
}

3, 冒泡排序
主要的思路:
想泡沫一样，每一次排序把最大的向后交换。最后所有的数都排好序了。
void BubbleSort(int a[],int n ){
	for(int i = 0; i< n; ++i){
		for(int j = 1; j<n-i; ++j){
			if(a[j]<a[j-1])
				swap(a[j],a[j-1]);
		}
	}
}
4, 归并排序
主要的思路:
把需要排序的序列分成多个子序列，最后使得每个子序列含有1个元素。然后把每两个有序的子序列合成一个有序的子序列，最后得到有序的序列。算法的关键是，两个有序的子序列合成一个有序的子序列的子函数。需要增加内存消耗。
void Merge(int a[], int low, int high, int mid){
	int b[high-low+1];
	int i = low, j = mid+1;
	int m = mid, n= high;
	int k = 0;
	while(i<=m&&j<=n){
		if(a[i]<=a[j]){
			b[k++] = a[i++];
		}else{
			b[k++] = a[j++];
		}
	}
	while(i<=m){
		b[k++] = a[i++];
	}
	while(j<=n){
		b[k++] = a[j++];
	}
	for(int i = low; i<=high; ++i){
		a[i] = b[i-low];
	}
}

void MergeSort(int a[], int low, int high ){
	if(low<high){
		int mid = (high+low)/2;
		MergeSort(a,low,mid);
		MergeSort(a,mid+1,high);
		Merge(a,low,high,mid);

	}

}

5,快速排序
主要思路：
应用了分而治之的思路，每次把所有的序列二分，把大于基准项（取第一个）的元素放到中间向的右边，小于的放到左边，然后把左右的序列进行相同的操作。那么，每次操作可以把中间项的位置排好。所以，当序列为最小时，既可以完成序列的排序。
问题：子函数，怎么存储大于小于基准项的元素？
while(low<high) 作为循环条件，把所有的元素都考虑到了。同时，初始化，从最后的元素开始，找到小于基准的元素，赋值到最左边，然后找大于基准左边的元素，赋值到右边，循环进行。
//quick_sort
int Partition(int a[], int low, int high){
	int pivot = a[low];
  	while(low<high){
  		while(low<high && a[high]>=pivot){
  			high--;
  		}
  		a[low] = a[high];
  		while(low<high && a[low]<=pivot){
  			low++;
  		}
  		a[high] = a[low];	
  	}
  	a[low] = pivot;
  	return low;
}

void QuickSort(int a[], int low, int high){
	if(low<high){
		int temp = Partition(a,low,high);
		QuickSort(a,low,temp-1);
		QuickSort(a,temp+1,high);
	}
	
}


6, 选择排序
是一种简单直观的排序算法，无论什么数据进去都是O（n2）的时间复杂度。所以用到它的时候，数据规模越小越好。
不用消耗额外的空间。
算法主要思路：
每次遍历序列找出最小的元素，然后和地一个元素进行交换，然后遍历剩下的序列。
//选择排序
void SelectSort(int a[], int n){
    for (int i = 0; i < n; ++i){
        int temp = i;
        for (int j = i+1; j < n; ++j){
            if(a[j]<=a[temp])
                temp = j;        
        }
        swap(a[i],a[temp]);
    }
}

7,堆排序



