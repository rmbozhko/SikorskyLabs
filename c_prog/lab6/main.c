#include <stdlib.h>
#include <gmp.h>
#include <stdio.h>
#include <math.h>
 
#define mpq_for(buf, op, n)\
    do {\
        size_t i;\
        for (i = 0; i < (n); ++i)\
            mpq_##op(buf[i]);\
    } while (0)
 
void bernoulli_sequence(mpq_t rop, unsigned int n)
{
    unsigned int m, j;
    mpq_t *a = malloc(sizeof(mpq_t) * (n + 1));
    mpq_for(a, init, n + 1);
 
    for (m = 0; m <= n; ++m) {
        mpq_set_ui(a[m], 1, m + 1);
        for (j = m; j > 0; --j) {
            mpq_sub(a[j-1], a[j], a[j-1]);
            mpq_set_ui(rop, j, 1);
            mpq_mul(a[j-1], a[j-1], rop);
        }
    }
 
    mpq_set(rop, a[0]);
    mpq_for(a, clear, n + 1);
    free(a);
}
 
int main(void)
{
    mpq_t         rop;
    mpz_t         n, d;
    unsigned int  i;
    int           precision;
    double        res;
    double        x;

    res = 0;
    mpq_init(rop);
    mpz_inits(n, d, NULL);

    printf("Enter function series precision(max 34): ");
    scanf("%d", &precision);

    if (precision <= 34) {
      printf("x | tan(x) | series tan(x)\n");
      for (x = -(M_PI_2) + 0.1; x < (M_PI_2); x += 0.1) {
        for (i = 0; i <= precision; ++i) {
            bernoulli_sequence(rop, i);
            if (mpq_cmp_ui(rop, 0, 1)) {
                mpq_get_num(n, rop);
                mpq_get_den(d, rop);

                //printf("TEMP: %d, %d %ld, %ld\n", n->_mp_size, d->_mp_size, n->_mp_d[0], d->_mp_d[0]);
            }
        }
        printf("%f | %f | %f\n", x, res, tan(x));
      }
    }
    mpz_clears(n, d, NULL);
    mpq_clear(rop);
    return ((precision <= 34) ? 0 : 1);
}