#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int x) {
    data = x;
    left = right = nullptr;
  }
};

// Same as above, just uses init lists.
// struct Node {
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val) : value(val), left(nullptr), right(nullptr) {}
// };

class Bst {
private:
  Node *root;
  void _insert(Node *&sub_root, int x) {
    if (sub_root == nullptr) {
      sub_root = new Node(x);
    } else {
      // go left if less
      if (x < sub_root->data) {
        _insert(sub_root->left, x);
      } else {
        // go right if greater
        _insert(sub_root->right, x);
      }
    }
  }

//   Node* _delete(Node* sub_root, int x) {             // Function to delete a node recursively
//     if (sub_root == nullptr) return sub_root;
    
//     if (x < sub_root->data) {
//       sub_root->left = _delete(sub_root->left, x);
//     } else if (x > sub_root->data) {
//       sub_root->right = _delete(sub_root->right, x);
//     } else {
     
//       if (sub_root->left == nullptr) {               // Case 1: Node has no children or only one child
//         Node* temp = sub_root->right;
//         delete sub_root;                             // Free memory of deleted node
//         return temp;                                 // Return the new subtree root
//       } else if (sub_root->right == nullptr) {
//         Node* temp = sub_root->left;
//         delete sub_root;                             // Free memory of deleted node
//         return temp;                                 // Return the new subtree root
//       }
      
   
//       Node* temp = _min_value_node(sub_root->right); // Case 2: Node has two children, find the inorder successor
//       sub_root->data = temp->data;                   // Copy inorder successor's value to this node
//       sub_root->right = _delete(sub_root->right, temp->data); // Delete the inorder successor
//     }
//     return sub_root;                                 // Return the updated subtree root
//   }
  
  
//   Node* _min_value_node(Node* node) {               // Helper function to find the node with the minimum value in a subtree
//     Node* current = node;
//     while (current && current->left != nullptr) {
//       current = current->left;
//     }
//     return current;
//   }

  void _print(Node *root) {
    if (!root) {
      return;
    }


    _print(root->right);
    cout << root->data << " ";
    _print(root->left);
  }

public:
  Bst() { root = nullptr; }
  void insert(int x) { _insert(root, x); }
  bool search() { return 0; }
  void print() { _print(root); }
  void remove(int x) { root = _delete(root, x); }
};

int main() {
  std::cout << "Hello World!\n";
  Bst tree;
  tree.insert(8);
  tree.insert(3);
  tree.insert(1);
  tree.insert(11);
  tree.insert(7);
  tree.insert(15);
  // for(int i=0;i<1000;i++){
  //    tree.insert(rand()%1000);
  // }
  tree.print();
}