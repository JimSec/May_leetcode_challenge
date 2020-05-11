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

    void floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        cursion(image, sr, sc, newColor, image.at(sr).at(sc));
        //return image;

    }

    void cursion (vector<vector<int>>& img, int w_r, int w_c, int nC, int oC) {

        img[w_r][w_c] = nC;

        try {
        //y-1
            if ((img.at(w_r-1).at(w_c) == oC) && (img.at(w_r-1).at(w_c) != nC)){
                cursion(img, w_r-1, w_c, nC, oC); 
            }
        }
        catch (const std::out_of_range& oor) {}

        try {
        //y+1
            if ((img.at(w_r+1).at(w_c) == oC) && (img.at(w_r+1).at(w_c) != nC)){
                cursion(img, w_r+1, w_c, nC, oC); 
            }
        }
        catch (const std::out_of_range& oor) {}

        try {
        //x-1
            if ((img.at(w_r).at(w_c-1) == oC) && (img.at(w_r).at(w_c-1) != nC)){
                cursion(img, w_r, w_c-1, nC, oC); 
            }
        }
        catch (const std::out_of_range& oor) {}

        try {
        //x+1        
            if ((img.at(w_r).at(w_c+1) == oC) && (img.at(w_r).at(w_c+1) != nC)){
                cursion(img, w_r, w_c+1, nC, oC); 
            }
        }
        catch (const std::out_of_range& oor) {}
    }

};

int main( int  argc, char* argv[]) {

    Solution s = Solution();
    vector<vector<int>> img = {{1,1,0,1},{2,1,4,4},{2,1,1,4},{1,1,2,1}};
    int r = 1; 
    int c = 1;
    int color = 7;

    //cout << img[r-1][c-1] << endl;
    string i_str = "";

    for (auto y : img ) {
        for (auto x : y) {
            i_str += to_string(x);
        }
        i_str += "\n";
    }

    cout << i_str << endl;
    
    s.floodFill(img,r,c,color); 

    string o_str = "";

    for (auto y : img ) {
        for (auto x : y) {
            o_str += to_string(x);
        }
        o_str += "\n";
    }

    cout << o_str << endl;
    

    /*

    0 0 0
    0 1 1
    0 0 0
    ALL PIXELS IN XY PATH OF SAME COLOR ARE RECOLORED
    needed return:
    0 0 0
    0 1 1
    0 0 0

    */

    return 0;
 }