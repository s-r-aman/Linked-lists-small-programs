int FindMin(BSTnode *root)
{
  if (root == NULL)
  {
    throw "Tree is empty!";
  }
  while (root->left != NULL)
  {
    root = root->left;
  }
  return root->data;
}

int FindMax(BSTnode *root)
{
  if (root == NULL)
  {
    throw "Tree is empty!";
  }
  while (root->right != NULL)
  {
    root = root->right;
  }
  return root->data;
}
