#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct student{
    int id;
    string name;
    int final;
    int midterm;
    vector<int> hw_grades;
};


student get_student();

void output_hw_scores(student s);

double compute_final_grade(const student & s);

void output_final_grade(student s);

void output_midterm_grade(student s);

#endif