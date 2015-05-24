// gcc security_growth_calc.c -o security_growth_calc

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ( int argc, char** argv )
{
     if ( argc != 4 ) {
          printf ( "usage: %s <starting value> <ending value> <divident yeild pct>\n",
                   argv [ 0 ] );
          return 0;
     }

     double starting_value = atof ( argv [ 1 ] );
     double ending_value = atof ( argv [ 2 ] );
     double dividend_pct = atof ( argv [ 3 ] );

     double dividend_yeild = ending_value * dividend_pct;

     double return_per_share = ( ending_value + dividend_yeild ) - starting_value;
     double pct_growth = ( ( ending_value + dividend_yeild ) / starting_value ) - 1.0;

     setlocale ( LC_NUMERIC, "" );

     printf ( "return per share: $%'.2f\n", return_per_share );
     printf ( "growth: %.5f\n", pct_growth );

     return 0;
}
