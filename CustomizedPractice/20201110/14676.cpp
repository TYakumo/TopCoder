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
    long long _solve(const VVI& adja, VVLL& dp, int now, int reseted, long long sum) {
        if (dp[reseted][now] >= 0) {
            return dp[reseted][now];
        }

        long long best = 0;
        VLL res;

        for (int i = 0; i < adja[now].size(); ++i) {
            int nextv = adja[now][i];
            res.push_back(_solve(adja, dp, nextv, 1, sum+))
        }
    }

public:
    int maximalScore(VI parent, VI pleasure) {
        int N = pleasure.size();
        VVI adja(N);
        VVLL dp(2, VLL(N, -1));

        for (int i = 0; i < parent.size(); ++i) {
            int f;
            int t;
            adja[f].push_back(t);
        }

        int initReset = pleasure[0] < 0 ? 1 : 0;
        return _solve(adja, dp, 0, initReset, 0);
    }
};

int main() {

    return 0;
}