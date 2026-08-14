#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    int missingNumber(int arr[], int n) {
        int expected = n * (n + 1) / 2;
        int actual = 0;

        for (int i = 0; i < n - 1; i++) {
            actual += arr[i];
        }

        return expected - actual;
    }
};

int main() {
    int n = 5;
    int arr[] = {1, 2, 4, 5};

    solution obj;

    cout << obj.missingNumber(arr, n);

    return 0;
}