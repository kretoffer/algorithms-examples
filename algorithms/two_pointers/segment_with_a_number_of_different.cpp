#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAXA = 10000000;

int countLength(vector<int> a, int k){
    vector<int> cnt(MAXA, 0);
    int l = 0, r = 0, res = 0, dif = 0;
    for (; l<a.size(); l++){
        while (r<a.size() && (dif+1 <= k || (dif <= k && cnt[a[r]] != 0))){
            cnt[a[r]]++;
            if (cnt[a[r]] == 1){
                dif++;
            } 
            r++;
        }
        res = max(res, r-l);
        cnt[a[l]]--;
        if (cnt[a[l]] == 0){
            dif--;
        }
    }
    return res;
}

int main() {
    const int k = 3;
    vector<int> a = {0, 1, 2, 6, 0, 0, 2, 1, 0, 3, 8};
    int res = countLength(a, k);

    cout << res << endl;
    return 0;
}