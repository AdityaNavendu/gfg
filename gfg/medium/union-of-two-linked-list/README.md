# Union of Two Linked Lists

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given two singly linked lists, create a new linked list that contains the union of elements present in both lists. Each element should appear only once in the resulting list (no duplicates allowed).
The order of elements in the resulting list should be:

- First, include elements from the first list in the order they appear.
- Then include elements from the second list that were not already included, in their original order.

 **Examples:** 

```
Input: head1 = [9, 6, 4, 2, 3, 8], head2 = [1, 2, 8, 6, 2]

Output: 9 -> 6 -> 4 -> 3 -> 8 -> 1 -> 2

Explanation: All the distinct numbers from two lists. 
```

```
Input: head1 = [1, 5, 1, 2, 2, 5], head2 = [4, 5, 6, 7, 1]
 
Output: 1 -> 5 -> 2 -> 4 -> 6 -> 7

Explanation: All the distinct numbers from two lists.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-26T02:09:21.449Z  

```cpp
class Solution {
  public:
    Node* makeUnion(Node* head1, Node* head2) {
        unordered_set<int> p;

        Node* head = nullptr;
        Node* tail = nullptr;

        Node* t = head1;

        while(t) {
            if(p.find(t->data) == p.end()) {
                p.insert(t->data);

                Node* temp = new Node(t->data);

                if(head == nullptr) {
                    head = temp;
                    tail = temp;
                }
                else {
                    tail->next = temp;
                    tail = temp;
                }
            }
            t = t->next;
        }

        t = head2;

        while(t) {
            if(p.find(t->data) == p.end()) {
                p.insert(t->data);

                Node* temp = new Node(t->data);

                if(head == nullptr) {
                    head = temp;
                    tail = temp;
                }
                else {
                    tail->next = temp;
                    tail = temp;
                }
            }
            t = t->next;
        }

        return head;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/union-of-two-linked-list/1)