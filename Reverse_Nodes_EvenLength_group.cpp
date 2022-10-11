QUESTION : You are given the head of a linked list.

The nodes in the linked list are sequentially assigned to non-empty groups whose lengths form the sequence of the natural numbers (1, 2, 3, 4, ...);
The length of a group is the number of nodes assigned to it. In other words,

The 1st node is assigned to the first group.
The 2nd and the 3rd nodes are assigned to the second group.
The 4th, 5th, and 6th nodes are assigned to the third group, and so on.
Note that the length of the last group may be less than or equal to 1 + the length of the second to last group.

Reverse the nodes in each group with an even length, and return the head of the modified linked list;


============================================================================================================================
  
  
Input: head = [5,2,6,3,9,1,7,3,8,4]
Output: [5,6,2,3,9,1,4,8,3,7]
Explanation:
- The length of the first group is 1, which is odd, hence no reversal occurs.
- The length of the second group is 2, which is even, hence the nodes are reversed.
- The length of the third group is 3, which is odd, hence no reversal occurs.
- The length of the last group is 4, which is even, hence the nodes are reversed.;


Input: head = [1,1,0,6]
Output: [1,0,1,6]
Explanation:
- The length of the first group is 1. No reversal occurs.
- The length of the second group is 2. The nodes are reversed.
- The length of the last group is 1. No reversal occurs.;


Input: head = [1,1,0,6,5]
Output: [1,0,1,5,6]
Explanation:
- The length of the first group is 1. No reversal occurs.
- The length of the second group is 2. The nodes are reversed.
- The length of the last group is 2. The nodes are reversed.;



APPROACH : 


--> I traverse the list in groups where the sizes are in the increasing order of natural numbers.
--> Whenever a group with even length is encountered, that group is reversed using the reverse function and I proceed with processing the next group.
--> The solution involves several pointers which track the current group’s head, tail and the next group’s head.;


CODE :::::::::::::

class Solution {
public:
    
    // Function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode* prev = NULL;
        while(head) {
            ListNode* temp = head -> next;
            head -> next = prev;
            prev = head;
            head = temp;
        }
        
        return prev;
    }
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        // Creating a dummy node to avoid adding checks for the first node
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        
        ListNode* prev = dummy;
        
        // Loop to determine the lengths of groups
        for(int len = 1; len < 1e5 && head; len++) {
            ListNode* tail = head;
            ListNode* nextHead;
            
            // Determining the length of the current group
            // Its maximum length can be equal to len
            int j = 1;
            while(j < len && tail && tail -> next) {
                tail = tail -> next;
                j++;
            }
            
            // Head of the next group
            nextHead = tail -> next;
            
            if((j % 2) == 0) {
                // If even sized group is found
                // Reversing the group and setting prev and head appropriately
                tail -> next = NULL;
                prev -> next = reverseList(head);
                prev = head;
                head -> next = nextHead;
                head = nextHead;
            } else {
                // If group is odd sized, then simply going towards the next group
                prev = tail;
                head = nextHead;
            }
        }
        
        // Returning the head
        return dummy -> next;
    }
};


