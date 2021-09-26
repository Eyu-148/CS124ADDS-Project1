/** cs124 project1 by Eyu on 5/30/21 */

#include <vector>
#include <iostream>
#include "Course.h"

/**
 * Main
 */
int main() {

    std::vector<Course> course;
    std::string fn = "../uvm_fall2021_courses.csv";

    if (loadFromFile(fn, course)) {
        std::cout << course.size()
                  << " records read from file" << std::endl;
        int firstId = course.front().getRowId();
        std::cout << "The first row ID read was " << firstId << std::endl;
        int lastId = course.back().getRowId();
        std::cout << "The last row ID read was " << lastId << std::endl;
    } else {
        std::cout << "Something went wrong." << std::endl;
    }

    // Run tests to verify everything is working correctly.
    CourseTest();

    // Check for bad data or incorrectly set fields.
    validFields(course);

    // give the number of the courses without instructor
    needInstructor(course);

    // Print a few object to test overload of <<
    std::cout << std::endl;

    std::cout << std::left
              << std::setw(7) << "RowId"
              << std::setw(8) << "Subject"
              << std::setw(40) << "Title"
              << std::setw(7) << "CRN"
              << std::setw(9) << "College"
              << std::setw(5) << "Max"
              << std::setw(5) << "Cur"
              << std::setw(25) << "Instructor"
              << std::setw(25) << "Email"
              << std::endl;

    std::cout << std::string(120, '-') << std::endl;
    for (int i = 0; i < 7; i++) {
        std::cout << course.at(i) << std::endl;
    }
    std::cout << "* max = max enrollment, cur=current enrollment" << std::endl
              << std::endl;

}