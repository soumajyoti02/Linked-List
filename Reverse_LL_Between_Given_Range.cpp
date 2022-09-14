/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
QUESTION : Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
---------------------------------------------------
Input: head = [5], left = 1, right = 1
Output: [5]
-------------------------------------------------------------------------------------------
Main Approach To Solve this Program is as Follows :
--> We have to reverse a certain part of the linked-list. So, 1st find the starting Node and it's Previous Node.
-------------------------------------------------------------------------------------------

<<<---------DRY RUN-------->>>

##### EXAMPLE: head = [1,2,3,4,5], left = 2, right = 4
--> Here Prev = 1, Tail [Starting node] = 2;
                
 Initially make a dummy node and set it's value NULL, set that dummy node->next to head;
 This dummy node is our prev because we want to start prev from before of head.
    
--> If our starting Node is 2 and previous is 1 then :
a) Fix the previous elememt by storing it into Node* prev BY A LOOP TILL i = = to (left - 1)
        
##START A LOOP FOR i = 0 to (right - left) bcz, that;s the range of reversing.
        
b) Store the next of previous(1) i.e. 2 inside temp; because after prev(1), new reversed Node(3) is added, so it will lost.
        
c) Reverse of 2 and 3 becomes 3, 2. --> JUST FOR UNDERSTANDING
        
d) Add that 3 (tail(2)->next) after previous(1) by prev->next = tail->next(3);
        
e) Because we shifted our tail(2)'s next, so SET tail(2)->next by tail->next->next(4) 
        
   --->Because previously it was 1 2 3 4 5
    We have to make 1 3 2 4 5
                  
f) Make prev(1)->next(3)->next = 2 --> this 2 is stored inside TEMP in 1st step;

*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev, *temp = NULL, *tail = NULL;
        if(head == NULL or left - right == 0)
            return head;
        ListNode dummy(NULL);
        prev = &dummy;
        dummy.next = head;
        for(int i = 0; i < left - 1; i++)
        {
            prev = prev->next;
        }
        tail = prev->next;
        for(int i = 0; i < (right - left); i++)
        {
            temp = prev->next;
            prev->next = tail->next;
            tail->next = tail->next->next;
            prev->next->next = temp;
        }
        return dummy.next;
    }
};
