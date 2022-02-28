#include <iostream>
using namespace std;
int main()
{
    int num, k, count = 0;
    cin >> num;
    cin >> k;
    int arr[num], arr2[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
        arr2[i]=arr[i];
    }
    // for (int i = 0; i < num; i++)
    // {
    //     for (int j = i + 1; j < num; j++)
    //     {
    //         if (arr[i] + arr[j] == k)
    //         {
    //             count++;
    //         }
    //     }
    // }
    cout<<count<<endl;

    return 0;
}
