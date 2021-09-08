#include<bits/stdc++.h>

int maximum(int arr[], int start, int end)
{
    int max = arr[start];
    int index = start;
    for(int i=start+1; i<end; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
            index = i;
        }
    }
    return index;
}


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void largest_permutation(int arr[], int n, int k)
{
    for(int i=0; i<n; i++)
    {
        int pos = maximum(arr,i,n);

        if(k>0 && pos!=i)
        {
            swap(&arr[pos], &arr[i]);
            k--;
        }
    }
}
int main()
{
    int *arr;

    int n ;
    int k;
    scanf("%d %d",&n,&k);
    arr=(int*)malloc(sizeof(int)*n+5);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    largest_permutation(arr,n,k);
    for(int i=0; i<n; i++)
    printf("%d ",arr[i]);
    return 0;
}
