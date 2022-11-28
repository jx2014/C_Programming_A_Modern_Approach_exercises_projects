#define PROJECT (1)

#if (PROJECT == 1)
#include <stdio.h>
#include <stddef.h>

struct s {
    char a;
    int b[2];
    float c;
}s_s;


int main(void) {
    struct s test_struct;

    printf("Address of struct s: 0x%p\n", &test_struct);
    printf("offset(sizeof) of member a: %d(%d)\n", \
                offsetof(struct s, a), sizeof(s_s.a)); // offset is 0, size is 1
    printf("offset(sizeof) of member b: %d(%d)\n", \
                offsetof(struct s, b), sizeof(s_s.b)); // offset is 4, size is 8, implies s_s.a has 3 bytes of holes
    printf("offset(sizeof) of member c: %d(%d)\n", \
                offsetof(struct s, c), sizeof(s_s.c)); // offset is 12, size is 4, total struct size is 12 + 4 = 16 bytes.

    return 0;
}
#endif
