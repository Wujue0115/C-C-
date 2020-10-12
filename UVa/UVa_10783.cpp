#include<iostream>

using namespace std;

int oddSum[101];

void init(){
	oddSum[0]=0;
	for( int i=1 ; i<100 ; i+=2 ){
		oddSum[i]=oddSum[i+1]=oddSum[i-1]+i;
	}
}

int main(){
	int T,a,b;
	
	init();
	
	cin >> T;
	for( int i=1 ; i<=T ; ++i ){
		cin >> a >> b;
		
		cout << "Case " << i << ": " << oddSum[b]-oddSum[a-1] << endl;
	}
}