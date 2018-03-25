#include "BS_Tree.h"

bool has_path (node* tmp, int k) {
    if (tmp != NULL) {
        if (k > 0) { // this is not a good check, key of the tree can be negative
            if (has_path(tmp->left,k-tmp->value) || has_path(tmp->right,k-tmp->value))
                return true;
        }
        else
            return false;
    }
    if (k == 0)
        return true;
    return false;
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

    if (has_path(t->return_root(),177))
        cout<<"\n\tThe given tree has a path from root to leaf of sum = 177\n";
    else
        cout<<"\n\tThe given tree does not have a path from root to leaf of sum = 177\n";

    if (has_path(t->return_root(),300))
        cout<<"\n\tThe given tree has path from root to leaf of sum = 300\n";
    else
        cout<<"\n\tThe given tree does not have a path from root to leaf of sum = 300\n";
    cout<<endl;

    return 0;
}
