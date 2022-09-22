==================================================================================================================================
QUESTION : Given a Linked list, rearrange it such that converted list should be of the form a < b > c < d > e < f .. 
where a, b, c are consecutive data node of linked list and such that the order of linked list is sustained.

For example: In 11 15 20 5 10 we consider only 11 20 5 15 10 because it satisfies the above condition and the order of linked list.
5 20 11 15 10 is not considered as it does not follow the order of linked list.

To maintain the order, keep swapping the adjacent nodes of the linked list (whenever required) to get the desired output. 
==================================================================================================================================

Input:
LinkedList: 1->2->3->4 
Output: 1 3 2 4 
--------------------------------------------------

Input: 
LinkedList: 11->15->20->5->10 
Output: 11 20 5 15 10 
Explanation: In the given linked list,
after arranging them as 11 < 20 > 5
< 15 > 10 in the pattern as asked above.
--------------------------------------------------

Simple Approach for this program is as Follows : 

## In every odd round, check if cur < cur->next or not.
## In every even round, check if cur > cur->next or not.
## Declare a variable to identify which type of round i.e. iteration is running currently.

1) Declare a pointer called CUR and store head inside it. Because We don't want to lose our head pointer (We have to return it in the end)

2) Declare a bool type variable check. Let's understand it's importance :

 We have to arrange our linked-list this way: a < b > c < d > e < f
    
 ## So in 1st round (every odd round i.e. 1 3 5 7 ...), we have to check that if a < b or not.
   If not then swap the values to make a < b;
        
 ## Then We have to check in 2nd round (every even round i.e. 2 4 6 ...) that if b > c or not.
   If not then swap the values to make a > b;
    
 ## So we need a check or flag type variable which will helps us to identify which case is currently running.
    
 --> If check is true then it's 1st,3rd,5th,... case; So check CUR < CUR->NEXT or not. If not then swap them.
 --> Then make check = ! check -->>> It Will reverse the check. i.e. if check is false it will convert it into true and vice versa.
   
 --> If check is false then it's one of 2nd,4th,6th,... case; so So check CUR > CUR->NEXT or not. If not then swap them.
    
3) Finally return head.'
    


 ### CODE BELOW ###


class Solution
{
    public:
    Node *zigZag(Node* head)
    {
     // your code goes here
     Node *cur = head;
     bool check = true; 
     while(cur->next)
     {
         if(check) 
         {
             if(cur->data > cur->next->data)
             {
                 swap(cur->data,cur->next->data);
             }
         }
         else
         {
             if(cur->data < cur->next->data)
             {
                 swap(cur->data,cur->next->data);
             }
         }
         cur = cur->next;
         check = !check;
     }
     return head;
    }
};
