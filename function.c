// I/O
#include <stdio.h>
// string process
#include <string.h>
// math operate
#include <math.h>
//memory management
#include <stdlib.h>
//
#include <time.h>

// global variable init = 0
// global variable cannot init function or another var
int i;
// static global var only run in this file
static int s_i;

int function_f(int);
int f(int);
int recurrence(int);

int function_t (int x) {
 return x + 5;
}

int c_standard_function_int (int x) {
    printf("sqrt %d = %f\n", x, sqrt(x));
    return 0;
}

int add(int a, int b) {
    return a + b;
}

int calculate(int (*op)(int, int)) {
    int result = 1;
    for (int i=2; i<=5; i++) {
        result = op(result, i);
    }
    return result;
}

int main (void) {
    printf("i = %d\n", i);
    // // local variable
    // int i = 3;
    // {
    //     int i = 4;
    //     printf("%d\n", i);
    // }
    // printf("%d\n", function_f(3));
    // printf("%d\n", function_t(3));
    // c_standard_function_int(3);
    // return 0;

    // //設定時間亂數軸，讓rand隨機seed
    // srand(time(0));
    // int i;
    // for (i = 1; i<=5; ++i) {
    //     int dice = rand() % 6 + 1;
    //     printf("%d\n", dice);
    // }

    // f(0);
    // return 0;

    int n;
    printf("recurrence function test - input a number: ");
    scanf("%d", &n);
    printf("%d\n", recurrence(n));

    void hello(); //宣告function hello
    void (*func)() = &hello; // 宣告定義func為一個指標指向為一個指標指向function hello
    (*func)(); // 呼叫function
    func();

    printf("%d\n", calculate(add));
    return 0;
}

void hello() {
    printf("hello world!\n");
}

int function_f(int x) {
 return x + 4;
}

int f(int i) {
    if(i < 10) {
        printf("%d\n", i);
        return f(++i);
        // // 會0無限遞回，因為i++是傳i值到下一步，++i是傳i+1到下一步
        // return f(i++);
    } else {
        return i;
    }
}

int recurrence(int n) {
    if (n <= 2) {
        return n;
    }
    return recurrence(n-1) + recurrence(n-2);
}