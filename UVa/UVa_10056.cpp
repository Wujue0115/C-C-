#include<iostream>
#include<cmath>
#include<iomanip>

#define eps 1e-9

using namespace std;

int main(){
	int t,n,k;
	double p,ans,np;
	
	cin >> t;
	while( t-- ){
		cin >> n >> p >> k;
		
		ans=0;
		for( int i=0 ; i<100000 ; ++i ){
			np=pow((1-p),i*n)*pow((1-p),k-1)*p;
			ans+=np;
			if( np<eps ) break;
		}
		
		cout << fixed << setprecision(4) << ans << endl;
	}
}