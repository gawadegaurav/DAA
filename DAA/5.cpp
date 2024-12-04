#include <bits/stdc++.h>
using namespace std;

int maxProfit(int* prices, int n)
{
    int profit = 0, currentDay = n - 1;

    while (currentDay > 0) {

        int day = currentDay - 1;

        while (day >= 0 && (prices[currentDay] > prices[day])) {

            profit += (prices[currentDay] - prices[day]);

            day--;
        }

        currentDay = day;
    }

    return profit;
}

int main()
{
    int prices[] = { 2, 3, 5 };

    int N = sizeof(prices) / sizeof(prices[0]);

    cout << maxProfit(prices, N);

    return 0;
}
