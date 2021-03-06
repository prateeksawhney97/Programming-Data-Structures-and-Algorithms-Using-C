#include<bits/stdc++.h>
using namespace std;
 
/* C++ program to Check if a given array contains duplicate
   elements within k distance from each other */
bool checkDuplicatesWithinK(int arr[], int n, int k)
{
    // Creates an empty hashset
    set<int> myset;
 
    // Traverse the input array
    for (int i = 0; i < n; i++)
    {
        // If already present n hash, then we found
        // a duplicate within k distance
        if (myset.find(arr[i]) != myset.end())
            return true;
 
        // Add this item to hashset
        myset.insert(arr[i]);
 
        // Remove the k+1 distant item
        if (i >= k)
            myset.erase(arr[i-k]);
    }
    return false;
}
 
// Driver method to test above method
int main ()
{
    int n,k,i;
    cin>>n;
    cin>>k; 
    int arr[n];

    for (i = 0; i < n; i++){
        cin >> arr[i];
    }    
    if (checkDuplicatesWithinK(arr, n, k))
        cout << "Yes";
    else
        cout << "No";
}
