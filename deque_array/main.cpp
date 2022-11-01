#include <iostream>

#define read(x) int x; cin >> x;
#define write(x) cout << x << ' ';
using namespace std;

template<typename T>
class dq {
    T* arr;
    int curr_size, total_size, head, rear;
public:
    dq(int total_size = 1000) {
        this->total_size = total_size;
        head = rear = -1;
        curr_size = 0;
        this->arr = new T[total_size];
    }
    ~dq() {
        delete []arr;
    }
    T get_front() {
        if (!this->isEmpty())
            return arr[head];
        cout << "Queue is empty!";
        return 0;
    }
    T get_rear() {
        if (!this->isEmpty())
            return arr[rear];
        cout << "Queue is empty!";
        return 0;
    }
    int getSize() {
        return curr_size;
    }
    bool isEmpty() {
        return curr_size == 0;
    }
    void front_push(int val) {
        if (curr_size == total_size) {
            cout << "Queue is full!";
            return;
        }
        if (head == -1)
            head += total_size;
        else {
            head += -1;
            if (head == -1)
                head += total_size;
        }
        arr[head] = val;
        // update element...
        ++curr_size;
        if (rear == -1)
            rear = head;
    }
    void rear_push(int val) {
        if (curr_size == total_size) {
            cout << "Queue is full!";
            return;
        }
        rear = (rear + 1) % total_size;
        arr[rear] = val;
        // update values...
        ++curr_size;
        if (head == -1)
            head = rear;
    }
    void front_pop() {
        if (this->isEmpty()) {
            cout << "Queue is empty!";
            return;
        }
        if (head == rear)
            head = rear = -1;
        else
            head = (head + 1) % total_size;
        --curr_size;
    }
    void rear_pop() {
        if (this->isEmpty()) {
            cout << "Queue is empty!";
            return;
        }
        if (head == rear)
            head = rear = -1;
        else {
            rear += -1;
            if (rear == -1)
                rear += total_size;
        }
        --curr_size;
    }
};
int main() {

    dq<int> q = dq<int>();

    q.front_push(7);
    q.rear_push(0);
    write(q.get_front())
    q.rear_push(3);
    write(q.get_front())
    q.front_push(9);
    write(q.get_rear());
    write(q.get_front());
    write(q.get_front());
    q.rear_pop();
    write(q.get_rear());

    return 0;
}
