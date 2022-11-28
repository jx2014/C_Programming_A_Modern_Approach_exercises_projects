#define PREPROCESS_CHECK (0)

#if (PREPROCESS_CHECK == 0)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#endif

#define EXERCISE (22)

#if (EXERCISE == 1)
int main(void) {

    // following struct is legal
    // struct x and y both have different addresses.
    // they occupy different memory locations.
    // x.x and x.y are within the address of struct x;
    // y.x and y.y are within the address of struct y;
    struct {int x, y;} x;
    struct {int x, y;} y;

    x.x = 10;
    x.y = 100;
    y.x = 11;
    y.y = 999.99;
    
    printf("Hello world\n");
    printf("x.x: %d\n", x.x);
    return 0;
}
#endif

#if (EXERCISE == 2)
int main(void) {
    // creating a structure for c1, c2, and c3
    // only initialize c1 and c2.
    struct {
        double real, imaginary;
    }   c1 = {.real = 0.0, .imaginary = 0.1}, 
        c2 = {1.0, 0.0}, 
        c3;

    printf("c1.real: %g, c1.imaginary: %g\n", c1.real, c1.imaginary);
    printf("c2.real: %g, c2.imaginary: %g\n", c2.real, c2.imaginary);
    printf("c3.real: %g, c3.imaginary: %g\n", c3.real, c3.imaginary);
    printf("\n");
    // copy c2 to c1
    c2 = c1;

    printf("c1.real: %g, c1.imaginary: %g\n", c1.real, c1.imaginary);
    printf("c2.real: %g, c2.imaginary: %g\n", c2.real, c2.imaginary);
    printf("c3.real: %g, c3.imaginary: %g\n", c3.real, c3.imaginary);
    printf("\n");

    // store c3 with result of c1 + c2
    c2.real = 1.0;
    c2.imaginary = 0.0;
    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;
    printf("c1.real: %g, c1.imaginary: %g\n", c1.real, c1.imaginary);
    printf("c2.real: %g, c2.imaginary: %g\n", c2.real, c2.imaginary);
    printf("c3.real: %g, c3.imaginary: %g\n", c3.real, c3.imaginary);
    printf("\n");


    return 0;
}
#endif

#if (EXERCISE == 3)
int main(void) {

    // creating a struct tag, complex
    struct complex {
        double real, imaginary;
    };

    // using complex tag to create three variables, c1, c2, and c3
    struct complex c1, c2, c3;

    // function to store two arguments and return the structure
    struct complex make_complex(double real, double imaginary) {
        struct complex c;
        c.real = real;
        c.imaginary = imaginary;
        return c;
    }

    // using make_complex();
    struct complex c4 = make_complex(10.3, -20.3);

    // a function that add two complex numbers together,
    // and return the result in the form of another complex number.
    struct complex add_complex(struct complex a, struct complex b) {
        struct complex r;
        r.real = a.real + b.real;
        r.imaginary = a.imaginary + b.imaginary;
        return r;
    }

    c1 = make_complex(1, 2);
    c2 = make_complex(2, -2);

    c3 = add_complex(c1, c2);

    printf("c1.real: %g, c1.imaginary: %g\n", c1.real, c1.imaginary);
    printf("c2.real: %g, c2.imaginary: %g\n", c2.real, c2.imaginary);
    printf("c3.real: %g, c3.imaginary: %g\n", c3.real, c3.imaginary);
    printf("c4.real: %g, c4.imaginary: %g\n", c4.real, c4.imaginary);


    return 0;
}
#endif

