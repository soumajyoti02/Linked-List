/*

QUESTION : Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List.
When a value appears in multiple nodes, the node which appeared first should be kept, 
all others duplicates are to be removed.

Input:
N = 4
value[] = {5,2,2,4}
Output: 5 2 4
Explanation:Given linked list elements are
5->2->2->4, in which 2 is repeated only.
So, we will delete the extra repeated
elements 2 from the linked list and the
resultant linked list will contain 5->2->4

Input:
N = 5
value[] = {2,2,2,2,2}
Output: 2
Explanation:Given linked list elements are
2->2->2->2->2, in which 2 is repeated. So,
we will delete the extra repeated elements
2 from the linked list and the resultant
linked list will contain only 2.

Main Approach To solve this program is as follows :

## value[] = {5,2,2,4}
      Output: 5 2   4
     
1) Make an unordered set because in set, every value is present only 1 time.
2) Take 2 pointers, 
    i) Curr --> To travarse the linked-list
    ii) prev --> When a duplicate Node is found, we link prev to curr->next; thus, curr will be eliminated from list.
3) Start a loop while cur != NULL :
    3.1) Check if set.find(cur->data) == set.end() or not. --> If it set.end() then value is not present in set. Otherwise that value is already present.
    3.2) If set.find() != set.end() then link prev to cur->next. Then delete cur;

    3.3) ELSE set.insert(cur->data) i.e. that value is not present. So insert that value in set. and make prev = curr to Move previous by step 1;
4) Move curr step 1 by curr = prev->next;

*/
class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    { 
        //using set to store already seen values in list. 
        unordered_set<int> seen; 
      
        //using two pointers one of which stores first node other null.
        struct Node *curr = head; 
        struct Node *prev = NULL; 
        
        //traversing over the linked list.
        while (curr != NULL) 
        { 
            //if data at current node is already present in set, we skip the 
            //current node and store the node next to current in link of prev. 
            if (seen.find(curr->data) != seen.end()) 
            { 
               prev->next = curr->next;
               //deleting current node which contains duplicates. 
               delete (curr);             
            }
            
            //else we just insert the data at current node in set and update 
            //prev to the current node.
            else
            { 
               seen.insert(curr->data);
               prev = curr; 
            }
            //updating current to the next node of prev node.
            curr = prev->next; 
        } 
        return head;
    }
    
};
