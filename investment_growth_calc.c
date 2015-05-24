// gcc investment_growth_calc.c -o investment_growth_calc

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

const char* month_names [ ] = {
     "january",
     "february",
     "march",
     "april",
     "may",
     "june",
     "july",
     "august",
     "september",
     "october",
     "november",
     "december",
};

int main ( int argc, char** argv )
{
     if ( argc != 5 ) {
          printf ( "usage: %s <starting investment> <monthly investment> <speculative yearly growth percent> <total years>",
                   argv [ 0 ] );
          return 0;
     }

     const int months_per_year = 12;

     // get date
     time_t current_time = time ( NULL );
     struct tm converted_time = *localtime ( &current_time );

     // investment values
     double starting_investment = atof ( argv [ 1 ] );
     double monthly_investment = atof ( argv [ 2 ] );
     double speculative_yearly_growth_pct = atof ( argv [ 3 ] );

     // date / years invested
     int total_years = atoi ( argv [ 4 ] );
     int starting_year = converted_time.tm_year + 1900;
     int ending_year = starting_year + total_years;
     int starting_month = converted_time.tm_mon;

     // loop vars
     double assets = starting_investment;
     double growth_pct_per_month = speculative_yearly_growth_pct / (double)(months_per_year);
     int y;
     int m;

     // so we can get commas in our output
     setlocale ( LC_NUMERIC, "" );

     // calculations
     for ( y = starting_year; y < ending_year; ++y ) {
          printf ( "\n%d\n", y );

          double year_growth = 0.0;

          for ( m = starting_month; m < months_per_year; ++m ) {
               double month_growth = assets * growth_pct_per_month;

               printf ( " %10s: $%'.2f + $%'.2f + $%'.2f\n",
                        month_names [ m ], assets, assets * growth_pct_per_month,
                        monthly_investment );

               assets += month_growth;
               assets += monthly_investment;

               year_growth += month_growth;
          }

          printf ( "\n year growth: $%'.2f + $%'.2f = $%'.2f\n",
                   year_growth, monthly_investment * (double)(months_per_year),
                   year_growth + monthly_investment * (double)(months_per_year) );

          starting_month = 0;
     }

     return 0;
}
