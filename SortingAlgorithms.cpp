#include<iostream>

void print(int arr[], int size) {
	std::cout<<"Elements of the array: ";
	for(int i=0; i<size; i++) {
		std::cout<<arr[i]<<", ";
	}
	std::cout<<std::endl;
}

void selectionSort(int arr[], int size) {
	int min;
	for(int i=0; i<size-1;i++) {
		min=i;
		for(int j= i+1; j<size; j++) {
			if(arr[j]<arr[min]) {
				min = j;
			}
		}
		if(min!=i) {
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}

void insertionSort(int arr[], int size) {
	int key;
	int j;
	for(int i=1; i<size;i++) {
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j]>key) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void bubbleSort(int arr[], int size) {
	for(int i = 0; i < size-1; i++) {
		for(int j = 0; j < size-i-1; j++) {
			if(arr[j]>arr[j+1]) {
				std::swap(arr[j], arr[j+1]);
			}
			
		}
	}
}

void optimizedBubbleSort(int arr[], int size) {
	int flag = true;
	for(int i = 0; i < size-1; i++) {
		flag = true;
		for(int j = 0; j < size-i-1; j++) {
			if(arr[j]>arr[j+1]) {
				std::swap(arr[j], arr[j+1]);
				flag = false;
			}
			
		}
		if(flag) {
			break;
		}
	}
}

void merge(int arr[], int left, int mid, int right) {
	int i = left;
	int j = mid+1;
	int k = left;
	int temp[right - left + 1];
	
	while(i<=mid && j<=right) {
		if(arr[i] <= arr[j]) {
			temp[k] = arr[i];
			i++;
			k++;
		} else {
			temp[k] = arr[j];
			j++;
			k++;
		}
	}
	
	while(i<=mid) {
		temp[k] = arr[i];
		i++;
		k++;
	}
	
	while(j<=right) {
		temp[k] = arr[j];
		j++;
		k++;
	}
	
	for(int p = left; p<=right; p++) {
		arr[p] = temp[p];
	}
}

void mergeSort(int arr[], int left, int right) {
	if(left<right) {
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}

int partition(int arr[], int left, int right) {
	int pivot = arr[right];
	int pIndex = left;
	for(int i=left; i<right; i++) {
		if(arr[i]<=pivot) {
			std::swap(arr[i], arr[pIndex]);
			pIndex++;
		}
	}
	std::swap(arr[pIndex], arr[right]);
	return pIndex;
}

void quickSort(int arr[], int left, int right) {
	if(left<right) {
		int p = partition(arr, left, right);
		quickSort(arr, left, p-1);
		quickSort(arr, p+1, right);
	}
}

void countingSort(int input_array[], int size, int range) {
	int output_array[size];
	int count_array[range];
	
	for(int i=0; i<range; i++) {
		count_array[i] = 0;
	}
	
	for(int i=0; i<size; i++) {
		++count_array[input_array[i]];
	}
	
	for(int i=1; i<range; i++) {
		count_array[i] = count_array[i] + count_array[i-1];
	}
	
	for(int i=0; i<size; i++) {
		output_array[--count_array[input_array[i]]] = input_array[i];
	}
	
	for(int i=0; i<size; i++) {
		input_array[i] = output_array[i];
	}
}

int getMax(int arr[], int size) {
	int max = arr[0];
	for(int i=1; i<size; i++) {
		if(arr[i]>max) {
			max = arr[i];
		}
	}
	return max;
}

void countingSortForRadixSort(int arr[], int size, int div) {
	int output_array[size];
	int count[10] = {0};
	
	for(int i=0; i<size; i++) {
		count[(arr[i]/div)%10]++;
	}
	
	for(int i=1; i<10; i++) {
		count[i] += count[i-1];
	}
	
	for(int i=size-1; i>=0; i--) {
		output_array[count[(arr[i]/div)%10]-1] = arr[i];
		count[(arr[i]/div)%10]--;
	}
	
	for(int i=0; i<size; i++) {
		arr[i] = output_array[i];
	}
}

void radixSort(int arr[], int size) {
	int m = getMax(arr, size);
	for(int div = 1; m/div>0; div*=10) {
		countingSortForRadixSort(arr, size, div);
	}
}

void shellSort(int arr[], int size) {
	for(int gap = size/2; gap>0; gap /= 2) {
		for(int i=gap; i<size; i++) {
			int temp = arr[i];
			int j;
			for(j=i; j>=gap && arr[j-gap]>temp; j -= gap) {
				arr[j] = arr[j-gap];
			}
			arr[j] = temp;
		}
	}
}

int main() {
	int size;
	std::cout<<"Enter the size of array: ";
	std::cin>>size;
	int arr[size];
	std::cout<<"Enter the elements: "<<std::endl;
	for(int i = 0; i<size; i++) {
		std::cin>>arr[i];
	}
	std::cout<<"Before Sorting: "<<std::endl;
	print(arr, size);
	radixSort(arr, size);
	std::cout<<"After Sorting: "<<std::endl;
	print(arr, size);
	return 0;
}
