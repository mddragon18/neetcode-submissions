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
    int goodNodes(TreeNode* root) {
        int count=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,root->val});
        while(!q.empty()) {
            if(q.front().first->val >= q.front().second) count++;
            auto temp = q.front();
            q.pop();

            if(temp.first->left) {
                if(temp.first->left->val >= temp.second) 
                    q.push({temp.first->left,temp.first->left->val});
                else
                    q.push({temp.first->left,temp.second});
            }

            if(temp.first->right) {
                if(temp.first->right->val >= temp.second) 
                    q.push({temp.first->right,temp.first->right->val});
                else
                    q.push({temp.first->right,temp.second});
            }
        }

        return count;

    }
};
