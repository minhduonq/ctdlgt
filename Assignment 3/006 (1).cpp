struct Node {
    int data;
    Node* link;
};

Initializer:
    Node* top = NULL;

Push(x) {
    Node* temp = new Node;
    temp->data = x;
    temp -> next = top;
    top = temp;
}

Pop():
    if(top==NULL) return;
    else x = top->data;
    top = top ->link;
    return x;

isEmpty():
    return top==NULL;
