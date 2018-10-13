// C++ program to demonstrate uses of some string function
#include <bits/stdc++.h>
using namespace std;
 
// this function returns floating point part of a number-string
/*
string returnFloatingPart(string str)
{
    int pos = str.find(".");
    if (pos == string::npos)
        return "";
    else
        return str.substr(pos + 1);
}
*/ 
// this function checks whether string contains all digit or not
bool containsOnlyDigit(string str)
{
    int l = str.length();
    for (int i = 0; i < l; i++)
    {
        if (str.at(i) < '0' || str.at(i) > '9')
            return false;
    }
    //  if we reach here all character are digits
    return true;
}
 
// this function replaces all single space by %20
// Used in URLS
string replaceBlankWith20(string str)
{
    string replaceby = "IIT";
    int n = 0;
 
    // loop till all space are replaced
    while ((n = str.find(" ", n)) != string::npos )
    {
        str.replace(n, 1, replaceby);
        n += replaceby.length();
    }
    return str;
}
 
// driver function to check above methods
int main()
{
 
    string num;
    getline(cin, num);
    if (containsOnlyDigit(num))
        cout << "YES"<<endl;
    else
        cout << "NO"<<endl;
 
    
    cout << replaceBlankWith20(num);
 
    return 0;      
}
