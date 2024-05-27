// YoobeeExercises_1.4.cpp : 
#include "CS102_EXCIS.h"  
using namespace std;
using namespace CS102_EXCIS;

int main() {
    std::cout << "*****Yoobee CS102 Exercises*****" << endl
        << "      1: CS102_EXCIS_I_1(); " << endl
        << "      2: CS102_EXCIS_I_2(); " << endl
        << "      3: CS102_EXCIS_I_3(); " << endl
        << "      4: CS102_EXCIS_I_4(); " << endl
        << "      5: CS102_EXCIS_I_5(); " << endl
        << "      6: CS102_EXCIS_I_6(); " << endl
        << "      7: CS102_EXCIS_I_7(); " << endl
        << "      8: CS102_EXCIS_I_8(); " << endl
        << "      9: CS102_EXCIS_I_9(); " << endl
        << "     10: CS102_EXCIS_I_10(); " << endl
        << "     11: CS102_EXCIS_I_11(); " << endl
        << "     12: CS102_EXCIS_I_12(); " << endl
        << "     13: CS102_EXCIS_I_13(); " << endl
        << "     14: CS102_EXCIS_I_14(); " << endl
        << "     15: CS102_EXCIS_I_15(); " << endl

        << "     16: CS102_EXCIS_II_1(); " << endl
        << "     17: CS102_EXCIS_II_2(); " << endl
        << "     18: CS102_EXCIS_II_3(); " << endl

        << "     19: CS102_EXCIS_III_1(); " << endl
        << "     20: CS102_EXCIS_III_2(); " << endl
        << "     21: CS102_EXCIS_III_3(); " << endl
        << "     22: CS102_EXCIS_III_4a(); " << endl
        << "     23: CS102_EXCIS_III_4b(); " << endl
        << "     24: CS102_EXCIS_III_4c(); " << endl
        << "     25: CS102_EXCIS_III_4d(); " << endl
        << "     26: CS102_EXCIS_III_4e(); " << endl
        << "     27: CS102_EXCIS_III_4f(); " << endl
        << "     28: CS102_EXCIS_III_5(); " << endl
        << "     29: CS102_EXCIS_III_6(); " << endl;

    int iChoice = InputInteger("Please choose an exercise: ", 1, 29);

    switch (iChoice) {
    case 1: CS102_EXCIS_I_1(); break;
    case 2: CS102_EXCIS_I_2(); break;
    case 3: CS102_EXCIS_I_3(); break;
    case 4: CS102_EXCIS_I_4(); break;
    case 5: CS102_EXCIS_I_5(); break;
    case 6: CS102_EXCIS_I_6(); break;
    case 7: CS102_EXCIS_I_7(); break;
    case 8: CS102_EXCIS_I_8(); break;
    case 9: CS102_EXCIS_I_9(); break;
    case 10: CS102_EXCIS_I_10(); break;
    case 11: CS102_EXCIS_I_11(); break;
    case 12: CS102_EXCIS_I_12(); break;
    case 13: CS102_EXCIS_I_13(); break;
    case 14: CS102_EXCIS_I_14(); break;
    case 15: CS102_EXCIS_I_15(); break;
    case 16: CS102_EXCIS_II_1(); break;
    case 17: CS102_EXCIS_II_2(); break;
    case 18: CS102_EXCIS_II_3(); break;
    case 19: CS102_EXCIS_III_1(); break;
    case 20: CS102_EXCIS_III_2(); break;
    case 21: CS102_EXCIS_III_3(); break;
    case 22: CS102_EXCIS_III_4a(); break;
    case 23: CS102_EXCIS_III_4b(); break;
    case 24: CS102_EXCIS_III_4c(); break;
    case 25: CS102_EXCIS_III_4d(); break;
    case 26: CS102_EXCIS_III_4e(); break;
    case 27: CS102_EXCIS_III_4f(); break;
    case 28: CS102_EXCIS_III_5(); break;
    case 29: CS102_EXCIS_III_6(); break;
    default: break;
    }
    return 0;
}