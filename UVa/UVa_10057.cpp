#include<iostream>
#include<algorithm>

using namespace std;

int num[1000005];

int main(){
	int n,mid,mid2,counts;
	
	while( cin >> n ){
		for( int i=0 ; i<n ; ++i ){
			cin >> num[i];
		}
		
		sort(num,num+n);
		
		mid=num[(n-1)/2];
		if( n%2==0 ){
			mid2=num[n/2];
		}
		
		counts=0;
		for( int i=0 ; i<n ; ++i ){
			if( n%2 ){
				if( num[i]==mid ){
					++counts;
				}
			}
			else{
				if( num[i]==mid || num[i]==mid2 ){
					++counts;
				}
			}
		}
		
		cout << mid << " " << counts << " ";
		if( n%2 ){
			cout << "1" << endl;
		}
		else{
			cout << (mid2-mid)+1 << endl;
		}
	}
}