#if (EXERCISE == 4)
// same exercise as (3) but with typedef instead of tag
int main(void) {

    // creating a struct tag, complex
    typedef struct {
        double real, imaginary;
    } Complex;

    // using complex tag to create three variables, c1, c2, and c3
    Complex c1, c2, c3;

    // function to store two arguments and return the structure
    Complex make_complex(double real, double imaginary) {
        Complex c;
        c.real = real;
        c.imaginary = imaginary;
        return c;
    }

    // using make_complex();
    Complex c4 = make_complex(10.3, -20.3);

    // a function that add two complex numbers together,
    // and return the result in the form of another complex number.
    Complex add_complex(Complex a, Complex b) {
        Complex r;
        r.real = a.real + b.real;
        r.imaginary = a.imaginary + b.imaginary;
        return r;
    }

    c1 = make_complex(1, 2);
    c2 = make_complex(2, -2);

    c3 = add_complex(c1, c2);

    printf("c1.real: %g, c1.imaginary: %g\n", c1.real, c1.imaginary);
    printf("c2.real: %g, c2.imaginary: %g\n", c2.real, c2.imaginary);
    printf("c3.real: %g, c3.imaginary: %g\n", c3.real, c3.imaginary);
    printf("c4.real: %g, c4.imaginary: %g\n", c4.real, c4.imaginary);


    return 0;

    return 0;
}
#endif

#if (EXERCISE == 5)
struct date { int month, day, year;};

#define PRINT_DATE(d) printf("day of year for " #d " is %d\n", day_of_year(d))
#define COMPARE_DATES(a, b) printf("Comparing " #a " and " #b \
                                       ": %d\n", compare_dates(a, b))

// return date of the year between 1 to 366
int day_of_year(struct date d);

// -1 if d1 is eariler than d2, +1 if later, 0 if the same
int compare_dates(struct date d1, struct date d2);

int main(void) {

    struct date d1 = {.month = 5, .day = 30, .year = 2022}; 
    struct date d2 = {.month = 5, .day = 30, .year = 2021};
    struct date d3 = {.month = 12, .day = 30, .year = 2023};

    PRINT_DATE(d1);
    PRINT_DATE(d2);
    PRINT_DATE(d3);

    COMPARE_DATES(d1, d2);
    COMPARE_DATES(d2, d1);
    COMPARE_DATES(d1, d3);
    COMPARE_DATES(d3, d1);
    COMPARE_DATES(d2, d3);
    COMPARE_DATES(d3, d2);
    COMPARE_DATES(d1, d1);
    COMPARE_DATES(d2, d2);
    COMPARE_DATES(d3, d3);   

    return 0;
}
int day_of_year(struct date d) {    
    return d.month * 12 + d.day;    
}

// compare_dates return -1 if d1 is eariler than d2, +1 if later, 0 if the same
int compare_dates(struct date d1, struct date d2) {
    int r = d1.year * 10000 + d1.month * 12 + d1.day - ( d2.year * 10000 + d2.month * 12 + d2.day );
    return r == 0 ? 0 : r / abs(r);
}
#endif

#if (EXERCISE == 6)
struct time {int hours, minutes, seconds;};
struct time split_time(long total_seconds);

#define PRINT_TIME_CONV(n)      \
        do {                    \
            t = split_time(n);  \
            printf("Total time %ld (seconds) is %02d:%02d:%02d\n", n, t.hours, t.minutes, t.seconds);  \
        } while (0)

int main(void) {

    struct time t;
    PRINT_TIME_CONV(86400); // expect 00:00:00
    PRINT_TIME_CONV(169921); // expect 23:12:01
    PRINT_TIME_CONV(86401); // expect 00:00:01
    PRINT_TIME_CONV(1599792); // expect 12:23:12

    return 0;
}

struct time split_time(long total_seconds) {
    struct time t;
    long days = total_seconds / 86400;
    t.hours = (total_seconds - days * 86400 ) / 3600;
    t.minutes = (total_seconds - days * 86400 - t.hours * 3600) / 60;
    t.seconds = (total_seconds - days * 86400 - t.hours * 3600 - t.minutes * 60);
    return t;
}

#endif

#if (EXERCISE == 7)

struct fraction {int numerator, denominator;};

