#include<bits/stdc++.h>
using namespace std;
vector<int> mergeSort(vector<int>& arr){
    vector<int> a1(arr.begin(), arr.begin()+arr.size()/2);
    vector<int> a2(arr.begin()+arr.size()/2, arr.end());
    
    for(int i=0;i<arr.size();i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    if(arr.size()>2){
    	a1 = mergeSort(a1);
    	a2 = mergeSort(a2);
	}  
	
	
	
    if(a1.size()>a2.size())
        swap(a1, a2);
    
    vector<int> ret;
    int i=0,j=0;
    while(a1.size()>i || a2.size()>j){
    	if(a1.size() == i){
    		ret.push_back(a2[j]);
            j++;
		}
    	else if(a2.size() == j){
    		ret.push_back(a1[i]);
            i++;
		}
    	
        else if(a1[i]>=a2[j]){
            ret.push_back(a2[j]);
            j++;
        }
        else{
            ret.push_back(a1[i]);
            i++;
        }
    }
     for(int i=0;i<ret.size();i++){
        printf("%d ", ret[i]);
    }
    printf("\n");
    
    
    
    return ret;
}

int main(){
    int arr[9] = {9,8,7,6,5,4,3,2,1};
    vector<int> ar;
    for(int i=0;i<9;i++){
        ar.push_back(arr[i]);
    }
    
     for(int i=0;i<ar.size();i++){
        printf("%d ", ar[i]);
    }
    printf("\n");
    
    vector<int> ar2 = mergeSort(ar);
    for(int i=0;i<ar2.size();i++){
        printf("%d ", ar2[i]);
    }
    printf("\n");
}
