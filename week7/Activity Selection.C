// C++ program for activity selection problem.
// The following implementation assumes that the activities
// are already sorted according to their finish time
#include<stdio.h>
 
// Prints a maximum set of activities that can be done by a single
// person, one at a time.
//  n   -->  Total number of activities
//  s[] -->  An array that contains start time of all activities
//  f[] -->  An array that contains finish time of all activities

// A utility function to swap two elements
void merge(int arr[], int s[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];
    int K[n1], P[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++){
      L[i] = arr[l + i];
      K[i] = s[l + i];
    }
        
    for (j = 0; j < n2; j++){
      R[j] = arr[m + 1+ j];
      P[j] = s[m + 1+ j];
    }
        

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            s[k] = K[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            s[k] = P[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        s[k] = K[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        s[k] = P[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int s[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, s, l, m);
        mergeSort(arr, s, m+1, r);

        merge(arr, s, l, m, r);
    }
}


void printMaxActivities(int s[], int f[], int n)
{
    int i, j, count=1;
 
    
 
    // The first activity always gets selected
    i = 0;
    
 
    // Consider rest of the activities
    for (j = 1; j < n; j++)
    {
      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
      if (s[j] >= f[i])
      {
          count++;
          i = j;
      }
    }
    printf("%d", count);
}
 
// driver program to test above function
int main()
{
    int n,i;
    scanf("%d", &n);
    int s[n], f[n];
    for (i = 0; i < n; i++){
      scanf("%d", &s[i]);
    }

    for (i = 0; i < n; i++){
      scanf("%d", &f[i]);
    }

    mergeSort(f, s, 0, n - 1);
  

    
    printMaxActivities(s, f, n);
    return 0;
}
