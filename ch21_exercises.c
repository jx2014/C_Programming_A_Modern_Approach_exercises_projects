#define EXERCISE (5)

#if (EXERCISE == 1)
#include <stdio.h>

int main(void) {

    // locate where header files are kept on your system. 
    // Find the nonstandard headers and determine the purpose of each.

    // C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\ucrt
    //


    return 0;
}
#endif

#if (EXERCISE == 2)
int main(void) {


    return 0;
}
#endif

#if (EXERCISE == 3)
int main(void) {

    //  corecrt_math.h
    // #define _DSIGN_C(_Val)  (((_double_val *)(char*)&(_Val))->_Sh[_D0_C] & _DSIGN)
    // #define _FSIGN_C(_Val)  (((_float_val  *)(char*)&(_Val))->_Sh[_F0_C] & _FSIGN)
    // #define _LSIGN_C(_Val)  (((_ldouble_val*)(char*)&(_Val))->_Sh[_L0_C] & _LSIGN)

    // functoin prototype comes before macro definition.

    return 0;
}
#endif

#if (EXERCISE == 4)
// list of all reserved identifiers 

int main(void) {

    // identifiers that are reserved for use only when a specifi header is included

    // identifiers that are reserved for use as external names

    return 0;
}
#endif

#if (EXERCISE == 5)
#include <ctype.h>

#define islower(c) ((c) >= 'a' && (c) <= 'z')

int main(void) {
    int n;
    n = islower('a');

    return 0;
}
#endif

#if (EXERCISE == 6)
int main(void) {


    return 0;
}
#endif

#if (EXERCISE == 7)
int main(void) {
    /*
    (a) time.h
    (b) string.h   <-- ctype.h
    (c) inttypes.h <-- limits.h
    (d) math.h
    (e) ctype.h    <-- limits.h
    (f) float.h
    (g) string.h
    (h) stdio.h
    */
    return 0;
}
#endif
