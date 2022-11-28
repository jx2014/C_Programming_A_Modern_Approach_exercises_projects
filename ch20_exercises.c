#define EXERCISE (16)

#if (EXERCISE == 1)
#include <stdio.h>

int main(void) {
    int i = 8, j = 9, k;
    // i: 0000 1000 j 0000 1001
    // 1 + j = 0000 1010, 10
    // i >> 10, i is 0, 
    // i >> 1, i is 0
    printf("%d\n", i >> 1 + j >> 1); // print 0

    i = 1;
    // i: 0001, ~i: 1110, i & ~i: 0000
    printf("%d\n", i & ~i); // print 0

    i = 2; j = 1; k = 0;
    // ~i 1101
    //  j 0001
    //  & 0001
    printf("%d\n", ~i & j ^ k); // print 1

    i = 7; j = 8; k = 9;
    // j: 1000
    // k: 1001
    // &: 1000
    // i: 0111
    // ^: 1111
    printf("%d\n", i ^ j & k); // print 15


    return 0;
}
#endif

#if (EXERCISE == 2)

#include <stdio.h>
/* a simple method to toggle a bit, change it from 0 to 1, or 1 to 0 */
int main(void) {
    // using xor ^1 to toggle a bit.

    // toggles bit 4 of the variable i

    int i = 15; // 1111
    i = i ^ (1 << 3);
    printf("0x%.2X\n", i);

    return 0;
}
#endif

#if (EXERCISE == 3)

#define SWAP_INT(x, y)                      \
({                                          \
    if ((x) != (y)) {                       \
        (x)^=(y);                           \
        (y)^=(x);                           \
        (x)^=(y);                           \
    }                                       \
})                                          \

int main(void) {
    // x = 0011    y = 1101
    // x = x ^ y:  x = 1110
    // y = y ^ x:  y = 0011
    // x = x ^ y:  x = 1101
    int a = 10, b = 10;
    SWAP_INT(a, b);
    a = 11;
    SWAP_INT(a, b);

    return 0;
}
#endif

#if (EXERCISE == 4)
/******************************************************************
* Exercise 4: Stores RGB values (256-bits each color) in a        *
*             single long integer. A MK_COLOR macro with three    *
*             parameters will return a long in which the last     *
*             three bytes contain the red, green, and blue        *
*             intensities. With Red value as the last byte and    *
*             the green value as the next-to-last byte.           *
******************************************************************/
#define MK_COLOR(r,g,b) ((long) (b) << 16 | (g) << 8 | (r))
typedef unsigned char BYTE;
int main(void) {
    BYTE R=255, G=200, B=125;
    long rgb;

    rgb = MK_COLOR(R, G, B);

    return 0;
}
#endif

#if (EXERCISE == 5)
#define MK_COLOR(r,g,b) ((long) (b) << 16 | (g) << 8 | (r))
typedef unsigned char BYTE;
/******************************************************************
* Exercise 5: Use three macros: GET_RED, GET_GREEN, GET_BLUE      *
*             that, when given a color as an argument, return     *
*             its 8-bit red, gren, and blue intensities.          *
******************************************************************/
#define GET_BLUE(rgb) ((BYTE) ((rgb) >> 16 & 255) )
#define GET_GREEN(rgb) ((BYTE) ((rgb) >> 8 & 255) )
#define GET_RED(rgb) ((BYTE) ((rgb) & 255) )

int main(void) {
    BYTE R=255, G=200, B=125;
    long rgb;

    rgb = MK_COLOR(R, G, B);

    R = GET_RED(rgb);
    G = GET_GREEN(rgb);
    B = GET_BLUE(rgb);
    return 0;
}
#endif

#if (EXERCISE == 6)
/******************************************************************
* Exercise 6: Use bitwise operators to create swap_bytes:         *
*             unsigned short swap_bytes(unsigned short i);.       *
*             swap_bytes returns the number that results from     *
*             swapping the two bytes in i.(Short integers occupy  *
*             two bytes on most computers.) For example, if i     *
*             has the value 0x1234 (00010010 00110100 in          *
*             binary), then swap_bytes should return 0x3412       *
*             (00110100 00010010 in binary).                      *
******************************************************************/
#include <stdio.h>
unsigned short swap_bytes(unsigned short i);

int main(void) {
    unsigned short x;
    printf("Enter a hexadecimal number (up to four digits): ");    
    scanf("%x", &x);
    printf("Number with bytes swapped: 0x%.4x", swap_bytes(x));


    return 0;
}
unsigned short swap_bytes(unsigned short i) {    
    return (i >> 8 | i << 8);
}
#endif

#if (EXERCISE == 7)
/******************************************************************
* Exercise 7: Create two functions: rotate_left, and              *
*             rotate_right. rotate_left returns the result of     *
*             shifting the bits in i to the left by n places,     *
*             with the bits that were "shifted off" moved to the  *
*             right end of i. (For example, the call              *
*             rotate_left(0x12345678, 4) will return 0x23456781   *
*             if integers are 32bits long.) rotate_right is       *
*             similar, but it will "rotate" to the right instead  *
*             of the left.                                        *
******************************************************************/
#include <stdio.h>

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

int main(void) {
    unsigned int a = 0x12345678, b;
    printf("0x%x\n", a);
    b = rotate_left(a, 1);
    printf("0x%x\n", b);
    b = rotate_right(b, 1);
    printf("0x%x\n", b);

    return 0;
}

unsigned int rotate_left(unsigned int i, int n) {
    unsigned short N = sizeof(unsigned int) * 8 - n;
    unsigned int bit_mask = ~0 << N;
    return ((bit_mask & i) >> N) | (i << n);
}

