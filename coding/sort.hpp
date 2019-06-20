#include <iostream>
#include <cmath>
#include <string>

using namespace std;

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

//bubble sort

void BubbleSort(int a[],int n ){
	for(int i = 0; i< n; ++i){
		for(int j = 1; j<n-i; ++j){
			if(a[j]<a[j-1])
				swap(a[j],a[j-1]);
		}
	}
}
//Insert sort  插入排序
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
//Shell sort
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