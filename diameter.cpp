#include "BS_Tree.h"

int max_of (int a, int b) {
    if (a >= b)
        return a;
    else
        return b;
}

int max_of (int a, int b, int c) {
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

int tree_height(node* tmp) {
    if (tmp != NULL) {
        int left = tree_height(tmp->left);
        int right = tree_height(tmp->right);
        return (max_of(left,right)+1);
    }
    return 0;
}

int tree_diameter(node* tmp) {
    if (tmp != NULL) {
        int diam = 0;
        diam = max_of (tree_height(tmp->left)+tree_height(tmp->right)+1,tree_diameter(tmp->left),tree_diameter(tmp->right));
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
