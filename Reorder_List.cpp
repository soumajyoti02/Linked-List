/*
================================================================================================
QUESTION : You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed. 
===============================================================================================

Input: head = [1,2,3,4]
Output: [1,4,2,3]
-----------------------------------------
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
-----------------------------------------
<<<<<<--: Main Approach for Solving this Program is as Follows :-->>>>>>

Make a Function that Takes The head of a linked-list and returns the reversend linked-list''s head.

INSIDE reOrderList function :

1) Get the length of the linked-list. Store it inside len.
2) Take a Node pointer to that middle Node by :

  --> Starting a loop FOR i = 1 to len/2; cur = cur->next;
    
3) Devide the List into 2 parts :

 i) Beginning to MIddle node. --> in headleft
 ii) Next of middle node to end. --> in headright
    
4) Now assign Cur->next = NULL to Finally seperate that 2 linked list.

5) Pass the headright in reverse function to reverse the 2nd part.

6) NOW THE ACTUAL ARRANGING WILL START :

 a) Declare pleftNext to store left part's next Temporarily
 b) Declare prughtNext to store right part's next Temporarily
    
 c) Now our linked-list looks like this: head = 1->2->3->4 to headleft = 1->2->N and headright = 4->3->N
        We have to make 1->4->2->3
        
 d) START A LOOP TILL HEADLEFT AND HEADRIGHT != NULL :
    
  i) Store Both part's Next into both variable.
  ii) hleft -> next = hright; 1->4
  iii) hright -> next = pleftNext; 1->4->2
  iv) hleft = pleftNext; 1->4->2 (Now 2 is Head);
        
  v) hright = prightNext; Now 3 is hright. In next iteration, it will be added after 2 by STEP (II) --> [hleft -> next = hright]
  
7) Return Head.
            
*/

struct ListNode* reverseList(struct ListNode *head)
{
    if (head==NULL) return NULL;
    struct ListNode *pLast=head, *pCur=head->next, *pNext=NULL;
    head->next=NULL;

    while (pCur!=NULL)
    {
        pNext = pCur->next;
        pCur->next = pLast;

        pLast = pCur;
        pCur = pNext;
    }
    return pLast;
}
 
void reorderList(struct ListNode* head) 
{
    if (head==NULL) return NULL;
    int i,len;
    struct ListNode *pCur=head;

    for(len=0; pCur; len++, pCur=pCur->next); 

    pCur=head;
    for(i=1; i<(len+1)/2 ; i++, pCur=pCur->next); // Moving Cur to Mid Node
    
    struct ListNode *pLeft = head;
    struct ListNode *pRight = pCur->next;
    pCur->next = NULL; // Dividing linked-list into 2 parts.
    pRight = reverseList(pRight);

    struct ListNode *pLeftNext, *pRightNext;
    // Assume Our LInked-LIst is : 1->2->3->4 && We have to make 1->4->2->3 
    while (pLeft && pRight) {
        pLeftNext = pLeft->next; // = 2
        pRightNext = pRight->next; // = 3
        
        pLeft->next = pRight; // 1 -> 4
        pRight->next = pLeftNext; //1 -> 4 -> 2
        
        pLeft = pLeftNext; // = 2
        pRight = pRightNext; // = 3
    }
    
    return head;
}
