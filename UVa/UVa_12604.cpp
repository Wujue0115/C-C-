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

    const int MAX=1e6;

    int n;
    string a,w,s;
    unordered_map<int,char> imap;
    unordered_map<int,char> cmap;
    string cw;
    int failures[MAX];
    vector<int> ans;

    function<void()> Failures=[&](){
        failures[0]=0;
        for( int i=1 ; i<w.size() ; ++i ){
            int j=failures[i-1];
            while( j>0 && w[i]!=w[j] ){
                j=failures[j-1];
            }

            failures[i]=( w[i]==w[j] ? j+1 : 0 );
        }
    };

    function<int()> Search=[&](){
        int i=0,j=0,sum=0;
        while( i<s.size() ){
            if( s[i]==cw[j] ){
                ++i; ++j;
                
                if( j==cw.size() ){
                    if( ++sum==2 ){
                        return sum;
                    }
                    i=i-j+1; j=0;
                }
            }
            else{
                j==0 ? ++i : j=failures[j-1];
            }
        }

        return sum;
    };
    
    cin >> n;
    while( n-- ){
        cin >> a >> w >> s;

        imap.clear();
        for( int i=0 ; i<a.size() ; ++i ){
            imap[i]=a[i];
            cmap[a[i]]=i;
        }

        Failures();

        ans.clear();
        for( int i=0 ; i<a.size() ; ++i ){
            cw=w;
            for( int j=0 ; j<cw.size() ; ++j ){
                cw[j]=imap[(cmap[cw[j]]+i)%a.size()];
            }

            if( Search()==1 ){
                ans.emplace_back(i);
            }
        }
        
        if( ans.size() ){
            cout << ( ans.size()>1 ? "ambiguous" : "unique" ) << ':';
            for( const auto &p: ans ){
                cout << ' ' << p;
            }
            cout << '\n';
        }
        else{
            cout << "no solution\n";
        }
    }
}