/*
 * Simple isinf_sign.
 * Written by Anders Magnusson 2026-02-08.  Public domain.
 */

union ud {
	double d;
	unsigned int i[2];
};
#if __FLOAT_WORD_ORDER__ == __ORDER_BIG_ENDIAN__
#define dih	i[0]
#define dil	i[1]
#else
#define dih	i[1]
#define dil	i[0]
#endif
#define DOUBLE_INF      0x7ff00000
#define DOUBLE_SIGN	0x80000000

/*
 * If d is infinite, return -1 for -Inf or 1 for +Inf.
 */
int
__isinf_sign(double d)
{
	union ud ud;

	ud.d = d;

	if ((ud.dih & ~DOUBLE_SIGN) != DOUBLE_INF || ud.dil)
		return 0;	/* not inf */
	return ud.dih & DOUBLE_SIGN ? -1 : 1;
}
