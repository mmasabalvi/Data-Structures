int countLeafNodes(binaryTreeNode<int>* root1)
{
    if (root1 == NULL)
    {
        return 0;
    }

    if (root1->llink == NULL && root1->rlink == NULL)
    {
        return 1;
    }

    else
    {
        int left = countLeafNodes(root1->llink);
        int right = countLeafNodes(root1->rlink);
        return left + right; 
    }
}
