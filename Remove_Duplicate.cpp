=========================================================================================================
QUESTION : Given a singly linked list consisting of N nodes. 
The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
=========================================================================================================

Input:
LinkedList: 2->2->4->5
Output: 2 4 5
Explanation: In the given linked list 
2 ->2 -> 4-> 5, only 2 occurs more 
than 1 time.
------------------------------------------------------
Input:
LinkedList: 2->2->2->2->2
Output: 2
Explanation: In the given linked list 
2 ->2 ->2 ->2 ->2, 2 is the only element
and is repeated 5 times.

------------------------------------------------------

Approach for this program is as follows : 

 --> Start a while loop till temp->next != NULL
 
    i) Check If temp->data is equal to its next data ?
        If yes then make tem->next = temp->next->next;
        ELSE forward temp by 1;

-------------------------------------------------------

 ### CODE BELOW ###
 
 
//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 // your code goes here
    Node*temp = head;
    while(temp and temp->next)
    {
        if(temp->data == temp->next->data)
        {
            temp->next = temp->next->next;
        }
        else
            temp = temp->next;
    }
    return head;
 
}
