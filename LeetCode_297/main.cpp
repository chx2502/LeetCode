#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    vector<string> levelTraversal(TreeNode *root) {
        vector<string> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (!node) {
                result.push_back("null");
                continue;
            }
            result.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        }
        // for (auto s : result) cout << s << " ";
        cout << endl;
        int i = result.size()-1;
        while (result[i].compare("null") == 0) i--;
        result.erase(result.begin()+i+1, result.end());
        return result;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "[";
        vector<string> inorder = levelTraversal(root);
        for (auto &node : inorder) {
            result = result + node + ",";
        }
        if (result.back() == ',') result.pop_back();
        result += "]";
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        for (auto &c : data) {
            if (c =='[' || c == ']' || c == ',') c = ' ';
        }
        cout << "data: " << data << endl;
        stringstream ss(data);
        string temp;

        vector<TreeNode*> arr;
        arr.push_back(nullptr);
        while (ss >> temp) {
            cout << "temp: " << temp << endl;
            if (temp.compare("null") == 0) arr.push_back(nullptr);
            else {
                TreeNode *node = new TreeNode(stoi(temp));
                arr.push_back(node);
            }
        }
        int count = 1;
        while (count < arr.size()) count <<= 1;
        cout << "count = " << count << endl;
        cout << "arr: ";
        for (auto &n : arr) {
            if (n) cout << n->val << " ";
            else cout << "null ";
        }
        cout << endl;
        for (int i = 1; i < count && i < arr.size(); i++) {
            cout << "arr.size() = " << arr.size() << endl;
            if (!arr[i]) {
                arr.insert(arr.begin()+i*2-1, nullptr);
                arr.insert(arr.begin()+i*2, nullptr);        
                cout << "arr: ";
                for (auto &n : arr) {
                    if (n) cout << n->val << " ";
                    else cout << "null ";
                }
                cout << endl;
                continue;
            }
            if (i*2 < arr.size()) arr[i]->left = arr[i*2];
            if (i*2+1 < arr.size()) arr[i]->right = arr[i*2+1];
        }
        return arr.size() > 1 ? arr[1] : arr[0];
    }
};

int main(int argc, char *argv[]) {
    Codec c;
    string data = "[1,2,3,null,null,4,5]";
    TreeNode *tree = c.deserialize(data);
    string result = c.serialize(tree);
    cout << result << endl;
}