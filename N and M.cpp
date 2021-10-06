#include <bits/stdc++.h>
using namespace std;
int num[10] ={};

void showVector(vector<int>& v, int n){
    for(int i=0;i<n;i++)
        printf("%d ", v[i]);
}

void p(int n, int r, int level, vector<int>& v){
    if(level == r)
    {
        showVector(v, v.size());
        printf("\n");
        return;
    }
    for(int i=0;i<n;i++){
        if(num[i]==0)
        {
            num[i]++;   
            v.push_back(i+1);
            p(n, r, v.size(), v);
            v.pop_back();
            num[i]=0;
        }
    }
}

int main()
{
    vector<int> v;
    int n, m;
    scanf("%d %d", &n, &m);
    p(n, m, 0, v);
}
