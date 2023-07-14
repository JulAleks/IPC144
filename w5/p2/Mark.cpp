/*/////////////////////////////////////////////////////////////////////////
                       OOP244 Workshop - #5 (PART 2-DIY)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  June 14, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"


using namespace std;
namespace sdds {
    //set to empty, it is always better to set to empty before initializing
    void Mark::setToDefault() {
        m_mark = 0;
        goodMark = true;
    }

    //sets the class to default
    Mark::Mark() {
        setToDefault();
    }

    //checks if the grade is in the valid range
    bool isValidInt(int num) {
        bool ok = false;
        if (num >= 0 && num <= 100) {
            ok = true;
        }
        return ok;
    }


    //Construction : Mark can be created using an integer value(one argument constructor)that sets the value of the mark.If this value is not provided(no - argument constructor), the value of the mark will be zero.
    Mark::Mark(int num) {
        setToDefault();
        if (isValidInt(num)) {
            m_mark = num;
            goodMark = true;
        }
        else if (!isValidInt(num)) {
            goodMark = false;
        }
        else {
            m_mark = 0;
            goodMark = true;
        }
    }


    //Mark can be casted to an integer (int type). The result would be the value of the mark or zero if the mark is in an invalid state.
    Mark::operator int() const {
        return (m_mark >= 0 && m_mark <= 100) ? m_mark : 0;
    }

    // An integer can be added to the value of the mark using += operator; 
    //if the mark is invalid, the action is omitted.Reference of the mark is returned after the operation.
    Mark& Mark::operator+=(int num) {

        if (isValidInt(num) && m_mark >= 0 && m_mark + num <= 100 && goodMark) {
            m_mark += num;
        }
        else {
            m_mark = 0;
        }
        return *this;
    }


    //Mark can be set to an integer using the assignment operator. If the mark is in an invalid state, the invalid value can be corrected by the assignment. 
    //Reference of the mark is returned after the operation
    Mark& Mark::operator=(int num) {   

        if (isValidInt(num)) {
            m_mark = num;
            goodMark = true;
        }
        else {
            goodMark = false;
        }

        return *this;
    }


    //Mark can be casted to a double, the result would be the GPA equivalent of the integer value.See the table of mark values above.Casting an invalid mark will result in a zero value.
    Mark::operator double() const {
        double returnScale=0.0; 
         if (goodMark && 50 <= m_mark && m_mark < 60){
             returnScale = 1.0;
         }
        else if (goodMark && 60 <= m_mark && m_mark < 70){
             returnScale = 2.0;
}
        else if (goodMark && 70 <= m_mark && m_mark < 80) {
             returnScale = 3.0;
        }
         else if (goodMark && 80 <= m_mark && m_mark <= 100) {
             returnScale = 4.0;
        }
        else if(!goodMark){
             returnScale = 0.0;
        }
         return returnScale;
    }

    //Mark can be casted to a character (char type), the result would be the grade letter value of the mark. See the table of mark values above. Casting an invalid mark will result in an 'X' value.
    Mark::operator char() const {
        char grade = 'X';
        if (goodMark && 0 < m_mark && m_mark < 50) {
            grade = 'F';
        }
        else if (goodMark && 50 <= m_mark && m_mark < 60) {
            grade = 'D';
        }
        else if (goodMark && 60 <= m_mark && m_mark < 70) {
            grade = 'C';
        }
        else if (goodMark && 70 <= m_mark && m_mark < 80) {
            grade = 'B';
        }
        else if (goodMark && 80 <= m_mark && m_mark <= 100) {
            grade = 'A';
        }
       
        return grade;
    }

    //fetch the value of marks
    int Mark::fetchMarks()const {
        return m_mark;
    }

    //checkinng if mark is valid
    bool Mark::fetchMarkBool() const{
        return goodMark;
    }

    //Mark can be added to an integer, returning the integer after the operation. Invalid marks will not add any value to the integer.
    int& operator+=(int& num, const Mark& rhs) {
        if (rhs.fetchMarkBool()) {
            num += rhs.fetchMarks();
        }
        return num;
    }
}

