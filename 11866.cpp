#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    int k; 
    int i=0;
    int j=0;
    cin >> n >> k ;
    int count=0;
    vector<int> v;
    cout<<"<";
    bool die[1001] = {};
    while(count!=n){
        i++;
		if(i>n)
            i=1;
        if(die[i])
        	continue;
        j++;
        if(j%k==0){
            v.push_back(i);
            die[i]= true;
            count++;
        }
    }
	for(int i=0;i<v.size();i++){
		cout<<v[i];
		if(i!=v.size()-1){
			cout<<", ";
		}
	}
	cout<<">";
}
