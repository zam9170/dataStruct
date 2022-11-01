#include <iostream>
#include <climits>
#define read(x) int x; cin >> x;
using namespace std;

template <typename T>
class Queue {
    int total_size,
    head,
    rear,
    curr_size;
    T* arr;
public:
    Queue(int total_size = 5) {
        this->total_size = total_size;
        this->head = this->rear = -1;
        this->curr_size = 0;
        this->arr = new T[total_size];
    }
    ~Queue() {
        delete []arr;
    }
    int getSize() {
        return curr_size;
    }
    int isEmpty() {
        return curr_size == 0;
    }
    void enqueue(int val) {
        if (curr_size == total_size) {
            T* new_arr = new T[2*total_size];
            for (int j = 0, i = head; i <= rear; ++i)
                new_arr[j++] = arr[i % total_size];
            // reset the pointers...
            head = 0;
            rear = total_size - 1;
            total_size *= 2;
            delete []arr;
            arr = new_arr;
        }
        this->rear = (this->rear + 1) % total_size;
        arr[this->rear] = val;
        // update the info...
        if (this->head == -1)
            this->head = 0;
        ++curr_size;
    }
    void dequeue() {
        if (this->isEmpty()) {
            cout << "Queue is empty!";
            return;
        }
        this->head = (this->head + 1) % total_size;
        --curr_size;
        if (curr_size == 0)
            this->head = this->rear = -1;
    }
    T face() {
        if (!this->isEmpty())
            return arr[this->head];
        cout << "Queue is empty!";
        return 0;
    }
};
int main() {

    Queue<int> q = Queue<int>();

    read(n)
    while(n != -1) {
        q.enqueue(n);
        cin >> n;
    }

    while (q.isEmpty() == false) {
        cout << q.face() << ' ';
        q.dequeue();
    }

    return 0;
}
