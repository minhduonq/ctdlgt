#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

class Tree {
public:
  Tree(int n, int m) {
    nodes.resize(n + 1);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      nodes[u]->left = nodes[v];
    }
  }

  int height() {
    return height(nodes[1]);
  }

  void preorder(vector<int>& preorder) {
    preorderTraversal(nodes[1], preorder);
  }

  void postorder(vector<int>& postorder) {
    postorderTraversal(nodes[1], postorder);
  }

  void inorder(vector<int>& inorder) {
    inorderTraversal(nodes[1], inorder);
  }

  bool isBinary() {
    return isBinary(nodes[1]);
  }

private:
  vector<Node*> nodes;

  int height(Node* node) {
    if (node == nullptr) {
      return -1;
    }

    return max(height(node->left), height(node->right)) + 1;
  }

  void preorderTraversal(Node* node, vector<int>& preorder) {
    if (node == nullptr) {
      return;
    }

    preorder.push_back(node->data);
    preorderTraversal(node->left, preorder);
    preorderTraversal(node->right, preorder);
  }

  void postorderTraversal(Node* node, vector<int>& postorder) {
    if (node == nullptr) {
      return;
    }

    postorderTraversal(node->left, postorder);
    postorderTraversal(node->right, postorder);
    postorder.push_back(node->data);
  }

  void inorderTraversal(Node* node, vector<int>& inorder) {
    if (node == nullptr) {
      return;
    }

    inorderTraversal(node->left, inorder);
    inorder.push_back(node->data);
    inorderTraversal(node->right, inorder);
  }

  bool isBinary(Node* node) {
    if (node == nullptr) {
      return true;
    }

    if (node->left != nullptr && node->right != nullptr) {
      return isBinary(node->left) && isBinary(node->right);
    } else if (node->left != nullptr || node->right != nullptr) {
      return false;
    } else {
      return true;
    }
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  Tree tree(n, m);

  int height = tree.height();
  cout << "Height: " << height << endl;

  vector<int> preorder, postorder, inorder;
  tree.preorder(preorder);
  tree.postorder(postorder);

  if (tree.isBinary()) {
    tree.inorder(inorder);
  } else {
    cout << "NOT BINARY TREE" << endl;
  }

  cout << "Preorder: ";
  for (int i = 0; i < preorder.size(); i++) {
    cout << preorder[i] << " ";
  }
  cout << endl;

  cout << "Postorder: ";
  for (int i = 0; i < postorder.size(); i++) {
    cout << postorder[i] << " ";
  }
  cout << endl;

  if (tree.isBinary()) {
    cout << "Inorder: ";
    for (int i = 0; i < inorder.size(); i++) {
      cout << inorder[i] << " ";
    }
  }

  cout << endl;

  return 0;
}
