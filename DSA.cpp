#include <iostream>
using namespace std;

// 1. Linked List (Singly)
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at the end of the list
    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Print the list
    void print() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// 2. Stack using Linked List
class Stack {
private:
    LinkedList list;

public:
    // Push operation
    void push(int val) {
        list.insert(val);
    }

    // Pop operation
    void pop() {
        if (list.head == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = list.head;
        list.head = list.head->next;
        delete temp;
    }

    // Print stack
    void print() {
        list.print();
    }
};

// 3. Queue using Linked List
class Queue {
private:
    LinkedList list;

public:
    // Enqueue operation
    void enqueue(int val) {
        list.insert(val);
    }

    // Dequeue operation
    void dequeue() {
        if (list.head == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = list.head;
        list.head = list.head->next;
        delete temp;
    }

    // Print queue
    void print() {
        list.print();
    }
};

// 4. Sorting Algorithms

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Merge Sort helper function
void merge(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge(arr, left, mid);
        merge(arr, mid + 1, right);
        // Merge the two halves
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int L[n1], R[n2];
        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int n) {
    merge(arr, 0, n - 1);
}

// 5. Searching Algorithms

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    // Testing Linked List
    LinkedList ll;
    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.print();

    // Testing Stack
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    cout << "Stack contents: ";
    s.print();
    s.pop();
    cout << "Stack after pop: ";
    s.print();

    // Testing Queue
    Queue q;
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    cout << "Queue contents: ";
    q.print();
    q.dequeue();
    cout << "Queue after dequeue: ";
    q.print();

    // Testing Sorting and Searching
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nArray before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, n);
    cout << "Array after Bubble Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(arr2, n);
    cout << "Array after Merge Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    int key = 43;
    int result = binarySearch(arr2, 0, n - 1, key);
    if (result != -1)
        cout << "Element " << key << " found at index " << result << endl;
    else
        cout << "Element " << key << " not found." << endl;

    return 0;
}
