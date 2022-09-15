/*
======================================================================================
QUESTION : Given two singly linked lists of size N and M, 
write a program to get the point where two linked lists intersect each other.
======================================================================================
Input: 
Linked List 1 = 3->7->4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation: 
l1  l2

3
|
7   5
|   |
4   6
|   |
1   1
 \  /      
  8    
  |
  4
  |
  5
  |
 NULL     
  

Main Approach For Solving This Program is as Follows :

1) Determine the Length of both linked List.
2) Move the big linked-list's Head such that both heads will come at a equilibrium level, let's understand this first :
   
  -->In the above diagram, list1 is bigger. So Move the head of list1 to 7. It's the eqilibrium point i.e. from here, both list's size is same.
    
Do this by checking:
 i) While n1 (length of list1) > n2 (length of list2) ?
  --> head1 = head->next; n1--; 
 ii) While n2 (length of list2) > n1 (length of list1) ?
  --> head2 = head2->next;
  --> Here n1 = 7, and n2 = 6. So n1 > n2 and the difference is 1 (7 - 6); 
    
   So We have to move head1 by 1 step to make both list's height equal. Same thing had been done above.
   --> In 1st iteration, head1 becomes 7 and n1 becomes 1 - 1 = 0 [i.e Condition False], So loop terminates.
   Now, l1 = 6 and l2 = 6;

3) Now Move both head simultaneously by a while loop till they becomes equal i.e.-->
 i) head1 becomes 4 and head2 becomes 6;
 ii) head1 becomes 1 and head2 becomes 1;
 iii) head1 and head2 both becomes 8 and the loop condition breaks.
    
4) Return the value of head1 or head2 beacuse both are same now.

*/

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    int n1=0, n2=0;
    Node* temp = head1;
    
    //finding length of list1.
    while(temp != NULL)
    {
        n1++;
        temp = temp->next;
    }
    temp = head2; // temp will be used for head2 also.
    while(temp != NULL)
    {
        n2++;
        temp = temp->next;
    }
    //if list1 is longer, we ignore some of its starting
    //elements till it has as many elements as list2.
    while(n1 > n2)
    {
        head1 = head1->next;
        n1--;
    }
        
    //similarly, if list2 is longer, we ignore some of its starting
    //elements till it has as many elements as list1.
    while(n2 > n1)
    {
        head2 = head2->next;
        n2--;
    }
        
    //now we simply traverse ahead till we get the intersection point, if there 
    //is none, this loop will break when both pointers point at NULL.
    while(head1 != head2)
    {
        head1 = head1->next;
        head2 = head2->next;
    }
    
    // if head1 is not NULL, we return its data otherwise we return -1.
    if(head1 != NULL) 
        return head1->data;
    else
        return -1;

}
