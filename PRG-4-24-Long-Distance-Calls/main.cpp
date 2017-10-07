//
//  main.cpp
//  PRG-4-24-Long-Distance-Calls
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  A long-distance carrier charges the following rates for telephone calls:
//
//  Starting Time of Call                   Rate per Minute
//  -----------------------------------------------------------------
//  00:00 - 06:59                           $0.05
//  07:00 - 19:00                           $0.45
//  19:01 - 23:59                           $0.20
//
//  Write a program that asks for the starting time and the number of minutes of the call,
//  and displays the charges. The program should ask for the time to be centered as a
//  floating-point number in the form HH.MM For example, 07:00 hours will be
//  entered as 7.00, and the 16:28 hours will be entered as 16.28.
//
//  Input Validation: The program should not accept times that are greater than 23:59. Also,
//  no number whose last two digits are greater than 59 should be accepted. Hint: Assuming
//  num is a floating-point variable, the following expression will give you its fractional part:
//
//  num - static_cast<int>(num)

#include <iostream>

using namespace std;

int main()
{
    float num = 1.55;
    float fractional;
    
    fractional = num - static_cast<int>(num);
    cout << fractional << endl << endl;
    
    int intUserTimeInputHours;
    
    float fltUserTimeInput,
          fltUserTimeInputMinutes,
          fltCallCost;
    
    const float FLT_RATE_PER_MINUTE_1 = 0.05f,
                FLT_RATE_PER_MINUTE_2 = 0.45f,
                FLT_RATE_PER_MINUTE_3 = 0.20f;
    
    cout << "Please enter a time value in the format HH.MM:\n";
    cin >> fltUserTimeInput;
    
    
    intUserTimeInputHours = fltUserTimeInput;
    
    fltUserTimeInputMinutes = fltUserTimeInput - static_cast<int>(fltUserTimeInput);
    
    if(fltUserTimeInputMinutes < 0.00f || fltUserTimeInputMinutes > 0.60f)
    {
        cout << "Please enter a valid time.";
        return 0;
    }
    else if(intUserTimeInputHours < 0 || intUserTimeInputHours > 24)
    {
        cout << "Please enter a valid time.";
        return 0;
    }
    
    if(intUserTimeInputHours <= 6)
    {
        fltCallCost = FLT_RATE_PER_MINUTE_1
                    * ((intUserTimeInputHours * 60)
                    + (fltUserTimeInputMinutes * 100.0f));
        cout << "The cost of your call "
             << fltUserTimeInput
             << " is $"
             << fltCallCost << endl;
    }
    else if(intUserTimeInputHours > 6 && intUserTimeInputHours <= 19)
    {
        fltCallCost = FLT_RATE_PER_MINUTE_2
                    * ((intUserTimeInputHours * 60)
                    + (fltUserTimeInputMinutes * 100.0f));
        cout << "The cost of your call "
             << fltUserTimeInput
             << " is $"
             << fltCallCost << endl;
    }
    else if(intUserTimeInputHours > 19 && intUserTimeInputHours <= 23)
    {
        fltCallCost = FLT_RATE_PER_MINUTE_3
                    * ((intUserTimeInputHours * 60)
                    + (fltUserTimeInputMinutes * 100.0f));
        cout << "The cost of your call "
             << fltUserTimeInput
             << " is $"
             << fltCallCost << endl;
    }
    else
    {
        cout << "ERROR CALCULATING CALL COST\n";
    }
    
    return 0;
}