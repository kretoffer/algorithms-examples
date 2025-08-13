#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> countLength(vector<int> a){
    stack<int> st;
    vector<int> ans;
    st.push(0);
    for (int num : a){
        while (st.top() > num){
            st.pop();
        }
        ans.push_back(st.top());
        st.push(num);
    }
    return ans;
}

int main() {
    vector<int> a = {3, 5, 2, 6, 4, 1, 8, 7};
    vector<int> res = countLength(a);

    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}