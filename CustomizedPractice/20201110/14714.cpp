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

class GraphAndPairs {
    void __construct(VVI& adja, int& startIdx, int d, int& k) { // note d >= 2
        const int THRESHOLD = 50;
        if (k <= THRESHOLD) { // under threshold
            // go d-1+k
            int now = startIdx;
            adja.push_back({});

            for (int i = 1; i <= d-1+k; ++i) {
                int next = now+1;
                adja.push_back({});
                adja[next].push_back(now);

                now = next;
            }

            k = 0;
        } else {
            // center
            // |G| groups
            // 2*g + (d-2) nodes
            // Total pairs : g*g
            for (int g = 500; g >= 1; --g) {
                int tot = d == 2 ? g*(g-1)/2 : g*g;

                if (tot <= k) {
                    int left = startIdx;
                    adja.push_back({});

                    int cur = startIdx;
                    for (int i = 1; i < d-1; ++i) {
                        int next = cur+1;
                        adja.push_back({});
                        adja[next].push_back(cur);
                        cur = next;
                    }
                    int right = cur;

                    for (int i = 0; i < g; ++i) {
                        int next = cur+1;
                        adja.push_back({});
                        adja[next].push_back(left);
                        cur = next;
                    }

                    if (d > 2) {
                        for (int i = 0; i < g; ++i) {
                            int next = cur+1;
                            adja.push_back({});
                            adja[next].push_back(right);
                            cur = next;
                        }
                    }

                    k -= tot;
                    break;
                }
            }
        }

        startIdx = adja.size();
    }
public:
    VI construct(int d, int k) {
        VI ret;
        VVI adja;
        int now = 0;

        while (k > 0) {
            __construct(adja, now, d, k);
        }

        ret.push_back(adja.size());
        for (int i = 0; i < adja.size(); ++i) {
            for (int j = 0; j < adja[i].size(); ++j) {
                ret.push_back(i);
                ret.push_back(adja[i][j]);
            }
        }
        return ret;
    }
};

int main() {

    return 0;
}