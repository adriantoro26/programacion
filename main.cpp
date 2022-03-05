#include <iostream>
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
typedef enum {
    ROOTS,
    SPHERE_VOLUME,
    DISPLACEMENT,
} operations_t;

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
       operations_t op;

       /**
        * Get operation from user
       */

        switch(op){
            case ROOTS:
            break;

            case SPHERE_VOLUME:
            break;

            case DISPLACEMENT:
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