#include <iostream>
#include <algorithm>
using namespace std;

void merge(int a[],int l,int m,int h)
{
    int n1,n2,i,j,k;
    n1=(m-l+1);
    n2=(h-m);
    int ar1[n1],ar2[n2];
    for(i=0;i<n1;i++)
        ar1[i]=a[l+i];
    for(i=0;i<n2;i++)
        ar2[i]=a[m+1+i];
    i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(ar1[i]<=ar2[j])
            a[k++]=ar1[i++];
        else
            a[k++]=ar2[j++];
    }
    while(i<n1)
        a[k++]=ar1[i++];
    while(j<n2)
        a[k++]=ar2[j++];
        
}
void mergesort(int a[],int n)
{
    int cur_size, left_end;
    
    for(cur_size = 1; cur_size < n; cur_size = 2*cur_size) {
        for(left_end = 0; left_end < n-1; left_end += 2*cur_size) {
            int mid = left_end + cur_size - 1;
            int right_end = min(n-1, left_end + 2*cur_size - 1);
            merge(a, left_end, mid, right_end);
        }
    }
}
int main() {
	int n,i;
	cin>>n;
	int* a=new int[n];
	for(i=0;i<n;i++)
	    cin>>a[i];
	mergesort(a,n);
	for(i=0;i<n;i++)
	    cout<<a[i]<<" ";
	delete []a;   
	return 0;
}
