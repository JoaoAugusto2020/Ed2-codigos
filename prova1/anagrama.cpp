#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<ctype.h>

#define MAX 1000

using namespace std;

void buscarSubstring(string str1, string str2) {
	char p1[MAX], p2[MAX];
	
	strcpy(p1, str1.c_str());
	strcpy(p2, str2.c_str());
	
	cout<<p1<<endl;
	cout<<p2<<endl;
	
	
	if(strstr(p1,p2)!=NULL){
		cout<<"sim"<<endl;
	}else{
		cout<<"nao"<<endl;
	}
}

int main(){
	string str1, str2;
	
	cin>>str1;
	fflush(stdin);
	cin>>str2;
	
	reverse(str1.begin(),str1.end());
	
	buscarSubstring(str1, str2);
	
	return 0;
}
