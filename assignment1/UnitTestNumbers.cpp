#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN


#include "doctest.h"
#include "ECNumbers.h"

int nums[] = {2, 2, 3, 3};
int nums_1[] = {95, 95, 99, 2};
int nums_2[] = {2, 98, 89, 90, 90};
int nums_3[] = {};
int nums_4[] = {4, 5, 6, 3, 4, 1, 2, 2};
int nums_5[] = {2, 2, 2, 2};

TEST_CASE("Testing swap value to delete"){
 
  SUBCASE("swap_val_to_end"){
    
    CHECK(swap_val_to_end(nums, sizeof(nums)/sizeof(nums[0]), 2) == 2);
    CHECK(swap_val_to_end(nums_1, sizeof(nums_1)/sizeof(nums_1[0]), 2) == 1);
    CHECK(swap_val_to_end(nums_2, sizeof(nums_2)/sizeof(nums_2[0]), 2) == 1);
    CHECK(swap_val_to_end(nums_3, 0, 2) == 0);
    CHECK(swap_val_to_end(nums_4, sizeof(nums_4)/sizeof(nums_4[0]), 2) == 2);
    CHECK(swap_val_to_end(nums_5, sizeof(nums_5)/sizeof(nums_5[0]), 2) == 4);
  };
}
