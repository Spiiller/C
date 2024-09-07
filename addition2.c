#include <cs50.h>
#include <stdio.h>

int main (void)
{
    // capitar numeros do usuario
    int x = get_int("x: ");
    int y = get_int("y: ");

    //dividir x por y
     
    float z =
    (float) x /
    (float)y;

    printf("%f\n", z );
}
