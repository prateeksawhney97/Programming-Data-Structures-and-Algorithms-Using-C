#include<bits/stdc++.h>
using namespace std;
 
int countSteps(int x, int y)
{
    // If y divides x, then simply return
    // x/y.
    if (x%y == 0)
        return x/y;
 
    // Else recur. Note that this function
    // works even if x is smaller than y because
    // in that case first recursive call exchanges
    // roles of x and y.
    return x/y + countSteps(y, x%y);
}
 
// Driver code
int main()
{
   int x, y;
   cin >> x >> y;
   cout << countSteps(x, y);
   return 0;
}
