
uint16_t permute_bits(uint16_t x, uint16_t* p) {
    uint16_t y = 0;
    for (int i = 0; i < N; i++) y += ((x/_2_to[i])%2)*_2_to[p[i]];
    return y;
}
uint16_t shift_bits(uint16_t x, uint16_t a) {
    return (x << a) | (x >> (N - a));
}



uint16_t _enc_p(uint16_t T[card_T], uint16_t S[card_S],  uint16_t p[N], int d, uint16_t x) {
    uint16_t r = 0;
    int code = chi_value(T, d, x);
    for (int i = 0; i < SEARCH_LIMIT; i++) {
        r = arc4random_uniform(card_S);
        if (chi_value(S, d, r) == code) return permute_bits(r,p);
    }
    printf("\nFAILURE TO ENCODE\n");
    return 0;
}



void enc_p(uint16_t T[card_T], uint16_t S[card_S], uint16_t p[N][N], uint16_t x, uint16_t y[N]) {
    uint16_t T_code[N], S_code[N], mixed_y[N] = {0};
    for (int i = 0; i < N; i++) {
        y[i] = _enc_p(T, S, p[i] , i, x);
    }
    //mix_rows(y, mixed_y);
    //for (int i = 0; i < N; i++) y[i] = mixed_y[i]; 
}

