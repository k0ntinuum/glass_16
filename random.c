void shuffle(uint16_t* f, int l) {
    int j = 0;int t = 0;
    for (int i = l - 1; i > 0; i -= 1) {
        j = arc4random_uniform(i+1);
        t = f[i];f[i] = f[j];f[j] = t;
    }
}
void create_perm(uint16_t* t, int L) {
    for (int i = 0; i < L ; i++) t[i] = i;
    shuffle(t, L);
}

int index(uint16_t* f, uint16_t k, uint16_t l) {
    for (int i = 0; i < l; i++)
        if (f[i] == k ) return i;
    return -1;
}
void invert(uint16_t* f, uint16_t* g, uint16_t l) {
    for (uint16_t i = 0; i < l; i++) g[i] = index(f, i, l);
}

void shift_perm(uint16_t* f, uint16_t* g, uint16_t a, uint16_t l) {
    uint16_t s[N];
    //for (int i = 0; i < l; i++) s[i] = f[(i+a)%l];
    for (int i = 0; i < l; i++) s[i] = (f[i] + a)%l;
    for (int i = 0; i < l; i++) g[i] = s[i];
}
