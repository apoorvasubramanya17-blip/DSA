#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// CREATE LINKED LIST
void create()
{
    struct Node *newNode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

// DELETE FROM BEGINNING
void deleteFirst()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);

    printf("First node deleted successfully.\n");
}

// DELETE FROM END
void deleteEnd()
{
    struct Node *temp, *prev;

    if(head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    free(temp);

    printf("Last node deleted successfully.\n");
}

// DELETE FROM GIVEN POSITION
void deletePosition()
{
    struct Node *temp, *prev;
    int pos, i;

    if(head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if(pos <= 0)
    {
        printf("Invalid position.\n");
        return;
    }

    if(pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    temp = head;

    for(i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;

    free(temp);

    printf("Node deleted successfully.\n");
}

// DISPLAY LINKED LIST
void display()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// MAIN FUNCTION
int main()
{
    int choice;

    while(1)
    {
        printf("\n----- LINKED LIST MENU -----\n");
        printf("1. Create Linked List\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from Given Position\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                deleteFirst();
                break;

            case 3:
                deletePosition();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
