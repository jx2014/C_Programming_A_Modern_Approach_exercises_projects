#define FUNCTION_CHAR(NUM)           \
        char fn_char_##NUM(int x) {  \
            printf("fn_char_" #NUM ", x is: %d\n", x); \
            return 'a' - 1 + NUM;              \
        }

FUNCTION_CHAR(1);
FUNCTION_CHAR(2);
FUNCTION_CHAR(3);
FUNCTION_CHAR(4);
FUNCTION_CHAR(5);
FUNCTION_CHAR(6);
FUNCTION_CHAR(7);
FUNCTION_CHAR(8);
FUNCTION_CHAR(9);
FUNCTION_CHAR(10);