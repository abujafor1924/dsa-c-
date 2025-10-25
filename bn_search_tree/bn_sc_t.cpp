#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Search Tree class
class BST {
private:
    Node* root;

    // Helper function to insert a new node
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

    // Helper function to search for a value
    bool search(Node* node, int value) {
        if (node == nullptr)
            return false;
        if (node->data == value)
            return true;
        if (value < node->data)
            return search(node->left, value);
        else
            return search(node->right, value);
    }

    // Helper function for inorder traversal
    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Helper function for preorder traversal
    void preorder(Node* node) {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Helper function for postorder traversal
    void postorder(Node* node) {
        if (node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Find minimum value node in a subtree
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    // Delete a node from the BST
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr)
            return node;

        if (value < node->data)
            node->left = deleteNode(node->left, value);
        else if (value > node->data)
            node->right = deleteNode(node->right, value);
        else {
            // Node found
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        return search(root, value);
    }

    void inorder() {
        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    }

    void preorder() {
        cout << "Preorder traversal: ";
        preorder(root);
        cout << endl;
    }

    void postorder() {
        cout << "Postorder traversal: ";
        postorder(root);
        cout << endl;
    }

    void deleteValue(int value) {
        root = deleteNode(root, value);
    }
};

// Main function
int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Binary Search Tree Created!" << endl;

    tree.inorder();
    tree.preorder();
    tree.postorder();

    cout << "\nSearch for 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search for 90: " << (tree.search(90) ? "Found" : "Not Found") << endl;

    cout << "\nDeleting 20, 30, 50..." << endl;
    tree.deleteValue(20);
    tree.deleteValue(30);
    tree.deleteValue(50);

    tree.inorder();

    return 0;
}
