#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

string encrypt(string p, int n)
{
	string c = "";
	for(auto ch: p)
	{
		if(ch != ' ')
			c = c + char(int(ch) + n);
	}
	return c;
}

string decrypt(string c, int n)
{
	string p = "";
	for(auto ch: c)
	{
		p = p + char(int(ch) - n);
	}
	return p;
}

int main()
{
	int n;
	string p;
	int t;
	do{

		cout<<"Do you want to encrypt(1), decrypt(2) or exit(3): ";
		cin>>t;
		switch(t){
			case 1:
				cout<<"Enter passphrase to encrypt: ";
				cin.ignore();
				getline(cin, p, '\n');
				cout<<"Enter Shift value: ";
				cin>>n;
				cout<<"Encrypted String is "<<encrypt(p,n)<<endl;
				break;
			case 2: 
				cout<<"Enter Cypher text: ";
				cin.ignore();
				getline(cin, p, '\n');
				cout<<"Enter shift value: ";
				cin>>n;
				cout<<"Decrypted String is "<<decrypt(p,n)<<endl;
				break;
			case 3: exit(0);
			default: 
				cout<<"Wrong Choice!!!!!!!!!!!!!\n";
				break;
		}
	} while(t != 3);
	return 0;
}
