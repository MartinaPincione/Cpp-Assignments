#include <iostream>

#include "student.h"

using namespace std;

student get_student(){              // gets and sets student data

    student s;

    cout << "Enter a student's id: ";
    cin >> s.id;

    cout << "Enter a student's name: ";
    cin >> s.name;

    cout << "Enter a student's midterm grade: ";
    cin >> s.midterm;

    cout << "Enter a student's final grade: ";
    cin >> s.final;

    cout << "Enter a student's homework grades: ";
    cout << "Press ^D to terminate input. " << endl;

    int score;
    while(cin >> score){
        s.hw_grades.push_back(score);
    }

    return s;
}

void output_hw_scores(student s){           // outputs the list of homework scores

    cout << s.name << "'s homework scores are: " << endl;

    for(auto i: s.hw_grades){
        cout << " " << i;
    }
    cout << endl;
}

double compute_final_grade(const student & s){          //computes the total student grade

    double hw_average = 0.0; 
    int hw_count = 0;

    try{

        for (auto hw: s.hw_grades){
            hw_count++;
            hw_average += hw;
        }

        if (hw_count == 0) throw int(hw_count);
        hw_average /=  hw_count;

        double final_grade = (hw_average * .4) + (s.final * .3) + (s.midterm * .3);
        return final_grade;

    } catch(int i){

        cout << "cannot divide by homework count of " << i << endl;

        double final_grade = (s.final * .3) + (s.midterm * .3);
        
        return final_grade;
    }    

}


void output_final_grade(student s){     // outputs final grade
    cout << s.name << " earned a final test grade of " << s.final << endl;
}

void output_midterm_grade(student s){   // outputs midterm grade
    cout << s.name << " earned a midterm test grade of " << s.midterm << endl;
}