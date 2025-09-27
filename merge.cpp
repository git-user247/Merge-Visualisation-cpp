#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int pass = 1;

void logState(const vector<int>& arr, int pass) {
    ofstream out("steps.csv", ios::app);
    out << "Pass " << pass << ",";
    for (int val : arr) out << val << ",";
    out << "\n";
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
    logState(arr, pass++);

}

int main() {
vector<int> arr = {
    82317, 45162, 92684, 13579, 59034, 74310, 63825, 10984, 39275, 81652,
    78013, 20938, 57493, 68425, 94716, 23564, 18907, 75491, 32048, 91835,
    49623, 23017, 81456, 60584, 70126, 55849, 38014, 69713, 80015, 21639,
    47120, 96304, 31342, 84069, 23450, 98312, 16490, 44783, 38562, 56823,
    62197, 45710, 91265, 70213, 83497, 61435, 74162, 38510, 49012, 23984,
    72308, 15902, 69273, 59813, 73196, 34129, 96502, 41235, 80124, 27963,
    56347, 97013, 36284, 48920, 35829, 24571, 63491, 51092, 91620, 37049,
    49175, 62983, 78520, 47210, 87349, 28763, 79513, 62739, 58102, 46590,
    53124, 34197, 59310, 78124, 32845, 93871, 40512, 51730, 20931, 67420,
    82359, 36948, 24186, 59841, 47031, 28417, 83591, 63420, 29375, 81246
};
    mergeSort(arr, 0, arr.size() - 1);  
    return 0;
}