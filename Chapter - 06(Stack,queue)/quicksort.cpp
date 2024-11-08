#include <iostream>
#include <stack>
using namespace std;

int quickSortProcess(int *ar, int beg, int end) {
    int left = beg, right = end, loc = beg;
    while (true) {
        while (ar[loc] <= ar[right] && loc != right) {
            right--;
        }
        if (loc == right)
            return loc;
        if (ar[loc] > ar[right]){
            swap(ar[loc], ar[right]);
            loc = right;
        }
        while (ar[loc] >= ar[left] && loc != left) {
            left++;
        }
        if (loc == left)
            return loc;
        if (ar[loc] < ar[left]){
            swap(ar[loc], ar[left]);
            loc = left;
        }
    }
}
void quickSort(int *arr, int beg, int end) {
    stack<int> lower, upper;
    lower.push(beg);
    upper.push(end);
    while (!lower.empty()) {
        int loc = quickSortProcess(arr, lower.top(), upper.top());
        beg = lower.top(), end = upper.top();
        lower.pop(), upper.pop();
        if (loc + 1 < end) {
            lower.push(loc+1);
            upper.push(end);
        } if (beg < loc - 1 ) {
            lower.push(beg);
            upper.push(loc - 1);
        }
    }
}
int main() {
    int ar[] = {44, 33, -15, 55, 77, 90, 40, 60, 99, 22, 88, 66};
    quickSort(ar, 0, sizeof(ar)/sizeof(ar[0]) - 1);
    
    cout << "And the sorted array is : " << "\n";
    for (int i = 0; i < sizeof(ar)/sizeof(ar[0]); i++) {
        cout << ar[i] << " ";
    }
}