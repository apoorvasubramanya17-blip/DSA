#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *newNode, *temp;
    int n, i;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if(head1 == NULL)
            head1 = newNode;
        else
        {
            temp = head1;
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    printf("Enter number of nodes in second list: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if(head2 == NULL)
            head2 = newNode;
        else
        {
            temp = head2;
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    if(head1 == NULL)
        head1 = head2;
    else
    {
        temp = head1;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = head2;
    }

    printf("Concatenated list: ");

    temp = head1;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    return 0;
}
