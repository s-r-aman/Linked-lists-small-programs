// int FindMin(BSTnode *root)
// {
//   if (root == NULL)
//   {
//     throw "Tree is empty!";
//   }
//   while (root->left != NULL)
//   {
//     root = root->left;
//   }
//   return root->data;
// }

// int FindMax(BSTnode *root)
// {
//   if (root == NULL)
//   {
//     throw "Tree is empty!";
//   }
//   while (root->right != NULL)
//   {
//     root = root->right;
//   }
//   return root->data;
// }

int FindMin(BSTnode *root)
{
  if (root == NULL)
  {
    throw "Tree is empty!";
  }
  if (root->left == NULL)
  {
    return root->data;
  }
  return FindMin(root->left);
}

int FindMax(BSTnode *root)
{
  if (root == NULL)
  {
    throw "Tree is empty!";
  }
  if (root->right == NULL)
  {
    return root->data;
  }
  return FindMax(root->right);
}
