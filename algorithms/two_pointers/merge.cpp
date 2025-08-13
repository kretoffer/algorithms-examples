#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> a, vector<int> b){
    int i = 0, j = 0;
    vector<int> ans;
    while (i < a.size() && j < b.size()){
        if (a[i] < b[j]){
            ans.push_back(a[i]);
            i++;
        } else {
            ans.push_back(b[j]);
            j++;
        }    
    }
    for (; i<a.size(); i++){
        ans.push_back(a[i]);
    }
    for (; j<b.size(); j++){
        ans.push_back(b[j]);
    }
    return ans;
}

int main() {
    vector<int> a = {1, 2, 2, 5, 6};
    vector<int> b = {2, 5, 7, 9};
    vector<int> merged = merge(a, b);

    for (int num : merged) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
