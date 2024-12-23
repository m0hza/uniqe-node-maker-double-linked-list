#include <iostream>
using namespace std;

template <typename T>  // Template class for data type
struct node {
    T data;             // T represents any data type
    node* next;
    node* prev;
    node() { next = prev = nullptr; data = T(); }  // Default constructor
};

template <typename T>  // Template class for Linked List
class linkedlist {
    node<T>* head, * tail;  // Pointer to head and tail
    int counter;

    bool isEmpty() { return head == nullptr; }

    node<T>* nodemaker(T v) {
        node<T>* NewNode = new node<T>();  // Create a new node
        NewNode->data = v;
        NewNode->next = nullptr;
        NewNode->prev = nullptr;
        return NewNode;
    }

    node<T>* find(T value) {
        node<T>* finder = head;
        while (finder != nullptr && finder->data != value)
            finder = finder->next;
        return finder;
    }

public:
    linkedlist() {
        head = tail = nullptr;
        counter = 0;
    }

    void appeand(T d) {
        counter++;
        if (isEmpty()) {
            head = tail = nodemaker(d);
        }
        else {
            node<T>* NewNode = nodemaker(d);
            NewNode->next = head;
            NewNode->prev = nullptr;
            head = NewNode;
        }
    }

    void addtolast(T d) {
        counter++;
        if (isEmpty()) {
            head = tail = nodemaker(d);
        }
        else {
            node<T>* NewNode = nodemaker(d);
            NewNode->prev = tail;
            tail->next = NewNode;
            tail = NewNode;
        }
    }

    void InPlace(T v, int pos) {
        if (pos < 1 || pos > counter + 1) {
            cout << "invalid position" << endl;
            return;
        }
        if (pos == 1) appeand(v);
        else if (pos == counter + 1) addtolast(v);
        else {
            node<T>* NewNode = nodemaker(v);
            node<T>* mover = head;
            for (int i = 1; i < pos - 1 && mover != nullptr; i++) {
                mover = mover->next;
            }
            if (mover == nullptr) {
                cout << "invalid position" << endl;
            }
            else {
                NewNode->next = mover->next;
                NewNode->prev = mover;
                if (mover->next != nullptr) mover->next->prev = NewNode;
                mover->next = NewNode;
                counter++;
            }
        }
    }

    void deletebydata(T data) {
        node<T>* ToBeDeleted = find(data);
        if (ToBeDeleted == nullptr) return;

        if (ToBeDeleted == tail) {
            tail = tail->prev;
        }
        else if (ToBeDeleted == head) {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
        }
        else {
            ToBeDeleted->next->prev = ToBeDeleted->prev;
            ToBeDeleted->prev->next = ToBeDeleted->next;
        }
        delete ToBeDeleted;
        counter--;
    }

    void deletebypos(int pos) {
        if (pos < 1 || pos > counter) return;
        node<T>* ToBeDeleted;
        if (pos == 1) {
            ToBeDeleted = head;
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
        }
        else {
            node<T>* mover = head;
            for (int i = 1; i < pos - 1 && mover != nullptr; i++) {
                mover = mover->next;
            }
            if (mover == nullptr || mover->next == nullptr) return;
            ToBeDeleted = mover->next;
            mover->next = mover->next->next;
            if (mover->next != nullptr) mover->next->prev = mover;
        }
        delete ToBeDeleted;
        counter--;
    }

    void destroy() {
        while (head != nullptr) {
            node<T>* ToBeDeleted = head;
            head = head->next;
            delete ToBeDeleted;
        }
        tail = nullptr;
    }

    void print() {
        node<T>* printer = head;
        while (printer != nullptr) {
            cout << printer->data << " ";
            printer = printer->next;
        }
        cout << endl;
    }

    void evensum() {
        node<T>* summer = head;
        T sum = T(); // Initializing sum to default value of T
        while (summer != nullptr) {
            if (summer->data % 2 == 0) {
                sum += summer->data;
            }
            summer = summer->next;
        }
        cout << "sum is " << sum << endl;
    }

    void deleteMin() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }
        node<T>* mover = head;
        node<T>* minNode = head;
        while (mover != nullptr) {
            if (mover->data < minNode->data) {
                minNode = mover;
            }
            mover = mover->next;
        }
        if (minNode == head) {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
        }
        else if (minNode == tail) {
            tail = tail->prev;
            if (tail != nullptr) tail->next = nullptr;
        }
        else {
            minNode->prev->next = minNode->next;
            minNode->next->prev = minNode->prev;
        }
        delete minNode;
        counter--;
    }
};

int main() {
    linkedlist<int> list;  // Use the template with int data type

    cout << "how many nodes u wanna add?" << endl;
    int nodes;
    cin >> nodes;

    for (int i = 0; i < nodes; i++) {
        cout << "-----------------------------------------" << endl;
        cout << "enter the data of the node " << i + 1 << ":";
        int v;
        cin >> v;
        list.addtolast(v);
    }
    list.print();

    return 0;
}
