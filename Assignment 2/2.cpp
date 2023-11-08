#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int p, int x) {
        Node* newNode = new Node(x);
        if (p == 0 || head == nullptr) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* curr = head;
            int pos = 1;
            while (pos < p && curr->next != nullptr) {
                curr = curr->next;
                pos++;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }

    void deleteNode(int p) {
        if (head == nullptr) {
            return;
        }
        if (p == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* curr = head;
            int pos = 1;
            while (pos < p && curr->next != nullptr) {
                curr = curr->next;
                pos++;
            }
            if (curr->next == nullptr) {
                return; // Position not found
            }
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
    }

    void printList() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    LinkedList linkedList;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "insert") {
            int p, x;
            cin >> p >> x;
            linkedList.insert(p, x);
        } else if (operation == "delete") {
            int p;
            cin >> p;
            linkedList.deleteNode(p);
        }
    }

    linkedList.printList();

    return 0;
}

