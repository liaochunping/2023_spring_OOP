#include <iostream>
#include <memory>

using namespace std;

struct Node {
    int value;
    shared_ptr<Node> next;
};

int main() {
    int i , j ,k ;
    cin>>i>>j>>k;
    shared_ptr<Node> head = make_shared<Node>(i);
    head->next = make_shared<Node>(j);
    head->next->next = make_shared<Node>(k);
    
    shared_ptr<Node> curr = head;
    while (curr) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
    
    
    return 0;
}
