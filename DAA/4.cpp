#include <bits/stdc++.h>
using namespace std;

bool compareBy(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int maximumShops(int* opening, int* closing, int n, int k)
{
    pair<int, int> a[n];

    for (int i = 0; i < n; i++) {
        a[i].first = opening[i];
        a[i].second = closing[i];
    }

    sort(a, a + n, compareBy);

    int count = 0;
    multiset<int> st;

    for (int i = 0; i < n; i++) {
        bool flag = false;

        if (!st.empty()) {
            auto it = st.upper_bound(a[i].first);

            if (it != st.begin()) {
                it--;

                if (*it <= a[i].first) {
                    st.erase(it);
                    st.insert(a[i].second);
                    count++;
                    flag = true;
                }
            }
        }

        if (st.size() < k && flag == false) {
            st.insert(a[i].second);
            count++;
        }
    }

    return count;
}

int main()
{
    int S[] = { 1, 8, 3, 2, 6 };
    int E[] = { 5, 10, 6, 5, 9 };
    int K = 2, N = sizeof(S) / sizeof(S[0]);

    cout << maximumShops(S, E, N, K) << endl;
}
