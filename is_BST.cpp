#include "BS_Tree.h"

//using namespace std;

/*struct node {
    int value;
    node* left;
    node* right;
};

class tree {
    node* root;
public:
    tree() {
        root = NULL;
    }
    node* create_node(int val) {
        node* new_node = new node();
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->value = val;
        return new_node;
    }
    void insert_into_tree(node* new_node) {
        node* tmp = root;
        if (tmp == NULL) {
            root = new_node;
            root->left = NULL;
            root->right = NULL;
            return;
        }
        int val = new_node->value;
        node* prev = root;
        while(tmp != NULL) {
            if (tmp == root)
                ;
            else {
                prev = tmp;
            }
            if (tmp->value > val) {
                tmp = tmp->left;
            }
            else {
                tmp = tmp->right;
            }
        }
        if (prev->value < val) {
            prev->right = new_node;
        }
        else {
            prev->left = new_node;
        }
        return;
    }
    node* return_root() {
        return root;
    }
    int no_of_nodes(node* nd,int ctr) {
        if (nd != NULL) {
            ctr++;
            no_of_nodes(nd->left,ctr);
            no_of_nodes(nd->left,ctr);
        }
        return ctr;
    }
};*/

void inorder(node* tmp, int i, int arr[]) {
    if (tmp != NULL) {
        inorder (tmp->left,i,arr);
        arr[i]=tmp->value;
        i++;
        inorder(tmp->right,i,arr);
    }
    return;
}

bool is_BST(BS_Tree* tr) {
    int n = tr->no_of_nodes(tr->return_root(),0);
    int* arr = new int[n];
    inorder(tr->return_root(),0,arr);
    for (int i=0; i<n-1; i++) {
        if (arr[i] > arr[i+1])
            return false;
    }
    return true;
}

int main() {
    BS_Tree* t = new BS_Tree();

    node* nn1 = t->create_node(50);
    node* nn2 = t->create_node(65);
    node* nn3 = t->create_node(13);
    node* nn4 = t->create_node(32);
    node* nn5 = t->create_node(78);

    t->insert_into_tree(nn1);
    t->insert_into_tree(nn2);
    t->insert_into_tree(nn3);
    t->insert_into_tree(nn4);
    t->insert_into_tree(nn5);

    if (is_BST(t))
        cout<<"\n\tGiven tree is BST\n";
    else
        cout<<"\n\tGiven tree is not BST\n";
    return 0;
}
