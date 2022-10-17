QUESTION : You are given the head of a Linked List. You have to move the last element to the front of the Linked List and return the list.;

-----------------------------------------------------------------
Input:
N = 5
List = {2,5,6,2,1}
Output:
{1,2,5,6,2}
Explanation:
In the given linked list, the last element is 1,
after moving the last element to the front the
linked list will be {1,2,5,6,2}.;

--------------------------------------------------------
Input:
N = 1
List = {2}
Output:
{2}
Explanation:
Here 2 is the only element so, the linked list
will remain the same.;

---------------------------------------------------------
APPROACH  :
Just traverse the whole list and make the next of the last node to the head. Also Make previous of the last node to NULL;
=============================================================================================================================
  
CODE ::::::

class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        if(!head or !head->next)  return head;
        ListNode *tail = head, *prev = NULL;
        while(tail->next) 
        {
            prev = tail;
            tail = tail->next;
        }
        prev->next = NULL;
        tail->next = head;
        head = tail;
        return head;
    }
};

  
