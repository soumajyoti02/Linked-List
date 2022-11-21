QUESTION : Sort a linked list ny quick sot method;

Code ::::

node* partition(node* root, node* end)
{
    node* pivot = root, *curr = root->next;
    while(curr)
    {
        // Check the low elements right to the pivot. If found, then swap.
        if(curr->data <= pivot->data) swap(curr->data,pivot->data);
        curr = curr->next;
    }
    return pivot;
}
void quick_sort(node* head, node* end = NULL)
{
    if(!head or !head->next or head == end) return;
    
    node* pivot = partition(head,end);
    
    quick_sort(head,pivot);
    quick_sort(pivot->next,end);
    
}
void quickSort(struct node **headRef) {
    quick_sort(*headRef);
}
