#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int number;
    struct Node * next;
} node;

node * head = NULL;

node* create_node()
{
    node* new_node = malloc(sizeof(node));
    printf("Enter the value: ");
    scanf("%d", &new_node->number);
    new_node->next = NULL;
    return new_node;
}

void count_node()
{
    int counter = 0;
    node* iterator = head;
    if(iterator == NULL) 
    {
        printf("Count = %d\n", counter);
        return;
    }
    while (iterator != NULL)
    {
        counter += 1;
        iterator = iterator->next;
    }
    printf("Count = %d\n", counter);
    return;
}

void print_list()
{
    node* iterator = head;
    if(iterator == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    while (iterator != NULL)
    {
        printf("%d ", iterator->number);
        iterator = iterator->next;
    }
    printf("\n");
}

void insert()
{
    node* new_node = create_node();
    node * iterator = head;
    if(iterator == NULL) 
    {
        head = new_node;
        return;
    }
    while (iterator->next != NULL)
    {
        iterator = iterator->next;
    }
    iterator->next = new_node;
    return;
}

void insert_at_first()
{
    node* new_node = create_node();
    node * iterator = head;
    head = new_node;
    head->next = iterator;
    return;
}

void insert_at_intermidiate(int position) 
{
    int index = 1;
    node* iterator = head;
    while(index < position) 
    {
        if(iterator == NULL) 
        {
            printf("Invalid Position Passed\n");
            return;
        }
        iterator = iterator->next;
        index += 1;
    }
    node* temp = iterator->next;
    node* new_node = create_node();
    new_node->next = temp;
    iterator->next = new_node;
    return;
}

void update_at(int position) 
{
    int index = 1;
    node* iterator = head;
    while(index < position) 
    {
        if(iterator == NULL) 
        {
            printf("Invalid Position Passed\n");
            return;
        }
        iterator = iterator->next;
        index += 1;
    }
    node* temp = iterator->next;
    node* new_node = create_node();
    new_node->next = temp->next;
    iterator->next = new_node;
    free(temp);
    return;
}

void delete_at(int position)
{
    int index = 1;
    node* iterator = head;
    while(index < position) 
    {
        if(iterator == NULL) 
        {
            printf("Invalid Position Passed\n");
            return;
        }
        iterator = iterator->next;
        index += 1;
    }
    node* temp = iterator->next;
    printf("Deleting %d\n", temp->number);
    iterator->next = temp->next;
    free(temp);
    return;
}

int main()
{
    insert();
    print_list();
    insert_at_first();
    print_list();
    insert();
    insert();
    print_list();
    insert_at_intermidiate(2);
    // insert_at_intermidiate(500);
    print_list();
    update_at(2);
    print_list();
    delete_at(2);
    print_list();
    count_node();
    
    return 0;
}