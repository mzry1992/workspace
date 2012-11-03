struct Hash {
static const int mask = 0x7fff;
int p[32768], q[32768];

void clear() {
for (int i = 0; i <= mask; ++i) {
q[i] = -1;
}
}

int& operator[](int k) {
int i = k & mask;
for (int j = 0; q[i] != -1 && p[i] != k; i = (i + 1) & mask) {
continue;
}
p[i] = k;
return q[i];
}
} hash;
