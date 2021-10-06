#include<bits/stdc++.h>
using namespace std;
multiset<int, greater<int> > s;

void solve(){
    int k, tmp;
    char IorD;
    scanf("%d", &k);
    getchar();
    
    multiset<int>::iterator M = s.begin();
    multiset<int>::iterator m = s.end();
    s.clear();
    
    while(k--){
        IorD = getchar();
        scanf("%d", &tmp);
        getchar();
        if(IorD=='I'){
            s.insert(tmp);
        	m = s.end(); m--;
        	M = s.begin();
        }
        else{
            if(!s.empty()){
                if(tmp==1){
                    s.erase(M);
                    M = s.begin();
                    m = s.end();
                    s.empty() ? m : --m;
                }
                else
                {
                    s.erase(m);
                    m = s.end();
                    s.empty() ? m : --m;
                    M = s.begin();
                }
            }
        }
    }  
	if(s.empty())
           printf("EMPTY\n");
    else
    {
        printf("%d %d\n", *M, *m);
    }
}

int main(){
   
    int t;
    scanf("%d", &t);
    while(t--)  solve();
}
