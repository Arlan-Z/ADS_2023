#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n, x;
    std::cin >> n >> x;

    std::priority_queue<int> ticketPrices;
    for (int i = 0; i < n; ++i) {
        int seats;
        std::cin >> seats;
        ticketPrices.push(seats);
    }

    long long totalRevenue = 0;
    for (int i = 0; i < x; ++i) {
        int currentPrice = ticketPrices.top();
        ticketPrices.pop();

        totalRevenue += currentPrice;
        if (currentPrice > 1) {
            ticketPrices.push(currentPrice - 1);
        }
    }

    std::cout << totalRevenue << std::endl;

    return 0;
}