struct fraction frac_reduce(struct fraction f);
struct fraction frac_add(struct fraction f1, struct fraction f2);
struct fraction frac_subtract(struct fraction f1, struct fraction f2);
struct fraction frac_multiply(struct fraction f1, struct fraction f2);
struct fraction frac_divide(struct fraction f1, struct fraction f2);

// Need to create a look up table for switch-case for operators.
enum {add = 1, substract, multiply, divide};

typedef struct {
    char *key;
    int value;
} t_oper_struct;

static t_oper_struct op_lookup_table[] = {{"add", add}, {"substract", substract}, {"multiply", multiply}, {"divide", divide}};
int get_key_from_string(char* oper);
void print_fract(struct fraction f1, char* operator, struct fraction f2);

int main(void) {

    struct fraction f1 = {.numerator = 12, .denominator = 28}; // 12/28 = 3/7
    struct fraction f2 = {.numerator = 20, .denominator = 50}; // 20/50 = 2/5
    struct fraction f;

    f = frac_add(f1, f2);
    print_fract(f1, "add", f2);
    print_fract(f1, "substract", f2);
    print_fract(f1, "multiply", f2);
    print_fract(f1, "divide", f2);
    print_fract(f1, "wtf", f2);

    return 0;
}

int get_operator_key(char* oper) {
    for (int i = 0; i < 4; i++) {
        t_oper_struct p_oper_lookup = op_lookup_table[i];
        if (strcmp(oper, p_oper_lookup.key) == 0) {
            return p_oper_lookup.value;
        }
    }
    return -1; // invalid operator    
}

void print_fract(struct fraction f1, char *operator, struct fraction f2) {
    struct fraction f;

    switch (get_operator_key(operator)) {
        case add:
            f = frac_add(f1, f2);
            break;
        case substract:
            f = frac_subtract(f1, f2);
            break;
        case multiply:
            f = frac_multiply(f1, f2);
            break;
        case divide:
            f = frac_divide(f1, f2);
            break;
        default:
            printf("Incorrect operator name \"%s\"\n", operator);
            return;
    }

    printf("%d/%d %s %d/%d = %d/%d\n", f1.numerator, f1.denominator, operator, \
            f2.numerator, f2.denominator, f.numerator, f.denominator);
}

struct fraction frac_reduce(struct fraction f) {
    // using Euler's method to find GCD
    struct fraction fr;
    int r, a, b;
    a = f.numerator;
    b = f.denominator;

    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }            
    // the GCD is a
    fr.numerator = f.numerator / a;
    fr.denominator = f.denominator / a;

    return fr;
}

struct fraction frac_add(struct fraction f1, struct fraction f2) {
    struct fraction f, f1r, f2r;
    f1r = frac_reduce(f1);
    f2r = frac_reduce(f2);
    if (f1r.denominator == f2r.denominator) {
        f.numerator = f1.numerator + f2.numerator;
    } else {
        f.numerator = f1r.numerator * f2r.denominator + f2r.numerator * f1r.denominator;
        f.denominator = f1r.denominator * f2r.denominator;  
    }
  
    return frac_reduce(f);
}

struct fraction frac_subtract(struct fraction f1, struct fraction f2) {
    struct fraction f, f1r, f2r;
    f1r = frac_reduce(f1);
    f2r = frac_reduce(f2);
    if (f1r.denominator == f2r.denominator) {
        f.numerator = f1.numerator - f2.numerator;
    } else {
        f.numerator = f1r.numerator * f2r.denominator - f2r.numerator * f1r.denominator;
        f.denominator = f1r.denominator * f2r.denominator;  
    }
  
    return frac_reduce(f);
}

struct fraction frac_multiply(struct fraction f1, struct fraction f2) {
    struct fraction f, f1r, f2r;
    f1r = frac_reduce(f1);
    f2r = frac_reduce(f2);
    f.numerator = f1r.numerator * f2r.numerator;
    f.denominator = f1r.denominator * f2r.denominator;  
  
    return frac_reduce(f);
}

