/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> bfs;
        bfs.push(root);
        vector<int> subList;
        while(!bfs.empty()) {
            int l = bfs.size();
            for(int i=0; i<l; i++) {
                TreeNode* temp = bfs.front();
                subList.push_back(temp->val);
                bfs.pop();

                if(temp->left) bfs.push(temp->left);
                if(temp->right) bfs.push(temp->right);
            }
            result.push_back(subList);
            subList.clear();

        }
        return result;
    }
};
