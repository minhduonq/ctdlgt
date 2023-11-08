#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item
{
    int value;
    int weight;
};

//hàm tính toán thứ tự ưu tiên
bool compare(Item& one, Item& two)
{
    double m = (double)one.value/one.weight;
    double n = (double)two.value/two.weight;
    return m > n;
}

double greedy(int capacity, struct Item items[], int n)
{
    double key = 0;
    sort(items, items+n, compare); // sắp xếp theo thứ tự ưu tiên
    int curCapacity = 0;
    for(int i = 0; i < n; i++) {
        if(curCapacity + items[i].weight <= capacity) { // nếu tổng trọng số cho phép thì lấy vào
            curCapacity += items[i].weight;
            cout << items[i].value << " ";
            key += items[i].value;
        } /*else { // khong su dung doan ma nay vi chi lay nguyen ven.
            int remain = capacity - curCapacity;
            key += items[i].value* (double)remain/items[i].weight; // nếu quá tải thì lấy một phần
            break;
        }*/
    }
    return key;
}

int main()
{
    int capacity = 50;
    Item items[] = {{60,10}, {100,20}, {120,30}};
    int n = sizeof(items)/sizeof(items[0]);
    cout << greedy(capacity, items,n);
}
