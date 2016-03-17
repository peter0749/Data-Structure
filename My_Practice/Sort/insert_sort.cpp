#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

#define MAX 7

using namespace std;

int main(void)
{
    int arr[]= {-6,5,-5,3,2,6,1};

    int i, j, k, temp;
    for(i=1; i<MAX; i++)
    {
        temp = arr[i];
        for(j=0; j<i; j++)
        {
            if(abs(arr[i])<abs(arr[j]))break;
        }
        if(i!=j)
        {
            for(k=i-1; k>=j; k--)
            {
                arr[k+1] = arr[k];
            }
            arr[j] = temp;
        }
    }
    for(i=0;i<MAX;i++)cout<<arr[i]<<endl;

    return 0;
}
