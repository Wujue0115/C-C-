#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int main(){
	string s;
	int odd,even;
	
	while( getline(cin,s) && s!="0" ){
		odd=even=0;
		for( int i=0 ; i<s.size() ; ++i ){
			if( i%2 ){
				odd+=s[i]-'0';
			}
			else{
				even+=s[i]-'0';
			}
		}
		
		if( abs(odd-even)%11==0 ){
			cout << s << " is a multiple of 11." << endl;
		}
		else{
			cout << s << " is not a multiple of 11." << endl;
		}
	}
}