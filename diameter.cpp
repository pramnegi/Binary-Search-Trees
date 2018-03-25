#include "BS_Tree.h"

int max_of(int a, int b) {
    if (a >= b)
        return a;
    else
        return b;
}

int max_of(int a, int b, int c) {
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

int tree_height(node* root) {
    if(root == NULL)
        return 0;
    
    int left = tree_height(root->left);
    int right = tree_height(root->right);
    return 1 + max(left, right);  // use #include <algorithm>    // std::max
}

// what is the run_time for this, you can reduce this easily
int tree_diameter(node* root) {
    if (root != NULL) {
        int diam = 0;
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        int left_diameter = tree_diameter(root->left);
        int right_diameter = tree_diameter(root->right);
        
        diam = max(max(left_height + right_height +1, left_diameter), right_diameter);
        return diam;
    }
}

int main() {
    BS_Tree* t = new BS_Tree();

    node* nn1 = t->create_node(50);
    node* nn2 = t->create_node(40);
    node* nn3 = t->create_node(30);
    node* nn4 = t->create_node(45);
    node* nn5 = t->create_node(42);
    node* nn6 = t->create_node(47);
    node* nn7 = t->create_node(26);
    node* nn8 = t->create_node(32);
    node* nn9 = t->create_node(31);

    t->insert_into_tree(nn1);
    t->insert_into_tree(nn2);
    t->insert_into_tree(nn3);
    t->insert_into_tree(nn4);
    t->insert_into_tree(nn5);
    t->insert_into_tree(nn6);
    t->insert_into_tree(nn7);
    t->insert_into_tree(nn8);
    t->insert_into_tree(nn9);

    cout<<"\n\tHeight of the tree is : "<<tree_height(t->return_root());
    cout<<"\n\n\tDiameter of the tree is : "<<tree_diameter(t->return_root());
    cout<<endl;

    return 0;
}
