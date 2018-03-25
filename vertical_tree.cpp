#include "BS_Tree.h"

void give_horizontal_dist(node* root,int *min_dist, int *max_dist,int horizontal) {
    if (root != NULL) {
        if (horizontal < *min_dist)
            *min_dist = horizontal;
        else if (horizontal > *max_dist)
            *max_dist = horizontal;

        give_horizontal_dist(root->left,min_dist,max_dist,horizontal-1);
        give_horizontal_dist(root->right,min_dist,max_dist,horizontal+1);
    }
}

void one_line_display(node* nd, int line, int horiz) {
    if (nd != NULL) {
        if (horiz == line)
            cout<<nd->value<<" ";
        one_line_display(nd->left,line,horiz-1);
        one_line_display(nd->right,line,horiz+1);
    }
}

void vertical_tree_display(node* root) {
    if (root != NULL) {
        int min_dist = 0, max_dist = 0;
        give_horizontal_dist(root,&min_dist,&max_dist,0);
        for (int i = min_dist; i <= max_dist; i++) {
            one_line_display(root,i,0);
            cout<<endl;
        }
    }
}

int main()
{
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

    vertical_tree_display(t->return_root());

    return 0;
}
