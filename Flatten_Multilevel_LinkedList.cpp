====================================================================================================================================================
QUESTION : Given a linked list where in addition to the next pointer, each node has a child pointer, which may or may not point to a separate list.
These child lists may have one or more children of their own, and so on, to produce a multilevel data structure
====================================================================================================================================================

-->You are given the head of the first level of the list.
-->Flatten the list so that all the nodes appear in a single-level linked list. 
-->You need to flatten the list in way that all nodes at the first level should come first, then nodes of second level, and so on.
------------------------------------------------------------
IMAGE FOR UNDERSTAND MORE CLEARLY (Copy and paste it in Browser) : https://media.geeksforgeeks.org/wp-content/cdn-uploads/flattenList.png   
------------------------------------------------------------
<<<-----: Simple Approach To Solve this Program :----->>>

1) Take "cur" pointer, which will point to head of the first level of the list
2) Take "tail" pointer, which will point to end of the first level of the list
3) Repeat the below procedure while "curr" is not NULL.
    I) if current node has a child then
    a) append this new child list to the "tail"
        tail->next = cur->child
    b) find the last node of new child list and update "tail"
        tmp = cur->child;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tail = tmp;
    II) move to the next node. i.e. cur = cur->next


##### CODE BELOW #####



// C++ Program to flatten list with next and child pointers
#include <bits/stdc++.h>
using namespace std;

/* The main function that flattens a multilevel linked list */
void flattenList(Node *head)
{
	/*Base case*/
	if (head == NULL)
	return;

	Node *tmp;

	/* Find tail node of first level linked list */
	Node *tail = head;
	while (tail->next != NULL)
		tail = tail->next;

	// One by one traverse through all nodes of first level
	// linked list till we reach the tail node
	Node *cur = head;
	while (cur != tail)
	{
		// If current node has a child
		if (cur->child)
		{
			// then append the child at the end of current list
			tail->next = cur->child;

			// and update the tail to new last node
			tmp = cur->child;
			while (tmp->next)
				tmp = tmp->next;
			tail = tmp;
		}

		// Change current node
		cur = cur->next;
	}
}
