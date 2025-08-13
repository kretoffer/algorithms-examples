#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int countSquareInGistogram(vector<int> a){
    a.push_back(0); a.insert(a.begin(), 0);
    stack<int> st;
    st.push(0);
    vector<int> smaller_left(a.size(), 0);
    for (int i = 0; i<a.size(); i++){
        while (a[st.top()] > a[i]){
            st.pop();
        }
        smaller_left[i] = st.top();
        st.push(i);
    }
    st.push(a.size()-1);
    vector<int> smaller_right(a.size(), 0);
    for (int i = a.size()-1; i>=0; i--){
        while (a[st.top()] > a[i]){
            st.pop();
        }
        smaller_right[i] = st.top();
        st.push(i);
    }
    int res = 0;
    for (int i = 0; i<a.size(); i++){
        res = max(res, (smaller_right[i]-smaller_left[i]-1)*a[i]);
    }
    return res;
}

int countSquareInTable(vector<vector<int>> arr){
    vector<int> gistogram(arr[0].size(), 0);
    int res = 0;
    for (int i = 0; i<arr.size(); i++){
        for (int j = 0; j<gistogram.size(); j++){
            if (arr[i][j] == 0){
                gistogram[j] += 1;
            } else {
                gistogram[j] = 0;
            }
        }
        res = max(res, countSquareInGistogram(gistogram));
    }
    return res;
}

int main() {
    vector<vector<int>> a = {
        {0, 1, 0, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 1, 1},
        {1, 0, 1, 0, 0}
    };
    int res = countSquareInTable(a);

    cout << res << endl;
    return 0;
}