#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class BinarySearchTree;

template <typename T>
class Node
{
private:
    T data;
    Node<T>* left;
    Node<T>* right;
public:
    Node<T>();
    Node<T>(const Node<T>& n);
    ~Node<T>();
    Node<T>& operator=(const Node<T>& n);
    friend class BinarySearchTree<T>;
};

template <typename T>
Node<T>::Node() {
    data = "";
    left = nullptr;
    right = nullptr;
}

template <typename T>
Node<T>::Node(const Node<T>& n) {

    data = n.data;
    if (n.left == nullptr) {
        left = nullptr;
    } else {
        left = new Node<T> (*n.left);
    }
    if (n.right == nullptr) {
        right = nullptr;
    } else {
        right = new Node<T>(*n.right);
    }
}

template <typename T>
Node<T>& Node<T>::operator=(const Node<T>& n){
    data = n.data;

    if (n.left == nullptr) {
        left = nullptr;
    }
    else {
        left = new Node<T>(*n.left);
    }
    if (n.right == nullptr) {
        right = nullptr;
    }
    else {
        right = new Node<T>(*n.right);
    }
}

template <typename T>
Node<T>::~Node() {
    // Toss all the subtrees recursively
    delete left;
    delete right;
}

/*
   This class implements a binary search tree whose
   nodes hold strings.
*/
template <typename T>
class BinarySearchTree {
public:
    
    struct Assignment {
    int id;
    int groupId;
    string description;
    string startDate;
    string endDate;
    int possiblePoints;
    int pointsEarned;
};
    void populateTree();

    /**
       Constructs an empty tree.
    */
    BinarySearchTree();
    
    // Destructor
    ~BinarySearchTree();

    /**
       Inserts a new node into the tree.
       @param element the element to insert
    */
    void insert(T element);

    /**
       Tries to find an element in the tree.
       @param element the element to find
       @return 1 if the element is contained in the tree
    */
    int count(T element) const;

    /**
       Tries to remove an element from the tree. Does nothing
       if the element is not contained in the tree.
       @param element the element to remove
    */
    void erase(T element);
    
    
    /**
    Prints a node and all of its descendants in sorted order.
    */
    void print() const;
    
    /**
       Assignment operator
       @param tree  the tree to be copied
    */
    BinarySearchTree<T>& operator=(const BinarySearchTree<T>& bst);

private:
/**
       Inserts a new node as a descendant of a given node.
       @param parent the root node
       @param new_node the node to insert
    */
    void add_node(Node<T>* parent, Node<T>* new_node) const;
    /**
    Prints a node and all of its descendants in sorted order.
    @param parent the root of the subtree to print
    */
    void print(Node<T>* parent) const;

    Node<T>* root;
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    delete root;
}

template <typename T>
void BinarySearchTree<T>::insert(T element) {
    Node<T>* new_node = new Node<T>;
    new_node->data = element;
    new_node->left = nullptr;
    new_node->right = nullptr;
    if (root == nullptr) {
        root = new_node;
    } else {
        add_node(root, new_node);
    }
}

template <typename T>
int BinarySearchTree<T>::count(T element) const {
    Node<T>* current = root;
    while (current != nullptr) {
        if (element < current->data) {
            current = current->left;
        } else if (element > current->data) {
            current = current->right;
        } else {
            return 1;
        }
    }
    return 0;
}

template <typename T>
void BinarySearchTree<T>::erase(T element) {
    // Find node to be removed

    Node<T>* to_be_removed = root;
    Node<T>* parent = nullptr;
    bool found = false;
    while (!found && to_be_removed != nullptr) {
        if (element == to_be_removed->data) {
            found = true;
        } else {
            parent = to_be_removed;
            if (element < to_be_removed->data) {
                to_be_removed = to_be_removed->left;
            } else {
                to_be_removed = to_be_removed->right;
            }
        }
    }

    if (!found) {
        return;
    }

    // to_be_removed contains element

    // If one of the children is empty, use the other

    if (to_be_removed->left == nullptr || to_be_removed->right == nullptr) {
        Node<T>* new_child;
        if (to_be_removed->left == nullptr) {
            new_child = to_be_removed->right;
        } else {
            new_child = to_be_removed->left;
        }

        if (parent == nullptr) { // Found in root
            root = new_child;
        } else if (parent->left == to_be_removed) {
            parent->left = new_child;
        } else {
            parent->right = new_child;
        }
        return;
    }

    // Neither subtree is empty

    // Find smallest element of the right subtree

    Node<T>* smallest_parent = to_be_removed;
    Node<T>* smallest = to_be_removed->right;
    while (smallest->left != nullptr) {
        smallest_parent = smallest;
        smallest = smallest->left;
    }

    // smallest contains smallest child in right subtree

    // Move contents, unlink child

    to_be_removed->data = smallest->data;
    if (smallest_parent == to_be_removed) {
        smallest_parent->right = smallest->right;
    } else {
        smallest_parent->left = smallest->right;
    }
}

int indent;
template <typename T>
void BinarySearchTree<T>::print(Node<T>* parent) const {
    if (parent == nullptr) {
        return;
    }
    indent += 4;
    print(parent->left);
    for (int i = 0; i < indent; i++){
        cout << ' ';
    }
    cout << parent->data << ' ' << endl;;
    print(parent->right);
    indent -= 4;
}

template <typename T>
void BinarySearchTree<T>::print() const {
    indent = -4;
    print(root);
    cout << endl;
}


template <typename T>
void BinarySearchTree<T>::add_node(Node<T>* parent, Node<T>* new_node) const{
    if (new_node->data < parent->data) {
        if (parent->left == nullptr){
            parent->left = new_node;
        } else {
            add_node(parent->left, new_node);
        }
    }
    else if (new_node->data > parent->data) {
        if (parent->right == nullptr) {
            parent->right = new_node;
        } else {
            add_node(parent->right, new_node);
        }
    }
}
template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator= (const BinarySearchTree<T>& bst) {
    delete root;
    if (bst.root == nullptr) {
        root = nullptr;
    } else {
        root = new Node<T>(*(bst.root));
    }
}

template <typename T>
void BinarySearchTree<T>::populateTree() {
    ifstream file("assignment-data.csv");
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        vector<string> tokens;
        while (getline(ss, temp, ',')) {
            tokens.push_back(temp);
        }
        if (tokens.size() != 7) {
            cerr << "Error: Invalid data format." << endl;
            continue;
        }

        Assignment assignment;
        assignment.id = stoi(tokens[0]);
        assignment.groupId = stoi(tokens[1]);
        assignment.description = tokens[2];
        assignment.startDate = tokens[3];
        assignment.endDate = tokens[4];
        assignment.possiblePoints = stoi(tokens[5]);
        assignment.pointsEarned = stoi(tokens[6]);

        //insert(assignment);
    }

    file.close();
}

#endif