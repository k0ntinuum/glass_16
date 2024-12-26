void print_bit(int b) { b == 0 ? printf("O ") : printf("| "); }
void print_v(int* v, int L) { for (int i = 0; i < L; i++) print_bit(v[i]); }
void print_bits(uint16_t x ) {
    for (int i = 0 ; i < 16; i++ ) print_bit((x & ( 1 << i))>>i);
    //printf("\n");
}

void bit_print_fwd(uint16_t x, uint16_t y[N]) {
    printf("\n\n   ");print_bits(x);printf("\n\n");
    for (int i = 0; i < N; i++) {printf("   ");print_bits(y[i]);printf("\n");}
}

void bit_print_rvs(uint16_t d, uint16_t y[N]) {
    //printf("\n\ng\n");
    //for (int i = 0; i < N; i++) {printf("   ");print_bits(y[i]);printf("\n");}
    printf("\n   ");print_bits(d);printf("\n\n"); 
}
void print_y(uint16_t y[N]) {
    for (int i = 0; i < N; i++) {printf("   ");print_bits(y[i]);printf("\n");}
    printf("\n");
}
void check_mixer() {
    uint16_t x[N]={0};uint16_t y[N] = {0}; uint16_t z[N] = {0};
    for (int i = 0; i < N; i++) x[i] = arc4random_uniform(card_T);
    mix_rows(x,y);
    unmix_rows(y,z);
    for (int i = 0; i < N; i++) printf("x[%2d] = %5d    z[%2d] = %8d \n", i,  x[i], i, z[i] );
    print_y(x);
    print_y(y);
    //print_y(z);



}

