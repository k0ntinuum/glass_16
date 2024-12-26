#define N 16 //bits in elements of T
#define M 16 //bits in elements of S 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "constant.c"
#include "text.c"
#include "chi.c"
#include "mix.c"
#include "print.c"
#include "random.c"
#include "enc.c"
#include "dec.c"
#include "test.c"





int main() {
    uint16_t x = 120;
    uint16_t y[N]= {0};
    uint16_t z[N]= {0};
    uint16_t T[card_T] = {0};
    uint16_t S[card_S] = {0};
    int Y[N][N] ={0};
    uint16_t p[N][N] = {0};
    uint16_t p_inv[N][N] = {0};
    srand(time(NULL));
    create_perm(T, card_T);
    create_perm(S, card_S);
    for (int i = 0 ; i < N; i++ ) {
        create_perm(p[i], N);
        invert(p[i],p_inv[i],N);
    }
    hide_cursor();
    cls();
    for (int t = 0; t < 2000000; t++) {
        x = arc4random_uniform(card_T);
        for (int i = 0; i < 100; i++) {
            cursor_to(2,0);
            test_system(T, S, p, p_inv, x);
            usleep(200000);
        }
        
    }
    

}
      