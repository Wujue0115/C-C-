#include<iostream>
#include<iomanip>

using namespace std;

int main(){
	double Point[4][2],x,y;
	int a,b;
	
	while( cin >> Point[0][0] >> Point[0][1] ){
		for( int i=1 ; i<4 ; ++i ){
			cin >> Point[i][0] >> Point[i][1];
			for( int j=0 ; j<i ; ++j ){
				if( Point[i][0]==Point[j][0] && Point[i][1]==Point[j][1] ){
					a=i;
					b=j;
				}
			}
		}
		
		x=Point[a][0];
		y=Point[a][1];
		for( int i=0 ; i<4 ; ++i ){
			if( i!=a && i!=b ){
				x+=Point[i][0]-Point[a][0];
				y+=Point[i][1]-Point[a][1];
			}
		}
		
		cout << fixed << setprecision(3) << x << " " << y << endl;
	}
}