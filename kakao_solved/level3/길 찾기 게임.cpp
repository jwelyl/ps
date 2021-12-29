// https://programmers.co.kr/learn/courses/30/lessons/42892 
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Node {
public:
    int node_num;
    int x, y;
    Node* left; 
    Node* right;

    Node(int node_num, int x, int y) : node_num(node_num), x(x), y(y) {
        left = NULL;
        right = NULL;
    }
};

Node* root = NULL;
vector<Node*> nodes;
vector<bool> used;

bool comp(Node* node1, Node* node2) {
    if(node1->y != node2->y)
        return node1->y > node2->y;
    else
        return node1->x < node2->x;
}

void preorder(Node* root, vector<int>& answer) {
    if(!root) return;

    answer.push_back(root->node_num);
    preorder(root->left, answer);
    preorder(root->right, answer);
}

void postorder(Node* root, vector<int>& answer) {
    if(!root) return;

    postorder(root->left, answer);
    postorder(root->right, answer);
    answer.push_back(root->node_num);
}

void insert_node(Node** root, Node* node) {
    if(!(*root)) {
        (*root) = node;
        return;
    }
    
    if((*root)->x > node->x)
        insert_node(&((*root)->left), node);
    else
        insert_node(&((*root)->right), node);
}

void delete_tree(Node** root) {
    if(!(*root)) return;

    delete_tree(&((*root)->left));
    delete_tree(&((*root)->left));
    
    delete (*root);
    *root = NULL;
}

vector<vector<int> > solution(vector<vector<int> > nodeinfo) {
    vector<vector<int> > answer;
    answer.assign(2, vector<int>());

    nodes.assign(nodeinfo.size(), NULL);
    used.assign(nodeinfo.size(), false);

    for(int i = 0; i < nodeinfo.size(); i++) 
        nodes[i] = new Node(i + 1, nodeinfo[i][0], nodeinfo[i][1]);

    sort(nodes.begin(), nodes.end(), comp);

    for(int i = 0; i < nodes.size(); i++)
        insert_node(&root, nodes[i]);
    
    preorder(root, answer[0]);
    postorder(root, answer[1]);

    delete_tree(&root);
    
    return answer;
}