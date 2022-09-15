======================================================================================================================
QUESTION : Given a singly linked list, remove all the nodes which have a greater value on their right side.
======================================================================================================================

Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on the following nodes. So, after deleting
them, the linked list would like be 15,
11, 6, 3.
=---------------------------------------------------------------------------
Input:
LinkedList = 10->20->30->40->50->60
Output: 60
=---------------------------------------------------------------------------

<<<-----: Main Approach for solve this program is below :----->>>

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
## 1. Reverse list
## 2. Remove nodes which have bigger value on the left.

## 3. To do this, simply iterate from left to right, and store the max value seen.
      Keep comparing all nodes to the stored max value.
      
## 4. In the end reverse the list again.
  
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

ALGORITHM : 

1) Reverse the Linked-List because we have to traverse it from right to left.
2) Start traversing. Declare a maxNode variable to store Temporary maximum value.
3) Check that current->next value is greater or equal to maxNode or not.
  
 --> If not then delete that current->next by connecting current->next = current->next->next.
 --> Else Move that current node by one step and make the current our new maxNode.
    
4) Finally reverse again by head.
5) Return head.




    <<<<<----- ## CODE BELOW ## ----->>>>>



class Solution
{
    public:
    Node* reverse(Node *head)
    {
        Node* cur = head;
        Node* next = NULL;
        Node* prev = NULL;
        while(cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    
    Node *compute(Node *head)
    {
        head = reverse(head);
        Node* maxNode = head;
        Node* cur = head;
        while(cur and cur->next)
        {
            if(cur->next->data < maxNode->data)
            {
                Node* temp = cur->next;
                cur->next = temp->next;
                free(temp);
            }
            else
            {
                cur = cur->next;
                maxNode = cur;
            }
        }
        head = reverse(head);
        return head;
    }
    
};
   
