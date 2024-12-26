void test_system(uint16_t T[card_T], uint16_t S[card_S], uint16_t p[N][N], uint16_t inv_p[N][N], uint16_t x) {
    uint16_t d = 0;
    uint16_t y[N];
    enc_p(T, S, p, x, y);
    d = dec_p(T, S, inv_p, y);
    bit_print_fwd(x,y);
    //bit_print_rvs(d,y);
    if (x != d) printf("\n\nFAILURE TO DECODE\n\n");
}

