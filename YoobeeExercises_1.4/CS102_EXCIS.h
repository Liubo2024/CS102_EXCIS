// CS102_EXCIS.h  
#pragma once

#ifndef CS102_EXCIS_H  
#define CS102_EXCIS_H  

#include <iostream>
#include <algorithm>
#include <string>
#include <limits>  
#include <vector> 
#include <regex>
#include <cstdlib>  
#include <ctime>  
#include <iomanip>
#include <stdexcept>
#include <fstream>

namespace CS102_EXCIS { 
    
    //********************************************************************************************************************************
    //function declaration
    //********************************************************************************************************************************
    bool CheckIsInt(double d);
    bool CheckIsInt(std::string s);
    int InputInteger(std::string sPrompt);
    int InputInteger(std::string sPrompt, int iMin);
    int InputInteger(std::string sPrompt, int iMin, int iMax);
    int InputInteger(std::string sPrompt, int iMin, int iMax, bool bZeroAllowed);
    std::string InputString(std::string sPrompt);
    std::string PadWithSpaces(const std::string& s, unsigned int len);
    std::string PadWithSpaces(const int& i, unsigned int len);
    void QuickSort(std::vector<int>& arr, int low, int high);
    void QuickSort(std::vector<int>& arr, bool bAscending);

    void CS102_EXCIS_I_1(); //1. Evaluate the expression: Z = ax +(b-c)(c-d)/y 
    void CS102_EXCIS_I_2(); //2. Write a program to find smallest of three numbers.
    void CS102_EXCIS_I_3(); //3. Write a program to find a given number is prime or not. Read a number from user and display as per the output format.
    void CS102_EXCIS_I_4(); //4. Write a program to generate even numbers between two different values. Proceed to verify the given inputs are not null.
    void CS102_EXCIS_I_5(); //5. Write a program to generate an odd list between 20 to 47 and count number of odds in the list.Display your result as per the output format.
    void CS102_EXCIS_I_6(); //6. Write a program to generate Fibonacci series as per the user input. 
    void CS102_EXCIS_I_7(); //7. Write a program to read a number from user, find factorial for the given number and display as like,
    void CS102_EXCIS_I_8(); //8. Write a program to display the pattern below as per the user input. 
    void CS102_EXCIS_I_9(); //9. Write a program to read a value from user and display the place value.
    void CS102_EXCIS_I_10(); //10. Write a program to generate the following pattern
    void CS102_EXCIS_I_11(); //11. Write a program to read the first name and last name. Validate the user inputs as follows: • Verify first name and last name are different • Verify the name contains only alphabets 
    void CS102_EXCIS_I_12(); //12. Write a program to read a sentence and display. Count number of words, special characters and vowels in the sentence and display as follows,
    void CS102_EXCIS_I_13(); //13. write a program to generate 10 random numbers as per the user input range. Count number of repeated numbers in the list and display.
    void CS102_EXCIS_I_14(); //14. write a program to create an integer array of size 10 and display. Count number of even numbers and number of odds in the list and display as follows
    void CS102_EXCIS_I_15(); //15. write a program to read 5 different double values and store in an array called double list.Sort the array elements and display the sorted list.

    void CS102_EXCIS_III_1(); //1. Write a program to display the following. Allow the user to provide input as like,
    void CS102_EXCIS_III_2(); //2. Write a program to generate multiplication times table as like,
    void CS102_EXCIS_III_3(); //3. Write a program to generate multiplication times table as per the user input.
    void CS102_EXCIS_III_4a(); //4. Write a program to print the following, a) 
    void CS102_EXCIS_III_4b(); //4. Write a program to print the following, b) 
    void CS102_EXCIS_III_4c(); //4. Write a program to print the following, c) 
    void CS102_EXCIS_III_4d(); //4. Write a program to print the following, d) 
    void CS102_EXCIS_III_4e(); //4. Write a program to print the following, e) 
    void CS102_EXCIS_III_4f(); //4. Write a program to print the following, f) 
    void CS102_EXCIS_III_5(); //5. Write a program to create an integer array and allow the user to find a value from the list. Please follow the output format.
    void CS102_EXCIS_III_6(); //6. Write a program to store 6 different random numbers in the list between 10 to 20. Allow the user to find their lucky number in two tries.

    void CS102_EXCIS_II_1(); //1. Write a program to read a set of integer values and display the values in descending order and find the middle value in the list.
    void CS102_EXCIS_II_2(); //2. Write a program to create manipulation package. Allow the package to manage addition, subtraction, multiplication and division classes.
    void CS102_EXCIS_II_3(); //3. Write a program to create a student personal class and student grade_calculation class.

    //********************************************************************************************************************************
    //class declaration
    //********************************************************************************************************************************
    class Student {
    protected:
        std::string mName;
        unsigned int mRollno;
        std::string mCourse;
    public:
        Student(std::string sName, unsigned int iRollno, std::string sCourse);

        std::string GetName();
        unsigned int GetRollno();
        std::string GetCourse();

        void SetCourse(std::string sCourse);
    };

    enum Grade { None, Fail, Pass };

    struct PaperScore {
        std::string Paper;
        unsigned int Score;
        Grade Grade;
    };

    class StudentGrade : public Student {
    private:
        std::vector<PaperScore> mvcPaperScore;
        Grade mOverallGrade;
    public:
        StudentGrade(std::string sName, unsigned int iRollno, std::string sCourse);
        StudentGrade(std::string sName, unsigned int iRollno, std::string sCourse, const std::vector<PaperScore>& vcPaperScore);

        std::vector<PaperScore> GetPaperScore();
        Grade GetOverallGrade();

        bool AddPaperScore(const PaperScore tPaperScore);
        bool AddPaperScore(std::string sPaper, unsigned int iScore, Grade sGrade);
        Grade CalculateOverallGrade();
    };

    class Addition {
    public:
        Addition(int iVar1, int iVar2);
        Addition(double dVar1, double dVar2);
        Addition(double dVar1, double dVar2, double dVar3);
        double GetResult();
    private:
        double mResult;
    };

    class Subtraction {
    public:
        Subtraction(int iVar1, int iVar2);
        Subtraction(double dVar1, double dVar2);
        Subtraction(double dVar1, double dVar2, double dVar3);
        double GetResult();
    private:
        double mResult;
    };

    class Multiplication {
    public:
        Multiplication(int iVar1, int iVar2);
        Multiplication(double dVar1, double dVar2);
        double GetResult();
    private:
        double mResult;
    };

    class Division {
    public:
        Division(int iDividend, int iDivisor);
        Division(double dDividend, double dDivisor);
        double& GetResult();
    private:
        double mResult;
    };
} // end of namespace CS102_EXCIS  
#endif // CS102_EXCIS_H  