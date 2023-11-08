#include<iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    int a[x];
    for(int i = 0; i < x; i++) {
        cin >> a[i];
    }
    int count = 0;
    for(int i = 0; i < x; i++) {
        for(int j = i+1; j < x; j++) {
            if(a[i] == a[j]) {
                count++;
            }
        }
    }
    cout << count;
}
