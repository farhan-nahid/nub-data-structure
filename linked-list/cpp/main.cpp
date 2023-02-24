#include <iostream>

typedef struct Node {
    int number;
    struct Node *next;
} node;

using namespace std;

node *head = NULL;

node *create_node(){
    node *new_node = new node;
    cout << "Enter Number ";
    cin>> new_node->number;
    new_node->next = NULL;
    return new_node;
}

void insert_node(){
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


void insert_first(){
    node *new_node = create_node();
    node *iterate = head;
    head= new_node;
    head->next = iterate;
}

void delete_intermidiate(unsigned int position){
    int index = 0;
    node *iterate = head;
    node *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while(index < position){
      prev = iterate;
      iterate = iterate->next;
      index +=1;
      if(iterate == NULL){
        cout << "Not Possible to delete" << endl;
        return;
      }
    }
    if(prev == NULL)
    {
        head = head->next;
        free(iterate);
        return;
    }
        
    prev->next = iterate->next;
    free(iterate);
    return;
}

void update_intermidiate(unsigned int position){
    int index = 0;
    node *iterate = head;
    node *prev = NULL;

    while(index < position){
      prev = iterate;
      iterate = iterate->next;
      index +=1;
      if(iterate == NULL){
        cout << "Not Possible to update" << endl;
        return;
      }
    }
    node *new_node = create_node();
    new_node->next = iterate->next;
    if(prev != NULL) prev->next = new_node;
    else head = new_node;

    free(iterate);
    return;
   
}

 void print_list(){
    node *iterate = head;

    if(iterate == NULL){
        printf("No item in Linked List \n");
        return;
    }

    while(iterate != NULL){
        printf("%d ", iterate->number);
        iterate = iterate->next;
    }

    cout << endl;
 }

 int main(){
    insert_node();
    print_list();
    insert_node();
    insert_node();
    print_list();
    insert_first();
    print_list();
    update_intermidiate(2);
    print_list();
    delete_intermidiate(4);
    print_list();

    return 0;
 }