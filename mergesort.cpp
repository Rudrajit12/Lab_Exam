#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>

using namespace std;
using namespace std::chrono;
int comp = 0;

void merge(int arr[],int beg,int mid,int end)
{
	int i = beg, j = mid + 1, index = beg, temp[10] ,k;
	while((i <= mid) && (j <= end))
	{
		if(arr[i] < arr[j])
		{
			temp[index] = arr[i];
			i++;
		}
		else
		{
			temp[index] = arr[j];
			j++;
		}
		index++;
		comp++;
	}
	if(i > mid)
	{
		while(j <= end)
		{
			temp[index] = arr[j];
			j++;
			index++;
		}
	}
	else
	{
		while(i <= mid)
		{
			temp[index] = arr[i];
			i++;
			index++;
		}
	}
	for(k=beg;k<index;k++)
	{
		arr[k] = temp[k];
	}
}

void mergesort(int arr[],int beg,int end)
{
	int mid;
	if(beg < end)
	{
		mid = (beg + end)/2;
		mergesort(arr,beg,mid);
		mergesort(arr,mid+1,end);
		merge(arr,beg,mid,end);
	}
}

int main()
{
	int arr[10],size,i;
	cout<<"Enter the number of elements:";
	cin>>size;
	srand(time(0));
	cout<<"Enter the array:"<<endl;
	for(i=0;i<size;i++)
	{
		arr[i] = rand()%100;
		cout<<" "<<arr[i];
	}
	auto start = high_resolution_clock::now();
	mergesort(arr,0,size-1);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop-start);
	cout<<endl<<"The sorted array is:"<<endl;
	for(i=0;i<size;i++)
		cout<<" "<<arr[i];
	cout<<endl<<"Time taken by function:"<<duration.count()<<" microseconds "<<endl;
	cout<<"Number of comparisons ="<<comp<<endl;
}