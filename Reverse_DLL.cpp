=========================================================================================================
QUESTION : Given a doubly linked list of n elements. The task is to reverse the doubly linked list.
=========================================================================================================

Input:
LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3
----------------------------------------------
Input:
LinkedList: 75 <--> 122 <--> 59 <--> 196
Output: 196 59 122 75
----------------------------------------------
 <<<----: Simple Approach for this program is as follows :---->>> 

1) Declare 2 pointers : i) pre -> To Store previous Node and ii) Cur -> To point current node.
2) Let's Understand Via a Dry Run :
    
    HERE IS OUR LINKED LIST : NULL <-- 75 <--> 122 <--> 59 <--> 196 --> NULL
    
    i) Store the previous of Cur (pre = cur->prev);
        --> Here cur(75)'s previous is NULL. So, NULL is Stored inside pre.
        
    ii) Make cur->prev = cur->next;
        --> Here cur's Next is 122; So it's assigned as cur's previous : 122 <-- 75
        
    iii) Make cur->next = pre;
        --> Here cur's next is 122, So : (122 <-- 75 --> NULL) but (75 <-- 122) is still connected which will erase in 2nd iteration's ii) step.
    
    ## Thus in every iteration, We 1st store the previous.
    
        --> Then We send our cur's next value backward [As our motive is to reverse the list]
        
        Then We cur->next = pre --> Because we assigned the cur's next into cur's previous but cur and cur's next is still connected. We have to break
        the bond by assigning Other data in cur's Next. : 
        
            --> a) In swapping of 1 <--> 2 <--> 3; ===AFTER 1ST ITERATION===>>> 2 <-- 1 --> NULL Connection is done by (cur->prev = cur->next):
            
            --> CUR IS NOW 2; but  2 <--> 3 connection is still present. And 2's previous is still 1 i.e. (1 <-- 2 bond is also present)
            
                b) In second iteration, Store that 1 [cur->prev] in pre;
                
                   --> Cur(2)->next --> (3) is now cur's previous (cur->prev = cur->next) i.e. 3 <-- 2 <--> 1 --> NULL; 
                   --> Make Cur(2)->next = pre(1); i.e. 3 <-- 2 <-->1 --> NULL; NOW CUR IS 3...
                    But 2 <-- 3 bond is still connected.
                    
                c) In 3rd iteration, Store that 2[cur->prev] in pre.
                   --> Make cur->prev = cur->next which is NULL. i.e.==>> : NULL <-- 3 <-- 2 <--> 1 --> NULL
                   --> Make cur(3)->next = pre(2) i.e. NULL <-- 3 <--> 2 <--> 1 --> NULL
                    ### NOW CUR == NULL SO LOOP WILL TERMINATE.
                    
    iv) Here Our previous is 2. So we return pre -> prev which is 3 as our new head.
    
                     
    
    ### CODE BELOW ###
    
  
                     
    
Node* reverseDLL(Node * head)
{
    //Your code here
    if(head == NULL || head->next == NULL) // Base Condition
        return head;
    Node* pre = NULL;
    Node* cur = head;
    while(cur)
    {
        pre = cur->prev;
        cur->prev = cur->next;
        cur->next = pre;
        cur = cur->prev;
        
    }
    return pre->prev;
}
