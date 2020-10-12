#include<iostream>
#include<string>

using namespace std;

int main(){
	string s,key="`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	
	while( getline(cin,s) && s!="" ){
		for( int i=0 ; i<s.length() ; ++i ){
			if( s[i]>='A' && s[i]<='Z' ){
				s[i]+='a'-'A';
			}
			
			bool Print=false;
			for( int j=0 ; j<key.length() ; ++j ){
				if( s[i]==key[j] ){
					cout << key[(key.length()+j-2)%key.length()];
					Print=true;
				}
			}
			if( !Print ){
				cout << s[i];
			}
		}
		cout << endl;
	}
}