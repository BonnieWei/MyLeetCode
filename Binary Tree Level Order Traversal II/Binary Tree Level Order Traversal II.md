##107. Binary Tree Level Order Traversal II
###题目描述：[https://leetcode.com/problems/binary-tree-level-order-traversal-ii/](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)
> 将一棵二叉树按照层次输出结果到一个vector中，要求按照从下到上，从左到右的顺序输出。    
> 例如：
> 
>          3
>         /  \
>        9   20
>           /  \
>          15   7
> 输出结果为[[15,7],[9,20],[3]]

###解题思路：
BFS+reverse
###代码：
	/**
	 * Definition for a binary tree node.
	 * struct TreeNode {
	 *     int val;
	 *     TreeNode *left;
	 *     TreeNode *right;
	 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	 * };
	 */
	class Solution {
	public:
	    vector<vector<int>> levelOrderBottom(TreeNode* root) {
	        vector<vector<int> > v;
	        vector<int> vv;
	        queue<pair<TreeNode*, int> > q;
	        if(root == NULL)
	            return v;
	        q.push(pair<TreeNode*, int>(root, 0));
	        while(!q.empty()){
	            pair<TreeNode*, int> top = q.front();
	            if(top.first == NULL){
	                q.pop();
	                continue;
	            }
	            if(v.size() <= top.second)
	                v.push_back(vv);
	            v[top.second].push_back(top.first->val);
	            q.pop();
	            q.push(pair<TreeNode*, int>(top.first->left, top.second+1));
	            q.push(pair<TreeNode*, int>(top.first->right, top.second+1));
	        }
	        reverse(v.begin(), v.end());
	        return v;
	    }
	};
