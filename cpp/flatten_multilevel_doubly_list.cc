// Idea: insert the second layer list into the first one to form a new layer
// and then insert the third layer into the new layer and so on.
// Note: don't forget to let child pointer be null.
class Solution {
public:
  Node* flatten(Node* head) {
    for (Node* h = head; h != nullptr; h = h->next) {
      if (h->child != nullptr) {
        Node* post = h->next;
        Node* last = h->child;
        for (; last->next != nullptr; last = last->next);
        h->next = h->child;
        h->next->prev = h;
        h->child = nullptr;
        last->next = post;
        if (post != nullptr) {
          post->prev = last;
        }
      }
    }
    return head;
  }
};
