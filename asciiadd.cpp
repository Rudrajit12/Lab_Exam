#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

int main()
{
	char first_name[100], last_name[100];
	int k = 0,i;
	long sum = 0,sum1 = 0,sum2 = 0;
	cout<<"Enter first and second name";
	cin>>first_name>>last_name;
	for(i=0;i<strlen(first_name);i++)
	{
		k = (int)(first_name[i]);
		sum1 += k;
		if(i<(strlen(first_name)-1))
		{
			if((int)first_name[i+1] >= 100)
				sum1 = sum1 * 1000;
			else
				sum1 = sum1 * 100;
		}
	}
	cout<<"ASCII value of first name is"<<sum1<<endl;
	k = 0;
	for(i=0;i<strlen(last_name);i++)
	{
		k = (int)(last_name[i]);
		sum2 += k;
		if(i<(strlen(last_name)-1))
		{
			if((int)last_name[i+1] >= 100)
				sum2 = sum2 * 1000;
			else
				sum2 = sum2 * 100;
		}
	}
	cout<<"ASCII value of last name is:"<<sum2<<endl;
	sum = sum1 + sum2;
	cout<<"Sum of ASCII values of first name and last name is:"<<sum<<endl;
}