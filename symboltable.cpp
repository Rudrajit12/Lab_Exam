#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<ctype.h>

using namespace std;

int isKeyword(char buffer[])
{
	char keywords[32][10] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern",
		"float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch"
		,"typedef","union","unsigned","void","volatile","while"};
	int i, flag = 0;
	for(i=0;i<32;i++)
	{
		if(strcmp(keywords[i],buffer) == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}

int main()
{
	char ch,buffer[15],operators[] = "+-*/%=";
	ifstream fin("program.txt");
	int i,j = 0;

	if(!fin.is_open())
	{
		cout<<"Error opening file"<<endl;
		exit(0);
	}

	while(!fin.eof())
	{
		ch = fin.get();
		for(i=0;i<6;i++)
		{
			if(ch == operators[i])
				cout<<ch<<" is an operator "<<endl;
		}
		if(isalnum(ch))
		{
			buffer[j++] = ch;
		}
		else if((ch == ' ' || ch == '\n') && (j != 0))
		{
			buffer[j] = '\0';
			j = 0;
			if(isKeyword(buffer) == 1)
				cout<<buffer<<" is a keyword "<<endl;
			else
				cout<<buffer<<" is an identifier "<<endl;
		}
	}
	fin.close();
	return 0;
}
