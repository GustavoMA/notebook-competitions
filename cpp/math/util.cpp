//mod always positive
int int_mod(int a, int b) {
  return (a % b + b) % b;
}
//exp of a number in O(log n)
int exp(int n, int e) {
    if (e == 0) return 1;
    if (e % 2  == 1) return n * exp(n, e-1);
    int half = exp(n, e/2);
    return half*half;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * (b / gcd(a,b));
}
