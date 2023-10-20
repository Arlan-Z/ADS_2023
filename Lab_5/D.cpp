#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::priority_queue<int, std::vector<int>, std::greater<int>> mixtures;
    for (int i = 0; i < n; ++i) {
        int density;
        std::cin >> density;
        mixtures.push(density);
    }

    int operations = 0;
    while (!mixtures.empty() && mixtures.top() < m) {
        int least = mixtures.top();
        mixtures.pop();

        if (mixtures.empty()) {
            std::cout << "-1" << std::endl;
            return 0;
        }

        int second_least = mixtures.top();
        mixtures.pop();

        int new_density = least + 2 * second_least;
        mixtures.push(new_density);
        operations++;
    }

    std::cout << operations << std::endl;

    return 0;
}
