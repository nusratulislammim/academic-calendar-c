

#include <stdio.h>
#include <conio.h> // for _getch() function
#include <stdlib.h> // for system("cls")

// Function to check if a year is a leap year
int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

// Function to find the day of the week for a given date (Zeller's Congruence)
int dayOfWeek(int year, int month, int day) {
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

// Function to print the calendar for a given month and year
void printCalendar(int year, int month) {
    // Array to store the number of days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check for leap year
    if (isLeapYear(year)) {
        daysInMonth[1] = 29; // February has 29 days in a leap year
    }

    // Print the month and year
    printf("   -------------- %d / %d --------------\n", month, year);
    printf("   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Calculate the day of the week for the first day of the month
    int startDay = dayOfWeek(year, month, 1);

    // Print leading spaces until the first day of the month
    for (int i = 0; i < startDay; i++) {
        printf("     ");
    }

    // Print the days of the month
    for (int day = 1; day <= daysInMonth[month - 1]; day++) {
        int color = 0; // Default color is white

        // Apply color based on specified dates
        if ((dayOfWeek(year, month, day) == 5) || (dayOfWeek(year, month, day) == 6)) {
            color = 2; // Friday and Saturday (green)
        } else if (year == 2023){
            if (month == 9) {
            if(day==5){
            color = 5; // 5 September (purple)
            }
            if(day==13 || day==28){
                color = 2;
            }

            }

            if( (month == 9 && (day >= 24 && day<=27)) || (month == 10 && day <=5)){
                color = 3;// 1st mid 1st semester (24 sep - 5 oct)(yellow)
            }
            if(day==13 && day==28){
                color = 2;
            }

         else if (month == 10){
            if(day >= 29) {
            color = 4; // 12 October - 19 October (yellow)
            }
            if(day>=22 && day<=26){
                color = 2;
            }
         }

         else if (month == 11){

                if(day <= 9){
                    color = 4;// 29 oct - 9 nov (maganda)
                }

           if(day == 12){
                color = 2;
            }
            if(day >=29){
                color = 6;
            }
         }

         if( (month == 11 && day >= 26) || (month == 12 && day <=7)){
                color = 3;// 3st mid)
            }


            else if(month == 12){
                if(day>=17 && day<=31){
                color = 6;
            }
            }



        }





       else if( year == 2024){

            if(month == 1){
                if(day>=4){
                    color = 1; // 4 januyary - 8 february (red)
                }
            }

            else if(month == 2){
                if(day <= 8){
                    color = 1; // 4 januyary - 8 february (red)
                }
                if(day == 11){
                    color = 4; // 11 feb -(maganta)
                }
                if(day == 14){
                    color = 2; // 14 feb -(green)
                }
                if(day == 21){
                    color = 2; // 14 feb -(green)
                }
                if(day == 26){
                    color = 2; // 14 feb -(green)
                }

                if(day >= 25 && day != 26){
                    color = 3; //(yellow) - 1st mid 2nd semester
                }
            }

            else if(month == 3){
                    if(day <= 7){
                        color = 3;
                    }
                if(day == 24 || day == 27 || day == 28){
                    color = 4; // 2nd mid 2nd sem (magenta)
                }
                if(day == 17 || day == 25 || day == 26 || day == 31){
                    color = 2; // (green)
                }
            }

            else if(month == 4){
                if(day <=4){
                    color = 4;
                }
                if(day >= 7 && day <= 18){
                    color = 2; // 14 feb -(green)
                }
                if(day >= 28){
                    color = 4;
                }
            }

            else if(month == 5){
                    if(day == 1 || day == 22){
                    color = 2; // 1 may-(green)
                    if(day >=2 && day <= 9){
                    color = 4;
                }

                }

                if(day <=10 ){
                    color = 2;
                }
            if(day >=12 && day<=23 && day != 22){
                    color = 3; // (Yellow)
                }
                if(day >= 26){
                    color = 1;
                }
            }


            else if(month == 6){
                if(day <=27){
                    color = 1;
                }

            }
            else if(month == 7){
                if(day == 1){
                    color = 4;
                }
               if(day >= 21 ){
                    color = 3;
                }
                if(day == 8 || day == 17){
                    color = 2;
                }
            }

            else if(month == 8){
                if(day >=19 && day != 26 && day != 27){
                    color = 4;
                }
                if(day == 15 || day == 26 || day == 27){
                    color = 2;
                }
            }

            else if(month == 9){
                if(day >= 22){
                    color = 4;
                }
                 if(day == 30){
                    color = 6;
                }
                if(day == 4 || day == 16){
                    color = 2;
                }
            }
            else if(month == 10){
                if(day >= 1 && day <=8){
                    color = 6;
                }
                if(day >= 16 && day != 31){
                    color = 1;
                }
                if(day >=9 && day <= 15 || day ==31){
                    color = 2;
                }
            }


            else if(month == 11){
                if(day <= 21){
                    color = 1;
                }
            }

            else if(month == 12){
                if(day == 1){
                    color = 4;
                }
                if(day == 14 || day == 16){
                    color = 2;
                }
                else if(day >= 22 && day <= 26){
                    color = 2;
                }
            }


        }

        else if(year == 2025){

            if(month == 1){
                if(day >=1 && day<=9){
                    color = 3;
                }
            }

            else if(month == 2){
                if(day >=2 && day<=13){
                    color = 4;
                }
            }

            else if(month == 3){
                if(day >=10 && day<=20){
                    color = 4;
                }
                if(day >=27){
                    color = 2;
                }
                if(day==26){
                    color = 4;
                }

            }

            else if(month == 4){
                if(day <= 5){
                    color = 2;
                }
                if(day >=6 && day<=15){
                    color = 4;
                }
                if(day >= 16){
                    color = 1;
                }

            }
            else if(month == 5){
                if(day <= 26 ){
                    color = 1;
                }
            }
            else if(month == 6){
                if(day == 2 ){
                    color = 4;
                }

            }

            else if(month == 7){
                if(day >=22 && day<=29){
                    color = 3;
                }

            }
            else if(month == 8){
                if(day >=3 && day<=14){
                    color = 4;
                }


            }

            else if(month == 9){
                if(day >=7 && day<=16){
                    color = 4;
                }

            }
            else if(month == 11){
                if(day >=1){
                    color = 1;
                }

            }

            else if(month == 12){
                if(day<=4){
                    color = 1;
                }

            }


        }

        else if(year == 2026){

            if(month == 1){
                if(day == 4){
                    color = 4;
                }
                if(day >=18 && day<=28){
                    color = 3;
                }
            }

            else if(month == 3){
                if(day >=9 && day<=30){
                    color = 4;
                }
            }

            else if(month == 5){
                if(day >=3 && day<=14){
                    color = 4;
                }

                if(day >=17 && day<=31){
                    color = 6;
                }
            }
            else if(month == 6){
                if(day >= 3 ){
                    color = 1;
                }

            }

            else if(month == 7){
                if(day <= 6 ){
                    color = 1;
                }
                if(day == 22 ){
                    color = 4;
                }

            }
            else if(month == 8){
                if(day >=23 && day<=31){
                    color = 3;
                }


            }


            else if(month == 11){
                if(day >=11 && day<=22){
                    color = 4;
                }

            }



        }

        else if(year == 2027){

            if(month == 1){
                if(day >=10 && day<=20){
                    color = 4;
                }
            }
            else if(month == 2){
                if(day >= 2){
                    color = 1;
                }
            }

            else if(month == 3){
                if(day <= 3){
                    color = 1;
                }
                if(day == 15){
                    color = 4;
                }
            }

             else if(month == 4){
                if(day >=8 && day<=27){
                    color = 3;
                }
            }



            else if(month == 5){
                if(day >=16 && day<=26){
                    color = 4;
                }
            }

            else if(month == 7){
                if(day >=12 && day<=21){
                    color = 4;
                }
                if(day >=22 && day<=29){
                    color = 6;
                }

            }
            else if(month == 8){
                if(day >=2){
                    color = 1;
                }
            }
            else if(month == 9){
                if(day <=5){
                    color = 1;
                }

            }

        }














        // Apply color
        switch (color) {
            case 1: printf("\x1b[31m"); break; // red
            case 2: printf("\x1b[32m"); break; // green
            case 3: printf("\x1b[33m"); break; // yellow
            case 4: printf("\x1b[35m"); break; // magenta
            case 5: printf("\x1b[35m"); break; // purple
            case 6: printf("\x1b[36m"); break; // cyan
            default: printf("\x1b[0m"); break; // reset
        }

        printf("%5d", day);
        printf("\x1b[0m"); // Reset color

        // Move to the next line if it's the last day of the week (Saturday)
        if ((day + startDay) % 7 == 0 || day == daysInMonth[month - 1]) {
            printf("\n");
        }
    }
}

int main() {
    int year, month;

    // Input year and month from the user
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month: ");
    scanf("%d", &month);

    int ch;
    do {
        // Clear the console screen before printing the calendar for the new month
        system("cls");

        // Print the calendar
        printf("\x1b[36m");
        printf("              ACADEMIC CALENDAR\n");


        printCalendar(year, month);

        // print below the months

    // print below the months
    if(year==2023){
        if(month==9){
                printf("\x1b[35m");
                printf("\n5 September 2023 = Class start (1-1)\n");
                printf("\x1b[32m");
                printf("13 September 2023= Akhari Chahar Somba\n28 September 2023= Eid e-Milad-un Nabi\n");
                printf("\x1b[33m");
                printf("24 september - 5 october = First Mid Term Week (1-1)\n");

        }
        else if(month==10){
                printf("\x1b[33m");
                printf("24 september - 5 october = First Mid Term Week (1-1)\n");

                printf("\x1b[32m");
                printf("22-26 october 2023 = Sri Sri Durga Puja(Class and office off)\n");

                printf("\x1b[35m");
                printf("29 october - 9 november 2023 = 2nd Mid Term Week (1-1)\n");

        }
        else if(month==11){

            printf("\x1b[35m");
            printf("29 october - 9 november 2023 = 2nd Mid Term Week (1-1)\n");

            printf("\x1b[32m");//green
            printf("12 = Sri Shayama Puja\n");

            printf("\x1b[33m");
                printf("26 november - 7 december 2023 = 3nd Mid Term Week (1-1)\n");
        }
        else if(month==12){

            printf("\x1b[33m");
            printf("26 november - 7 december 2023 = 3nd Mid Term Week (1-1)\n");

            printf("\x1b[36m");
            printf("\n 17 - 31 December 2023 = off for Exam's Preparation (1-1)\n");
        }

    }

    else if(year == 2024){

        if(month == 1){
                printf("\x1b[31m");
            printf("\n4 January - 8 February 2024 = 1st year 1st semester Exam (1-1) \n");
        }
        else if(month == 2){
            printf("\x1b[31m");
            printf("\n4 January - 8 February 2024 = 1st year 1st semester Exam (1-1) \n");printf("\x1b[35m");
            printf("\n11 February 2024 = 2nd semester class start (1-2)\n");
            printf("\x1b[33m");
            printf("\n25 february - 7 march 2024 = 1st mid term week (1-2)\n");

            printf("\x1b[32m");
            printf("\n9 February 2024 = Shab-e-Meraj\n");
            printf("\n14 February 2024 = Shri shri sharashoti pura\n");
            printf("\n21 February 2024 = Language Martys's Day\n");
            printf("\n26 February 2024 = Shab-e-Barat\n");





      }
       else if(month == 3){
            printf("\x1b[33m");
            printf("\n25 february - 7 march 2024 = 1st mid term week (1-2)\n");
            printf("\x1b[35m");
            printf("\n24 march - 4 april 2024 = 2nd mid term week (1-2)\n");

            printf("\x1b[32m");
            printf("\n17 March 2024 = Sheikh Mujibur Rahman's Birthday\n national child day\n");
            printf("\n25 March 2024 = Doljatra\n");
            printf("\n26 March 2024 = Independence Day\n");
            printf("\x1b[32m");
            printf("\n31 March 2024 = Easter Sunday\n");





      }
      else if(month == 4){
            printf("\x1b[35m");
            printf("\n24 march - 4 april 2024 = 2nd mid term week (1-2)\n");
            printf("\x1b[35m");
            printf("\n28 April - 9 May 2024 = 3rd mid term week (1-2)\n");

            printf("\x1b[32m");
            printf("\n7 -18 April 2024 = Sob-e-kadar , Jumatul Bida , Eid-ul-Fitar , Bangali New Year\n");


      }

      else if(month == 5){
            printf("\x1b[35m");
            printf("\n28 April - 9 May 2024 = 3rd mid term week (1-2)\n");
            printf("\x1b[33m");
            printf("\n10 May - 24 May 2024 = Off for exam's Preparation of 2nd semester (1-2)");
            printf("\x1b[31m");
            printf("\n26 May - 27 june = 1st year 2nd semester Exam (1-2)\n");

            printf("\x1b[32m");
            printf("\n1 May 2024 = May Day\n");
            printf("\n22 May = Buddha Purnima\n");



      }

      else if(month == 6){
            printf("\x1b[31m");
            printf("\n26 May - 27 june = 1st year 2nd semester Exam (1-2)\n");


      }

      else if(month == 7){
        printf("\x1b[35m");
            printf("\n1 July = 2nd Year 1st semester class start (2-1)\n");
            printf("\x1b[33m");
            printf("\n21 July - 31 July = 1st Mid term week  (2-1)\n");

            printf("\x1b[32m");
            printf("\n8 July 2024 = Muharram /Hijri nababorsho\n");
            printf("\n17 July 2024 = Ashura\n");



      }

      else if(month == 8){
        printf("\x1b[35m");
            printf("\n19 August - 29 August = 2nd Mid term week  (2-1)\n");

            printf("\x1b[32m");
            printf("\n15 August 2024 = National Mourning Day\n");
            printf("\n26 August 2024 = Janmostomi\n");
            printf("\n27 August 2024 = Jatiya Kabi Kazi Nazrul Islam's Mohaproyan day\n");



      }

      else if(month == 9){
        printf("\x1b[35m");
            printf("\n22 - 30 September = 3rd Mid term week  (2-1)\n");
            printf("\x1b[36m");
            printf("\n30 September = Last class of 2nd year 1st semester  (2-1)\n");

            printf("\x1b[32m");
            printf("\n4 September 2024 = Akheri Chahar Shomba\n");
            printf("\n16 September 2024 = Eid-e-Milad-un Nabi\n");

      }

      else if(month == 10){
        printf("\x1b[36m");
            printf("\n1 - 8 October = Exam Preparation Off  (2-1)\n");
            printf("\x1b[31m");
            printf("\n16 October - 21 November = 2nd year 1st semsester (2-1)\n");

            printf("\x1b[32m");
            printf("\n9 - 15 Octobar 2024 = sri sri Durga puja\n");
            printf("\n31 octobar 2024 = sri sri Shemapuja\n");

      }

      else if(month == 11){
        printf("\x1b[31m");
            printf("\n16 October - 21 November = 2nd year 1st semsester (2-1)\n");

      }

      else if(month == 12){
        printf("\x1b[35m");
            printf("\n1 December = 2nd Year 2nd semester class Start\n");

            printf("\x1b[32m");
            printf("\n14 December 2024 = Shahid Buddhijibi Dibosh\n");
            printf("\x1b[32m");
            printf("\n16 December 2024 = Victory Day\n");
            printf("\x1b[32m");
            printf("\n22 - 26 December 2024 = Winter Vacation & Christmas Day\n");

      }


    }

    else if(year == 2025){

        if(month == 1){
            printf("\x1b[33m");
            printf("\n1 - 9 Januyary = 1st Mid term week (2-2)\n");

        }
        else if(month == 2){
            printf("\x1b[35m");
            printf("\n2 - 13 Februyary = 2nd Mid term week (2-2)\n");

        }

        else if(month == 3){
            printf("\x1b[35m");
            printf("\n10 - 20 March = 3rd Mid term week (2-2)\n");
            printf("\x1b[35m");
            printf("\n26 March = Last Class of 2nd year 2nd semester (2-2)\n");

            printf("\x1b[32m");
            printf("\n26 March - 5 April = Eid ul_Fitr Holiday\n");

        }

        else if(month == 4){

            printf("\x1b[32m");
            printf("\n26 March - 5 April = Eid ul_Fitr Holiday\n");

            printf("\x1b[35m");
            printf("\n6 - 15 April = off for Exam's preparation (2-2)\n");

            printf("\x1b[31m");
            printf("\n16 April - 26 May = 2nd year 2nd semester (2-2)\n");

        }

        else if(month == 5){
            printf("\x1b[31m");
            printf("\n16 April - 26 May = 2nd year 2nd semester (2-2)\n");

        }

        else if(month == 6){

            printf("\x1b[35m");
            printf("\n2 June 2025 = Class Start of 3rd Year 1st semester (3-1)\n");


        }

        else if(month == 7){

            printf("\x1b[33m");
            printf("\n22 - 29 July 2025 = 1st Mid term week (3-1)\n");


        }

        else if(month ==8){

            printf("\x1b[35m");
            printf("\n3 - 14 August 2025 = 2nd Mid term week (3-1)\n");


        }

        else if(month == 9){

            printf("\x1b[35m");
            printf("\n7 - 16 September 2025 = 3rd Mid term week (3-1)\n");

            printf("\x1b[35m");
            printf("\n16 September 2025 = last class of 3rd year 1st semester (3-1)\n");


        }

        else if(month == 11){

            printf("\x1b[31m");
            printf("\n1 November - 4 December 2025 = 3rd year 1st semester exam (3-1)\n");

        }

        else if(month == 12){

            printf("\x1b[31m");
            printf("\n1 November - 4 December 2025 = 3rd year 1st semester exam (3-1)\n");

        }



    }

    else if(year == 2026){

        if(month == 1){

            printf("\x1b[35m");
            printf("\n4 Januyary = Class Start of (3-2)\n");

            printf("\x1b[33m");
            printf("\n18 - 28 Januyary = 1st mid term week of  (3-2)\n");

        }
       else if(month == 3){

            printf("\x1b[35m");
            printf("\19 - 30 March = 2nd Mid term week of (3-2)\n");

        }

       else if(month == 5){

            printf("\x1b[35m");
            printf("\n3 - 14 May = 3rd Mid term week of (3-2)\n");

            printf("\x1b[35m");
            printf("\n14 May = last class of 3-2\n");
            printf("\x1b[36m");
            printf("\n17 -31 May = off for preparation of (3-2)\n");



        }

       else if(month == 6){

            printf("\x1b[31m");
            printf("\n3 June - 6 July = Semester Exam of (3-2)\n");

        }
       else if(month == 7){

            printf("\x1b[31m");
            printf("\n3 June - 6 July = Semester Exam of (3-2)\n");

            printf("\x1b[35m");
            printf("\n22 July = Class start of (4-1)\n");


        }

        else if(month ==8){

            printf("\x1b[33m");
            printf("\n23 - 31 August 2026 = 1st mid term week of (4-1)\n");


        }



        else if(month == 11){

            printf("\x1b[35m");
            printf("\n11 - 22 November 2026 = 2nd mid term week(4-1)\n");

        }






    }


    else if(year == 2027){


        if(month == 1){

            printf("\x1b[35m");
            printf("\n10 - 20 Januyary, 2027 = 3rd Mid term week of (4-1) \n");

            printf("\x1b[35m");
            printf("\n20 Januyary, 2027 = last class of (4-1) \n");

        }

       else if(month == 2){

            printf("\x1b[31m");
            printf("\2 february - 3 March = Semester Exam of (4-1)\n");

        }

        else if(month == 3){

            printf("\x1b[31m");
            printf("\2 february - 3 March = Semester Exam of (4-1)\n");

            printf("\x1b[35m");
            printf("\15 March = Class start of (4-2)\n");

        }

        else if(month == 4){

            printf("\x1b[33m");
            printf("\18 - 27 April = 1st Mid term week of (4-2)\n");


        }

       else if(month == 5){

            printf("\x1b[35m");
            printf("\n16 - 26 May = 2nd Mid term week of (4-2)\n");


        }


       else if(month == 7){

            printf("\x1b[35m");
            printf("\n12 -21 july 2027 = 3rd mid term week of (4-2)\n");

            printf("\x1b[35m");
            printf("\n21 july 2027 = last class of (4-2)\n");

            printf("\x1b[36m");
            printf("\n22 -29 july 2027 = off for preparation of (4-2)\n");




        }

        else if(month ==8){

            printf("\x1b[31m");
            printf("\n2 August - 5 September 2027 = semester exam of (4-2)\n");


        }

         else if(month ==9){

            printf("\x1b[31m");
            printf("\n2 August - 5 September 2027 = semester exam of (4-2)\n");


        }



    }



        // Check for arrow key inputs
        ch = _getch(); // Get keypress
        if (ch == 0 || ch == 224) { // Check for arrow key
            ch = _getch(); // Get second byte of extended key code
            switch(ch) {
                case 75: // Left arrow key
                    if (month > 1) {
                        month--;
                    } else {
                        month = 12; // Wrap around to December
                        year--;
                    }
                    break;
                case 77: // Right arrow key
                    if (month < 12) {
                        month++;
                    } else {
                        month = 1; // Wrap around to January
                        year++;
                    }
                    break;
            }
        }
    } while (ch != 27); // Exit loop on Esc key press

    return 0;
}
