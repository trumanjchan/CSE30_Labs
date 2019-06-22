#include <iostream>

using namespace std;

struct ResizableArray {
    // This is the poiner to the start of our array
    int* data;
    
    // Keep track of how much memory we have allocated
    int size;
    
    // Keep track of how much memory we have used
    int counter;
    
    // A default constructor
    ResizableArray(){
        // Start off by allocating memory for 1 int
        data = new int[1];
        
        // This means we have allocated for 1
        size = 1;
        
        // And we are currently using 0
        counter = 0;
    }
    
    // Print the contents we have
    void print(){
        for (int i = 0; i < counter; i++){
            cout << data[i] << endl;
        }
    }
    
    int getValueAt(int index){
		for (int i = 0; i < size; i++) {
			if (data[i] == data[index]) {
				return data[i];
			}
		}
    }
    
    void setValueAt(int index, int value){
		for (int i = 0; i < size; i++) {
			data[index] = value;
		}
    }
    
    void insertAt(int index, int value){
		//int oldSize = size;

		//if (counter == size) {
		//	size = size * 2;
		//}

		//int* newArr = new int[size];
		//counter++;
		//counter++;

		if (index < size) {
			int oldSize = size;
			size = size * 2;
			int* newArr = new int[size];

			for (int i = 0; i < index; i++) {
				newArr[i] = data[i];
			}
			for (int i = 0; i < size; i++) {
				if (i == index) {
					newArr[i] = value;
					counter++;
				}
			}
			for (int i = (index+1); i < size; i++) {
				newArr[i] = data[i-1];
			}
			for (int i = 7; i < 9; i++) {
				newArr[i] = 0;
				counter++;
			}

			delete[] data;
			data = newArr;
			for (int i = 0; i < size; i++) {
				if (!(data[i] > 0)) {
					data[i] = 0;
					//counter++;
				}
			}
		}

		////for (int i = 0; i < index; i++) {
		////	newArr[i] = data[i];
		////}

		////for (int i = index + 1; i < size; i++) {
		////	newArr[i] = data[i-1];
		////}

		//for (int i = 0; i < size; i++) {
		//	if (i == index) {
		//		newArr[i] = value;
		//		counter++;
		//	}
		//	for (int t = 0; t < index; t++) {
		//		newArr[t] = data[t];
		//	}
		//	for (int p = index + 1; p < size; p++) {
		//		newArr[p] = data[p-1];
		//	}
		//	if (i == 7 || i == 8 || i == 9) {
		//		newArr[i] = 0;
		//		counter++;
		//	}
		//}

		////for (int i = 0; i < size; i++) {
		////	if (i == index) {
		////		newArr[i] = value;
		////		counter++;
		////	}
		////}

		//delete[] data;
		//data = newArr;
    }
    
    // Store a new value in the array
    void insert(int value){
        // The very first time this is called
        // we know we have enough storage allocated
        // because we allocated space for 1 int
        // so we store it
        data[counter] = value;
        // and increase the counter
        counter++;
        
        // If we are out of space, i.e. we have
        // stored as much as we have allocated
        // then we need to increase our storage space
        if (counter == size){
            // Just for convenience, store the old size
            int oldSize = size;
            
            // Let's double the amount of storage we have
            size = size * 2;
            
            // Allocate another chunk of memory
            // twice as big as the first
            int* newArr = new int[size];
            
            // Copy all elements from the old location
            // to the new location
            for (int i = 0; i < oldSize; i++) {
                newArr[i] = data[i];
            }
            
            // Release the old location
            delete[] data;
            
            // Make our data pointer point to the new location
            data = newArr;
            
        }
    }
};


int main(int argc, const char * argv[]) {
    // Create a resizable array
    ResizableArray array;
    
    for (int i = 0; i < 6; i++) {
        array.insert(i);
    }
    
    array.insertAt(2, 77);
    
    array.insertAt(10, 89);
    
    array.insert(101);
    
    // Print out the array
    array.print();
    
    /* Expected output of array.print()
     0
     1
     77
     2
     3
     4
     5
     0
     0
     0
     89
     101
    */
    
    cout << "count: " << array.counter << endl;
    cout << "size : " << array.size << endl;

    /* Expected output of 2 lines above
     
     count: 12
     size : 16
    
    */
    
    return 0;
}
