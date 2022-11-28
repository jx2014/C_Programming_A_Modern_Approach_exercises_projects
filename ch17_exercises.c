/* */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
//*/


#define EXERCISE (19)

#if (EXERCISE == 0)

/***********************************************
 * Just some random codes as practice while    *
 * reading chapter 17.                         *
************************************************/

void modify_str(char **some_string, char *c) {
    *some_string = c;
    printf("%s\n", *some_string);
}

int main(void) {

    struct vstring {
        int len;
        char chars[1];
    };
    int n = 5;
    struct vstring *str = malloc(sizeof(struct vstring) + n - 1);
    str->len = n;

    struct one_kb {
        char a[1024]; 
    };
    char *a_string = "abcdefg";

    modify_str(&a_string, "ABC");
    modify_str(&a_string, "ZFG");
    modify_str(&a_string, "BFB");
    modify_str(&a_string, "GGD");

    struct one_kb one_mb[2000]; // memory size changes between 2000, 1000, etc.

        for (int i = 0; i < 1024; i++) {
        printf("Enter some text: ");
        scanf("%s", one_mb[i].a);
        if (one_mb[i].a[0] == 'q')
            break;
    }

    for (int i = 0; i < 1024; i++) {
        printf("you entered: %s\n", one_mb[i].a);
    }

    return 0;
}
#endif

#if (EXERCISE == 1)
/*****************************************************
 * my_malloc: Wrapper for malloc() that tests and    *
 *            make sure malloc doesn't returns       *
 *            a NULL pointer, then returns the       *
 *            pointer from malloc.                   *
 *            If malloc returns a NULL pointer,      *
 *            terminates the program w/ an error     *
 *            message.                               *
 * ***************************************************/ 
 
