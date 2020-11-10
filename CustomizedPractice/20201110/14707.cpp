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

class RememberWords {
    pair <long long, long long> getRange(int d, int w) {
        long long rlow = -1;
        long long rup = -1;

        // [2*base+(d-1)]*d/2 >= w
        // 2*base*d+d*d-d >= w*2
        // 2*base*d >= w*2 + d - d*d
        long long low = 0;
        long long up = w;
        while (low <= up) {
            long long mid = (low+up) / 2;
            long long highb = mid+(d-1);
            long long val = (mid+highb)*d/2;

            if (val >= w) {
                rlow = mid;
                up = mid-1;
            } else {
                low = mid+1;
            }
        }

        // [2*base-(d-1)]*d/2 <= w
        // 2*base*d-d*d+d <= w*2
        // 2*base*d <= w*2 - d + d*d
        low = 0;
        up = w;
        while (low <= up) {
            long long mid = (low+up) / 2;
            long long maxlen = min((long long)d, mid+1);
            long long lowb = mid-(maxlen-1);
            long long val = (mid+lowb)*maxlen/2 + lowb*(d-maxlen);

            if (val <= w) {
                rup = mid;
                low = mid+1;
            } else {
                up = mid-1;
            }
        }

        return make_pair(rlow, rup);
    }

    bool intersect(pair<long long, long long> a, pair<long long, long long> b) {
        if (a.first == -1 || b.first == -1 || a.second == -1 || b.second == -1) {
            return false;
        }

        if (a.first > a.second || b.first > b.second) {
            return false;
        }

        if ( (a.second >= b.first && a.second <= b.second)
            || (b.second >= a.first && b.second <= a.second)
            || (a.first >= b.first && a.first <= b.second)
            || (b.first >= a.first && b.first <= a.second)) {
                return true;
        }

        return false;
    }

public:
    string isPossible(int d1, int d2, int w1, int w2) {
        pair <long long, long long> r1 = getRange(d1, w1);
        pair <long long, long long> r2 = getRange(d2, w2);

        // {x1 ...  xs} = w1; {xs(+-1) ... xend} = w2
        r2.first = max(r2.first-1, 0LL);
        ++r2.second;

        if (intersect(r1, r2)) {
            return "Possible";
        } else {
            return "Impossible";
        }
    }
};

int main() {
    RememberWords rw;
    cout << rw.isPossible(3, 5, 300, 500) << endl;
    return 0;
}