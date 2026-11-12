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
    struct Node *head3 = NULL, *tail = NULL;
    int n, i;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data in sorted order: ");
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

        printf("Enter data in sorted order: ");
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

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            newNode = head1;
            head1 = head1->next;
        }
        else
        {
            newNode = head2;
            head2 = head2->next;
        }

        newNode->next = NULL;

        if(head3 == NULL)
        {
            head3 = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if(head1 != NULL)
        tail->next = head1;

    if(head2 != NULL)
        tail->next = head2;

    printf("Merged list: ");

    temp = head3;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    return 0;
}
