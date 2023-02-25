#include <iostream>

using namespace std;

typedef struct Node {
    int number;
    string name;
    struct Node *next;
} node;



node *create_node(){
    node *new_node = new node;
    cout << "Enter number ";
    cin >> new_node->number;
    // cout << "Enter name ";
    // cin >> new_node->name;
    new_node->next = NULL;
    return new_node;
}

void insert_node(node *&head){
    node *new_node = create_node();
    node *iterate = head;
    if(iterate == NULL){
        head = new_node;
        return;
    }

    while(iterate->next != NULL){
        iterate = iterate->next;
    }
    iterate->next = new_node;
    
    return;
}


void print_list(node *head ){
    node *iterate = head;
    if(iterate == NULL){
        cout << "List Empty" << endl;
        return;
    }

    while(iterate != NULL){
        cout  << iterate->number << " ";
        iterate = iterate->next;
    }

    cout << endl;
}

void update_dynamicly(node *&head, int position){
    int index = 0;
    node *iterate = head;
    node *prev = NULL;

    if(head == NULL){
        cout << "Node eMPTY" << endl;
        return;
    }

    while(index < position){
        prev = iterate;
        iterate = iterate->next;
        index +=1;

        if(iterate == NULL){
            cout << "Position not found" << endl;
            return;
        }
    }
    node *new_node = create_node();
    new_node->next = iterate->next;
    if(prev==NULL) head = new_node;
    else  iterate->next = new_node;
    return;
}


int main (){
    node *head = NULL;

    print_list(head);
    insert_node(head);
    insert_node(head);
    print_list(head);
    update_dynamicly(head, 1);
    print_list(head);
    return 0;
}