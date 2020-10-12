#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include<bits/extc++.h>
using namespace std;
#define io ios::sync_with_stdio(0),cin.tie(0)
#define Filex
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

int main(){
    io;
    #ifdef File
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    int n,k,m;
    int a,b,finds,visit[20];

    function<pii()> Solve=[&](){
        int acounts=0;
        while( true ){
            if( visit[a]==0 ){
                if( ++acounts==k ){
                    break;
                }
            }
            a=(a+1)%n;
        }

        int bcounts=0;
        while( true ){
            if( visit[b]==0 ){
                if( ++bcounts==m ){
                    break;
                }
            }
            b=( b-1<0 ? n-1 : b-1 );
        }

        visit[a]=visit[b]=1;

        return make_pair(a+1,b+1);
    };

    while( cin >> n >> k >> m && n|k|m ){
        a=0; b=n-1;
        finds=0;
        memset(visit,0,sizeof(visit));
        while( finds<n ){
            pii p=Solve();

            if( p.fi!=p.se ){
                cout << setw(3) << p.fi;
                cout << setw(3) << p.se;

                ++++finds;
            }
            else{
                cout << setw(3) << p.fi;

                ++finds;
            }

            if( finds && finds!=n ) cout << ',';
        }
        cout << '\n';
    }
}