struct fraction frac_divide(struct fraction f1, struct fraction f2) {
    struct fraction f, f1r, f2r;
    f1r = frac_reduce(f1);
    f2r = frac_reduce(f2);
    f.numerator = f1r.numerator * f2r.denominator;
    f.denominator = f1r.denominator * f2r.numerator;  
  
    return frac_reduce(f);
}
#endif

#if (EXERCISE == 8)
int main(void) {

    struct color {
        int red;
        int green;
        int blue;
    };

    const struct color MAGENTA = {255, 0, 255};
    const struct color MAGENTA_C99 = {.red=255, .blue=255};

    return 0;
}
#endif

#if (EXERCISE == 9)

struct color { int red, green, blue;};
struct color make_color(int red, int green, int blue);
int getColor(struct color c);
bool equal_color(struct color c1, struct color c2);
struct color brighter(struct color c);
struct color darker(struct color c);

int main(void) {

    struct color some_random_color1 = make_color(0, 1, 2);
    struct color some_random_color2 = make_color(0, 1, 2);
    struct color some_random_color3 = make_color(100, 100, 100);
    struct color some_random_color4 = make_color(100, 100, 100);
    struct color some_random_color5 = make_color(255, 254, 253);
    struct color some_random_color6 = make_color(255, 254, 253);

    printf("red is: %d\n", getColor(some_random_color1));
    printf("same color? %d\n", equal_color(some_random_color1, some_random_color1));
    printf("same color? %d\n", equal_color(some_random_color1, some_random_color3));

    some_random_color1 = brighter(some_random_color1);
    some_random_color2 = darker(some_random_color2);
    some_random_color3 = brighter(some_random_color3);
    some_random_color4 = darker(some_random_color4);
    some_random_color5 = brighter(some_random_color5);
    some_random_color6 = darker(some_random_color6);

    return 0;
}

struct color make_color(int red, int green, int blue) {
    struct color c;
    c.red = (red < 0 ? 0 : (red > 255 ? 255 : red));
    c.green = (green < 0 ? 0 : (green > 255 ? 255 : green));
    c.blue = (blue < 0 ? 0 : (blue > 255 ? 255 : blue));
    return c;
}

int getColor(struct color c) {
    return c.red;
}

bool equal_color(struct color c1, struct color c2) {
    if (c1.red == c2.red && \
        c1.green == c2.green && \
        c1.blue == c2.blue)
        return true;
    else
        return false;
}

struct color brighter(struct color c) {
    struct color new_c;
    new_c.red = (c.red == 0 ? 3 : (c.red < 3 ? 4 : ((c.red / 0.7) > 255 ? 255 : c.red / 0.7)));    
    new_c.green = (c.green == 0 ? 3 : (c.green < 3 ? 4 : ((c.green / 0.7) > 255 ? 255 : c.green / 0.7)));
    new_c.blue = (c.blue == 0 ? 3 : (c.blue < 3 ? 4 : ((c.blue / 0.7) > 255 ? 255 : c.blue / 0.7)));

    return new_c;
}


struct color darker(struct color c) {
    struct color new_c;
    new_c.red = (c.red == 0 ? 3 : (c.red < 3 ? 2 : ((c.red * 0.7) > 255 ? 255 : c.red * 0.7)));    
    new_c.green = (c.green == 0 ? 3 : (c.green < 3 ? 2 : ((c.green * 0.7) > 255 ? 255 : c.green * 0.7)));
    new_c.blue = (c.blue == 0 ? 3 : (c.blue < 3 ? 2 : ((c.blue * 0.7) > 255 ? 255 : c.blue * 0.7)));

    return new_c;
}

#endif

#if (EXERCISE == 10)

struct point {int x, y; };
struct rectangle { struct point upper_left, lower_right; };
int area(struct rectangle r);
struct point center(struct rectangle r);
struct rectangle move(struct rectangle r, int by_x, int by_y);
bool point_with_in(struct rectangle r, struct point p);

