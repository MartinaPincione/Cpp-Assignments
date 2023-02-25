#include <iostream>
#include <string>
#include <vector>
#include "student.h"

using namespace std;

int main(){

    student s1;
    s1 = get_student();
    output_hw_scores(s1);
    output_midterm_grade(s1);
    output_final_grade(s1);
    cout << "student earned a final whole grade of " << compute_final_grade(s1) << endl;

    return 0;
}

