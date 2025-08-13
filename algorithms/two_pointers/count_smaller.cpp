#include <iostream>
#include <vector>

using namespace std;

vector<int> countSmaller(vector<int> a, vector<int> b){
    int j = 0;
    vector<int> reses(b.size(), 0);
    for (int i = 0; i<b.size(); i++){
        while (j<a.size() && a[j] < b[i]){
            j++;
        }
        reses[i] = j;
    }
    return reses;
}

int main() {
    vector<int> a = {1,2,4,5,7};
    vector<int> b = {2,5,10};
    vector<int> res = countSmaller(a, b);

    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
