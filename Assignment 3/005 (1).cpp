// Khai bao Stack
stack a = empty array
int top = -1;

Push( x) {
    if(top == length(stack) -1) stackIsFull
    else top++;
    stack[top] = x;
}
//O(1)

Pop() {
    if(top ==-1) return;
    y = stack[top]
    top--;
    return y;
}
//O(1)

IsEmpty():
    return (top==-1);
//O(1)
