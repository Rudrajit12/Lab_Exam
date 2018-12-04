#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	int arr[10], num, i, size, found = 0, pos = -1;
	cout<<"Enter the number of elements:";
	cin>>size;
	srand(time(0));
	cout<<"Enter the array:"<<endl;
	for(i=0;i<size;i++)
	{
		arr[i] = rand()%100;
		cout<<" "<<arr[i];
	}
	cout<<endl<<"Enter the number to be searched:";
	cin>>num;
	for(i=0;i<size;i++)
	{
		if(arr[i] == num)
		{
			found = 1;
			pos = i;
			cout<<num<<" found in position "<<i<<endl;
		}
	}
	if(found == 0)
	{
		cout<<num<<" not found in the array ";
	}
}