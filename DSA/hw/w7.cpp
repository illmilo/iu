#include <iostream>

using namespace std;

class AVLTree {
private:
    struct Node {
        int key, value, height;
        Node* left;
        Node* right;

        Node(int k, int v) : key(k), value(v), height(1), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int rotations;

    int height(Node* n) {
        return n ? n->height : 0;
    }

    int getBalance(Node* n) {
        return n ? height(n->left) - height(n->right) : 0;
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        rotations++;
        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        rotations++;
        return y;
    }

    Node* insert(Node* node, int key, int value) {
        if (!node) return new Node(key, value);

        if (key < node->key)
            node->left = insert(node->left, key, value);
        else if (key > node->key)
            node->right = insert(node->right, key, value);
        else
            return node;

        node->height = max(height(node->left), height(node->right)) + 1;
        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rotateRight(node);

        if (balance < -1 && key > node->right->key)
            return rotateLeft(node);

        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* root, int key) {
        if (!root) return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left || !root->right) {
                Node* temp = root->left ? root->left : root->right;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }

        if (!root) return root;

        root->height = max(height(root->left), height(root->right)) + 1;
        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rotateRight(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0)
            return rotateLeft(root);

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    Node* lookup(Node* node, int key) {
        if (!node || node->key == key) return node;
        if (key < node->key) return lookup(node->left, key);
        return lookup(node->right, key);
    }

public:
    AVLTree() : root(nullptr), rotations(0) {}

    void add(int key, int value) {
        if (lookup(root, key)) {
            cout << "KEY ALREADY EXISTS\n";
        } else {
            root = insert(root, key, value);
        }
    }

    int lookup(int key) {
        Node* node = lookup(root, key);
        return node ? node->value : -101;
    }

    void del(int key) {
        if (!lookup(root, key)) {
            cout << "KEY NOT FOUND\n";
        } else {
            root = deleteNode(root, key);
        }
    }

    int getRotations() {
        return rotations;
    }
};

AVLTree tree;

void fetch(string command) {
    if (command == "ADD") {
        int k, v;
        cin >> k >> v;
        tree.add(k, v);
    }
    if (command == "LOOKUP") {
        int k;
        cin >> k;
        cout << tree.lookup(k) << '\n';
    }
    if (command == "DELETE") {
        int k;
        cin >> k;
        tree.del(k);
    }
    if (command == "PRINT_ROTATIONS") {
        cout << tree.getRotations() << endl;
    }
}

int main() {
    // freopen("i.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        fetch(command);
    }
}
