#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>

using namespace std;
using namespace std::chrono;
int comp = 0;

int partition(int arr[],int beg,int end)
{
	int left,right,loc,temp,flag;
	loc = left = beg;
	right = end;
	flag = 0;
	while(flag != 1)
	{
		while((arr[loc] <= arr[right]) && (loc != right))
		{
			right--;
			comp++;
		}
		if(loc == right)
			flag = 1;
		else if (arr[loc] > arr[right])
		{
			temp = arr[loc];
			arr[loc] = arr[right];
			arr[right] = temp;
			loc = right;
		}
		if(flag != 1)
		{
			while((arr[loc] >= arr[left]) && (loc != left))
			{
				left++;
				comp++;
			}
			if(loc == left)
				flag = 1;
			else if (arr[loc] < arr[left])
			{
				temp = arr[loc];
				arr[loc] = arr[left];
				arr[left] = temp;
				loc = left;
			}
		}
	}
	return loc;
}

void quicksort(int arr[],int beg,int end)
{
	int loc;
	if(beg < end)
	{
		loc = partition(arr,beg,end);
		quicksort(arr,beg,loc-1);
		quicksort(arr,loc+1,end);
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
	quicksort(arr,0,size-1);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop-start);
	cout<<endl<<"The sorted array is:"<<endl;
	for(i=0;i<size;i++)
		cout<<" "<<arr[i];
	cout<<endl<<"Time taken by the function : "<<duration.count()<<" microseconds "<<endl;
	cout<<"Number of comparisons = "<<comp<<endl;
}