int chi_value(uint16_t* chi, int d, uint16_t x) {
    return (chi[x]/_2_to[d]) % 2;
}
void chi_T_code(uint16_t* chi, uint16_t x, uint16_t code[N] ) {
    for (int i = 0 ; i < N ; i++) code[i] = chi_value(chi, i, x);
}
void chi_S_code(uint16_t* chi, uint16_t y[N], uint16_t code[N] ) {
    for (int i = 0 ; i < N ; i++) code[i] = chi_value(chi, i, y[i]);
}
int code_vec_eq(uint16_t a[N], uint16_t b[N] ) {
    for (int i = 0 ; i < N ; i++) {if (a[i] != b[i]) return 0;}
    return 1;
}