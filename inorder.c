void 
trav(struct TreeNode* tree, int* arr, unsigned int* i)
{
    if(tree)
    {
        trav(tree->left, arr, i);
        arr[(*i)++] = tree->val;
        trav(tree->right, arr, i);
    }
}

size_t
countNodes(struct TreeNode* tree) 
{
    if(tree == NULL) return 0;
    return 1 + countNodes(tree->left) + countNodes(tree->right);
}

int* 
inorderTraversal(struct TreeNode* root, int* returnSize) 
{
    size_t count = countNodes(root);
    *returnSize = count;

    unsigned int i = 0;

    int* res = malloc(count*sizeof(int));
    
    trav(root, res, &i);

    return res;
}
