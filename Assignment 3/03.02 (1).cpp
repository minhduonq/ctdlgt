
//Khai bao:
queue = emptyArray;
front = 0;
rear = -1;
Enqueue(x):
    if(rear = length(queue) - 1) return;
    else rear++
        queue[rear] = x;
// O(1)

Dequeue():
    if(front>rear): return; //empty
    else:
    x = rear[front];
    front++;
    return x;
// O(1)
Front():
    if (front > rear) return; //empty
    else:
            return queue[front];
// O(1)
IsEmpty():
    return (front>rear);
// O(1)
Size():
    return (rear - front + 1);
// O(1)
