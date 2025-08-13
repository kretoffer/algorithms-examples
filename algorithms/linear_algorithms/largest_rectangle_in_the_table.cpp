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

int main() {
    vector<int> a = {3, 5, 2, 6, 4, 1, 8, 7};
    int res = countSquareInGistogram(a);

    cout << res << endl;
    return 0;
}