int main(void) {
    struct rectangle rectangle1 = { .upper_left = {.x = 0, .y = 10}, 
                                    .lower_right = {.x = 10, .y = 0}}; // area is 100, center point 5, 5

    struct rectangle rectangle2 = { {2, 6}, {10, 2} }; // area is 32, center point is 6, 4

    struct point point1 = {1, 3}; // point1 is inside rectangle1 but not rectangle2

    struct point cpoint;

    printf("area of rectangle1 is %d\n", area(rectangle1));
    printf("area of rectangle2 is %d\n", area(rectangle2));
    cpoint = center(rectangle1);
    printf("Center point of rectangel1 is %d %d\n", cpoint.x, cpoint.y);
    cpoint = center(rectangle2);
    printf("Center point of rectangel2 is %d %d\n", cpoint.x, cpoint.y);

    struct rectangle new_rectangle = move(rectangle1, 5, 3); // (5, 13) (15, 3)
    printf("New rectangle has points (%d, %d) (%d, %d)\n", new_rectangle.upper_left.x, new_rectangle.upper_left.y,\
                                                        new_rectangle.lower_right.x, new_rectangle.lower_right.y);

    char is_or_not[10];

    strcpy(is_or_not, point_with_in(rectangle1, point1) ? "is" : "is not");
    printf("point1 %s within rectangle1.\n", is_or_not);
    
    strcpy(is_or_not, point_with_in(rectangle2, point1) ? "is" : "is not");
    printf("point1 %s within rectangle2.\n", is_or_not);

    return 0;
}

int area(struct rectangle c) {
    int w, l;
    w = c.lower_right.x - c.upper_left.x;
    l = c.upper_left.y - c.lower_right.y;

    return w * l;
}

struct point center(struct rectangle r) {
    struct point center_point;
    center_point.x = (r.lower_right.x + r.upper_left.x) / 2;
    center_point.y = (r.lower_right.y + r.upper_left.y) / 2;

    return center_point;
}

struct rectangle move(struct rectangle r, int by_x, int by_y) {
    struct rectangle new_pos;
    new_pos.lower_right.x = r.lower_right.x + by_x;
    new_pos.upper_left.x = r.upper_left.x + by_x;
    new_pos.lower_right.y = r.lower_right.y + by_y;
    new_pos.upper_left.y = r.upper_left.y + by_y;

    return new_pos;
}

bool point_with_in(struct rectangle r, struct point p) {
    return (p.x >= r.upper_left.x && p.x <= r.lower_right.x &&
            p.y >= r.lower_right.y && p.y <= r.upper_left.y ? true : false);
}


#endif

#if (EXERCISE == 11)
int main(void) {
   
    struct {
        double a;       // 8 bytes 
        union {
            char b[4];
            double c;   // 8 bytes
            int d;
        } e;            // 8 bytes due to double c
        char f[4];      // 4 bytes
    } s;                // 20 bytes

    sizeof(s);          // 24 bytes (3 * 8 bytes)

    return 0;
}
#endif

#if (EXERCISE == 12)
int main(void) {
     #pragma pack(1) // disable padding

    union {
        double a;       // 8 bytes
        struct {
            char b[4];  // 4 bytes
            double c;   // 8 bytes
            int d;      // 4 bytes
        } e;            // 16 bytes total
        char f[4];      // 4 bytes
    } u;    // 16 bytes

    struct {
        char b[3];  // 3 bytes
        double c;   // 8 bytes
        int d;      // 4 bytes
    } z;            // 15 bytes total

    char b[4];
    double c;
    int d;

    sizeof(u);

    return 0;
}
#endif

#if (EXERCISE == 13)
#define RECTANGLE (0)
#define CIRCLE (1)

struct point {int x, y;};
struct shape {
    int shape_kind;         // RECTANGLE or CIRCLE
    struct point center;    // coordinates of center
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;            
        } circle;
    } u;
} s;

