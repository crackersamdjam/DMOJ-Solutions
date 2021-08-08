int setbits(unsigned long long n){
    return __builtin_popcount(n)+__builtin_popcount(n>>32);
}