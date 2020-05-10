// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#include <stdio.h>
#include <iostream>
#include <string> 
#include <utility>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <bitset>
#include <typeinfo>
using namespace std;

class Solution {
public:
        bool isPerfectSquare(int num) {
        
        pair<float,float> range = {0,float(num)}; 
        bool ret = false; 
        float test = 0;
        if (num != 1 ) {
            recursion(num, range, test);
            return (test - int(test) <= 0);
        }
        else {
            //screw 1 == sqrt
            return true;
        }
        
    }

    void recursion(int s, pair<float,float> r, float& m) {

        float mid = (r.first + r.second) / 2;
        cout << "Recurse MID = " << mid << endl;
        float prod = mid * mid;  
        m++;
        if (prod == s) {
            m = mid;
            return ;
        }
        if (m > 1500) {
            m = mid;
            return ; 
        }
        if (mid*mid > s) {
            r.second = mid;
            recursion(s,r, m);
        }
        else if (mid*mid < s) {
            r.first = mid;
            recursion(s,r, m);
        }
    }
};

int main( int  argc, char* argv[]) {

    Solution s = Solution();
    s.isPerfectSquare(2775);

    return 0;
 };