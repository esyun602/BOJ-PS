#include<string>
#include<iostream>
using namespace std;
string operator*(string a, int b){
	string ret = "";
    while(b--){
      ret+=a;
    }
    return ret;
}

int main(){
    string a;
	cin >> a;
    a=a*5;
    cout << a;
}
