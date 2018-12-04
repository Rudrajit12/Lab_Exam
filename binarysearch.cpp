#include<iostream>
#include<cstdlib>

using namespace std;

int binarysearch(int arr[],int beg,int end,int key)
{
	while(beg <= end)
	{
		int mid = (beg + end)/2;
		if(arr[mid] == key)
			return mid;
		else if(arr[mid] > key)
			return binarysearch(arr,beg,mid-1,key);
		else
			return binarysearch(arr,mid+1,end,key);
	}
	return -1;
}

int main()
{
	int arr[10];
	int i,key,size,result;
	cout<<"Enter the number of elements:";
	cin>>size;
	cout<<"Enter the array:"<<endl;
	for(i=0;i<size;i++)
		cin>>arr[i];
	cout<<"Enter the value to be searched:";
	cin>>key;
	result = binarysearch(arr,0,size-1,key);
	(result == -1)?cout<<"Value not found in array":cout<<"Value found in position"<<" "<<result<<endl;
}