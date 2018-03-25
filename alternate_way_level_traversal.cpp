#include "BS_Tree.h"

void ulta_pulta_level(node* tmp) {
    if (tmp != NULL) {
        my_queue q1,q2;
        queue_node* qn = new queue_node;
        cout<<tmp->value<<" ";
        if (tmp->left != NULL)
            q2.insert_into_queue(tmp->left);
        if (tmp->right != NULL)
            q2.insert_into_queue(tmp->right);
        while(!q1.is_vacant()||!q2.is_vacant()) {
            while(!q1.is_vacant()) {
                //cout<<"\nFROM QUEUE 1\n";
                qn = q1.delete_from_queue_tail();
                tmp = qn->tree_node;
                cout<<tmp->value<<" ";
                if (tmp->left != NULL)
                    q2.insert_into_queue(tmp->left);
                if (tmp->right != NULL)
                    q2.insert_into_queue(tmp->right);
            }
            cout<<endl;
            while(!q2.is_vacant()) {
                //cout<<"\nFROM QUEUE 2\n";
                qn = q2.delete_from_queue_tail();
                tmp = qn->tree_node;
                cout<<tmp->value<<" ";
                if (tmp->right != NULL)
                    q1.insert_into_queue(tmp->right);
                if (tmp->left != NULL)
                    q1.insert_into_queue(tmp->left);
            }
            cout<<endl;
        }
    }
}

int main()
{
    BS_Tree* t = new BS_Tree();

    node* nn1 = t->create_node(50);
    node* nn2 = t->create_node(65);
    node* nn3 = t->create_node(13);
    node* nn4 = t->create_node(32);
    node* nn5 = t->create_node(78);
    node* nn6 = t->create_node(10);
    node* nn7 = t->create_node(60);
    node* nn8 = t->create_node(8);
    node* nn9 = t->create_node(11);
    node* nn10 = t->create_node(62);
    node* nn11 = t->create_node(30);
    node* nn12 = t->create_node(40);

    t->insert_into_tree(nn1);
    t->insert_into_tree(nn2);
    t->insert_into_tree(nn3);
    t->insert_into_tree(nn4);
    t->insert_into_tree(nn5);
    t->insert_into_tree(nn6);
    t->insert_into_tree(nn7);
    t->insert_into_tree(nn8);
    t->insert_into_tree(nn9);
    t->insert_into_tree(nn10);
    t->insert_into_tree(nn11);
    t->insert_into_tree(nn12);

    ulta_pulta_level(t->return_root());

    return 0;
}
