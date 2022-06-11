#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution_o001 {
public:
    int divide(int a, int b) {
        if (a == 0) return 0;
        if (b == 1 || b == -1) {
            if (b == 1) {
                return a <= -pow(2, 31) ? -pow(2, 31) : a;
            }
            else {
                return a <= -pow(2, 31) + 1 ? pow(2, 31) - 1 : -a;
            }
        }
        int m = a, n = b;
        if (a > 0) a = -a;
        if (b > 0) b = -b;
        int ret = 0;
        while (a <= b) {
            a -= b;
            if (ret >= pow(2, 31) - 1) {
                ret = pow(2, 31) - 1;
                break;
            }
            ++ret;
        }
        if (m > 0 && n > 0 || m < 0 && n < 0) {
            return ret;
        }
        else return -ret;
    }
};
void main_o001() {
    int a, b;
    cin >> a >> b;
    Solution_o001 so001;
    cout<<so001.divide(a, b)<<endl;
}