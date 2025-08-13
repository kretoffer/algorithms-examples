#include <iostream>
#include <vector>

using namespace std;

const int MAXA = 10000000;

vector<int> countingSort(vector<int> arr){
    vector<int> cnt(MAXA, 0);

    for (int num : arr) {
        cnt[num]++;
    }
    int j = 0;
    for (int i = 0; i<MAXA; i++){
        while (cnt[i] > 0){
            arr[j] = i;
            j++;
            cnt[i]--;
        }
    }
    return arr;
}

int main() {
    vector<int> data = {5, 9, 9, 6, 8, 25, 7, 45487, 45642, 8, 47, 4547, 674, 36};
    vector<int> sorted = countingSort(data);

    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}