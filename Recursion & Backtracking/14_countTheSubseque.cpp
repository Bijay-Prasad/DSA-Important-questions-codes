#include <iostream>

using namespace std;

int cntSubSeque(int ind, int s, int arr[], int sum, int n)
{
    if (ind == n)
        // Condition Satisfied
        if (s == sum)
            return 1;
        // Condition Not Satisfied
        else
            return 0;
    
    // Pick
    s += arr[ind];
    int l = cntSubSeque(ind + 1, s, arr, sum, n);

    // Not Pick
    s -= arr[ind];
    int r = cntSubSeque(ind + 1, s, arr, sum, n);

    return l + r;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    cout << cntSubSeque(0, 0, arr, sum, n);
    return 0;
}