#include <iostream>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include<chrono>

void quickSort(int arr[], int n) {
    std::stack<int> s;
    s.push(0);
    s.push(n - 1);
    while (!s.empty()) {
        int end = s.top();
        s.pop();
        int start = s.top();
        s.pop();
        int pivot = arr[end];
        int i = start - 1;
        for (int j = start; j < end; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i+1], arr[end]);
        int piv = i+1;
        if (piv - 1 > start) {
            s.push(start);
            s.push(piv - 1);
        }
        if (piv + 1 < end) {
            s.push(piv + 1);
            s.push(end);
        }
    }
}

int main() {
    int n;
    std::cout << "number of elements in the array: ";
    std::cin >> n;
    int* arr = new int[n];
    for (int p = 0; p < n; p++) {
        arr[p] = rand() % 1000;
    }

    // Measure the time taken by quicksort
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(arr, n);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken by quicksort: " << duration.count() << " microseconds\n";

  
    std::cout << "\n";
    
    delete[] arr;
    return 0;
}
