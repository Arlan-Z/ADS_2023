#include <iostream>
#include <queue>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::priority_queue<int> maxHeap;
    for (int i = 0; i < N; ++i) {
        int weight;
        std::cin >> weight;
        maxHeap.push(weight);
    }

    while (maxHeap.size() > 1) {
        int y = maxHeap.top();
        maxHeap.pop();

        int x = maxHeap.top();
        maxHeap.pop();

        if (x != y) {
            maxHeap.push(y - x);
        }
    }

    std::cout << (maxHeap.empty() ? 0 : maxHeap.top()) << std::endl;

    return 0;
}
