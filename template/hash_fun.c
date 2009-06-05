
const int M = 99997;
int get_hash_pos(char *key){
    unsigned long h=0;
    while(*key){
        h = (h<<4) + *key++;
        unsigned long g = h & 0xf0000000L;
        if(g)
            h ^= g >> 24;
        h &= ~g;
    }
    return h%M;
}
