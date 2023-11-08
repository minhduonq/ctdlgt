Node* removeMin(Node* root) {
  if (root == nullptr) {
    return nullptr;
  }

  //Node min ở vị trí bên trái của cây nên ta tìm node trái nhất của cây
  Node* curr = root;
  while (curr->left != nullptr) {
    curr = curr->left;
  }

  // Xóa node bên trái
  if (curr->right == nullptr) {
    //Xóa node nếu nó không có con
    delete curr;
    return nullptr;
  } else if (curr->right->left == nullptr) {
    //Thay node đó bằng con nếu node chỉ có một con
    Node* newRoot = curr->right;
    delete curr;
    return newRoot;
  } else {
    // The node has two children, so we need to find the minimum element in its right subtree
    // and replace the node with that element.
    //Nếu node có 2 con ta timf node nhỏ hơn là nude con bên phải và  thay node đó vào vị trí của node cha
    Node* newRoot = removeMin(curr->right);
    curr->right = newRoot;
    return curr;
  }
}
