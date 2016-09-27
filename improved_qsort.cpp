#include <iostream>
using namespace std;

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

int partition(int a[],int l,int h)
{
    int pivot=a[h];
    int i=l-1;
    for(int j=l;j<h;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[h]);
    return (i+1);
}

void improved_qsort(int a[],int l,int h)
{
    while(l<h)
    {
        int p=partition(a,l,h);
        improved_qsort(a,l,p-1);
        l = p+1;
    }
}
int main()
{
    int n,i;
	cin>>n;
	int* a=new int[n];
	for(i=0;i<n;i++)
	    cin>>a[i];
	improved_qsort(a,0,n-1);
	for(i=0;i<n;i++)
	    cout<<a[i]<<" ";
    cout<<endl;
	delete []a;   
	return 0;
}
