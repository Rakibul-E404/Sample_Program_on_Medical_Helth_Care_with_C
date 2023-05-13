/*
    NAME : S. M. Rakibul Alam
    Time : 26/03/2023

    Project details:
    This is a project where I want to develop a software that can be used to
    help people. With this software a person can know about his/her helth condition.
    And also this software could suggest medicine name & suggest doctors name.
*/

#include <stdio.h>
#include <math.h>
#define RESET "\x1B[0m" // text formation
#define BOLD "\x1B[1m"  // text formation
typedef struct
{
    int age, AfD, choice; // AfD = appoinment for doctor
    float temperature, height, weight;
    char name[50];
} info;
int main()
{
    info user;
    info *p = &user;
    printf("Welcome to Helth Care\nto Log in press '1'\n\tTo Sign in press '0'\n");

    printf("%sEnter your Name, Age, Weight, Height & Body temperature:%s\n", BOLD, RESET);

    /*

    Gathering genereal informaation

    */
    printf("Enter your Name: ");
    scanf("%[^\n]", &(*p).name);

    printf("Enter your Age: ");
    scanf("%d", &(*p).age);

    printf("Enter your Weight (in KG): ");
    scanf("%f", &(*p).weight);

    printf("Height (inch/ft). Press '0' for inch & '1' for ft:\n");
    // int choice;
again:
    printf("Enter your choice: ");
    scanf("%d", &(*p).choice);
    if ((*p).choice > 1)
    {
        printf("Enter choice correctly !\n");
        goto again;
    }
    printf("Now enter your height(in ft): ");
    scanf("%f", &(*p).height);

    printf("Body temperature (in fahenheit): ");
    scanf("%f", &(*p).temperature);

    printf("\n\n");

    /*
    ****************Helth Condition***************
    */

    /*

    *********BMI info & suggestions***********

    */

    double bmi;
    switch ((*p).choice)
    {
    case 0:
    {
        bmi = (*p).weight / (pow(((*p).height / 39.12), 2)); // bmi calculation//39.37
    }
    case 1:
    {
        bmi = (*p).weight / (pow(((*p).height / 3.32), 2)); // bmi calculation//3.28
    }
    }
    printf("Your BMI is: %.2lf .\n", bmi);
    if (18.5 > bmi)
    {
        printf("Abnormally underweight, you should eat healthy food more. Untile your BMI is equal to 18.5 or more & less than 25.0.\n");
    }
    else if (18.9 <= bmi && bmi <= 24.9)
    {
        printf("Weight is Normal.\n");
    }
    else if (25.0 <= bmi && bmi <= 29.9)
    {
        printf("It's overweight, you should have exercise.\nYou are at increased risk for a variety of illnesses at your present weight.\n");
        printf("You can follow 'GYM HOME' tutorial (youtube.com/gymhome)\n");
    }
    else
    {
        printf("Obese !!!\nHaving obesity can increase risk for chronic conditions, such as high blood pressure, type 2 diabetes, and high cholesterol.\n");
        printf("You should eat healthy food, You can follow 'GYM HOME' tutorial (youtube.com/gymhome)\n");
    }

    /*

    **************body temperature info & suggestions**************

    */
    if (99 <= (*p).temperature && (*p).temperature <= 102)
    {
        printf("You've feaver\nHow many days your body temperature is in this condition:\n");
        int btd;
        scanf("%d", &btd); // btd = body temperature days
        if (btd > 3)
        {
            printf("You should see a doctor\nDo you want to make an appointment?\nIf 'yes' then press '1'\nIf 'no' then press '0'\n");
            scanf("%d", &(*p).AfD); // AfD = appoinment for doctor
        }
        else
        {
            printf("Try to have 'Napa' tablate, One after 8 hours\nContinue to have 'Napa' tablate untile your body temperature is normal(97F - 98F)\n");
        }
    }

    else if ((*p).temperature >= 103)
    {
        printf("You probably have a fever due to an infection\nHow many days your body temperature is in this condition:\n");
        int btd;
        scanf("%d", &btd); // btd = body temperature days
        if (btd > 3)
        {
            printf("You should see a doctor immediately !!\nDo you want to make an appointment?\nIf 'yes' then press '1'\nIf 'no' then press '0'\n");
            scanf("%d", &(*p).AfD); // user.AfD = appoinment for doctor
        }
        else
        {
            printf("Try to have 'Napa' tablate, One after 8 hours\nContinue to have 'Napa' tablate untile your body temperature is normal(97F - 98F)\n");
        }
    }

    else if ((*p).temperature < 97)
    {
        printf("Your body temperature is low & you should see a doctor\n");
        printf("Do you want to make an appointment?\nIf 'yes' then press '1'\nIf 'no' then press '0'\n");

        scanf("%d", &(*p).AfD); // user.AfD = appoinment for doctor
    }

    else
    {
        printf("Your body temperature is perfect.\n");
    }

    if ((*p).AfD == 1) // user.AfD = appoinment for doctor
    {
        printf("Suggested doctor's list:\nDoc Md. aaa(phd) - 017....78\nDoc rty(mbbs) - 016.....03\n");
    }

    printf("\n\n\n\tThank you for useing this software.\n\tThis software is under development.\n");
    return 0;
}