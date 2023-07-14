/*/////////////////////////////////////////////////////////////////////////
                       OOP244 Workshop - #5 (PART 2-DIY)
Student Name: Julia Alekseev
Student ID#:  051292134
Email      :  jalekseev@myseneca.ca
Section    :  NEE
Date:      :  June 14, 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_


#include <iostream>

namespace sdds {
    class Mark {
        int m_mark;
        void setToDefault();
        bool goodMark;
    public:
        Mark();
        Mark(int);
        operator int() const;
        operator double() const;
        operator char() const;
        Mark& operator+=(int);
        Mark& operator=(int);
        int fetchMarks()const;
        bool fetchMarkBool()const;
    };

    bool isValidInt(int);
    int& operator+=(int& num, const Mark& rhs);
  
  


}
#endif // SDDS_MARK_H_