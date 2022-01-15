#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n;
    cin>>n;
    stack<int> s;
    int num=0;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        num+=s.size();
        while(!s.empty() && s.top()<tmp){
            s.pop();
        }
        s.push(tmp);
    }
    cout<<num;
}