int main(void) {
    s.shape_kind = RECTANGLE;
    s.center.x = 10;
    s.u.rectangle.height = 25;
    s.u.rectangle.width = 8;
    s.u.circle.radius = 5;
    s.u.circle.radius = 5;

    return 0;
}
#endif

#if (EXERCISE == 14)

#define RECTANGLE (0)
#define CIRCLE (1)

struct point {int x, y;};
struct shape {
    int shape_kind;         // RECTANGLE or CIRCLE
    struct point center;    // coordinates of center
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;            
        } circle;
    } u;
};

double get_area(struct shape s);
struct shape move_shape(struct shape s, int x, int y);
struct shape scale_shape(struct shape s, double c);

int main(void) {
    struct shape rectangle = {  .shape_kind = RECTANGLE,    \
                                .center.x = 10,             \
                                .center.y = 20,             \
                                .u.rectangle.height = 13,   \
                                .u.rectangle.width = 18     \
                                };
    
    struct shape circle = {     .shape_kind = CIRCLE,       \
                                .center.x = 10,             \
                                .center.y = 20,             \
                                .u.circle.radius = 8                           
                                };
    
    double area1, area2;
    struct shape new_rectangle, new_circle;
    struct shape new_rectangle2, new_circle2;
    area1 = get_area(rectangle);
    area2 = get_area(circle);
    new_rectangle = move_shape(rectangle, 3, 3);
    new_circle = move_shape(circle, 2, 2);
    new_rectangle2 = scale_shape(rectangle, 3);
    new_circle2 = scale_shape(circle, 5);
    return 0;
}

double get_area(struct shape s) {
    if (s.shape_kind == RECTANGLE)
        return s.u.rectangle.height * s.u.rectangle.width;
    else if (s.shape_kind == CIRCLE)
        return 3.1415926 * s.u.circle.radius * s.u.circle.radius;
    else
        return -1;
}

struct shape move_shape(struct shape s, int x, int y) {
    struct shape new_shape = s;    
    new_shape.center.x += x;
    new_shape.center.y += y;
    return new_shape;
}

struct shape scale_shape(struct shape s, double c) {
    struct shape new_shape = s;    
    if (new_shape.shape_kind == RECTANGLE) {
        new_shape.u.rectangle.height *= c;
        new_shape.u.rectangle.width *= c;
    } else if (new_shape.shape_kind == CIRCLE)
        new_shape.u.circle.radius *= c;    
    return new_shape;
}



#endif

#if (EXERCISE == 15)

int main(void) {
    int i;
    enum {MON=1, TUE, WED, THR, FRI, SAT, SUN} week_days;
    typedef enum {tMON=1, tTUE, tWED, tTHR, tFRI, tSAT, tSUN} t_week_days;
    i = SUN;
    i = week_days;
    t_week_days day;
    day = WED;
    day = tTHR;    

    return 0;
}
#endif

#if (EXERCISE == 16)
int main(void) {
    // Enumeration can have the same values
    enum {A,B,C,D} test;
    enum {SINGLE=1, SINGLE2 = 1, FLOAT=9999999999999999999999999999, NEGATIVE=-2} test2;

    printf("%g\n", FLOAT);
    // enum can store up to 8-byte integer long long

    return 0;
}
#endif

#if (EXERCISE == 17)
int main(void) {
    enum {FALSE, TRUE} b;
    int i;
    b = FALSE;     // legal, always meaningful
    b = i;         // legal, but not meaningful
    b++;           // legal, not safe
    i = b;         // legal, not safe if b has value other than FALSE and TRUE
    i = 2 * b + 1; // legal, not safe if b has value other than FALSE and TRUE

    return 0;
}
#endif

#if (EXERCISE == 18)

typedef enum {empty, pawn, knight, bishop, rook, queen, king} Piece;

typedef enum {black, white} Color;

typedef struct { 
    Piece piece;
    Color color;    
} Square;

