#include <iostream>
using namespace std;

#define M 7

struct Item {
    int value;
    int next;
};

struct HashTable {
    Item a[M];
    int r;
};

void Init(HashTable &h) {
    for (int i = 0; i < M; i++) {
        h.a[i].next = -1;
        h.a[i].value = -1;
    }
    h.r = M - 1;
}

int HashFunc(int value) {
    return value % M;
}

void input(HashTable &h, int value) {
    int bucket = HashFunc(value);

    if (h.a[bucket].value == -1) {
        h.a[bucket].value = value;
    } else {
        int current = bucket;

        while (h.a[current].next != -1) {
            current = h.a[current].next;
        }

        int newIndex = h.r;
        h.a[newIndex].value = value;
        h.a[current].next = newIndex;

        for (int i = h.r - 1; i >= 0; i--) {
            if (h.a[i].value == -1) {
                h.r = i;
                break;
            }
        }
    }
}

void display(HashTable h) {
    for (int i = 0; i < M; i++) {
        cout << "\n Bucket: " << i << " Value: " << h.a[i].value << " Next: " << h.a[i].next;
    }
}

void Delete(HashTable &h) {
    // Implement the delete operation here
}

/*bool search(HashTable h,int x) {
    int idx = HashFunc(x);
    if (h.a[idx].value != x) {
        idx = h.a[idx].next;
    } else {
        return 1;
    }
}*/

int main() {
    HashTable h;
    Init(h);

    while (true) {
        int lc;
        int value;
        cin >> lc;

        if (lc == 1) {
            cout << "\nNhap gia tri can them: ";
            cin >> value;
            input(h, value);
        } else if (lc == 2) {
            display(h);
        } else {
            break;
        }
    }

    return 0;
}
