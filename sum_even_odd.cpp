#include<iostream>



using namespace std;



struct node {

    int value;

    node* left;

    node* right;

};



struct queue_node {

    node* tree_node;

    queue_node* next;

};



class my_queue {

    queue_node* head;

public:

    my_queue() {

        head = NULL;

    }

    queue_node* create_node(node* tn) {

        queue_node* qn = new queue_node();

        qn->tree_node = tn;

        qn->next = NULL;

        return qn;

    }

    void insert_into_queue(node* tn) {

        queue_node* qn = create_node(tn);

        queue_node* tmp = head;

        if (tmp == NULL) {

            head = qn;

            head->next = NULL;

            return;

        }

        while(tmp->next != NULL) {

            tmp = tmp->next;

        }

        tmp->next = qn;

        qn->next = NULL;

    }

    queue_node* delete_from_queue() {

        queue_node* tmp = head;

        if (tmp == NULL) {

            cout<<"\nUnderflow!\n";

            return NULL;

        }

        head = head->next;

        return tmp;

    }

    bool is_vacant() {

        if (head == NULL)

            return true;

        return false;

    }

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

    int get_level(node* n) {

        node* tmp = root;

        if (n == NULL) {

            return -1;

        }

        if (tmp == NULL) {

            return -1;

        }

        int level=0;

        while(tmp!=NULL) {

            if (n == tmp)

                return level;

            if (n->value < tmp->value) {

                tmp = tmp->left;

                level++;

            }

            else {

                tmp = tmp->right;

                level++;

            }

        }

        return -1;

    }

    int sum_level(int lev, node* root) {

        node* tmp = root;

        int level = 0, sum_e = 0, sum_o = 0;

        if (tmp == NULL)

            return -1;

        my_queue q;

        queue_node* qn;

        q.insert_into_queue(tmp);

        while(!q.is_vacant()) {

            qn = q.delete_from_queue();

            tmp = qn->tree_node;

            level = get_level(tmp);

            if (level%2 == 0)

                sum_e += tmp->value;

            else

                sum_o += tmp->value;

            if (tmp->left != NULL)

                q.insert_into_queue(tmp->left);

            if (tmp->right != NULL)

                q.insert_into_queue(tmp->right);

        }

        return lev==0 ? sum_e : sum_o;

    }

};



void sum_even_odd(tree* tr) {

        cout<<"\n\n\tSum of nodes at even level : "<<tr->sum_level(0,tr->return_root())<<endl;

        cout<<"\n\tSum of nodes at odd level : "<<tr->sum_level(1,tr->return_root())<<endl;

    }



int main() {

    tree* t = new tree();



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



    sum_even_odd(t);



    return 0;

}