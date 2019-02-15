// This Program will use Binary search
// to process an array and locate a key value
// By Andrew Colbeck 2017

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//----------------------------------//
//		** 	PROTOTYPES **			//
//----------------------------------//
int binarySearch(int b[], int searchKey, int low, int high);
int partition(int a[], int L, int R);

//----------------------------------//
//			** 	MAIN PROGRAM **		//
//----------------------------------//
int main(){
	srand(time(NULL));
	int i, a[10], key, index = 0;

	// Produce an array of random integers in ascending order:
	printf("The Array is: \n");
	for (i = 0; i < 10; i++){
		a[i] = (rand()%10)+(i*10);
		printf("%i ", a[i]);
	}

	// Request key to search array for, and return result if found:
	printf("\n\n(Using Binary Search) enter a key to search for: ");
	scanf("%i", &key);
	index = binarySearch(a, key, 0, 9);
	if (index != -1)
		printf("Key was found at index %i in the array.\n", index);
	else
		printf("Key was not found.\n");
}

//----------------------------------//
//			** 	FUNCTIONS **		//
//----------------------------------//
int partition(int a[], int L, int R){
 	// This loop will re-arrange elements < or > than pivot
	// so that if they are less they'll be on the left, and greater will 
	// be on the right.  On the final call, the pivot will be placed in 
	// the middle, and it's position (marked by pindex) will be returned.

    int pivot = a[R];
    int pindex = L-1;
    // Initialise pindex so that left most element will be
    // included in calculation
    int hold;
    int i;

    for (i = L; i <= R; i++){
        if (a[i] <= pivot){
        	// If element a[i] <= pivot, swap with element
        	// at pindex location
	        pindex++;
	        // pindex = element in question's position in array
	        hold = a[pindex];
	        a[pindex] = a[i];
	        a[i] = hold;
        }
    }
	return(pindex);
}

int binarySearch(int b[], int searchKey, int low, int high){
	// Binary Search (Array must be sorted), more efficient
	// than linear search; especially with larger Arrays.

	int middle, part_count = 1, i;
	while (low <= high){
		middle = (low + high)/2;
		
		if (searchKey == b[middle])
			return middle;
		else if (searchKey < b[middle]){
			// If key is in lower half of array,
			// this if condition will change
			// start and end points to reflect only
			// the first half of the array.
			
			// PRINT RESULTS OF PARTITION TO TERMINAL
			high = middle - 1;
			printf("Partition %i\n", part_count);
			part_count++;
			for (i = low; i < high+1; i++)
				printf("%i ", b[i]);
			printf("\n");
		}
		else{
			// If key was found to be higher than 
			// middle, then start and end points of array
			// are changed to reflect only the second half
			// of the array.

			low = middle + 1;
		
			// PRINT RESULTS OF PARTITION TO TERMINAL
			printf("Partition %i\n", part_count);
			part_count++;
			for (i = low; i < high+1; i++)
				printf("%i ", b[i]);
			printf("\n");
		}
	}
	return -1;
}