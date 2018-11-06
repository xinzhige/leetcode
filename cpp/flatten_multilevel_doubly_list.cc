// Insert the second layer list into the first one to form a new layer and
// then insert the third layer into the new layer and so on.
class Solution {
public:
  Node* flatten(Node* head) {
    for (auto h = head; h != nullptr; h = h->next) {
      if (h->child != nullptr) {
        auto post = h->next;
        auto last = h->child;
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
