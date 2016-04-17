#include <iostream>
using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void heapify(int a[],int i,int n)
{
    int lc,rc,big=i;
    lc=2*i+1;
    rc=2*i+2;
    if(lc<n && a[lc]>a[big])
        big=lc;
    if(rc<n && a[rc]>a[big])
        big=rc;
    if(big!=i)
    {
        swap(a[i],a[big]);
        heapify(a,big,n);
    }
}

void buildheap(int a[],int n)
{
    for(int i=n/2;i>=0;i--)
        heapify(a,i,n);
}

void heapsort(int a[],int n)
{
    buildheap(a,n);
    while(n)
    {
        swap(a[0],a[n-1]);
        n=n-1;
        heapify(a,0,n);
    }    
}
int main()
{
	int n,i;
	cin>>n;
	int* a=new int[n];
	for(i=0;i<n;i++)
	    cin>>a[i];
	heapsort(a,n);
	for(i=0;i<n;i++)
	    cout<<a[i]<<" ";
	delete []a;    
	return 0;
}
