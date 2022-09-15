
===================================================================================================================================================
QUESTION : Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. 
The order of appearance of numbers within each segregation should be same as that in the original list.
===================================================================================================================================================

Input: 
N = 7
Link List:
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

Output: 8 2 4 6 17 15 9

Explaination: 8,2,4,6 are the even numbers 
so they appear first and 17,15,9 are odd 
numbers that appear later.
=--------------------------------------------------------------
Input:
N = 4
Link List:
1 -> 3 -> 5 -> 7

Output: 1 3 5 7

Explaination: There is no even number. 
So ne need for modification.
=--------------------------------------------------------------

<<<-----: Simple Approach for this program is described below :----->>>

## We have to seperate the Even numbers 1st and then all the odd numbers. We also have to maintain the proper order. ##
So,
------>>>>>>>>>
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

1) Declare 2 Pointers temp1(Pointer for our even part) and temp2(Pointer for our odd part).

2) We have to Put even Number 1st. So check that Some even nos are already present in the beginning of the linked-list ?

    while(temp1->next and temp1->next->data %2 == 0)
            temp1 = temp1->next;

3) Store the temp1 inside temp2 [temp2 = temp1];
3) When the loop(STEP 2) terminate, it means a odd value is present at our temp2 point. So check that if (temp2->next) value is even or not.

    --> If even then store (temp2->next) [ --> That newly founded even value] inside a temporary Pointer(h) because we will change it's next. So that value will lost.
    
    --> temp2->next = temp2->next->next;
    
    --> Make temp2(that even value)->next = temp1(last ended even value part of list)->next.
    --> Make temp1->next = h (previously stored temp2->next);
    
    --> As, in temp1 i.e. our even part, 1 new value is added So our new end of even part is (temp1 = temp1->next).
  @ ELSE just move temp2 by 1 step i.e. temp2 = temp2->next;
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



       <<<<<--------------- ## CODE BELOW ## --------------->>>>>
       


class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* dummy = new Node(0);
        dummy->next = head;
        Node *temp1 = dummy,*temp2 =dummy;
        while(temp1->next and temp1->next->data %2 == 0)
            temp1 = temp1->next;
        if(temp1 == NULL)
            return head;
        temp2 = temp1;
        while(temp2->next)
        {
            if((temp2->next->data) % 2 == 0)
            {
                Node *h = temp2->next;
                temp2->next = temp2->next->next;
                h->next = temp1->next;
                temp1->next = h;
                temp1 = temp1->next;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        return dummy->next;
    }
};
