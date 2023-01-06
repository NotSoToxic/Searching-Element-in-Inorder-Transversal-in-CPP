#include <iostream>
using namespace std;

struct node
{
  int key;
  struct node *left, *right;
};


struct node *newNode(int item)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}


void inorder(struct node *root)
{
  if (root != NULL)
  {
    
    inorder(root->left);

    
    cout << root->key << " | ";

    
    inorder(root->right);
  }
}


struct node *insert(struct node *node, int key)
{
  
  if (node == NULL)
    return newNode(key);
  if (key < node->key) 
    node->left = insert(node->left, key);
  else 
    node->right = insert(node->right, key);
  return node;
}


void search(struct node *root, int data)
{
  int depth = 0;
  node *temp = new node;
  temp = root;
  
  while (temp != NULL)
  {
    depth++;
    if (temp->key == data)
    {
      cout << "\nData found at depth: " << depth;
      return;
    }
    
    else if (temp->key > data)
      temp = temp->left;
    
    else
      temp = temp->right;
  }

  cout << "\n No Data Found";
  return;
}

int main()
{
  struct node *root = NULL;
  root = insert(root, 9);
  root = insert(root, 3);
  root = insert(root, 2);
  root = insert(root, 9);
  root = insert(root, 7);
  root = insert(root, 8);
  root = insert(root, 12);
  root = insert(root, 6);
  int n;
  bool flag;
  cout << "Inorder traversal: ";
  inorder(root);
  cout << "\n Enter element for Search : ";
  cin >> n;
  search(root, n);
}