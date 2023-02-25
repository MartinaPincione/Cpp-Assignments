#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "student.h"


TEST_CASE("testing compute_final_score"){

    student s1;
    s1.final = 100;
    s1.midterm = 100;
    s1.hw_grades.push_back(100);
    s1.hw_grades.push_back(100);

    double result1 = compute_final_grade(s1);
    CHECK(result1 == 100);
    CHECK(result1 >= 99.9);
    CHECK(result1 <= 101.1);



    student s2;
    s2.final = 80;
    s2.midterm = 80;
    s2.hw_grades.push_back(90);
    s2.hw_grades.push_back(0);

    double result2 = compute_final_grade(s2);
    CHECK(result2 == 66);

    student s3;
    s3.final = 80;
    s3.midterm = 100;
    s3.hw_grades.push_back(55);
    s3.hw_grades.push_back(2);
    s3.hw_grades.push_back(80);
    s3.hw_grades.push_back(100);

    double result3 = compute_final_grade(s3);
    CHECK(result3 == 77.7);

    // test case no homework grades
    student s4;
    s4.final = 80;
    s4.midterm = 100;

    double result4 = compute_final_grade(s4);
    CHECK(result4 == 54);

}

TEST_CASE("testing get student"){

    cout << "Input 80 for student final, 70 for midterm, and 60,70,100,100 for the hw grades" << endl;

    student s3 = get_student();

    CHECK( s3.final == 80);
    CHECK( s3.midterm == 70);
    CHECK( compute_final_grade(s3) == 78);

}