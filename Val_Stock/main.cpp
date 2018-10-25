


#include <iostream>
#include <vector>

using namespace std;

int Val_Stock(int A[], int n) {
    vector<int> max;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            max.push_back(A[j]-A[i]);
    sort(max.begin(), max.end(), greater<>());
    return max[0];
}

int Val_Stock_Twice(int A[], int n) {
    int minPos = 0, maxPos = 1;
    int max = A[1] - A[0];
    for (int i = 0; i < n - 1; i++)
        for (int j = i+1; j < n; j++)
            if (A[j] - A[i] > max) {
                max = A[j] - A[i];
                minPos = i;
                maxPos = j;
            }
    int *max1 = new int [minPos];
    int *max2 = new int [n - maxPos];
    int k = 0;
    
    for (int i = 0; i < minPos; i++) {
        max1[i] = A[i];
    }
    for (int i = maxPos + 1; i < n; i++) {
        max2[k] = A[i];
        k++;
    }

    int result1 = Val_Stock(max1, minPos);
    int result2 = Val_Stock(max2, n - maxPos - 1);
    
    return (result1 > result2 ? result1 : result2) + Val_Stock(A, n);
}

int main() {
    int A[9] = {12,11,13,5,5,20,4,10,14};
    cout << "Val_Stock: " << Val_Stock(A, 9) << endl;
    cout << "Val_Stock: " << Val_Stock_Twice(A, 9) << endl; //9
}
