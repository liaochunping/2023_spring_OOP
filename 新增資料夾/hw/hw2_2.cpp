#include <vector>
#include <iostream>

using namespace std;

struct Node {
    int value;
    Node * next;
};

Node * solution(std::vector<int> vec)
{

  Node * head = nullptr;

  // ----------------------
  // Please fill this blank

    for(int i = 0; i < vec.size(); i++) {
        Node * current = new Node;
        current -> value = vec[i];
        current -> next = nullptr;
        
        if(head == nullptr) {
            head = current;
        }
        else {
            Node * p = head;
            while(p -> next != nullptr) {
                p = p -> next;
            }
            p -> next = current;
        }
    }
  
  // ----------------------

  return head;
}

Node *deleteNode(Node * head, int deleteNum)
{
	// ----------------------
    // Please fill this blank

    Node * current = head;
    
    while(head->value == deleteNum) {
        head = head->next;
    }
    
    while(current->next != nullptr) {
        if(current->next->value == deleteNum) {
            current->next = current->next->next; // 接到下下個點
        }
        else {
            current = current->next; // 跳到下一個點   
        }
    }

    return head;

    // ----------------------
}

int main()
{
    int num;
    std::vector<int> vec;
    while (std::cin >> num)
    {
        vec.push_back(num);
    }

    Node * head = solution(vec);
    head = deleteNode(head, 3);

    while (head != nullptr)
    {
        std::cout << head->value;
        if (head->next != nullptr)
        {
            std::cout << "->";
        }
        head = head->next;
    }

    return 0;
}

