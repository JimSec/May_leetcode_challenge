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

    void createBT(unordered_map<int, TreeNode> map) {
        
        int mx[5] = {1,2,3,4,5};
        int size = sizeof(mx)/sizeof(*mx) ;
        //cout << size << endl;

        for (int i = 0; i < size ; i++ ){
            int o;
            
            if (i + 1 == 1) {
                o = i+1;
            }
            else {
                o = i * 2;
            }
            
            map[i].val = i + 1;
            if (o > size) {
                map[i].left = NULL; 
                map[i].right = NULL; 
            }
            else {
                map[i].left = &map[o];
                if (o+1 > size){
                    map[i].right = NULL; 
                }
                else{
                    map[i].right = &map[o+1];
                }
            }
        }

        //isCousins(&map[0], 4, 5);
        cout << isCousins(&map[0], 4, 5) << endl ;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        bool kin = false;
        int level = 0;
        int p_ref = -1;
        unordered_map<int, pair<int, int>> umap;

    //I used one of the top answers for this. I lost the whole day trying to figure out how to create a binary tree structure using maps to pass into this, and had to look up how to handle actually follow down the binary tree to find values to compare, ie recursive functions.  
        recursion(root, level, p_ref, umap); 
        if (umap[x].first == umap[y].first && umap[x].second != umap[y].second) {
            kin = true;
        }
        return kin;
    }

    void recursion(TreeNode* n, int l, int p, unordered_map<int, pair<int, int>>& map) {

        if (!n) {
            return; 
        }
        map[n->val] = {l,p};
        recursion(n->left, l+1, n->val, map);
        recursion(n->right, l+1, n->val, map);
    }


};

int main( int  argc, char* arg[]) {

    
    Solution s = Solution();
    unordered_map<int, TreeNode> mp;

    s.createBT(mp);
    return 0;
 };