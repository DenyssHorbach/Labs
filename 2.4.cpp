#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
#include <ctime>
using namespace std;

struct StackReal
{
    vector<double> data;
    int top_index = -1;
    const int capacity = 10;
};

bool isFull(const StackReal& s) {
    return s.top_index >= s.capacity - 1;
}

bool isEmpty(const StackReal& s) {
    return s.top_index == -1;
}

void Push(StackReal& s, double value) {
    if (isFull(s)) {
        cout << "Error: Stack is full. Element " << fixed << setprecision(2) << value << " not added." << endl;
        return;
    }

    s.top_index++;

    if (s.data.size() < s.capacity) {
        s.data.resize(s.capacity);
    }

    s.data[s.top_index] = value;
}

bool Pop(StackReal& s, double& value) {
    if (isEmpty(s)) {
        cout << "Error: Stack is empty. Impossible to do Pop." << endl;
        return false;
    }

    value = s.data[s.top_index];
    s.top_index--;

    return true;
}

void main() {
    srand(time(0));
    default_random_engine generator(time(0));
    uniform_real_distribution<double> real_dist(1.0, 99.99);

    const int N = (rand() % 10);
    const int M = (rand() % 16);

    StackReal MyStack;

    cout << "--- Task 4.1: Stack (Vector, Real data type) ---" << endl;
    cout << "Maximum stack size (capacity): " << MyStack.capacity << endl;
    cout << "Number of elements to add (N): **" << N << "**" << endl;
    cout << "Number of elements to remove (M): **" << M << "**" << endl;
    cout << "----------------------------------------------------" << endl;

    const int SIZE = 10;
    double arr[SIZE];

    cout << "Initialized array arr[10]: [ ";
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = real_dist(generator);
        cout << fixed << setprecision(2) << arr[i] << (i < SIZE - 1 ? ", " : "");
    }
    cout << " ]" << endl;
    cout << "----------------------------------------------------" << endl;

    cout << "4. Pushing N=" << N << " elements to the stack (Push):" << endl;

    for (int i = 0; i < N && i < SIZE; i++) {
        cout << "  Push: " << fixed << setprecision(2) << arr[i];
        Push(MyStack, arr[i]);
        cout << (MyStack.top_index != -1 && MyStack.data[MyStack.top_index] == arr[i] ? " -> OK" : " -> Fail") << endl;
    }
    cout << "Current stack size: " << MyStack.top_index + 1 << endl;
    cout << "----------------------------------------------------" << endl;

    cout << "5. Popping M=" << M << " elements from the stack (Pop):" << endl;

    double removed_value;
    int successful_pops = 0;

    for (int i = 0; i < M; i++) {
        if (Pop(MyStack, removed_value)) {
            cout << "  Pop: " << fixed << setprecision(2) << removed_value << " -> OK" << endl;
            successful_pops++;
        }
        else {
            break;
        }
    }

    cout << "Successfully removed elements: " << successful_pops << endl;
    cout << "Final stack size: " << MyStack.top_index + 1 << endl;

    cout << "Stack after operations (top index at " << MyStack.top_index << "): [ ";
    for (int i = MyStack.top_index; i >= 0; --i) {
        cout << fixed << setprecision(2) << MyStack.data[i] << " ";
    }
    cout << "]" << endl;
}
