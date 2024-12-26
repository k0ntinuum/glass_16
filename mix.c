void mix_rows(uint16_t y[N], uint16_t z[N] ) {
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) z[i] |=  y[(i + j)%N] & (1 << (j % N));       
}
void unmix_rows(uint16_t y[N], uint16_t z[N] ) {
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) z[i] |=  y[( 2*N +i - j)%N] & (1 << (j % N));       
}
