/*
===================================================================================================================
QUESTION :
--------
Given a linked list of N nodes such that it may contain a loop.
A loop here means that the last node of the link list is connected to the node at position X(1-based index). 
If the link list does not have any loop, X=0.
Remove the loop from the linked list, if it is present,
i.e. unlink the last node which is forming the loop.
====================================================================================================================

Input:
N = 3
value[] = {1,3,4}
X = 2
Output: 1
Explanation: The link list looks like
1 -> 3 -> 4
     ^    |
     |____|    
A loop is present. If you remove it 
successfully, the answer will be 1. 
------------------------------------------

Input:
N = 4
value[] = {1,8,3,4}
X = 0
Output: 1
Explanation: The Linked list does not 
contains any loop. 
------------------------------------------

Input:
N = 4
value[] = {1,2,3,4}
X = 1
Output: 1
Explanation: The link list looks like 
1 -> 2 -> 3 -> 4
     |_________|
A loop is present. 
If you remove it successfully, 
the answer will be 1. 
------------------------------------------

<<<---: Main Approach For Solving this Problem, is as Follows :--->>>

1.) We Will use rabbit-tortoise approach i.e. 2 pointers approach one is slow(moving by single step) and other is fast (moving by 2 steps).

2.) We Will start this Two pointers from head. If the fast pointer reaches NULL that means no Loop is present.
3.) If loop is present then this two pointers will meet one day. At that time we break the loop.

4.) After that if Slow == Fast ?  means we will check if the loop ends by meeting them or reaching of fast pointer to NULL.
5.) If this true then, We will move the slow pointer at head (slow = head);

6.) We Will again start a loop and this time BOTH SLOW AND FAST POINTERS WILL MOVE BY A SINGLE STEP.

 6.1) We will check that after moving slow to head, slow == fast ? i.e. is the loop starts from head ? :
 6.2) If it's true then move the fast pointer WHILE (fast->next != slow). 
     Then assign fast->next = NULL. This will break the loop. return the function.
     
 6.3) ELSE : START MOVING SLOW AND FAST BY SINGLE STEP TILL fast->next == slow->next
      --> Then assign fast->next = NULL.


structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        if(head == NULL or head->next == NULL)
            return;
        Node* slow = head, *fast = head;
        // Move both pointers a step forward to start while loop. Else in first iteration, loop will breaks.
        slow = slow->next;
        fast = fast->next->next;
        while(fast!= NULL and fast->next != NULL)
        {
            if(slow == fast)
                break;
            slow = slow->next;
            fast = fast->next->next;
        }
        // From Now, Increse fast pointer by 1.
        if(slow == fast)
        {
            slow = head;
            if(slow == fast) // Checking if the loop Starts from head Node ?
            {
                while(fast->next != slow)
                    fast = fast->next; 
                fast->next = NULL;
            }
            else
            {
                while(slow->next != fast->next)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                fast->next = NULL;
            }
        }
    }
};
