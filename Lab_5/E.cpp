#include <iostream>
#include <queue>
#include <vector>
#include <string>

int main() {
    int q, k;
    std::cin >> q >> k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> cookies;
    long long total_cookies = 0;

    while (q--) {
        std::string command;
        std::cin >> command;

        if (command == "insert") {
            int n;
            std::cin >> n;

            if (cookies.size() < k) {
                cookies.push(n);
                total_cookies += n;
            } else if (n > cookies.top()) {
                total_cookies -= cookies.top();
                cookies.pop();
                cookies.push(n);
                total_cookies += n;
            }
        } else if (command == "print") {
            std::cout << total_cookies << std::endl;
        }
    }

    return 0;
}

