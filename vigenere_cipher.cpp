#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int normalise(int value, int method)
{
	int normalisedValue = value%123;
	if(normalisedValue < 65)
	{
		if(method == 0)
	 		normalisedValue += 65;
		else {
			normalisedValue = 123 + normalisedValue - 65;
		}
	}
	return normalisedValue;
}

string encrypt(string p, string k)
{
	string c = "";
	int i = 0;
	for(auto ch: p)
	{
		if(ch >= 'A' && ch <= 'z')
		{
			c = c + char(normalise(int(ch) + int(k[i] - 'A'), 0));
			i++;
		}
		i %= k.length();
	}
	return c;
}

string decrypt(string c, string k)
{
	string p = "";
	int i = 0;
	for(auto ch: c)
	{
		p = p + char(normalise(int(ch) - int(k[i] - 'A'), 1));
		i++;
		i %= k.length();
	}
	return p;
}

int main()
{
	string k;
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
				cin>>k;
				cout<<"Encrypted String is "<<encrypt(p,k)<<endl;
				break;
			case 2: 
				cout<<"Enter Cypher text: ";
				cin.ignore();
				getline(cin, p, '\n');
				cout<<"Enter shift value: ";
				cin>>k;
				cout<<"Decrypted String is "<<decrypt(p,k)<<endl;
				break;
			case 3: exit(0);
			default: 
				cout<<"Wrong Choice!!!!!!!!!!!!!\n";
				break;
		}
	} while(t != 3);
	return 0;
}
