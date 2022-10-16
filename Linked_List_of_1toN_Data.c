#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
void display(node *head)
{
    for (; head != NULL; printf("%d\t", head->data), head = head->next);
}
node *push(node *head, int n)
{
    for (int i = 1; i <= n; i++)
    {
        node *ptr = (node *)malloc(sizeof(node));
        ptr->data = i;
        ptr->next = NULL;
        if (head == NULL)
            head = ptr;
        else
        {
            ptr->next = head;
            head = ptr;
        }
    }
    return head;
}
int main()
{
    node *head = (node *)malloc(sizeof(node));
    head = NULL;
    int n;
    printf("Enter the Upper Limit: ");
    scanf("%d", &n);
    head = push(head, n);
    display(head);
}
