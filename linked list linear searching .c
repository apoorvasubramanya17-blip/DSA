#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL, *newNode, *temp;
    int n, key, i, found = 0, position = 1;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Creating the linked list
    for(i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter the data: ");
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

    // Searching for an element
    printf("Enter the element to search: ");
    scanf("%d", &key);

    temp = head;

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            found = 1;
            printf("Element found at node number %d", position);
            break;
        }

        temp = temp->next;
        position++;
    }

    if(found == 0)
    {
        printf("Element not found!");
    }

    return 0;
}
