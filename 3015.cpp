#include<iostream>
#include<stack>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;
    stack<int> s;
    map<int,int> m;
    long long num=0;
    int tmp;
    int val=-1;
    int add=1;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(!s.empty()&&s.top()>=tmp){
            if(val==tmp){
                m[val]++;
            }
            else{
                m[tmp]=1;
            }
            num+=m[tmp];
            val = tmp;
        }
        else if(!s.empty()){
            
            while(!s.empty() && s.top()<tmp){
                m[s.top()] = 0;
                s.pop();
                num++;
            }
            if(m.find(tmp)==m.end()){
                m[tmp] = 1;
            }
            else{
                m[tmp]++;
            }
            if(!s.empty()){
                num+=m[tmp];
            }
            else{
                m[tmp]=0;
            }
            val = tmp;
        }
        s.push(tmp);
    }
    cout<<num;
}