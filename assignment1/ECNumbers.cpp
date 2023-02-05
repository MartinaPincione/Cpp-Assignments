#include <iostream>

#include "ECNumbers.h" //declaration of the function

using namespace std;

void output_int_array(int nums[], int length){
  for (int i =0; i< length; i++){
    cout << nums[i] << " ";
  }
  cout << endl;
}



int swap_val_to_end(int nums[], int length, int val){ //definition of the function

  int i = 0, backwards = length - 1;
    while (i <= backwards) {
        if (nums[i] == val) {
	  int temp = nums[backwards];
	  nums[backwards] = nums[i];                                                                                                  
	  nums[i] = temp;                                                                                                             
	  backwards--;
        } else {
            i++;
        }

    }
    int toDelete = length - (backwards + 1);
    cout << "to delete: " << toDelete<< endl;
    return toDelete;
}
/*
  cout << "to delete: " << toDelete<< endl;
  return toDelete;
}
*/

/*
 
 CLASS NOTES

 
 * REFACTORING = restructuring code but keeping the functionality the same
 

 
 */
