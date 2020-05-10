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
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type)) 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

  bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool lin = true;

        if ( coordinates.size() == 2 ) {
            return lin ;
        }


        int x = coordinates[1][0] - coordinates[0][0];
        int y = coordinates[1][1] - coordinates[0][1];

        float m = float(y) / float (x); 
        
        //cout << "Slope: "<< m << endl;
        vector<vector<int>>::iterator it;  
        vector<int> c = coordinates[1];   

        //cout << x << ":" << y << endl;
        
        for (it = coordinates.begin() + 2; it != coordinates.end(); it++ ) {

            /*cout << "Coord C: " << c[0] << ":" << c[1] << endl;
            cout << "Coord IT: " << it->at(0) << ":" << it->at(1) << endl;
            cout << "X:Y " << x << ":" << y << endl;

            cout << "" << endl;
            cout << "X - last[x]" << (it->at(0) - c[0]) << endl;
            cout << "Y - last[y]" <<  (it->at(1) - c[1]) << endl;
            
            cout << "y div/ x:  " << it->at(1) / it->at(0) << endl;
            */
            int diff_x = it->at(0) - c[0];
            int diff_y = it->at(1) - c[1];
            float test_m = float(diff_y) / float(diff_x);
            //cout << "diff_x: " << diff_x << endl;
            //cout << "diff_y: " << diff_y << endl;
            //cout << "test_m: " << test_m << endl;

            if (test_m != m) {
                lin = false;
                break;
            }

            else {
                c[0] = it->at(0);
                c[1] = it->at(1);
            }
            //cout << lin << endl;

        }

        return lin;
    }
};

int main( int  argc, char* arg[]) {

    
    Solution s = Solution();
    vector<vector<int>> v = {{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};

    cout << s.checkStraightLine(v) << endl;
    return 0;
 };