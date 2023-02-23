#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node *next;
} node;

node *head = NULL;

node *create_node(){
    node *new_node = malloc(sizeof(node));
    printf("Enter Value = ");
    scanf("%d", &new_node->number);
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

void insert_at_first(){
    node *new_node = create_node();
    node *iterable = head;
    head = new_node;
    head->next = iterable;
}

void insert_node_intermidiate(int position){
    int index = 1;
    node *iterable = head;
    while(index < position){
        if(iterable == NULL){
            printf("Invalid Position \n");
            return;
        }
        iterable = iterable -> next;
         index += 1;
    }
    
    node *temp = iterable->next;
    node *new_node = create_node();
    new_node->next = temp;
    iterable->next = new_node;
    return;
}

void update_node_intermidiate(unsigned int position){
    int index = 0;
    node *iterate = head;
    node* prev = NULL;
    
    while(index < position){
        if(iterate->next == NULL){
            printf("Invalid position\n");
            return;
        }
        prev = iterate;
        iterate = iterate->next;
        index += 1;
    }
    node *new_node = create_node();
    new_node->next = iterate->next;
    if(prev != NULL)
        prev->next = new_node;
    else
        head = new_node;
    free(iterate);
    return;
}


void delete_node(unsigned int position){
    int index = 0;
    node *iterate = head;

    while(index < position){
        if(iterate == NULL){
            printf("Invalid position\n");
            return;
        }
        iterate = iterate->next;
        index +=1;
    }
    
    node *temp = iterate->next;
    iterate->next = temp->next;
    free(temp);
    return;


}



void print_list(){
    node *iterate = head;
    if(iterate == NULL){
        printf("Your List is zero");
    }
    
    while(iterate != NULL){
        printf("%d ", iterate->number);
        iterate = iterate-> next;
    }
    
    printf("\n");
}

void count_node(){
    int count = 0;
    node *iterate = head;
    
    if(iterate == NULL){
        printf("count is = %d", count);
        return;
    }
    
    while(iterate !=NULL){
        count += 1;
        iterate = iterate->next;
    }
    printf("Count is = %d\n", count);
    
}



int main(){
    insert_node();
    insert_node();
    insert_node();
    print_list();
    delete_node(1); 
    print_list();
    update_node_intermidiate(1);
    print_list();    
    count_node();
}