void * my_malloc(size_t Size) {
    void *p;    
    if (!(p = malloc(Size))) {
        printf("Unable to allocate memory with my_malloc.\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

int main(void) {

    char *p, *q;
    p = my_malloc(sizeof(p) + 18 + 1); // allocate memory for 8 + 18 = 26 characters + 1 for null character.
    q = malloc(sizeof(q) + 18 + 1);
    strcpy(p, "abcdefghijklmnopqrstuvwxyz");
    strcpy(q, "abcdefghijklmnopqrstuvwxyz");

    printf("p: %s\n", p);
    printf("q: %s\n", q);

    return 0;
}
#endif

#if (EXERCISE == 2)

// duplicate: dynamically allocate stroage 
// to create a copy of a string, and
// returns the pointer to such string.
void * duplicate(char *s) {    
    void *temp;
    p = malloc(strlen(s) + 1);
    if (!temp)    
        return NULL;
    else {
        strcpy(temp, s);
        return temp;
    }
}

int main(void) {

    void *p;
    char *c = "this is a random string.";   
    p = duplicate(c);

    printf("%s\n", p);

    return 0;
}
#endif

#if (EXERCISE == 3)
// create_array: returns a pointer to a dynamically allocated
//               int array with n members. Each member is 
//               initialized to initial_value. Return value
//               is NULL if hte array can't be allocated.

void *create_array(int n, int initial_value) {
    int *temp;
    temp = malloc(n * sizeof(int));
    if (!temp)
        return NULL;
    for (int i = 0; i < n; i++) {
        temp[i] = initial_value;
    }
    return temp;
}

#define ARRAY_SIZE (11)
#define INIT_VALUE (123)

int main(void) {
    int *an_array;

    an_array = create_array(ARRAY_SIZE, INIT_VALUE);

    for (int j = 0; j <= ARRAY_SIZE; j++)
        printf("j: %2d -- %3d\n", j, an_array[j]);
    
    return 0;
}
#endif

#if (EXERCISE == 4)
struct point {int x, y;};
struct rectangle {struct point upper_left, lower_right; };


int main(void) {
    struct rectangle *p, *q;    
    p = malloc(sizeof(struct rectangle));
    q = malloc(sizeof(struct rectangle));
    
    if (!p || !q) // check for NULL pointer
        exit(EXIT_FAILURE);

    p->upper_left.x = 10;
    p->upper_left.y = 25;
    p->lower_right.x = 20;
    p->lower_right.y = 15;

    q->upper_left.x = 30;
    q->upper_left.y = 50;
    q->lower_right.x = 90;
    q->lower_right.y = 10;

    return 0;
}
#endif

#if (EXERCISE == 5)

struct {
    union {
        char a, b;
        int c;
    } d;
    int e[5];    
} f, *p = &f;

int main(void) {

    // (a) p->b = ' '; illegal, correct way: p->d.b = ' '
    // (b) p->e[3] = 10; legal
    // (c) (*p).d.a = '*'; legal
    // (d) p->d->c = 20; illegal, correct way: p->d.c = 20

    return 0;
}
#endif

#if (EXERCISE == 6)
struct node {
    int value;
    struct node *next;
};


struct node *add_to_list(struct node *list, int n);
struct node *delete_from_list(struct node *list, int n);
void clear_list(struct node *list);

int main(void) {
    struct node *first = NULL;
    struct node *new_node, *test_node;
    test_node = NULL;
    new_node = malloc(sizeof(struct node));
    new_node->value = 10;
    new_node->next = first;    
    first = new_node;

    new_node = malloc(sizeof(struct node));
    new_node->value = 20;
    new_node->next = first;
    first = new_node;

    new_node = malloc(sizeof(struct node));
    new_node->value = 30;
    new_node->next = first;
    first = new_node;

    test_node = add_to_list(test_node, 1);
    test_node = add_to_list(test_node, 2);
    test_node = add_to_list(test_node, 3);
    test_node = add_to_list(test_node, 4);
    test_node = add_to_list(test_node, 5);

    first = delete_from_list(first, 30);
    test_node = delete_from_list(test_node, 3);
    test_node = delete_from_list(test_node, 1);
    test_node = delete_from_list(test_node, 5); // only 4, 2 left.
    first = delete_from_list(first, 10); // only 20 left.

    clear_list(test_node);
    clear_list(first);

    return 0;
}

struct node *add_to_list(struct node *list, int n) {
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (!new_node) {
        printf("Error: malloc failed in add_to_list.\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = list;
    return new_node;
}

struct node *delete_from_list(struct node *list, int n) {

    /* Original solution w/ two pointers 
    struct node *current_node, *previous_node;

    for (current_node = list, previous_node = NULL; 
         current_node && current_node->value != n; 
           previous_node = current_node, \
           current_node = current_node->next)
        ;
    
    if (current_node == NULL) // first node is NULL, nothing to remove.
        return list;
    
    if (previous_node == NULL) // n is in first node.
        list = list->next;    
    else if (current_node->value == n) {                  
        previous_node->next = current_node->next;          
    }
    free(current_node);
    return list;
    */   

    /* Exercise 6, using one pointer instead of two */
    if (list == NULL) // first node is NULL, nothing to remove.
        return list;

    struct node *current_node;

    for (current_node = list; 
         current_node->value != n && current_node->next->value != n;
         current_node = current_node->next)
            ;
    if (current_node->value == n) // first node is the target node to be removed
        list = list->next;
    else {     // locating the target node which is after current_node
        current_node->next = current_node->next->next;
        current_node = current_node - (list - list->next); // setting current node to the target node for removal.
                                                           // using 'list - list->next' as memory offset for target node.
    }
    
    free(current_node);
    return list;    
}

void clear_list(struct node *list) {
    struct node *p, *temp;
    for (p = list; p != NULL;) {
        temp = p;
        p = p->next;
        free(temp); // free previous node
    }
}

#endif

#if (EXERCISE == 7)
/* Delete all nodes from a linked list and release all memory */
int main(void) {

    // original, problem is after free(p), p = p->next will fail.
    //for (p = first; p != NULL; p = p->next)
    //    free(p);

    // below version is also incorrect
    for (p = first; p != NULL;) {
        p = p->next;
        free(p - (list->next - list)); // free previous node <-- incorrect, will not work with list that has only one node.
    }

    // book answer
    struct node *temp;
    p = first;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }

    return 0;
}
#endif

#if (EXERCISE == 8)
int main(void) {
    // see ch17\ch17_exercises\exercise8

    return 0;
}
#endif

#if (EXERCISE == 9)
int main(void) {

    struct test {
        int a, b;
    } x = {1, 2};

    printf("(&x).b: %d\n", (&x)->b); // 2
    printf("x.b: %d\n", x.b); // 2

    int i = 0;

    printf("i:   %2d.\n", i);         // 0
    printf("i++: %2d.\n", i++);       // 0
    printf("++i: %2d.\n", ++i);       // 2
    printf("i:   %2d.\n", i);         // 2



    return 0;
}
#endif

#if (EXERCISE == 10)
int main(void) {
    // see ch17\exercises\exercise10

    return 0;
}
#endif

#if (EXERCISE == 11)

struct node {
    int value;
    struct node *next;
};

struct node *add_to_list(struct node *list, int n);

// EXERCISE 11, count the number of times value n appears in
// a list of nodes
int count_occurences(struct node *list, int n);

// EXERCISE 12, find_last will return the node pointer point to 
// the last node that contains int n; if n doesn't 
// exist in list, then returns NULL;
struct node *find_last(struct node *list, int n);

// EXERCISE 13, fixing insert_into_ordered_list
struct node *insert_into_ordered_list(struct node *list, 
                                      struct node *new_node);

// EXERCISE 14, delete from list
void delete_from_list(struct node **list, int n);

int main(void) {
    struct node *first = NULL, *target, *test = NULL;
    int count;

    first = add_to_list(first, 6);
    first = add_to_list(first, 5);
    first = add_to_list(first, 4);
    first = add_to_list(first, 3);
    first = add_to_list(first, 2);
    first = add_to_list(first, 1);
    first = add_to_list(first, 0);
    
    target = find_last(first, 5);
    if (target)
        printf("%d\n", target->value);

    // testing for exercise 12
    printf("Counts: %d\n", count_occurences(first, 2));
    printf("Counts: %d\n", count_occurences(first, 3));

    // testing for exercise 13
    struct node *new_node1 = NULL, *new_node2 = NULL, *new_node3 = NULL;
    new_node1 = add_to_list(new_node1, -1);
    new_node2 = add_to_list(new_node2, 3);
    new_node3 = add_to_list(new_node3, 7);
    
    first = insert_into_ordered_list(first, new_node1);
    first = insert_into_ordered_list(first, new_node2);
    first = insert_into_ordered_list(first, new_node3);

    // testing for exercise 14
    delete_from_list(&first, 6);
    delete_from_list(&first, 5);
    delete_from_list(&first, 4);
    delete_from_list(&first, 3);
    delete_from_list(&first, 2);
    delete_from_list(&first, 1);
    delete_from_list(&first, 0);
    delete_from_list(&first, 3);
    delete_from_list(&first, 7);
    delete_from_list(&first, -1);    

    return 0;
}

struct node *add_to_list(struct node *list, int n) {
    struct node *temp;
    temp = malloc(sizeof(struct node));
    if (!temp)
        exit(EXIT_FAILURE);
    temp->value = n;
    temp->next = list;
    return temp;
}

struct node *find_last(struct node *list, int n) {
    struct node *temp, *last_node_has_n = NULL;
    for (temp = list; temp != NULL; temp = temp->next) {
        if (temp->value == n)
            last_node_has_n = temp;
    }
    return last_node_has_n;
}

int count_occurences(struct node *list, int n) {
    int c = 0;

    for (; list != NULL; list = list->next) {
        if (list->value == n)
            c++;
    }
    return c;
}

struct node *insert_into_ordered_list(struct node *list, 
                                      struct node *new_node) {
    struct node *cur = list, *prev = NULL;

    while (cur != NULL && cur->value <= new_node->value) {
        prev = cur;
        cur = cur->next;
    }

    if (prev != NULL) // in sert in the middle.
        prev->next = new_node;

    new_node->next = cur;

    if (prev == NULL) // new_node is on top        
        list = new_node;

    return list;
}

void delete_from_list(struct node **list, int n) {
    struct node *current_node, *previous_node;

    for (current_node = *list, previous_node = NULL; 
         current_node && current_node->value != n; 
           previous_node = current_node, \
           current_node = current_node->next)
        ;
    
    if (current_node == NULL) // first node is NULL, nothing to remove.
        return;
    
    if (previous_node == NULL) // n is in first node.
        *list = (*list)->next;
    else if (current_node->value == n) {                  
        previous_node->next = current_node->next;          
    }

    free(current_node);
}


#endif

#if (EXERCISE == 12)
int main(void) {

    // see count_occurrences() in exercise 11


    return 0;
}
#endif

#if (EXERCISE == 13)
int main(void) {

    // see count_occurrences() in exercise 11

    return 0;
}
#endif

#if (EXERCISE == 14)
struct node {
    int value;
    struct node *next;
};

void delete_from_list(struct node **list, int n);

int main(void) {

    // see delete_from_list() in exercise 11

    struct node *first = NULL;
    struct node *new_node;

    // setting up first node
    new_node = malloc(sizeof(struct node));
    new_node->value = 1;
    new_node->next = first;    
    first = new_node;

    // setting up second node
    new_node = malloc(sizeof(struct node));
    new_node->value = 2;
    new_node->next = first;
    first = new_node;

    // setting up third node
    new_node = malloc(sizeof(struct node));
    new_node->value = 3;
    new_node->next = first;
    first = new_node;

    delete_from_list(&first, 1);
    delete_from_list(&first, 2);
    delete_from_list(&first, 3);

    return 0;
}


void delete_from_list(struct node **list, int n) {
    struct node *current_node, *previous_node;

    // locate node where n resides in: 
    for (current_node = *list, previous_node = NULL; 
         current_node && current_node->value != n; 
           previous_node = current_node, \
           current_node = current_node->next)
        ;
    
    if (current_node == NULL) // first node is NULL, nothing to remove.
        return;
    
    if (previous_node == NULL) // n is in first node.
        *list = (*list)->next;
    else if (current_node->value == n) {                  
        previous_node->next = current_node->next;          
    }
    
    free(current_node);
}

#endif

#if (EXERCISE == 15)

int f1(int (*f) (int)); 
int f2(int i);
void f3(int (*f_a) (int), int (*f_b) (int));

int main(void) {

    printf("Answer: %d\n", f1(f2)); // 3
    f3(f2, f2);

    return 0;
}

int f1(int (*f) (int)) {
    int n = 0;
    while ((*f)(n))
        n++;
    return n;
}

int f2(int i) {
    return i * i + i - 12;
}

void f3(int (*f_a) (int), int (*f_b) (int)) {

    int a = 1, b = 2, c = 3;

    printf("a: %d, f_a(a) or (*f_b)(b): %d\n", a, (*f_a)(a));
    printf("b: %d, f_b(b) or (*f_b)(b): %d\n", b, f_b(b));
    printf("c: %d, f_a(c) or (*f_a)(c): %d\n", c, (*f_a)(c));

}
#endif

#if (EXERCISE == 16)

// sum  the output of (*f)(int) from start to end with increment of 1.
int sum(int (*f)(int), int start, int end);

// return i + 1; 
int offset_of_1(int i);

int main(void) {

    printf("start: 0, end: 3, result: %d\n", sum(offset_of_1, 0, 3)); // 1 + 2 + 3 + 4 = 10

    return 0;
}

int offset_of_1(int i) {
    return i + 1;
}

int sum(int (*f)(int), int start, int end) {
    int sum=0;
    
    while (start <= end) {
        sum += (*f)(start++);
    }
    return sum;

}

#endif

#if (EXERCISE == 17)

// compare two integers.
// if l > s, return 1
// if l < s, return -1
// if l == s, return 0
int compare_int(const void *a, const void *b);

int main(void) {
    int a[100];

    // this will sort the first 50 elements.
    qsort(a, 50, sizeof(int), compare_int);

    // this will sort the last 50 elements.
    qsort(a+50, 50, sizeof(int), compare_int);

    // book answer: 
    qsort(&a[50], 50, sizeof(a[50]), compare_int);

    return 0;
}

int compare_int(const void *a, const void *b) {
    const int *p = a;
    const int *q = b;
    if (*p > *q)
        return 1;
    else if (*p < *q)
        return -1;
    else
        return 0;
}

#endif

#if (EXERCISE == 18)
int main(void) {

    // ch17 exercise 18, compare_parts
    // for actual codes, see ch17 exercise 10
    // sorting inventory in ascending order.
    int compare_parts1(const void *p, const void *q) {
        const struct part *a = p;
        const struct part *b = q;
        return (a->number - b->number); // hopefully number are all positive.
    }

    // sorting inventory in descending order.
    int compare_parts2(const void *p, const void *q) {
        const struct part *a = p;
        const struct part *b = q;
        return (b->number - a->number); // hopefully number are all positive.
    }

    // This function is to validate ch17 exercise 18, 
    // compare_parts, sorting inventory in ascending order.
    void qsort_part_numbers1(void) {
        qsort(inventory, num_parts, sizeof(struct part), compare_parts1);
    }

    // compare_parts, sorting inventory in descending order.
    void qsort_part_numbers2(void) {
        qsort(inventory, num_parts, sizeof(struct part), compare_parts2);
    }

    return 0;
}
#endif


#if (EXERCISE == 19)
// creating a menu 
#define FUNCTION_NAME(f_name) f_name(void)
#define GEN_FUNCTION(f_name)                        \
         void FUNCTION_NAME(f_name) {               \
         printf("Function " #f_name " has been called.\n"); \
       }

void new_cmd(void);
void open_cmd(void);
void close_cmd(void);
void close_all_cmd(void);
void save_cmd(void);
void save_as_cmd(void);
void save_all_cmd(void);
void print_cmd(void);
void exit_cmd(void);

int read_line(char str[], int n);

struct menu {
    char *cmd_name;
    void (*cmd_pointer) (void);
} file_cmd[] = {
    {"new", new_cmd},
    {"open", open_cmd},
    {"close", close_cmd},
    {"close all", close_all_cmd},
    {"save", save_cmd},
    {"save as", save_as_cmd},
    {"save all", save_all_cmd},
    {"print", print_cmd},
    {"exit", exit_cmd}
};

int main(void) {
    char cmd_name_from_user[50];
    int i = 0;
    
    while (true) {
        printf("Enter the name of a command: ");
        //scanf("%s", &cmd_name_from_user);
        i = read_line(cmd_name_from_user, 3);
        for (i = 0; i < sizeof(file_cmd) / sizeof(struct menu); i++) {
            if (strcmp(file_cmd[i].cmd_name, (const char*) cmd_name_from_user) == 0) {
                file_cmd[i].cmd_pointer();
                break;
            }
        }
        if (i >= sizeof(file_cmd) / sizeof(struct menu))
            printf("Unknown command. Try agian.\n");
    }

    return 0;
}

GEN_FUNCTION(new_cmd)
GEN_FUNCTION(open_cmd)
GEN_FUNCTION(close_cmd)
GEN_FUNCTION(close_all_cmd)
GEN_FUNCTION(save_cmd)
GEN_FUNCTION(save_as_cmd)
GEN_FUNCTION(save_all_cmd)
GEN_FUNCTION(print_cmd)
GEN_FUNCTION(exit_cmd)

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  while (ch != '\n' && ch != EOF) {
    if (i < n)
      str[i++] = ch;
    ch = getchar();
  }
  str[i] = '\0';
  return i;
}


#endif