#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> arr){
	int l = arr.size();
	while (l != 0) {
		int max_i = 0;
		for (int i = 1; i < l; i++) {
			if (arr[i - 1] > arr[i]) {
				swap(arr[i - 1], arr[i]);
				max_i = i;
			}
		}
		l = max_i;
	}
	return arr;
}

int main() {
    vector<int> data = {5, 9, 9, 6, 8, 25, 7};
    vector<int> sorted = bubbleSort(data);

    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
