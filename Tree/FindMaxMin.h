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
