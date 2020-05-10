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

    int findJudge(int N, vector<vector<int>>& trust) {
        
        unordered_map<int,int> tmap;
        string present = ",";
        int holder = -1;
        int cand = -1;

        if (N==1){
            // "Gotcha" test cases get "Gotcha" answers...
            return N;
        } 

        for (auto x : trust) {
            if (present.find(to_string(x[0])) == string::npos) {
                present += to_string(x[0])+",";
            }
            if (!tmap[x[1]]) {
                tmap[x[1]]= 1;
            }
            else {
                tmap[x[1]]++;
            }
        }
        
        for (auto y : tmap) {
            if ((y.second == N-1) && (present.find("," +to_string(y.first) + ",") == string::npos)) {
                cand = y.first;
            }
        }
 
        return cand;
        
    }

};

int main( int  argc, char* argv[]) {

    //vector<vector<int>> t =  {{1,3},{1,4},{2,3},{2,4},{4,3}};
    
    vector<vector<int>> t = {{1,2},{2,1}};
    int n = 2;
    Solution s = Solution();
    s.findJudge(n,t);

    return 0;
 };