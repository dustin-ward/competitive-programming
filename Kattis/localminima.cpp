#include <bits/stdc++.h>
using namespace std;

int localMinima(int arr[], int n) {
    if(arr[0] <= arr[1])
        return 0;
    else if(arr[n-1] >= arr[n])
        return n;
    else {
        int i = n/2;
        while(true) {
            if(arr[i] <= arr[i-1] && arr[i] <= arr[i+1])
                return i;
            else if(arr[i] >= arr[i-1])
                i--;
            else
                i++;
        }
    }
}

int main() {
    int arr[10] = {3, 2, 1, 4, 5, 6, 7, 8, 9, 10};

    int ans = localMinima(arr, 10);

    cout << ans << endl;

    return 0;
}