unsigned int rotate_right(unsigned int i, int n) {
    unsigned short N = sizeof(unsigned int) * 8 - n;
    unsigned int bit_mask = ~(~0 << n);
    return ((bit_mask & i) << N) | (i >> n);
}

#endif

#if (EXERCISE == 8)
unsigned int f(unsigned int i, int m, int n){
    return (i >> (m + 1 - n)) & ~(~0 << n);
}

int main(void) {
    // ~(~0 << n) creates a bit mask of n '1's from the right.    
    // i = 5a          0101 1010
    // n = 3             0000 0111
    // m = 5, >>  3,     0000 0011
    // m = 4, >>  2,     0000 0110
    // m = 3, >>  1,     0000 0101    
    // m = 2, >>  0,     0000 0010
    // m = 1, >> -1,     0000 0000
    // m = 0, >> -2,     0000 0000 

    // function returns the 'm'th bit with 'n' numbers of bit. 
    f(0x50a0, 0, 3);

    return 0;
}
#endif

#if (EXERCISE == 9)
/******************************************************************
* Exercise 9: count_ones return the number of 1 bits in ch. Part  *
*             (b) without using a loop.                           *
******************************************************************/
int count_ones(unsigned char ch);
int count_ones_b(unsigned int ch);

int main(void) {
    
    int n;
    n = count_ones_b(5);    // 0101, two '1's
    n = count_ones_b(0xf);  // 1111, four '1's
    n = count_ones_b(0xfa); // 1111 1010, six '1's
    n = count_ones_b(0xabcd); // 1010 1011 1100 1101, ten '1's

    return 0;
}

int count_ones(unsigned char ch) {
    int n = 0;
    for (int i = 0; i < (sizeof(unsigned char) * 8); i++) {
        if (ch & 1)
            n++;
        ch = ch >> 1;
    }
    return n;
}

// count ones without using a loop
int count_ones_b(unsigned int x) {
       x = (x & 0x55555555) + ((x >>  1) & 0x55555555); // count '1's in each  2-bits
       x = (x & 0x33333333) + ((x >>  2) & 0x33333333); // count '1's in each  4-bits
       x = (x & 0x0F0F0F0F) + ((x >>  4) & 0x0F0F0F0F); // count '1's in each  8-bits
       x = (x & 0x00FF00FF) + ((x >>  8) & 0x00FF00FF); // count '1's in each 16-bits
    return (x & 0x0000FFFF) + ((x >> 16) & 0x0000FFFF); // count '1's in each 32-bits        
}

#endif

#if (EXERCISE == 10)

unsigned int reverse_bits(unsigned int n);

int main(void) {

    unsigned int n = 0x5A3C, m; // given:  0000 0000 0000 0000 0101 1010 0011 1100
                                // expect: 0011 1100 0101 1010 0000 0000 0000 0000
    m = reverse_bits(n);

    return 0;
}

unsigned int reverse_bits(unsigned int n) {
    unsigned int result = ~0;
    short i = 0;    
    do {
        result = result << 1;
        if ((n >> i) & 1)
            result |= 1;
    } while (++i < (sizeof(unsigned int) * 8));

    return result;
}

#endif

#if (EXERCISE == 11)

#include <stdio.h>

#define SHIFT_BIT (1)
#define CTRL_BIT  (2)
#define ALT_BIT   (4)

int main(void) {
    int key_code = 8;    

    if ((key_code & (SHIFT_BIT | CTRL_BIT | ALT_BIT)) == 0) // == takes higher prioroty than &
        printf("No modifier keys pressed\n");

    return 0;
}
#endif

#if (EXERCISE == 12)
#include <stdio.h>

unsigned short create_short(unsigned char high_byte, \
                            unsigned char low_byte) {
                            return (high_byte << 8) + low_byte;
                            }
int main(void) {

    unsigned char hi = 0x50, lo = 0x33;
    unsigned short both;

    both = create_short(hi, lo);
    
    return 0;
}
#endif

#if (EXERCISE == 13)

int main(void) {
    unsigned int n = 0x5a; // 0101 1010

    n &= n - 1; // n = n & n - 1;
                //   0101 1010
                //   0101 1001
                // & 0101 1000
                //   0101 0111
                // & 0101 0000
                //   0100 1111
                // & 0100 0000
    n &= n - 1;
    n &= n - 1;

    return 0;
}
#endif

#if (EXERCISE == 14)

struct float_s{
    unsigned int sign:  1;
    unsigned int exp:   8;
    unsigned int frac: 23;
}

int main(void) {


    return 0;
}
#endif

#if (EXERCISE == 15)
#include <stdio.h>
struct {
    int flag1:1;
    unsigned int flag: 1;
} s;

int main(void) {
    s.flag1= 1; 
    s.flag = 1;
    printf("%d\n", s.flag1); // may display 1 or -1 (signed).
    printf("%d\n", s.flag);  // shall always display 1
    return 0;
}
#endif

#if (EXERCISE == 16)

typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef unsigned long DWORD;

union {
    struct {
        DWORD eax, ebx, ecx, edx;
    } dword;
    struct {
        WORD _ax, ax, _bx, bx, _cx, cx, _dx, dx;            
    } word;
    struct {
        BYTE _al, _ah, al, ah, _bl, _bh, bl, bh, _cl, _ch, cl, ch, _dl, _dh, dl, dh;
    } byte;
} regs;


int main(void) {

    regs.dword.eax = 0x01abcdef;

    return 0;
}
#endif
