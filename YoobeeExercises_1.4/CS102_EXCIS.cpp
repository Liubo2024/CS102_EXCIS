// CS102_EXCIS.cpp : 

#include "CS102_EXCIS.h" 

using namespace std;

namespace CS102_EXCIS {
    //********************************************************************************************************************************
    //function implementation
    //********************************************************************************************************************************
    bool CheckIsInt(double d) {
        // check in the range of Integer
        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
            return false;

        // check is not a float or double type 
        if (d != static_cast<int>(d))
            return false;

        return true;
    }

    bool CheckIsInt(string s) {
        //Check if it matches a numeric value.
        std::regex regx("^[-]?[0-9]+(\\.[0-9]+)?$");
        if (!std::regex_match(s, regx))
            return false;

        double d = std::stod(s);

        // check is not a float or double type 
        if (d != static_cast<int>(d))
            return false;

        // check in the range of Integer
        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
            return false;

        return true;
    }

    int InputInteger(string sPrompt) {
        return InputInteger(sPrompt, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), true);
    }

    int InputInteger(string sPrompt, int iMin) {
        return InputInteger(sPrompt, iMin, std::numeric_limits<int>::max(), true);
    }

    int InputInteger(string sPrompt, int iMin, int iMax) {
        return InputInteger(sPrompt, iMin, iMax, true);
    }

    int InputInteger(string sPrompt, int iMin, int iMax, bool bZeroAllowed) {
        //e.g. iMin = 0 for Whole Number, or 1 for Positive Integer.
        int n = 0;
        string sInput = "";
        cout << sPrompt;
        while (true)
        {
            getline(cin, sInput);

            if (!CheckIsInt(sInput)) {
                cin.clear();
                //cin.ignore(); //Clearing the newline character (\n) after cin
                cout << "Please provide an integer value: ";
                continue;
            }

            try {
                n = std::stoi(sInput);
            }
            catch (const std::invalid_argument& e) {
                cout << "Please provide an integer value: ";
                continue;
            }
            catch (const std::out_of_range& e) {
                cout << "The input number exceeds the range of an integer: ";
                continue;
            }

            if (n < iMin || n > iMax) {
                if (iMin != std::numeric_limits<int>::min() && iMax != std::numeric_limits<int>::max())
                    cout << "Please provide an integer value (between " + to_string(iMin) + " and " + to_string(iMax) + "): ";
                else if (iMin != std::numeric_limits<int>::min())
                    cout << "Please provide an integer value greater than " + to_string(iMin - 1) + ": ";
                else if (iMax != std::numeric_limits<int>::max())
                    cout << "Please provide an integer value less than " + to_string(iMin + 1) + ": ";
                else
                    cout << "Please provide an integer value: ";
                continue;
            }
            else if (n == 0 && !bZeroAllowed) {
                cout << "Please enter a non-zero integer.";
                continue;
            }
            else {
                cin.clear();
                //cin.ignore(); //Clearing the newline character (\n) after cin
                return n;
            }
        }
    }

    string InputString(string sPrompt = "Enter a value: ") {
        string s = "";
        cout << sPrompt;
        std::getline(cin, s);
        cin.clear();
        return s;
    }

    string PadWithSpaces(const std::string& s, unsigned int len) {
        string result = s;
        while (result.length() < len) {
            result += ' ';
        }
        return result;
    }

    string PadWithSpaces(const int& i, unsigned int len) {
        string result = to_string(i);
        return PadWithSpaces(result, len);
    }

    void QuickSort(std::vector<int>& vcArr, int iLow, int iHigh) {
        if (iLow < iHigh) {
            // get the index of the pivot after partitioning. 
            int i = iLow - 1;
            for (int j = iLow; j <= iHigh - 1; ++j)
                if (vcArr[j] <= vcArr[iHigh])
                    if (++i != j)
                        std::swap(vcArr[i], vcArr[j]);
            std::swap(vcArr[i + 1], vcArr[iHigh]);

            int pi = i + 1;

            // Recursively sort the elements on the left and right sides of the pivot.
            QuickSort(vcArr, iLow, pi - 1);
            QuickSort(vcArr, pi + 1, iHigh);
        }
    }

    void QuickSort(std::vector<int>& vcArr, bool bAscending = true) {
        QuickSort(vcArr, 0, vcArr.size() - 1);
        if (bAscending != true) //Descending
            for (int i = 0, j = vcArr.size() - 1; i < j; ++i, --j)
                std::swap(vcArr[i], vcArr[j]);
    }

    //********************************************************************************************************************************
    //function implementation
    //********************************************************************************************************************************
    void CS102_EXCIS_I_1() { //1. Evaluate the expression: Z = ax +(b-c)(c-d)/y 
        cout << "      \"Z = ax +(b-c)(c-d)/y\"" << endl;

        int a = InputInteger("Enter a value (e.g. 10841): "),
            b = InputInteger("Enter b value (e.g. 3): "),
            c = InputInteger("Enter c value (e.g. 2): "),
            d = InputInteger("Enter d value (e.g. 1): "),
            x = InputInteger("Enter x value (e.g. 7): "),
            y = InputInteger("Enter y value (e.g. 1): ");

        while (y == 0)
            y = InputInteger("Please enter a non-zero value: ");

        int Z = a * x + (b - c) * (c - d) / y;
        cout << "      Z = " << Z << endl;
    }

    void CS102_EXCIS_I_2() { //2. Write a program to find smallest of three numbers.
        int arrVar1[3] = { 0 };
        struct InputList {
            char m_Char;
            int m_Input;
        } arrVar2[3] = { 0 };

        for (int i = 0; i < 3; i++) {
            arrVar1[i] = InputInteger("Enter " + string(1, ('A' + i)) + " value: ");
            arrVar2[i] = { (char)('A' + i) , arrVar1[i] };
        }

        std::sort(arrVar1, arrVar1 + sizeof(arrVar1) / sizeof(arrVar1[0]));

        for (int i = 0; i < 3; i++) {
            if (arrVar2[i].m_Input == arrVar1[0]) {
                cout << "      \"" << arrVar2[i].m_Char << " is smallest.\"" << endl;
                break;
            }
        }
    }

    void CS102_EXCIS_I_3() { //3. Write a program to find a given number is prime or not. Read a number from user and display as per the output format.
        cout << "  Prime Check" << endl
            << "  **********" << endl;
        int fVar1 = InputInteger("Enter a number: ", 0);
        bool blnVar2 = true; // true means it's a prime number
        if (fVar1 < 2)
            blnVar2 = false;
        else
            for (int i = 2; i * i <= fVar1; ++i)
                if ((int)fVar1 % i == 0)
                    blnVar2 = false;

        cout << "      \"" << fVar1 << " is " << (blnVar2 ? "" : "not ") << "a prime number.\"" << endl;
    }

    void CS102_EXCIS_I_4() { //4. Write a program to generate even numbers between two different values. Proceed to verify the given inputs are not null.
        cout << "Even Number Generation" << endl
            << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
        int fStarting = InputInteger("Enter starting number: ", 1),
            fEnding = InputInteger("Enter final number: ", 1);
        if (fStarting > fEnding)
            cout << "The starting number should be less than or equal to the ending number. Please re-enter." << endl;
        else {
            cout << "Even list between " << fStarting << " and " << fEnding << ": ";

            string strOut = "";
            for (int i = fStarting; i <= fEnding; ++i)
                if (i % 2 == 0) // check if it is a even number or not.
                    strOut.append(", " + to_string(i));
            if (strOut != "")
                cout << strOut.substr(2) << endl;
        }
    }

    void CS102_EXCIS_I_5() { //5. Write a program to generate an odd list between 20 to 47 and count number of odds in the list.Display your result as per the output format.
        int j = 0;
        string strOut = "";
        for (int i = 20; i <= 47; ++i) {
            if (i % 2 != 0) {// check if it is a odd number or not.
                strOut.append(", " + to_string(i));
                ++j;
            }
        }

        cout << "Odd list between 20 to 47: " << strOut.substr(2) << endl
            << "Number of Odds between 20 to 47: " << j << endl;
    }

    void CS102_EXCIS_I_6() { //6. Write a program to generate Fibonacci series as per the user input. 
        int n = InputInteger("Enter the length of Fibonacci series: ", 2);
        vector<int> vcFibonacci(n + 1);
        vcFibonacci[0] = 0;
        vcFibonacci[1] = 1;
        for (int i = 2; i <= n; ++i) {
            vcFibonacci[i] = vcFibonacci[i - 1] + vcFibonacci[i - 2];
            (i == 2 ? cout << vcFibonacci[1] << "," << vcFibonacci[2] : cout << "," << vcFibonacci[i]);
        }

    }

    void CS102_EXCIS_I_7() { //7. Write a program to read a number from user, find factorial for the given number and display as like,
        int n = InputInteger("Enter a value: ", 1);
        long long int iFactorial = 1;

        for (int i = 1; i <= n; ++i)
            iFactorial = i * iFactorial;
        cout << "Factorial of " << n << " is " << to_string(iFactorial) << endl;
    }

    void CS102_EXCIS_I_8() { //8. Write a program to display the pattern below as per the user input. 
        for (int i = 1, n = InputInteger("Enter a value: ", 1), iNumerator = 0; i <= n; ++i) {
            (i == 1 || i == 2 ? iNumerator = 1 : iNumerator = iNumerator * 2);
            (i == 1 ? cout << "1" : (i % 2 == 0 ? cout << " - " : cout << " + "));
            (i == 1 ? cout << "" : cout << iNumerator << "/" << iNumerator * 2);
        }
    }

    void CS102_EXCIS_I_9() { //9. Write a program to read a value from user and display the place value.
        struct NumberList {
            string m_Str;
            int m_Num;
        } arrVar1[4] = { " Thousand", 0, " Hundred", 0, " Ten", 0, " One", 0 };

        int n = InputInteger("Enter a value: ", 0, 9999);
        string strOut = "";
        for (int i = 1000, j = 0; i > 0; i = i / 10, ++j) {
            arrVar1[j].m_Num = n / i;
            n = n - arrVar1[j].m_Num * i;
            strOut.append(", " + to_string(arrVar1[j].m_Num) + arrVar1[j].m_Str);
        }
        cout << "  \"" << strOut.substr(2) << "\"" << endl;
    }

    void CS102_EXCIS_I_10() { //10. Write a program to generate the following pattern
        int n = InputInteger("Enter a value: ", 1);
        string strOut1 = "1", strOut2 = "1", strOut3 = "1";
        for (int i = 2; i <= n; ++i) {
            (i % 3 == 0 ? strOut1.append(" + " + to_string(i)) : "");
            strOut2.append(" + " + to_string(i - 1) + "/" + to_string(i));
            (i % 2 == 0 ? strOut3.append(" + 1/" + to_string(i)) : strOut3.append(" - 1/" + to_string(i)));
        }
        strOut2.append(" + " + to_string(n) + "/" + to_string(n + 1));
        cout << strOut1 << endl
            << strOut2 << endl
            << strOut3 << endl;
    }

    void CS102_EXCIS_I_11() { //11. Write a program to read the first name and last name. Validate the user inputs as follows: • Verify first name and last name are different • Verify the name contains only alphabets 
        string sFirstName = "", sLastName = "";
        regex oRegex("^[A-Za-z]*$");
        cout << "First name: ";
        while (cin >> sFirstName && !regex_match(sFirstName, oRegex))
            cout << "\"Please provide only letters \"" << endl << "First name: ";

        cout << "Last name: ";
        while (cin >> sLastName && !regex_match(sLastName, oRegex))
            cout << "\"Please provide only letters \"" << endl << "Last name: ";

        (sFirstName == sLastName ? cout << "\" Please provide different surname \"" : cout << "\" Hi " << sFirstName << " " << sLastName << " \"");
    }

    void CS102_EXCIS_I_12() { //12. Write a program to read a sentence and display. Count number of words, special characters and vowels in the sentence and display as follows,
        string sSentence = "";
        cout << "Enter your sentence here: ";
        std::getline(cin, sSentence);
        cout << "Given sentence: \"" << sSentence << "\"" << endl;

        int iCountSpace = 0, iCountAlpha = 0, iCountSpecial = 0, iCountVowel = 0;
        bool bIsPrevSpace = false;
        for (char c : sSentence) {
            if (c == ' ') {
                (bIsPrevSpace ? 0 : ++iCountSpace);
                bIsPrevSpace = true;
            }
            else {
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                    ++iCountAlpha;
                    if ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ||
                        (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'))
                        ++iCountVowel;
                }
                else
                    ++iCountSpecial;
                bIsPrevSpace = false;
            }
        }

        cout << "Special characters: " << iCountSpecial << endl;
        cout << "Words: " << to_string(iCountSpace + 1) << endl;
        cout << "Vowels: " << iCountVowel << endl;
    }

    void CS102_EXCIS_I_13() { //13. write a program to generate 10 random numbers as per the user input range. Count number of repeated numbers in the list and display.
        int iMin = 1, iMax = InputInteger("Enter a number: ", iMin), arrRand[10] = { 0 }, arrSorted[10] = { 0 };
        srand(static_cast<unsigned int>(time(nullptr)));
        for (int i = 0; i < 10; ++i) {
            arrRand[i] = iMin + rand() % (iMax - iMin + 1);
            arrSorted[i] = arrRand[i];
            (i == 0 ? cout << "List: " + to_string(arrRand[i]) : cout << ", " + to_string(arrRand[i]));
        }
        cout << endl;

        std::sort(arrSorted, arrSorted + sizeof(arrSorted) / sizeof(arrSorted[0]));
        for (int i = 0; i < 10; ++i)
            (i == 0 ? cout << "Sorted list: " + to_string(arrSorted[i]) : cout << ", " + to_string(arrSorted[i]));
        cout << endl;

        int i = 0, j = 0;
        for (i = 1; i < 10; ++i) {
            if (arrSorted[i] == arrSorted[i - 1])
                ++j;
            else {
                if (j > 0)
                    cout << "Repeat: " << to_string(arrSorted[i - 1]) << " repeats " << to_string(j + 1) << " times" << endl;
                j = 0;
            }
        }
        if (j > 0)
            cout << "Repeat: " << to_string(arrSorted[i - 1]) << " repeats " << to_string(j + 1) << " times" << endl;
    }

    void CS102_EXCIS_I_14() { //14. write a program to create an integer array of size 10 and display. Count number of even numbers and number of odds in the list and display as follows
        float arrNumbers[10] = { 0 };
        for (int i = 0; i < 10; ++i)
            arrNumbers[i] = InputInteger("Enter 10 numbers, now it's the " + to_string(i + 1) + " of 10: ", 1);

        string sTenNumbers = "", sEvenNumbers = "", sOddNumbers = "";
        int iEvenNumbers = 0, iOddNumbers = 0;
        for (int i = 0; i < 10; ++i) {
            (i == 0 ? sTenNumbers.append("Enter 10 values: " + to_string((int)arrNumbers[i])) : sTenNumbers.append("," + to_string((int)arrNumbers[i])));
            if ((int)arrNumbers[i] % 2 == 0)
                (++iEvenNumbers == 1 ? sEvenNumbers.append("Even List: " + to_string((int)arrNumbers[i])) : sEvenNumbers.append("," + to_string((int)arrNumbers[i])));
            else
                (++iOddNumbers == 1 ? sOddNumbers.append("Odd List: " + to_string((int)arrNumbers[i])) : sOddNumbers.append("," + to_string((int)arrNumbers[i])));
        }
        cout << sTenNumbers << "." << endl
            << sEvenNumbers << endl
            << sOddNumbers << endl
            << "No. of Evens: " << to_string(iEvenNumbers) << endl
            << "No. of Odds: " << to_string(iOddNumbers) << endl;
    }

    void CS102_EXCIS_I_15() { //15. write a program to read 5 different double values and store in an array called double list.Sort the array elements and display the sorted list.
        float arrNumbers[5] = { 0 }, arrSorted[5] = { 0 };
        for (int i = 0; i < 5; ++i) {
            cout << "Enter 5 double values, now it's the " << to_string(i + 1) << " of 5: ";
            while (cin >> arrNumbers[i] && (arrNumbers[i] <= 0))
                cout << "Please provide a double value which is greater than 0: ";

            arrSorted[i] = arrNumbers[i];
        }
        std::sort(arrSorted, arrSorted + sizeof(arrSorted) / sizeof(arrSorted[0]));
        string sGivenList = "", sSortedList = "", sTemp = "";
        std::regex oRegexPattern("0+$");

        for (int i = 0; i < 5; ++i) {
            sTemp = regex_replace(to_string(arrNumbers[i]), oRegexPattern, "");
            (sTemp.back() == '.' ? sTemp += "0" : "");
            (i == 0 ? sGivenList.append("Given list: " + sTemp) : sGivenList.append(", " + sTemp));

            sTemp = regex_replace(to_string(arrSorted[i]), oRegexPattern, "");
            (sTemp.back() == '.' ? sTemp += "0" : "");
            (i == 0 ? sSortedList.append("Sorted list: " + sTemp) : sSortedList.append(", " + sTemp));
        }
        cout << sGivenList << endl
            << sSortedList << endl;
    }

    void CS102_EXCIS_III_1() { //1. Write a program to display the following. Allow the user to provide input as like,
        for (int i = 1, n = 1; i <= 5; cout << endl, n += 2, ++i)
            for (int j = 1; j <= n; cout << "* ", ++j);
    }

    void CS102_EXCIS_III_2() { //2. Write a program to generate multiplication times table as like,
        cout << "  Multiplication Table" << endl
            << "  ********************" << endl;
        for (int i = 1; i <= 10; cout << endl, ++i)
            for (int j = i; j <= i * 10; cout << to_string(j) + " ", j += i);
    }

    void CS102_EXCIS_III_3() { //3. Write a program to generate multiplication times table as per the user input.
        int n = InputInteger("Enter a number: ", 1);

        cout << "Multiplication Table:" + to_string(n) << endl
            << "************************" << endl;
        for (int i = 1; i <= 10; cout << to_string(i) + " X " + to_string(n) + " = " + to_string(i * n) << endl, ++i);
    }

    void CS102_EXCIS_III_4a() { //4. Write a program to print the following, a) 
        for (int i = 1; i <= 4; cout << endl, ++i)
            for (int j = 1; j <= i; cout << "* ", ++j);
    }

    void CS102_EXCIS_III_4b() { //4. Write a program to print the following, b) 
        for (int i = 1; i <= 4; cout << endl, ++i)
            for (int j = 1; j <= i; cout << to_string(j) + " ", ++j);
    }

    void CS102_EXCIS_III_4c() { //4. Write a program to print the following, c) 
        for (int i = 1; i <= 4; cout << endl, ++i)
            for (int j = 1; j <= i; cout << to_string(i) + " ", ++j);
    }

    void CS102_EXCIS_III_4d() { //4. Write a program to print the following, d) 
        CS102_EXCIS_III_4a();
        for (int i = 3; i >= 1; cout << endl, --i)
            for (int j = 1; j <= i; cout << "* ", ++j);
    }

    void CS102_EXCIS_III_4e() { //4. Write a program to print the following, e) 
        string s = "";
        for (int i = 1; i <= 4; cout << endl, ++i, s = "")
            for (int j = 1; j <= i; (j == 1 ? cout << s.append(4 - i, ' ') << "* " : cout << "* "), ++j);
    }

    void CS102_EXCIS_III_4f() { //4. Write a program to print the following, f) 
        for (int i = 1; i <= 5; cout << endl, ++i)
            for (int j = 1; j <= i; (i % 2 != 0 ? cout << "* " : cout << "~ "), ++j);
    }

    void CS102_EXCIS_III_5() { //5. Write a program to create an integer array and allow the user to find a value from the list. Please follow the output format.
        int arrVar1[6] = { 0 };
        string strOut1 = "";

        for (int i = 0; i < 6; ++i) {
            arrVar1[i] = InputInteger("Enter a[" + to_string(i) + "] value: ");

            if (i == 0)
                strOut1.append("Given list: " + to_string(arrVar1[i]));
            else if (i == 5)
                strOut1.append(" and " + to_string(arrVar1[i]) + ".");
            else
                strOut1.append(", " + to_string(arrVar1[i]));
        }

        int n = InputInteger("Enter your search value: ");

        strOut1 = "Search Result: Not found.";
        for (int i = 0; i < 6; ++i) {
            if (arrVar1[i] == n) {
                strOut1 = "Search Result: your value is located in " + to_string(i + 1) + "th place .";
                break;
            }
        }
        cout << strOut1 << endl;
    }

    void CS102_EXCIS_III_6() { //6. Write a program to store 6 different random numbers in the list between 10 to 20. Allow the user to find their lucky number in two tries.
        const int iMin = 10, iMax = 20;
        int i = 0, j = 0, arrRand[6] = { 0 }, intLuckyNum;
        string strOut1 = "";

        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        for (i = 0; i < 6; strOut1.append((i == 0 ? to_string(arrRand[i]) : ", " + to_string(arrRand[i]))), ++i)
            arrRand[i] = iMin + rand() % (iMax - iMin + 1);

        //cout << "Given list: " << strOut1 << endl; // for testing

        for (i = 0; i < 2; ++i) {
            intLuckyNum = InputInteger("Try " + to_string(i + 1) + ": Enter your lucky number (between 10 and 20): ", 10, 20);

            for (j = 0; j < 6 && arrRand[j] != intLuckyNum; ++j);
            if (j < 6)
                break;
            else
                cout << "Sorry, that's not your lucky number." << endl;
        }

        if (i < 2)
            cout << "Congratulations! You found your lucky number on try " << (i + 1) << "." << endl;
        cout << "Given list: " << strOut1 << endl;
    }

    void CS102_EXCIS_II_1() { //1. Write a program to read a set of integer values and display the values in descending order and find the middle value in the list.
        vector<int> vcVar1;
        int iSize = InputInteger("Enter your list size: ", 1);
        string strOut1 = "", strOut2 = "";
        for (int i = 0; i < iSize; ++i) {
            vcVar1.push_back(InputInteger("Enter list[" + to_string(i) + "] value:", 1));
            strOut1.append((i == 0 ? "Given list: " + to_string(vcVar1[i]) : ", " + to_string(vcVar1[i])));
        }
        QuickSort(vcVar1, false); //Descending
        for (int i = 0; i < iSize; ++i)
            strOut2.append((i == 0 ? "Sorted list: " + to_string(vcVar1[i]) : ", " + to_string(vcVar1[i])));
        cout << strOut1 << endl << strOut2 << endl << "Middle value: " << vcVar1[(int)(iSize / 2)];
    }

    void CS102_EXCIS_II_2() { //2. Write a program to create manipulation package. Allow the package to manage addition, subtraction, multiplication and division classes.
        cout << "*****Basic Arithmetic Operations*****" << endl
            << "1. Addition" << endl << "2. Subtraction" << endl << "3. Multiplication" << endl << "4. Division" << endl;
        unsigned int iChoice = InputInteger("Please choose an operation: ", 1, 4);
        int iValue1 = InputInteger("Enter two integers for addition. Integer[1]: ");
        int iValue2 = InputInteger("Enter two integers for addition. Integer[2]: "
            , std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), (iChoice == 4 ? false : true));

        switch (iChoice) {
        case 1: {
            Addition oAddition(iValue1, iValue2);
            cout << "Result: " << to_string(iValue1) << " + " << to_string(iValue2) << " = " << to_string((int)oAddition.GetResult()) << endl;
            break;
        }
        case 2: {
            Subtraction oSubtraction(iValue1, iValue2);
            cout << "Result: " << to_string(iValue1) << " - " << to_string(iValue2) << " = " << to_string((int)oSubtraction.GetResult()) << endl;
            break;
        }
        case 3: {
            Multiplication oMultiplication(iValue1, iValue2);
            cout << "Result: " << to_string(iValue1) << " * " << to_string(iValue2) << " = " << to_string((int)oMultiplication.GetResult()) << endl;
            break;
        }
        case 4: {
            try {
                Division oDivision(iValue1, iValue2);
                double dResult = oDivision.GetResult();
                cout << "Result: " << to_string(iValue1) << " / " << to_string(iValue2) << " = " << std::fixed << std::setprecision(2) << dResult << endl;
                break;
            }
            catch (std::runtime_error& e) {
                cout << "Exception handling: " << e.what() << " Exit the application automatically." << endl;
                break;
            }

        }
        default:
            cout << "Invalid choice!" << std::endl;
        }
    }

    void CS102_EXCIS_II_3() { //3. Write a program to create a student personal class and student grade_calculation class.
        cout << "Please enter the student's information." << endl;

        string sName = InputString("Name: ");
        unsigned int iRollno = InputInteger("Rollno: ", 1);
        string sCourse = InputString("Course: ");

        StudentGrade oStudentGrade(sName, iRollno, sCourse);

        cout << "Please enter the scores for 3 papers." << endl;
        int i = 0;
        while (i < 3) {
            string sPaper = InputString("Paper[" + to_string(i) + "]: ");
            unsigned int iScore = InputInteger("Score: ", 1);
            Grade eGrade = (iScore < 50 ? Fail : Pass);
            if (oStudentGrade.AddPaperScore(sPaper, iScore, eGrade))
                i++;
            else
                cout << "The paper already exists, please enter another one." << endl;
        }
        oStudentGrade.CalculateOverallGrade();

        vector<PaperScore> vcPaperScore = oStudentGrade.GetPaperScore();
        cout << "          " + oStudentGrade.GetName() + "'s Mark Sheet" << endl;
        cout << "Name          :" + oStudentGrade.GetName() << endl;
        cout << "Rollno        :" + to_string(oStudentGrade.GetRollno()) << endl;
        cout << "Course        :" + oStudentGrade.GetCourse() << endl;
        cout << "Paper                  Score                  Grade" << endl;
        cout << "***************************************************" << endl;
        for (int i = 0; i < vcPaperScore.size(); ++i) {
            cout << PadWithSpaces(vcPaperScore[i].Paper, 23)
                + PadWithSpaces(vcPaperScore[i].Score, 23)
                + PadWithSpaces((vcPaperScore[i].Grade == Fail ? "Fail" : "Pass"), 23) << endl;
        }
        switch (oStudentGrade.GetOverallGrade()) {
        case 0:
            cout << "Overall grade: None" << endl;
            break;
        case 1:
            cout << "Overall grade: Fail" << endl;
            break;
        case 2:
            cout << "Overall grade: Pass" << endl;
        }
    }

    //********************************************************************************************************************************
    //class implementation
    //********************************************************************************************************************************
    Student::Student(string sName, unsigned int iRollno, string sCourse) :mName(sName), mRollno(iRollno), mCourse(sCourse) {}

    string Student::GetName() { return mName; }
    unsigned int Student::GetRollno() { return mRollno; }
    string Student::GetCourse() { return mCourse; }

    void Student::SetCourse(string sCourse) { mCourse = sCourse; }

    StudentGrade::StudentGrade(string sName, unsigned int iRollno, string sCourse)
        :Student(sName, iRollno, sCourse) {
        this->mvcPaperScore = {};
        this->mOverallGrade = None;
    }

    StudentGrade::StudentGrade(string sName, unsigned int iRollno, string sCourse, const std::vector<PaperScore>& vcPaperScore)
        :Student(sName, iRollno, sCourse), mvcPaperScore(vcPaperScore) {
        this->mOverallGrade = None;
    }

    vector<PaperScore> StudentGrade::GetPaperScore() { return this->mvcPaperScore; }
    Grade StudentGrade::GetOverallGrade() { return this->mOverallGrade; }


    bool StudentGrade::AddPaperScore(const PaperScore tPaperScore) {
        for (auto item : this->mvcPaperScore)
            if (item.Paper == tPaperScore.Paper)
                return false; //duplicated
        mvcPaperScore.push_back(tPaperScore);
        return true;
    }

    bool StudentGrade::AddPaperScore(string sPaper, unsigned int iScore, Grade sGrade) {
        PaperScore tPaperScore = { sPaper, iScore, sGrade };
        return AddPaperScore(tPaperScore);
    }

    Grade StudentGrade::CalculateOverallGrade() {
        this->mOverallGrade = None;
        for (int i = 0; i < this->mvcPaperScore.size(); ++i) {
            this->mOverallGrade = this->mvcPaperScore[i].Grade;
            if (this->mvcPaperScore[i].Grade == Fail)
                break;
        }
        return this->mOverallGrade;
    }

    Addition::Addition(int iVar1, int iVar2) : mResult(iVar1 + iVar2) {}
    Addition::Addition(double dVar1, double dVar2) : mResult(dVar1 + dVar2) {}
    Addition::Addition(double dVar1, double dVar2, double dVar3) : mResult(dVar1 + dVar2 + dVar3) {}
    double Addition::GetResult() { return mResult; }

    Subtraction::Subtraction(int iVar1, int iVar2) : mResult(iVar1 - iVar2) {}
    Subtraction::Subtraction(double dVar1, double dVar2) : mResult(dVar1 - dVar2) {}
    Subtraction::Subtraction(double dVar1, double dVar2, double dVar3) : mResult(dVar1 - dVar2 - dVar3) {}
    double Subtraction::GetResult() { return mResult; }

    Multiplication::Multiplication(int iVar1, int iVar2) : mResult(iVar1* iVar2) {}
    Multiplication::Multiplication(double dVar1, double dVar2) : mResult(dVar1* dVar2) {}
    double Multiplication::GetResult() { return mResult; }

    Division::Division(int iDividend, int iDivisor) {
        if (iDivisor == 0)
            throw std::runtime_error("The divisor cannot be zero.");
        else
            mResult = (double)iDividend / iDivisor;
    }
    Division::Division(double dDividend, double dDivisor) {
        if (dDivisor == 0)
            throw std::runtime_error("The divisor cannot be zero.");
        else
            mResult = dDividend / dDivisor;
    }
    double& Division::GetResult() { return mResult; }

}// end of namespace CS102_EXCIS  
