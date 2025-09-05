#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>


void bucketSort(std::vector<double>& arr) {
    int n = arr.size();
    const int numBuckets = 1000;
    std::vector<std::vector<double>> buckets(numBuckets);

    
    for (int i = 0; i < n; ++i) {
        int index = static_cast<int>(numBuckets * arr[i]);
        if (index >= numBuckets) {
            index = numBuckets - 1;
        }
        buckets[index].push_back(arr[i]);
    }

   
    for (int i = 0; i < numBuckets; ++i) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    
    int index = 0;
    for (int i = 0; i < numBuckets; ++i) {
        for (double value : buckets[i]) {
            arr[index++] = value;
        }
    }
}


int main() {
  
    const int N = 100000000;
    std::vector<double> arr(N);

    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    for (int i = 0; i < N; ++i) {
        arr[i] = dis(gen);
    }

    auto start = std::chrono::high_resolution_clock::now();
    bucketSort(arr);
    auto end = std::chrono::high_resolution_clock::now();

   
    std::chrono::duration<double> duration = end - start;
    std::cout << "Sorting " << N << " elements took "
              << duration.count() << " seconds." << std::endl;
    
    if (std::is_sorted(arr.begin(), arr.end())) {
        std::cout << "Array successfully sorted." << std::endl;
    } else {
        std::cout << "Error: array is not sorted." << std::endl;
    }
    

    return 0;
}



