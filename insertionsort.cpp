#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>

using namespace std;
using namespace std::chrono;

void insertionsort(int arr[],int size)
{
	int i,j,temp = 0, comp = 0;
	for(i=1;i<size;i++)
	{
		temp = arr[i];
		j = i - 1;
		comp++;
		while((temp <= arr[j]) && (j >= 0))
		{
			arr[j+1] = arr[j];
			j--;
			comp++;
		}
		arr[j+1] = temp;
	}
	cout<<endl<<"The number of comparisons ="<<comp<<endl;
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
	insertionsort(arr,size);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop-start);
	cout<<endl<<"The sorted array is:"<<endl;
	for(i=0;i<size;i++)
		cout<<" "<<arr[i];
	cout<<endl<<"The time taken by the function is:"<<duration.count()<<" microseconds "<<endl;
}