/** cs124 project1 by Eyu on 9/12/21 */

#include <vector>
#include <iostream>
#include "Course.h"

using namespace std;
/**
 * Main
 */
int main() {

    vector<Course> course;
    string fn = "../uvm_fall2021_courses.csv";

    if (loadFromFile(fn, course)) {
        cout << course.size()
                  << " records read from file" << endl;
        int firstId = course.front().getRowId();
        cout << "The first row ID read was " << firstId << endl;
        int lastId = course.back().getRowId();
        cout << "The last row ID read was " << lastId << endl;
    } else {
        cout << "Something went wrong." << endl;
    }

    // Run tests to verify everything is working correctly.
    CourseTest();

    // give the number of the courses without instructor
    needInstructor(course);
    ifSeatAvailable(course);
    maxEnrollment(course);

    // Print a few object to test overload of <<
    cout << endl;

    cout << left
              << setw(7) << "RowId"
              << setw(8) << "Subject"
              << setw(40) << "Title"
              << setw(7) << "CRN"
              << setw(9) << "College"
              << setw(5) << "Max"
              << setw(5) << "Cur"
              << setw(25) << "Instructor"
              << setw(25) << "Email"
              << endl;

    cout << string(120, '-') << endl;
    for (int i = 0; i < 20; i++) {
        cout << course.at(i) << endl;
    }
    cout << "* max = max enrollment, cur=current enrollment" << endl
              << endl;

}