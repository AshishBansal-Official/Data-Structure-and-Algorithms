#include <iostream>
#define MAX_SIZE 5

template <typename T>
class StaticQueue {
	T queue[MAX_SIZE];
	int front, rear;
public:
	StaticQueue() : queue {0}, front(-1), rear(-1) {}
	
	bool isEmpty() {
		if(rear==-1 && front==-1) {
			return true;
		} else {
			return false;
		}
	}
	
	bool isFull() {
		if(rear==MAX_SIZE) {
			return true;
		} else {
			return false;
		}
	}
	
	void enqueue(T data) {
		if (isFull()) {
			std::cout << "Queue is full" << std::endl;
			return;
		}
		else if (isEmpty()) {
			front = rear = 0;
		} 
		else {
			rear++;
		}
		queue[rear] = data;
	}
	
	T dequeue() {
		int x=0;
		if (isEmpty()) {
			std::cout << "Queue is empty" << std::endl;
		}
		else {
			x = queue[front];
			std::cout<<"Front Value : "<<x<<std::endl;
			queue[front] = 0;
			front++;
			if (front == rear + 1) {
				front = rear = -1;
			}
		}
		return x;
	}
	
	int count() {
		return (rear - front + 1);
	}
	
	void print() {
		if (front == -1 && rear == -1) {
			std::cout << "Queue is empty" << std::endl;
		}
		else {
			std::cout << "Printing Queue...." << std::endl;
			int temp = front;
			while (temp != rear + 1) {
				std::cout << queue[temp++] << std::endl;
			}
		}
	}
};

template <typename T>
class DynamicQueue {
	struct Node {
		T data;
		Node* link;
	};
	Node* front = nullptr,* rear = nullptr;
public:
	void enqueue(T data) {
		Node* temp = new Node();
		temp->data = data;
		temp->link = nullptr;
		if (front == nullptr && rear == nullptr) {
			front = rear = temp;
		}
		else {
			rear->link = temp;
			rear = temp;
		}
	}
	void dequeue() {
		if (front == nullptr) {
			std::cout << "Queue is empty" << std::endl;
		}
		else {
			Node* temp = front;
			front = front->link;
			delete temp;
			if (front == nullptr) {
				rear = nullptr;
			}
		}
	}
	void print() {
		if (rear == nullptr) {
			std::cout << "Queue is empty" << std::endl;
		}
		else {
			std::cout << "Printing Queue...." << std::endl;
			Node* temp = front;
			while (temp != nullptr) {
				std::cout << temp->data << std::endl;
				temp = temp->link;
			}
		}
	}
};
