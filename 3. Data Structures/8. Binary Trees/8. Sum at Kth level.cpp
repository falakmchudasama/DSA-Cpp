#include <iostream>
#include <queue>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to calculate the sum of nodes at level K in the binary tree
int sumAtK(Node* root, int K) {
    // If the root is null, return -1 indicating an invalid input
    if (root == NULL) {
        return -1;
    }

    // Queue to perform level-order traversal
    queue<Node*> q;

    // Enqueue the root and a null marker to signify the end of each level
    q.push(root);
    q.push(NULL);

    int level = 0; // Variable to keep track of the current level
    int sum = 0;   // Variable to store the sum of nodes at level K

    // Level-order traversal using the queue
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        // If the node is not null, process it
        if (node != NULL) {
            // Check if the current level matches the target level K
            if (level == K) {
                sum += node->data; // Add the node's data to the sum
            }

            // Enqueue the left and right children if they exist
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        } else if (!q.empty()) {
            // If the node is null and the queue is not empty, enqueue a null marker
            // and increment the level to move to the next level
            q.push(NULL);
            level++;
        }
    }

    // Return the sum of nodes at level K
    return sum;
}

// Main function to test the sumAtK function
int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    // Print the sum of nodes at level 2
    cout << "Sum at level 2: " << sumAtK(root, 2) << endl;

    // Deallocate memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}