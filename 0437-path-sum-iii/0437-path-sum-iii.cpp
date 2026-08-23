class Solution {
public:
    long long cnt = 0;

    // Counts all valid downward paths
    // starting exactly from 'root'.
    void dfs(TreeNode* root, long long sum, long long targetSum)
    {
        if(root == nullptr)
            return;

        sum += root->val;

        if(sum == targetSum)
            cnt++;

        dfs(root->left, sum, targetSum);
        dfs(root->right, sum, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {

        if(root == nullptr)
            return 0;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();

            // Every node becomes a starting point.
            dfs(node, 0, targetSum);

            if(node->right)
                st.push(node->right);

            if(node->left)
                st.push(node->left);
        }

        return cnt;
    }
};