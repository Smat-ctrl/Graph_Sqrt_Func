#include "cs136.h"

// c_sqrt(x) produces the squareroot value of a numbers by using 
// the subtraction method.
// requires: X to be positive
int c_sqrt(int x) {
    assert(x >= 0);
    int count = 0;
    for (int i = 1; i <= x; i += 2) {
        x -= i;
        count++; // subtracted deletion method
        if (x < 0) {
            break;
        }
    }
    return count;
}   
// print_x(n, max_val), prints the X value when the squareroot of a number 
// is equal to the current n value, else a space.
// requires: n and max_val must be positive
void print_x(int n, int max_val) {
    assert(n >= 0);
    assert(max_val >= 0);
    for (int i = 1; i <= max_val; i++) {
        if(c_sqrt(i) == n) {
          printf("X"); 
        }
        else {
          printf(" ");
        }
    }
    printf("\n");
}

// plot_sqrt(max_x) plots a graph for sqrt(1), ..., sqrt(max_x).
// requires: max_x must be positive
// effects:  produces output
void plot_sqrt(int max_x) {
    assert(max_x >= 0);
    int val_sqrt = c_sqrt(max_x);
    
    // y-axis
    for (int i = val_sqrt; i >= 1; i--) {
        if (i % 2 == 0) {
            printf("%2d |", i);
            print_x(i, max_x);
        } else {
            printf("   |");
            print_x(i, max_x);
        }
    }
    
    // x-axis
    printf("   +");
    for (int x_axis = 0; x_axis < max_x; x_axis++) {
        printf("-");
    }
    printf("\n");
}

int main(void) {
  int x_max = read_int();
  assert(x_max != READ_INT_FAIL);
  plot_sqrt(x_max);
}