#include <bits/stdc++.h> 
using namespace std; 

char arr[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; 
int freq[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int no_of_bit[26];
int no_of_characters=26;

struct MinHeapNode 
{ 
	char data; 
	unsigned freq; 
	MinHeapNode *left, *right; 
	MinHeapNode(char data, unsigned freq) 
	{ 
		left = right = NULL; 
		this->data = data; 
		this->freq = freq; 
	} 
}; 

struct compare 
{ 
	bool operator()(MinHeapNode* l, MinHeapNode* r) 
	{ 
		return (l->freq > r->freq); 
	} 
}; 

void count_character_freq(string filename)
{
	fstream f;
	f.open(filename,ios::in);
	char ch;

	f>>ch;
	while(!f.eof())
	{
		int x = (int)ch;
		if(ch!=' '&& isalpha(ch))
			freq[(x-65)]++;
		f>>ch;
	}
	f.close();
}

void printCodes(struct MinHeapNode* root, string str,int n) 
{ 

	int i;

	if (!root)
		return; 
	if (root->data != '$')
	{
		cout << root->data << ": " << str <<" "<<n<<"\n"; 
		for(i=0;i<no_of_characters;i++)
		{
			if(arr[i]==root->data)
			{
				no_of_bit[i] = n;
				break;
			}
		}

	}
	

	printCodes(root->left, str + "0",n+1); 
	printCodes(root->right, str + "1",n+1); 
} 


void HuffmanCodes(char data[], int freq[], int size) 
{ 
	struct MinHeapNode *left, *right, *top;  
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap; 

	for (int i = 0; i < size; ++i) 
		if(freq[i]!=0)
			minHeap.push(new MinHeapNode(data[i], freq[i])); 

	while (minHeap.size() != 1) 
	{ 

		left = minHeap.top(); 
		minHeap.pop(); 
		right = minHeap.top(); 
		minHeap.pop(); 
		top = new MinHeapNode('$', left->freq + right->freq); 
		top->left = left; 
		top->right = right; 
		minHeap.push(top); 
	} 
	printCodes(minHeap.top(), "",0); 
} 

 
int main() 
{ 

	count_character_freq("file.txt");
	float p, avg_bit_size=0;

	int size = sizeof(arr) / sizeof(arr[0]); 

	HuffmanCodes(arr, freq, size);
	cout<<endl;

	cout<<"**************************************************************"<<endl; 

	for(int i=0;i<no_of_characters;i++)
	{
		p = (((float)freq[i]/100)*no_of_bit[i]);
		if(freq[i]!=0)
			cout<<arr[i]<<":\t"<<(float)freq[i]/100<<"\t"<<no_of_bit[i]<<"\t"<<p<<endl;
		avg_bit_size+=p;
	}

	cout<<endl;
	cout<<"Average bits/character: "<<avg_bit_size<<endl;
	cout<<"Total size of the Msg File: "<<((avg_bit_size*100)/8)<<" bytes";
	
	return 0; 
} 