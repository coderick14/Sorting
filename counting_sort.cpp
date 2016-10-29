//Stable counting sort
//Time complexity O(k+n)
//Space complexity O(k+n)

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void counting_sort(vector<ll> &a, ll n, ll k)    {
    vector<ll> b(n), c(k+1);
    ll i;
    for(i=0; i<=k; i++)
        c[i] = 0;
    for(i=0; i<n; i++)
        c[a[i]] += 1;
    for(i=1; i<=k; i++)
        c[i] = c[i] + c[i-1];
    for(i=n-1; i>=0; i--)   {
        b[c[a[i]]-1] = a[i];
        c[a[i]] -= 1;
    }
    for(i=0; i<n; i++)
        a[i] = b[i];
}

int main()  {
    ll i,k,n;
    cout<<"Enter range of numbers\n";
    cin>>k;
    cout<<"Enter n\n";
    cin>>n;
    vector<ll> a(n);
    for(i=0; i<n; i++)
        cin>>a[i];
    counting_sort(a,n,k);
    for(i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
