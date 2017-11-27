/**<
Patrick Roche
Exercise 7
Coordinate conversion */

/**< Preprocessor Directives */
#include <iostream>
#include <iomanip>      // std::setprecision
#include <cmath>
/**< Allows use of Trigonematric Fucntions */
#include <tgmath.h>
/**< for system("cls") */
#include <windows.h>

using namespace std;

/**< 3 functions being used */
int main();
void C2P(double n1, double n2, double *np1, double *np2);
void P2C(double n1, double n2, double *np1, double *np2);
void cart2pol(void);
void pol2cart(void);

/**< Main Function */
int main()
{
    /**< naming the character 'input, for the switch case */
    char input;

    /**< Heading */
    cout << "Coordinate Conversion\n" <<endl;

    do
    {
        /**< Prompting the user what to press */
        cout << "\nenter required program\n"
                "Press 'p' for Cartesian to Polar \n" <<
                "Press 'c' for Polar to Cartesian \n" <<
                "Press 'q' to quit program" <<endl;
        /**< inputting either p/c/q */
        cin >> input;

        /**< Switch case in the main function to decide which fucntion to use  */
        switch (input)
        {              /**< Clearing the screen */
            case 'p' : cart2pol();
                       break;

            case 'c' : pol2cart();
                       break;

            case 'q' : cout << "Quit Program" << endl;
                       break;

            default  : cout << "Please try again" << endl;
                       break;

        }
    }
    /**< While the input is not 'q' */
    while (input != 'q');



    return 0;
}



void cart2pol(void)
{
    double x, y, r, theta;
    double *r_ptr = &r, *theta_ptr = &theta;
    char b1, com, b2;

    system("cls");
    cout << "Cartesian to Polar in the form (x,y)" << endl;
    /**< Entering in the form of (1,1) */
    cin >> b1 >> x >> com >> y >> b2;
    /**< Calls the fucntion Cartesian to Polar to run on numbers 1 and 2 and pointer 1 and 2 */
    C2P(x, y, r_ptr, theta_ptr);

    /**< Prints out values stored in pointer 1's and pointer 2's memory */
    cout << fixed << "Magnitude is " << setprecision(2) << r << endl;
    cout << fixed << "Angle is " << setprecision(2) << theta << endl;

    return;
}

void pol2cart(void)
{
    double x, y, r, theta;
    double *x_ptr = &x, *y_ptr = &y;
    char b1, com, b2;

    system("cls");
    cout << "Polar to Cartesian in the form (r,theta)" << endl;
    /**< Entering in the form of (1,1) */
    cin >> b1 >> r >> com >> theta >> b2;
    /**< Calls the fucntion Cartesian to Polar to run on numbers 1 and 2 and pointer 1 and 2 */
    P2C(r, theta, x_ptr, y_ptr);

    /**< Prints out values stored in pointer 1's and pointer 2's memory */
    cout << fixed << "X is " << setprecision(2) << x << endl;
    cout << fixed << "Y is " << setprecision(2) << y << endl;

    return;
}




/**< A function that will convert cartesian to polar and has no output (void) and in thye form of 2 doubles and 2 pointers */
void C2P(double n1, double n2, double *np1, double *np2)
{
    /**< Changes the value stored in pointer 1's memory to the value 'r' */
    *np1 = sqrt(n1*n1 + n2*n2);
    /**< Changes the value stored in pointer 2's memory to be value 'theta' . atan = tan inverse */
    *np2 = atan(n2/n1)*(180/M_PI);

    return;
}




/**< A function that will convert poloar to cartesian and has no output (void) and in thye form of 2 doubles and 2 pointers */
void P2C(double n1, double n2, double *np1, double *np2)
{
    /**< Changes the value stored in pointer 1's memory to the value 'x' */
    *np1 = n1*cos(n2*(M_PI/180));
    /**< Changes the value stored in pointer 1's memory to the value 'y' */
    *np2 = n1*sin(n2*(M_PI/180));

    return;
}
