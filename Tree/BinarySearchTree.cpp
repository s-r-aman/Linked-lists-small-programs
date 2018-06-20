#include <iostream>
struct BSTnode
{
  int data;
  BSTnode *left;
  BSTnode *right;
};
#include "./FindMaxMin.h"

BSTnode *GetNewNode(int data)
{
  BSTnode *node = new BSTnode();
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

BSTnode *InsertNode(BSTnode *root, int data)
{
  if (root == NULL)
  {
    root = GetNewNode(data);
  }
  else if (data < root->data)
  {
    root->left = InsertNode(root->left, data);
  }
  else
  {
    root->right = InsertNode(root->right, data);
  }
  return root;
}

bool Search(BSTnode *root, int data)
{
  if (root == NULL)
  {
    return false;
  }
  else if (data == root->data)
  {
    return true;
  }
  else if (data < root->data)
  {
    return Search(root->left, data);
  }
  else
  {
    return Search(root->right, data);
  }
}

int main()
{
  BSTnode *root = NULL;
  root = InsertNode(root, 10);
  root = InsertNode(root, 20);
  root = InsertNode(root, 30);
  root = InsertNode(root, 1);
  root = InsertNode(root, 50);
  root = InsertNode(root, 60);
  int number;
  std ::cout << "Enter number to search\n";
  std ::cin >> number;
  if (Search(root, number) == true)
    std ::cout << "Found\n";
  else
    std ::cout << "Not Found\n";

  try
  {
    int min = FindMin(root);
    std::cout << min;
  }
  catch (const std::exception &)
  {
  }
  return 0;
}