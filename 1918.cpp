#include<bits/stdc++.h>
using namespace std;
typedef pair<char,double> pcd;
int main(){
    stack<pair<char, double>> operators;
    int bracketCount=0;
    map<char,double> priority;
    priority['*'] = priority['/'] = 0.5;
    priority['+'] = priority['-'] = 0;
    string s;
    string ret = string();
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]-'A'>=0 && s[i]-'A'<=25){
            ret += s[i];
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            if(operators.empty()){
                operators.push({s[i], priority[s[i]] + bracketCount});
                continue;
            }
            pcd  tmp = operators.top();
            if(tmp.second> priority[s[i]] + bracketCount){
                while(!operators.empty() &&operators.top().first != '('){
                    ret += operators.top().first;
                    operators.pop();
                }
            }
            else if(tmp.second == priority[s[i]] + bracketCount){
                ret += operators.top().first;
                operators.pop();
            }
            operators.push({s[i], priority[s[i]] + bracketCount});
        }
        else{
            if(s[i] == '('){
                operators.push({s[i],0});
                bracketCount++;
            }
            else if(s[i]==')'){
                while(!operators.empty() && operators.top().first != '('){
                    ret += operators.top().first;
                    operators.pop();
                }
                operators.pop();
                bracketCount--;
            }
        }
    }
    while(!operators.empty()){
        ret += operators.top().first;
        operators.pop();
    }
    cout<<ret;
}