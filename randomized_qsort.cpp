#include <iostream>
#include <cstdlib>
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

int randomized_partition(int a[], int l, int h) {
    int random_index = rand()%(h-l) + l;
    swap(a[random_index],a[h]);
    return partition(a,l,h);
}

void randomized_qsort(int a[],int l,int h)
{
    if(l<h)
    {
        int p=randomized_partition(a,l,h);
        randomized_qsort(a,l,p-1);
        randomized_qsort(a,p+1,h);
    }
}
int main()
{
    int n,i;
	cin>>n;
	int* a=new int[n];
	for(i=0;i<n;i++)
	    cin>>a[i];
	randomized_qsort(a,0,n-1);
	for(i=0;i<n;i++)
	    cout<<a[i]<<" ";
    cout<<endl;
	delete []a;   
	return 0;
}
