#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countLength(vector<int> a){
    int l = 0, r = 0, res = 0, sum = 0;
    while (r<a.size()){
        sum += a[r];
        r++;
        if (sum < 0){
            l=r;
            sum = 0;
        }
        res = max(res, sum);
    }
    return res;
}

int main() {
    vector<int> a = {0, -1, -2, 3, 1, -2, 1, -5, -8, 1, 1, -1, 1, 1};
    int res = countLength(a);

    cout << res << endl;
    return 0;
}