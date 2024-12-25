#include <string>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <ostream>
using std::cin;
using std::cout;
using std::endl;
using std::overflow_error;
using std::string;
using std::underflow_error;
using std::unique_ptr;
using std::ostream;
struct Employee
{
    string name_;
    int age_;
    string position_;
    int experience_;
     // Default constructor
    Employee() : name_("Unknown"), age_(0), position_("Unknown"), experience_(0) {}
    // parameters constructor 
    Employee(string name, int age, string position, int experience) : 
    name_(name), age_(age), position_(position), experience_(experience) {}
    // Overload << operator as a friend function
    friend ostream &operator<<(ostream &os, const Employee &emp);
};

// Implementation of the << operator overload
ostream &operator<<(ostream &os, const Employee &emp)
{
    os << "Name: " << emp.name_ << "\n"
       << "Age: " << emp.age_ << "\n"
       << "Position: " << emp.position_ << "\n"
       << "Experience: " << emp.experience_ << "\n";
    return os;
}

template <typename T>
class Queue
{
private:
    unique_ptr<T[]> arr; // Smart pointer to manage dynamic memory
    int size_;
    int front_;
    int back_;
    int count_;

public:
    Queue(int size);
    ~Queue();

    void enqueue(const T &item);
    void dequeue();
    T front() const;
    bool isEmpty() const;
    bool isFull() const;
    void print() const;
};

// Constructor
template <typename T>
Queue<T>::Queue(int size)
    : arr(new T[size]), size_(size), front_(0), back_(-1), count_(0) {}

// Enqueue method
template <typename T>
void Queue<T>::enqueue(const T &item)
{
    if (isFull())
    {
        throw overflow_error("Queue is full");
    }
    back_ = (back_ + 1) % size_;
    arr[back_] = item;
    count_++;
}

// Dequeue method
template <typename T>
void Queue<T>::dequeue()
{
    if (isEmpty())
    {
        throw underflow_error("Queue is empty");
    }
    front_ = (front_ + 1) % size_;
    count_--;
}

// Get front item
template <typename T>
T Queue<T>::front() const
{
    if (isEmpty())
    {
        throw underflow_error("Queue is empty");
    }
    return arr[front_];
}

// Check if queue is empty
template <typename T>
bool Queue<T>::isEmpty() const
{
    return count_ == 0;
}

// Check if queue is full
template <typename T>
bool Queue<T>::isFull() const
{
    return count_ == size_;
}

// Print all elements in the queue
template <typename T>
void Queue<T>::print() const
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    int i = front_;
    for (int k = 0; k < count_; ++k)
    {
        cout << arr[i] << " ";
        i = (i + 1) % size_;
    }
    cout << endl;
}
template <typename T>
Queue<T>::~Queue()
{
    cout << "END Queue" << endl;
}
struct QueueInt
{
    int arr[100];

    // some functionalities using type integer
};

struct QueueDouble
{
    double arr[100];

    // exactly same as above, but replace integer with souble
};

struct QueueString
{
    string arr[100];

    // exactly same as above, but replace integer with string
};



struct QueueEmployee
{
    Employee arr[100];
};
