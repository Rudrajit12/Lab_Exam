#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>

using namespace std;
using namespace std::chrono;

void swap(float *a,float *b)
{
	float temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubblesort(float arr[],int size)
{
	int i,j,comp = 0;
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			comp++;
			if(arr[j] > arr[j+1])
				swap(&arr[j],&arr[j+1]);
		}
	}
	cout<<endl<<"The number of comparisons ="<<comp<<endl;
}

void print(float arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
		cout<<" "<<arr[i];
}

int main()
{
	int i,size;
	float arr[10];
	cout<<"Enter the number of elements";
	cin>>size;
	srand(time(0));
	cout<<"Enter the array:"<<endl;
	for(i=0;i<size;i++)
	{
		arr[i] = rand()%100;
		cout<<" "<<arr[i];
	}
	auto start = high_resolution_clock::now();
	bubblesort(arr,size);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop-start);
	cout<<endl<<"The sorted array is:"<<endl;
	print(arr,size);
	cout<<endl<<"The time taken by the function is:"<<duration.count()<<" microseconds "<<endl;
}