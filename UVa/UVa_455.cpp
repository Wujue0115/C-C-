#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include<bits/extc++.h>
using namespace std;
#define io ios::sync_with_stdio(0); cin.tie(0);
#define Filex
#define fi first
#define se second

typedef long long ll;

int main(){
    io;
    #ifdef File
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    const int MAX=1e4;

    int n;
    string s;
    int failures[MAX],ans,len;

    function<void()> Failures=[&](){
        failures[0]=0;

        for( int i=1 ; i<s.size() ; ++i ){
            int j=failures[i-1];
            while( j>0 && s[i]!=s[j] ){
                j=failures[j-1];
            }

            failures[i]=( s[i]==s[j] ? j+1 : 0 );
        }
    };
    
    cin >> n;
    while( n-- ){
        cin >> s;

        Failures();

        for( ans=1 ; (ans<<1)<=s.size() ; ++ans ){
            if( s.size()%ans ) continue;

            for( len=(ans<<1) ; len<=s.size() ; len+=ans ){
                if( failures[len-1]+ans!=len ){
                    goto loop;
                }
            }

            break;

            loop:
            continue;
        }

        cout << ( (ans<<1)>s.size() ? s.size() : ans ) << '\n';
        if( n ) cout << '\n';
    }
}