/*
============================================================================================================
QUESTION : You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes.

The task is to delete the node. Pointer/ reference to head node is not given. 
Note: No head reference is given to you.

It is guaranteed that the node to be deleted is not a tail node in the linked list.
============================================================================================================
Input:
N = 2
value[] = {1,2}
node = 1
Output: 2
Explanation: After deleting 1 from the linked list, we have remaining nodes as 2.
---------------------------------------
Input:
N = 4
value[] = {10,20,4,30}
node = 20
Output: 10 4 30
Explanation: After deleting 20 from the linked list, we have remaining nodes as 10, 4 and 30.
----------------------------------------

<<<<<<<-----Main Approach for solving this program is as follows ----->>>>>>>>>>

If our Linked List is :- [1 2 3 4 5 6] and we have Node 3 which have to be deleted.

---> Store next of 3 (EX : Given Node) i.e. 4 in a variable called temp;
---> Make : Given Node's data = temp's data; i.e. [1 2 4(3) 4 5 6];
---> Then Make given Node's Next = temp's next i.e. connect 4(3) and 5  /-->To avoid repetative element.
---> Then free or delete temp i.e. 4;
*/

class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
        //storing the node next to given node in a pointer.	
    	Node* temp = del->next;
    	
    	//copying the data of pointer in the given current node.
    	del->data = temp->data;
    	
    	//storing the next node to pointer in link part of current node.
    	del->next = temp->next;

    	// freeing memory.
    	free(temp);
    	
    }
};
