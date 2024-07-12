#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";
        
        string result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "null,";
            }
        }

        // Remove the trailing comma
        if (!result.empty()) result.pop_back();
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null") return NULL;

        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);

        while (!ss.eof()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    TreeNode* leftChild = new TreeNode(stoi(item));
                    node->left = leftChild;
                    q.push(leftChild);
                }
            }

            // Right child
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    TreeNode* rightChild = new TreeNode(stoi(item));
                    node->right = rightChild;
                    q.push(rightChild);
                }
            }
        }

        return root;
    }
};

// Helper function to print the tree in level order
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

int main() {
    Codec codec;
    
    // Construct a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the binary tree
    string serialized = codec.serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    // Deserialize the string back to a binary tree
    TreeNode* deserializedRoot = codec.deserialize(serialized);

    // Print the deserialized tree in level order to verify
    cout << "Deserialized tree: ";
    printLevelOrder(deserializedRoot);

    return 0;
}
