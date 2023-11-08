#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    void insertBack(int x) {
        Node* newNode = new Node(x);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int count_triplets() {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return 0;
        }

        int count = 0;
        Node* current = head->next;

        while (current->next != nullptr) {
            int sum = current->data + current->prev->data + current->next->data;
            if (sum == 0) {
                count++;
            }
            current = current->next;
        }

        return count;
    }
};

int main() {
    int n;
    cin >> n;

    DoublyLinkedList doublyLinkedList;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        doublyLinkedList.insertBack(num);
    }

    int result = doublyLinkedList.count_triplets();
    cout << result << endl;

    return 0;
}

