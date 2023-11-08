
struct Node:
    int value;
    Node* next;

Initializer:
    front = null;
    rear = null;

Enqueue(x):
    newNode = new Node(x)
    if front == null:
        front = newNode;
        rear = newNode;
    else:
        rear.next = newNode;
        rear = newNode;
        //O(1)
Dequeue():
    if front == null return //empty
    else:
        x = front->value
        front = front->next
        if front == null:
            rear = null
        return x
        //O(1)

Front():
    if front == null return //empty
    else:
        return front->value
//O(1)
IsEmpty():
    return (front == null)
    //O(1)
