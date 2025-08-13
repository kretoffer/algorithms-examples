#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countLength(vector<int> a, int S){
    int l = 0, r = 0, res = 0, sum = 0;
    for (; l<a.size(); l++){
        while (r<a.size() && sum + a[r] <= S){
            sum += a[r];
            r++;
        }
        res = max(res, r-l);
        sum -= a[l];
    }
    return res;
}

int main() {
    const int S = 5;
    vector<int> a = {0, 1, 2, 6, 0, 0, 2, 1, 0, 3, 8};
    int res = countLength(a, S);

    cout << res << endl;
    return 0;
}