void initialize_board(Square board[8][8]);

Square some_board[8][8];

int main(void) {
    some_board[0][0].piece = king;
    some_board[0][0].color = white;

    initialize_board(some_board);

    return 0;
}

void initialize_board(Square board[8][8]) {
    int i, j;
    
    board[0][0].piece = rook;
    board[0][1].piece = knight;
    board[0][2].piece = bishop;
    board[0][3].piece = king;
    board[0][4].piece = queen;
    board[0][5].piece = bishop;
    board[0][6].piece = knight;
    board[0][7].piece = rook;

    board[7][0].piece = rook;
    board[7][1].piece = knight;
    board[7][2].piece = bishop;
    board[7][3].piece = king;
    board[7][4].piece = queen;
    board[7][5].piece = bishop;
    board[7][6].piece = knight;
    board[7][7].piece = rook;

    // mapping color to the whole board
    // assign pawn and empty pieces to the board
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ( (i + j) % 2 == 0) {
                board[i][j].color = black;
            } else {
                board[i][j].color = white;
            }
            if (i == 1 || i == 6) {
                board[i][j].piece = pawn;
            } else if (i > 1 && i < 6) {
                board[i][j].piece = empty;
            }
        }
    }
}
#endif

#if (EXERCISE == 19)

struct pingball_machine {
    char name[40];
    int year;
    enum {EM=0, SS} type;
    int players;
};

int main(void) {
    struct pingball_machine machine1 = {
        .name = "chargy machine",
        .year = 1994,
        .type = SS,
        .players = 4
    };
    return 0;
}
#endif

#if (EXERCISE == 20)
enum {WEST=1, EAST, NORTH, SOUTH} direction;

int main(void) {
    int x = 0, y = 0;
    bool exit = false;
    //int d;
    printf("Select a direction:\n (1) West\n (2) East\n (3) North\n (4) South\n");
    printf("Press 0 to end\n");
    while (!exit) {       
        
        scanf(" %d", &direction);
        switch (direction) {
            case WEST:
                x -= 1;
                break;
            case EAST:
                x += 1;
                break;
            case NORTH:
                y -= 1;
                break;
            case SOUTH:
                y += 1;
                break;
            case 0:
                exit = true;
                break;
            default:
                printf("Incorrect selection.\n");
        }
    }
    printf("x:%d y:%d", x, y);

    return 0;
}
#endif

#if (EXERCISE == 21)
int main(void) {
    enum {NUL, SOH, STX, ETX}; // NUL=0, SOH=1, STX=2, ETX=3;
    enum {VT = 11, FF, CR}; // VT=11, FF=12, CR=13
    enum {SO = 14, SI, DLE, CAN = 24, EM}; // SO=14, SI=15, DLE=16, CAN=24, EM=25
    enum {ENQ = 45, ACK, BEL, LF = 37, ETB, ESC}; // ENQ=45, ACK=46, BEL=47,
                                                  // LF=37, ETB=38, ESC=39
    printf("NUL: %d SOH: %d STX: %d ETX: %d\n", NUL, SOH, STX, ETX);
    printf("CR: %d VT: %d CR: %d\n", VT, FF, CR);
    printf("SO: %d SI: %d DLE: %d CAN: %d EM: %d\n", SO, SI, DLE, CAN, EM);
    printf("ENQ: %d ACK: %d BEL: %d LF: %d ETB: %d ESc: %d\n", ENQ, ACK, BEL, LF, ETB, ESC);
    return 0;
}
#endif

#if (EXERCISE == 22)
enum chess_pieces {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};

int main(void) {
    //int piece_value[6] = {200, 9, 5, 3, 3, 1};
    int piece_values[] = {
        [QUEEN] = 9,
        [ROOK] = 5,
        [BISHOP] = 3,
        [KNIGHT] = 3,
        [PAWN] = 1,
        [KING] = 200,
    };

    return 0;
}
#endif
