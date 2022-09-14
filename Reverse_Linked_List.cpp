/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
QUESTION : Given a linked list of N nodes. The task is to reverse this list.
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Input:
LinkedList: 1->2->3->4->5->6
Output: 6 5 4 3 2 1
Explanation: After reversing the list, 
elements are 6->5->4->3->2->1.
--------------------------------
Input:
LinkedList: 2->7->8->9->10
Output: 10 9 8 7 2
Explanation: After reversing the list,
elements are 10->9->8->7->2.
---------------------------------
Main Approach To Solve This Program is as Follows :------>>>>>>>>>>>

1. Take 3 pointers --> previous = NULL; Current = head; Next = NULL;

2. Start a Loop while (Current != NULL)

 2.1) Store current's next into Next pointer;
 2.2) current's Next = Previous --> Reversing
 2.3) Make Previous = current'
 2.4) Shift Current in front by current = Next;
    
3. As finally current will becomes NULL; So return prev; It's Our new head node.
*/
class Solution
{
    public:
    //Function to reverse a linked list.
    
    struct Node* reverseList(struct Node *head)
    {
        
        if(head==NULL)
            return NULL;
        
        //taking three pointers to store the current, previous and next nodes.
        struct Node *prev = NULL;   
        struct Node *current = head;
        struct Node *next= current->next;
        
        while(current!=NULL)
        {
            //taking the next node as next.
            next=current->next;
            
            //storing the previous node in link part of current node.
            current->next=prev; 
            
            //updating prev from previous node to current node.
            prev=current; 
            
            //updating current node to next node.
            current =next;        
        }
        
        return prev;
    }
    
};
