// https://programmers.co.kr/learn/courses/30/lessons/42892
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(vector<int> n1, vector<int> n2) {
    if(n1[2] > n2[2]) return true;
    else if(n1[2] == n2[2])
        return n1[1] > n2[1];
    else return false;
}

class Node {
public:
    int name;
    int x;
    int y;
    Node* left;
    Node* right;
    Node(int n, int x, int y) : name(n), x(x), y(y), left(NULL), right(NULL) {}
};

class BinTree {
public:
    Node* root;
    BinTree(int n, int y, int x) {
        root = new Node(n, y, x);
    }
    void insert_node(Node* root, Node* input) {
        if(input->x < root->x) {
            if(root->left)
                insert_node(root->left, input);
            else 
                root->left = input;
        }
        else {
            if(root->right)
                insert_node(root->right, input);
            else
                root->right = input;
        }
    } 
    void preorder(Node* root, vector<vector<int> >& traversal) {
        if(!root) return;

        traversal[0].push_back(root->name);
        preorder(root->left, traversal);
        preorder(root->right, traversal);
    }
    
    void postorder(Node* root, vector<vector<int> >& traversal) {
        if(!root) return;

        postorder(root->left, traversal);
        postorder(root->right, traversal);
        traversal[1].push_back(root->name);
    }

    void delete_tree(Node* root) {
        if(!root) return;

        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }

    ~BinTree() {
        delete_tree(this->root);
    }
};

BinTree* bt;

vector<vector<int> > solution(vector<vector<int> > nodeinfo) {
    vector<vector<int> > answer;
    vector<vector<int> > nodes;
    nodes.assign(nodeinfo.size(), vector<int>());
    answer.assign(2, vector<int>());

    for(int i = 0; i < nodeinfo.size(); i++) {
        nodes[i].push_back(i + 1);          //  노드 번호
        nodes[i].push_back(nodeinfo[i][0]); //  노드 x 좌표
        nodes[i].push_back(nodeinfo[i][1]); //  노드 y 좌표
    }
    sort(nodes.begin(), nodes.end(), comp);

    bt = new BinTree(nodes[0][0], nodes[0][1], nodes[0][2]);

    for(int i = 1; i < nodes.size(); i++) {
        Node* node = new Node(nodes[i][0], nodes[i][1], nodes[i][2]);
        bt->insert_node(bt->root, node);
    }

    bt->preorder(bt->root, answer);
    bt->postorder(bt->root, answer);
    delete bt;

    return answer;
}