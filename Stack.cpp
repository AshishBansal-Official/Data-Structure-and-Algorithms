#include<iostream>

template <typename T>
class DynamicStack {
	struct StackNode {
		T data;
		StackNode* link;
	};

	StackNode* top = nullptr;
public:
	void push(T data) {
		StackNode* temp = new StackNode();
		temp->data = data;
		temp->link = top;
		top = temp;
	}

	void pop() {
		if (top == nullptr) {
			std::cout << "Stack is Empty" << std::endl;
		}
		else {
			StackNode* temp = top;
			top = top->link;
			delete temp;
		}
	}

	void print() {
		StackNode* temp = top;
		if (temp == nullptr) {
			std::cout << "Stack is empty" << std::endl;
		}
		else {
			std::cout << "Printing Stack....." << std::endl;
			StackNode* temp = top;
			while (temp != nullptr) {
				std::cout << temp->data << std::endl;
				temp = temp->link;
			}
		}
	}
};


template<typename T, int SIZE>
class StaticStack {
	int top;
	T stack[SIZE];
public:
	StaticStack() : top(-1), stack{0} {}
	
	bool isEmpty() {
		return top==-1;
	}		
	

	bool isFull() {
		return top==SIZE-1;
	}
	
	void push(T data) {
		if(isFull()){
			std::cout<<"Stack Overflow!!!"<<std::endl;
		} else {
			top++;
			stack[top] = data;
		}
	}
	
	T pop() {
		if(isEmpty()) {
			std::cout<<"Stack Underflow!!!"<<std::endl;
			return 0;
		} else {
			T popValue = stack[top];
			stack[top] = 0;
			top--;
			return popValue;
		}
	}
	
	int count() {
		return top+1;
	}
	
	T peek(int position) {
		if(isEmpty()) {
			std::cout<<"Stack Underflow!!!"<<std::endl;
			return 0;
		} else {
			return stack[position];
		}
	}
	
	void change(int position, T value) {
		stack[position] = value;
		std::cout<<"Value changed at location "<<position<<std::endl;
	}
	
	void display() {
		if(isEmpty()) {
			std::cout<<"Stack is Empty"<<std::endl;
			return ;
		}
 		std::cout<<"All values in the Stack are : \n";
		for(int i=top; i>=0; i--) {
			std::cout<<stack[i]<<std::endl;
		}
	}
};

int main() {
	StaticStack<int, 5> s1;
	int option, postion, value;

  	do {
	    std::cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << std::endl;
	    std::cout << "1. Push()" << std::endl;
	    std::cout << "2. Pop()" << std::endl;
	    std::cout << "3. isEmpty()" << std::endl;
	    std::cout << "4. isFull()" << std::endl;
	    std::cout << "5. peek()" << std::endl;
	    std::cout << "6. count()" << std::endl;
	    std::cout << "7. change()" << std::endl;
	    std::cout << "8. display()" << std::endl;
	    std::cout << "9. Clear Screen" << std::endl << std::endl;
	
	    std::cin >> option;
	    switch (option) {
	    case 0:
	      break;
	    case 1:
	      std::cout << "Enter an item to push in the stack" << std::endl;
	      std::cin >> value;
	      s1.push(value);
	      break;
	    case 2:
	      std::cout << "Pop Function Called - Poped Value: " << s1.pop() << std::endl;
	      break;
	    case 3:
	      if (s1.isEmpty())
	        std::cout << "Stack is Empty" << std::endl;
	      else
	        std::cout << "Stack is not Empty" << std::endl;
	      break;
	    case 4:
	      if (s1.isFull())
	        std::cout << "Stack is Full" << std::endl;
	      else
	        std::cout << "Stack is not Full" << std::endl;
	      break;
	    case 5:
	      std::cout << "Enter position of item you want to peek: " << std::endl;
	      std::cin >> postion;
	      std::cout << "Peek Function Called - Value at position " << postion << " is " << s1.peek(postion) << std::endl;
	      break;
	    case 6:
	      std::cout << "Count Function Called - Number of Items in the Stack are: " << s1.count() << std::endl;
	      break;
	    case 7:
	      std::cout << "Change Function Called - " << std::endl;
	      std::cout << "Enter position of item you want to change : ";
	      std::cin >> postion;
	      std::cout << std::endl;
	      std::cout << "Enter value of item you want to change : ";
	      std::cin >> value;
	      s1.change(postion, value);
	      break;
	    case 8:
	      std::cout << "Display Function Called - " << std::endl;
	      s1.display();
	      break;
	    case 9:
	      system("cls");
	      break;
	    default:
	      std::cout << "Enter Proper Option number " << std::endl;
	    }

	} while (option != 0);

	return 0;
}
