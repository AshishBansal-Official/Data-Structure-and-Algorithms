#include<iostream>

void linearSearch(int arr[], int size, int data) {
	std::cout<<"************Linear Search************"<<std::endl;
	for(int i = 0; i<size; i++) {
		if(arr[i] == data) {
			std::cout<<"Element found at index -> "<<i<<std::endl;
			return ;
		}
	}
	std::cout<<"Element not found!!!"<<std::endl;
}

void binarySearch(int arr[], int size, int data) {
	std::cout<<"************Binary Search************"<<std::endl;
	int first = 0;
	int last = size - 1;
	int mid;
	while(first<= last) {
		mid = first + (last-first) / 2;
		if(arr[mid] == data) {
			std::cout<<"Element found at index -> "<<mid<<std::endl;
			return;
		} else if (arr[mid]> data) {
			last = mid- 1;
		} else if(arr[mid]<data) {
			first = mid+1;
		}
	}
	std::cout<<"Element not found!!!"<<std::endl;
}

int main() {
	int size;
	std::cout<<"Enter the size of array: ";
	std::cin>>size;
	int arr[size];
	std::cout<<"Enter the elements in ascending order: "<<std::endl;
	for(int i = 0; i<size; i++) {
		std::cin>>arr[i];
	}
	int element;
	std::cout<<"Enter the element to be searched: ";
	std::cin>>element;
	linearSearch(arr, size, element);
	binarySearch(arr, size, element);
	return 0;
}
