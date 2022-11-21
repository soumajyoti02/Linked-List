QUESTION : Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting;


Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.;


Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15
Explanation: After sorting the given
linked list , resultant will be
0->9->15.;


CODE ::::::::::


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    
    Node* sortedMarge(Node* a, Node* b)
    {
        struct Node* result = NULL;
        
        //base cases when either of two halves is null.
        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);
            
        //comparing data in both halves and storing the smaller in result and
        //recursively calling the mergeList function for next node in result.
        if (a->data <= b->data) {
            result = a;
            result->next = sortedMarge(a->next, b);
        } else {
            result = b;
            result->next = sortedMarge(a, b->next);
        }
        //returning the resultant list.
        return (result);
    }
    
    
    
    Node* mergeSort(Node* head) {
        // your code here
        if(head == NULL or head->next == NULL) return head;
        
        Node* slow = head, *fast = head;
        while(fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* b = slow->next;
        slow->next = NULL;
        
        
        Node* left = mergeSort(head);
        Node* right = mergeSort(b);
        
        return sortedMarge(left,right);
    }
};
