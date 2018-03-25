#include <iostream>

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
  my_queue() { head = NULL; }

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

    while (tmp->next != NULL) {
      tmp = tmp->next;
    }

    tmp->next = qn;

    qn->next = NULL;
  }

  queue_node* delete_from_queue() {
    queue_node* tmp = head;

    if (tmp == NULL) {
      cout << "\nUnderflow!\n";

      return NULL;
    }

    head = head->next;

    return tmp;
  }

  int how_many_elements() {
    int cnt = 0;

    queue_node* qn = head;

    if (qn == NULL) {
      return 0;
    }

    while (qn != NULL) {
      cnt++;

      qn = qn->next;
    }

    return cnt;
  }

  bool is_vacant() {
    if (head == NULL) return true;

    return false;
  }
};

class tree {
  node* root;

 public:
  tree() { root = NULL; }

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

    while (tmp != NULL) {
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

  node* return_root() { return root; }

  int sum_all_levels() {
    node* tmp = root;

    if(tmp == NULL)
        return -1;

    my_queue q;
    q.insert_into_queue(tmp);

    int sum = 0, lev = 0, cnt = 0;

    while (!q.is_vacant()) {
      cnt = q.how_many_elements();

      sum = 0;
      while (cnt--) {
        queue_node* qn = q.delete_from_queue();
        tmp = qn->tree_node;
        sum += tmp->value;
        if(tmp->left != NULL) 
            q.insert_into_queue(tmp->left);

        if(tmp->right != NULL) 
            q.insert_into_queue(tmp->right);
      }

      cout << "\n\tSum of nodes at level " << lev << " is : " << sum << endl;

      lev++;
    }
  }
};

void sum_all_levels() {}

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
  t->sum_all_levels();

  return 0;
}
