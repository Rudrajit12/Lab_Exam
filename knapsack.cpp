#include<iostream>

using namespace std;

int max(int a,int b)
{
	return(a > b)? a : b;
}

int knapsack(int cap,int wt[],int val[],int n)
{
	int i,w;
	int K[n+1][cap+1];
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=cap;w++)
		{
			if(i == 0 || w == 0)
			{
				K[i][w] = 0;
			}
			else if(wt[i-1] <= w)
			{
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],K[i-1][w]);
			}
			else
				K[i][w] = K[i-1][w];
		}
	}
	return K[n][cap];
}

int main()
{
	int i,n,cap;
	int val[n],wt[n];
	cout<<"Enter the number of elements in the knapsack:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter the value and weight of item"<<i<<" : ";
		cin>>val[i];
		cin>>wt[i];
	}
	cout<<"Enter the total capacity of the knapsack:";
	cin>>cap;
	cout<<"Total value inside the knapsack is:"<<knapsack(cap,wt,val,n);
}