#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    if (root_ == nullptr) {
      root_ = new Node(key, value);
      return;
    }
    Node* n = root_;
    while (true) {
      if (key < n->key) {
        if (n->left == nullptr) {
          break;
        }
        else {
          n = n->left;
        }
      }
      else if (key > n->key) {
        if (n->right == nullptr) {
          break;
        }
        else {
          n = n->right;
        }
      }
      else {
        n->value = value;
        return;
      }
    }
    if (key < n->key) {
      Node* k = new Node(key, value);
      n->left = k;
    }
    else {
      Node* k = new Node(key, value);
      n->right = k;
    }
  }

  bool BinarySearchTree::Remove(int key) {
    if (root() == nullptr)
      return false;
    return remove(key, root_);
  }

  void BinarySearchTree::Clear() {
    root_ = nullptr;
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    Node* n = root_;
    while (n != nullptr) {
      if (n->key == key) {
        return n->value;
      }
      if (key < n->key) {
        n = n->left;
      }
      else {
        n = n->right;
      }
    }
    return std::nullopt;
  }

  bool BinarySearchTree::Contains(int key) const {
    if (Find(key) != std::nullopt)
        return true;
    return false;
  }

  bool BinarySearchTree::IsEmpty() const {
    return root_ == nullptr;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    if (find_min(root_) != nullptr)
      return find_min(root_)->value;
    return std::nullopt;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    if (find_max(root_) != nullptr)
      return find_max(root_)->value;
    return std::nullopt;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    // Write your code here ...
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    if (node == nullptr) {
      return false;
    }
    if (node->key == key) {
      if (node->left == nullptr || node->right == nullptr) {
        if (node->left == nullptr && node->right == nullptr) {
          node = nullptr;
          return true;
        }
        if (node->right == nullptr) {
          node = node->left;
          return true;
        }
        node = node->right;
        return true;
      }
      node->key = find_min(node->right)->key;
      node->value = find_min(node->right)->value;
      remove(node->key, node->right);
      return true;
    }
    if (node->key > key) {
      return remove(key, node->left);
    }
    remove(key, node->right);
  }

  void BinarySearchTree::clear(Node* node) {
    // Write your code here...
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    // Write your code here...
    return nullptr;
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    if (node == nullptr)
      return nullptr;
    if (node->left == nullptr)
      return node;
    return find_min(node->left);
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    if (node == nullptr)
      return nullptr;
    if (node->right == nullptr)
      return node;
    return find_max(node->right);
  }

}  // namespace assignment