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

vector<int> mergeSort(vector<int> arr){
    if (arr.size() < 2){
        return arr;
    }
    int mid = arr.size()/2;
    vector<int> a,b;
    for (int i = 0; i<mid; i++){
        a.push_back(arr[i]);
    }
    for (int i = mid; i<arr.size(); i++){
        b.push_back(arr[i]);
    }
    return merge(mergeSort(a), mergeSort(b));
}

int main() {
    vector<int> data = {5, 9, 9, 6, 8, 25, 7, 45487, 45642, 8, 47, 4547, 674, 36};
    vector<int> sorted = mergeSort(data);

    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}