#include <iostream>
#include <stack>
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

void quicksort(int a[],int l,int h)
{
    stack<int> stk;
    stk.push(l);
    stk.push(h);

    while(!stk.empty()) {
        h = stk.top();
        stk.pop();
        l = stk.top();
        stk.pop();

        int p = partition(a,l,h);

        if(p-1 > l) {
            stk.push(l);
            stk.push(p-1);
        }
        if(p+1 < h) {
            stk.push(p+1);
            stk.push(h);
        }
    }
}
int main()
{
    int n,i;
	cin>>n;
	int* a=new int[n];
	for(i=0;i<n;i++)
	    cin>>a[i];
	quicksort(a,0,n-1);
	for(i=0;i<n;i++)
	    cout<<a[i]<<" ";
    cout<<endl;
	delete []a;   
	return 0;
}
