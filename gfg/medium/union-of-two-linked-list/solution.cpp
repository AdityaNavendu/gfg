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