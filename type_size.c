// from https://www.w3resource.com/c-programming-exercises/basic-declarations-and-expressions/c-programming-basic-exercises-87.php

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
int main( void )
{
    printf( "Ranges for integer data types in C\n\n" );
    printf( "------------------------------------------------------------\n");
    printf( "int8_t    %20d  %20d\n"     , SCHAR_MIN , SCHAR_MAX  );
    printf( "int16_t   %20d  %20d\n"     , SHRT_MIN  , SHRT_MAX   );
    printf( "int32_t   %20d  %20d\n"     , INT_MIN   , INT_MAX    );
    printf( "int64_t   %20lld  %20lld\n" , LLONG_MIN , LLONG_MAX  );
    printf( "uint8_t   %20d  %20d\n"     , 0         , UCHAR_MAX  );
    printf( "uint16_t  %20d  %20d\n"     , 0         , USHRT_MAX  );
    printf( "uint32_t  %20d  %20u\n"     , 0         , UINT_MAX   );
    printf( "uint64_t  %20d  %20llu\n"   , 0         , ULLONG_MAX );
    printf( "\n" );
    printf( "============================================================\n\n");
    printf( "Ranges for real number data types in C\n\n" );
    printf( "------------------------------------------------------------\n");
    printf( "float        %-14.7g   %-14.7g\n"   , FLT_MIN  , FLT_MAX  );
    printf( "double       %-14.7g   %-14.7g\n"   , DBL_MIN  , DBL_MAX  );
    printf( "long double  %-14.7Lg   %-14.7Lg\n" , LDBL_MIN , LDBL_MAX );
    printf( "\n" );
    printf( "============================================================\n\n");
    printf( "Size of data types in C\n\n" );
    printf( "------------------------------------------------------------\n");
    printf( "sizeof(char)                   %3d bytes, %3d bits\n", sizeof(char),         sizeof(char) * 8       );
    printf( "sizeof(int)                    %3d bytes, %3d bits\n", sizeof(int),          sizeof(int) * 8        );
    printf( "sizeof(float)                  %3d bytes, %3d bits\n", sizeof(float),        sizeof(float) * 8      );
    printf( "sizeof(double)                 %3d bytes, %3d bits\n", sizeof(double),       sizeof(double) * 8     );
    printf( "sizeof(long)                   %3d bytes, %3d bits\n", sizeof(long),         sizeof(long) * 8       );
    printf( "sizeof(long long)              %3d bytes, %3d bits\n", sizeof(long long),    sizeof(long long) * 8  );
    printf( "sizeof(long double)            %3d bytes, %3d bits\n", sizeof(long double),  sizeof(long double) * 8);

    printf("\n\n");
    printf("Conversion          Result of Applying              Result of Applying\
    \nSpecification       Conversion to 123               Conversion to -123\n");
    printf("%%8d                 |%8d|                        |%8d|\n", 123, -123);
    printf("%%-8d                |%-8d|                        |%-8d|\n", 123, -123);
    printf("%%+8d                |%+8d|                        |%+8d|\n", 123, -123);
    printf("%% 8d                |% 8d|                        |% 8d|\n", 123, -123);
    printf("%%08d                |%08d|                        |%08d|\n", 123, -123);
    printf("%%-+8d               |%-+8d|                        |%-+8d|\n", 123, -123);
    printf("%%- 8d               |%- 8d|                        |%- 8d|\n", 123, -123);
    printf("%%+08d               |%+08d|                        |%+08d|\n", 123, -123);
    printf("%% 08d               |% 08d|                        |% 08d|\n", 123, -123);

    printf("\n\n");
    printf("Conversion          Result of Applying              Result of Applying\
    \nSpecification       Conversion to 123               Conversion to 123.0\n");
    printf("%%8o               |%8o|                             \n", 123);
    printf("%%#8o              |%#8o|                             \n", 123);
    printf("%%8x               |%8x|                             \n", 123);
    printf("%%#8x              |%#8x|                             \n", 123);
    printf("%%8X               |%8X|                             \n", 123);
    printf("%%#8X              |%#8X|                             \n", 123);
    printf("%%8g                                                |%8g|\n", 123.0);
    printf("%%#8g                                               |%#8g|\n", 123.0);
    printf("%%8G                                                |%8G|\n", 123.0);
    printf("%%#8G                                               |%#8G|\n", 123.0);

    printf("\n\n"); 
    printf("Conversion          Result of Applying              Result of Applying\
    \nSpecification       Conversion to \"bogus\"              Conversion to \"buzzword\"\n");
    printf("%%6s               |%6s|                          |%6s|   \n", "bogus", "buzzword");
    printf("%%-6s              |%-6s|                          |%-6s|  \n", "bogus", "buzzword");
    printf("%%.4s              |%.4s|                            |%.4s|  \n", "bogus", "buzzword");
    printf("%%6.4s             |%6.4s|                          |%6.4s| \n", "bogus", "buzzword");
    printf("%%-6.4s            |%-6.4s|                          |%-6.4s|\n", "bogus", "buzzword");

    printf("\n\n");
    printf("All number below are written using %%.4g\n");
    printf("Number                  Result of Applying %.4g\n\
                        Conversion to Number\n");
    printf("123456.                 |%.4g|\n", 123456.);
    printf(" 12345.6                |%.4g|\n", 12345.6);
    printf("  1234.56               |%.4g|\n", 1234.56);
    printf("   123.456              |%.4g|\n", 123.456);
    printf("    12.3456             |%.4g|\n", 12.3456);
    printf("     1.23456            |%.4g|\n", 1.23456);
    printf("     0.123456           |%.4g|\n", 0.123456);
    printf("     0.0123456          |%.4g|\n", 0.0123456);
    printf("     0.00123456         |%.4g|\n", 0.00123456);
    printf("     0.000123456        |%.4g|\n", 0.000123456);
    printf("     0.0000123456       |%.4g|\n", 0.0000123456);
    printf("     0.00000123456      |%.4g|\n", 0.00000123456);

    int i = 123, width = 12, precesion = 10;
    printf("%6.*d\n", precesion, i);
    printf("%*.*d\n", width, precesion-4, i);
    printf("%*.*d\n", width, precesion, i);

    int len;
    printf("Hello, %d%n\n", 12345, &len); // after calling printf, len stores 12

    

return 0;
}