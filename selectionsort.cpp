#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int smallest(int arr[],int k,int n)
{
	int i, pos = k, small = arr[k];
	for(i=k+1;i<n;i++)
	{
		if(arr[i] < small)
		{
			small = arr[i];
			pos  = i;
		}
	}
	return pos;
}

void selectionsort(int arr[],int n)
{
	int k,pos,temp;
	for(k=0;k<n;k++)
	{
		pos = smallest(arr,k,n);
		temp = arr[k];
		arr[k] = arr[pos];
		arr[pos] = temp;
	}
}

int main()
{
	int arr[10],i,n;
	cout<<"Enter the number of elements:";
	cin>>n;
	srand(time(0));
	cout<<"Enter the array:"<<endl;
	for(i=0;i<n;i++)
	{
		arr[i] = rand()%100;
		cout<<" "<<arr[i];
	}
	selectionsort(arr,n);
	cout<<endl<<"The sorted array is:"<<endl;
	for(i=0;i<n;i++)
		cout<<" "<<arr[i];
}