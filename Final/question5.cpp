#define V 5
#include<iostream>
#include <vector>
#include <climits>
#include  <algorithm>
using namespace std;

int hash[6][2];

bool search(int num) //This method searches based on non negative or negative values of a number and checks hash array to see if it exists in the array
{
    if (num >= 0)
    {
        if (hash[num][0] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    num = abs(num);
    if (hash[num][1] == 1)
    {
        return true;
    }
    return false;
}

void insert(int a[], int n) //This method inserts into the hash array based on whether the element is negative or not, denoted by 0 or 1.
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            hash[a[i]][0] = 1;
        }
        else
        {

            hash[abs(a[i])][1] = 1;

        }
    }
}

int main()
{
    int a[] = {-1, 9, -5, -8, -5, -2} 
    int n= sizeof(a)/sizeof(a[0]);
    insert(a, n);
    int X=-5;
    if(search(X)==true)
    {
        cout<<"Present"<<endl;
    }
    else
    {
        cout<<"Not Present"<<endl;
    }

    return 0;

}
    

