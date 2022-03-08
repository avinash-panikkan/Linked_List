#include<stdio.h> //files include....
#include<stdlib.h> //preprocessor directory

struct node {    //structure-collection of diff type of data-user defined datatype
    int data;
    struct node * next;
};

int count = 0;
struct node *first_node;

struct node * createNode () {

    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next = NULL;

    printf("\n!----------Node created successfully----------!\n");
    return new_node;
}

void insertAtBeginning () {

    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next = first_node;
    first_node = new_node;
    printf("\nEnter the data of the new node : ");
    scanf("%d",&new_node->data);
    printf("\n!----------New node inserted successfully----------!\n");

    count++;
}

void insertAtEnd (struct node *current_node) {

    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next = NULL;

    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    printf("\nEnter the data of the new node : ");
    scanf("%d",&new_node->data);
    printf("\n!----------New node inserted successfully----------!\n");

    count++;
}

void insertAtPosition() {
 
    int i=1,pos;
    struct node *current_node;
    printf("\nEnter the position : ");
    scanf("%d",&pos);
    if(pos>count)
        printf("\nInvalid position\n");
    else
    {
        current_node = first_node;
        while (i<pos)
        {
            current_node = current_node->next;
            i++;
        }
        struct node * new_node = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data to be inserted : ");
        scanf("%d",&new_node->data);
        new_node->next = current_node->next;
        current_node->next = new_node;
        count++;
        printf("\n!----------New node inserted successfully----------!\n");
    }
}

void deleteAtBeginninig () {

    printf("\nThe data of the deleted node : %d",first_node->data);
    first_node = first_node->next;
    printf("\n!----------Node deleted successfully----------!\n");

    count--;
}

void deleteAtEnd (struct node *current_node) {

    while(current_node->next->next != NULL)
    {
        current_node = current_node->next;
    }
    printf("\nThe data of the deleted node : %d",current_node->next->data);
    current_node->next = NULL;
    printf("\n!----------Node deleted successfully----------!\n");

    count--;
}

void deleteAtPosition()
{
	struct node *current_node, *position;
	int i=1,pos;
	if(first_node==NULL)
		printf("\nLinked list is empty, deletion is not possible\n");
	else 
    {
		printf("\nEnter the position : ");
		scanf("%d", &pos);
        if(pos>count)
            printf("\nInvalid position\n");
        else
        {
		    position = malloc(sizeof(struct node));
		    current_node = first_node;
		    while(i<pos) 
		    {
		    	current_node = current_node->next;
		    	i++;
		    }
		    position=current_node->next;
		    current_node->next=position->next;
		    free(position);
            printf("\n!----------Node deleted successfully----------!\n");

            count--;
        }
	}
}

void display() {

    struct node *temp_node = first_node;
    printf("\nThe linked list :");
    while(temp_node != NULL)
    {
        printf("\t%d",temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

int main() {

    int choice;
    first_node = createNode();

    printf("\nEnter the data of the first node : ");
    scanf("%d",&first_node->data);

    struct node *current_node = first_node;

    while (1)
    {
        printf("\nThe followings operations can be performed : ");
        printf("\n1.Insert at beginning\t2.Insert at end\t3.Insert at position\t");
        printf("\n4.Delete at beginning\t5.Delete at end\t6.Delete at position\t");
        printf("\n7.Display linked list\t8.Exit program");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd(current_node);
                break;
            case 3:
                insertAtPosition();
                break;
            case 4:
                deleteAtBeginninig();
                break;
            case 5:
                deleteAtEnd(current_node);
                break;
            case 6:
                deleteAtPosition();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("\n!----------Exiting the program----------!\n");
                exit(0);
            default :
                printf("\nInvalid choice\n");
                break;
        }
    }
    

}
