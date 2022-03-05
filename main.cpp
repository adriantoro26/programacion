#include <iostream>
#include <math.h>

using namespace std;

/**
 * This program will perform the following 3 operations:
 * - Calculates the roots for a given second-degree polynomial.
 * - Calculates the volume of a sphere for a given radius.
 * - Calculates the travelled distance of a vehicle assuming
 *   uniform rectilinear motion.
*/

/**
 * Defines, typedefs and constants
*/
enum Operations{
    ROOTS,
    SPHERE_VOLUME,
    DISPLACEMENT,
};

/**
 * Calculates the roots for a given second-degree polynomial of the form:
 * a.x^2 + b.x + c.
 * @param a - Coefficient of x^2.
 * @param b - Coefficient of x^1 (x).
 * @param c - Coefficient of x^0 (1).
*/
static int root(float a, float b, float c, float &r1, float &r2){

    /**
     * Validate that there won't be complex roots
    */
    if(pow(b,2) < 4*a*c)
        return 1;

    r1 = (-b + sqrt(pow(b, 2) - 4*a*c))/(2*a);
    r2 = (-b - sqrt(pow(b, 2) - 4*a*c))/(2*a);
    return 0;
}
/**
 * Calculates the volume of a sphere for a given radius.
 * @param radius - Sphere radius.
*/
static int sphereVolume(float radius, float &result){

    /**
     * Validate that the radius is positive
    */
    if(radius <= 0)
        return 1;

    result = 4*M_PI*pow(radius, 3)/3;
    return 0;
}
/**
 * Calculates the travelled distance of a vehicle assuming
 * uniform rectilinear motion.
 * @param initalDisplacement - Vehicle inital displacement.
 * @param initialSpeed - Vehicle initial speed.
 * @param time - Time.
*/
static int displacement(float initalDisplacement, float initialSpeed, float acceleration, float time, float &result){
    result = initalDisplacement + initialSpeed*time + acceleration*pow(time, 2)/2;
    return 0;
}

/**
 * Entry point
 */
int main(){

    /**
     * Static variables
    */

    while(true){

        /**
         * States
        */
       int op;
       float * input = NULL;
       float result, r1, r2;
       int errorCode = 0;

       /**
        * Get operation from user
       */
        cout << "Ingrese Opcion:" << endl;
        cout << "0: Calcular raices de polinomio de segundo grado" << endl;
        cout << "1: Calcular volumen de esfera" << endl;
        cout << "2: Calcular desplazamiento de vehiculo" << endl;
        cin >> op;

        switch(op){
            case ROOTS:

                input = new float(3);

                cout << "Ingrese A" << endl;
                cin >> input[0];

                cout << "Ingrese B" << endl;
                cin >> input[1];

                cout << "Ingrese C" << endl;
                cin >> input[2];

                errorCode = root(input[0], input[1], input[2], r1, r2);

                if (!errorCode)
                    cout << "= " << "( " << r1 << " , " << r2 << " )" << endl;
                else
                    cout << "ERROR: Raices complejas!";

                delete [] input;
            break;

            case SPHERE_VOLUME:
                input = new float(1);

                cout << "Ingrese Radio de la esfera" << endl;
                cin >> input[0];

                errorCode = sphereVolume(input[0], result);

                if (!errorCode)
                    cout << "= " << result << endl;
                else
                    cout << "ERROR: Radio es menor o igual a cero!";

                delete [] input;
            break;


            case DISPLACEMENT:

                input = new float(4);

                cout << "Ingrese Desplazamiento inital" << endl;
                cin >> input[0];

                cout << "Ingrese Velocidad inicial" << endl;
                cin >> input[1];

                cout << "Ingrese Acceleracion" << endl;
                cin >> input[2];

                cout << "Ingrese Tiempo (seg)" << endl;
                cin >> input[3];

                displacement(input[0], input[1], input[2], input[3], result);
                cout << "= " << result << endl;

                delete [] input;
            break;

            default:
            break;
        }

        /**
         * Ask user if he wishes to continue
        */

    }

    return 0;
}