#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minHeap;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        minHeap.push(a);
    }

    long long totalCost = 0;
    while (minHeap.size() > 1) {
        long long min1 = minHeap.top();
        minHeap.pop();

        long long min2 = minHeap.top();
        minHeap.pop();

        long long cost = min1 + min2;
        totalCost += cost;

        minHeap.push(cost);
    }

    std::cout << totalCost << std::endl;

    return 0;
}
