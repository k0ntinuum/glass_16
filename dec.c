
uint16_t dec_p(uint16_t T[card_T], uint16_t S[card_S], uint16_t p_inv[N][N], uint16_t y[N]) {
    uint16_t T_code[N], unmixed_y[N]={0};
    uint16_t S_code[N];
    //unmix_rows(y, unmixed_y);
    //for (int i = 0; i < N; i++) y[i] = unmixed_y[i];
    for (int i = 0 ; i < N; i++) y[i] = permute_bits(y[i], p_inv[i]);
    chi_S_code(S, y, S_code);
    for (uint16_t i = 0; i < card_T; i++) {
        chi_T_code(T, T[i], T_code);
        if (code_vec_eq(T_code, S_code)) return T[i];
    }
    return 0;
}