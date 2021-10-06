#include<stdio.h>

int comparison(int arr1[], int arr2[]){
    if(arr1[0]<arr2[0]&&arr1[1]<arr2[1])
    	return 0;
    return 1;
}


int main()
{
    int rank[50] = {};
    int arr[50][2] = {};
    int N;
    int i;
    scanf("%d", &N);
    for(i=0;i<N;i++)
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    for(int j=0;j<i;j++)
        for(int k=0;k<i;k++)
        {
            if(comparison(arr[j], arr[k])&& j!=k)
            {
            	rank[j]++;
            }
        }
    for(int j=0;j<i;j++){
        printf("%d ", i-rank[j]);
    }
}
