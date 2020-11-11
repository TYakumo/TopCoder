#include <iostream>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
using namespace std;

using VI = vector <int>;
using VVI = vector <VI>;
using VLL = vector <long long>;
using VVLL = vector <VLL>;

class OwaskiAndTree {
    void _precal(const VVI& adja, const VI& pval, VLL& dp, int now) {
        dp[now] = pval[now];

        for (int i = 0; i < adja[now].size(); ++i) {
            int nextv = adja[now][i];
            _precal(adja, pval, dp, nextv);

            if (dp[nextv] > 0) {
                dp[now] += dp[nextv];
            }
        }
    }

    long long _solve(const VVI& adja, const VLL& dp, int now) {
        long long theMax = dp[now];
        long long noThis = 0;

        for (int i = 0; i < adja[now].size(); ++i) {
            int nextv = adja[now][i];
            noThis += max(0LL, _solve(adja, dp, nextv));
        }

        return max(theMax, noThis);
    }

public:
    int maximalScore(VI parent, VI pleasure) {
        int N = pleasure.size();
        VVI adja(N);
        VLL dp(N);

        for (int i = 0; i < parent.size(); ++i) {
            int f = parent[i];
            int t = i+1;
            adja[f].push_back(t);
        }

        _precal(adja, pleasure, dp, 0);
        return _solve(adja, dp, 0);
    }
};

int main() {
    OwaskiAndTree oat;
    cout << oat.maximalScore({0, 1, 2, 3, 4, 5, 6, 7, 8}, {1, 1, -1, -1, -1, -1, 1, 1, 1, 1}) << endl;
    return 0;
}