#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

int main(){
	int t,r,mid,ans;
	vector<int> s;
	
	cin >> t;
	while( t-- ){
		cin >> r;

		s.assign(r,0);
		for( int i=0 ; i<r ; ++i ){
			cin >> s[i];
		}
		
		sort(s.begin(),s.end());

		mid=s[r/2];
		ans=0;
		for( int i=0 ; i<r ; ++i ){
			ans+=abs(s[i]-mid);
		}
		
		cout << ans << endl;
	}
}