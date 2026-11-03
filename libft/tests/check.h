#ifndef CHECK_H
# define CHECK_H

/* Test-only helpers: this folder is never turned in. */

# include "../libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

static int	g_fail;

# define FAIL(...) do { \
	g_fail++; \
	printf("KO %s:%d  ", __FILE__, __LINE__); \
	printf(__VA_ARGS__); \
	printf("\n"); \
} while (0)

# define CHECK(cond) do { \
	if (!(cond)) \
		FAIL("%s", #cond); \
} while (0)

# define CHECK_INT(got, want) do { \
	long	g_ = (got); \
	long	w_ = (want); \
	if (g_ != w_) \
		FAIL("%s: got %ld, expected %ld", #got, g_, w_); \
} while (0)

# define CHECK_STR(got, want) do { \
	const char	*g_ = (got); \
	const char	*w_ = (want); \
	if (!g_ || !w_ ? g_ != w_ : strcmp(g_, w_)) \
		FAIL("%s: got \"%s\", expected \"%s\"", #got, \
			g_ ? g_ : "NULL", w_ ? w_ : "NULL"); \
} while (0)

/* prints one summary line, returns the exit status for main */
static int	done(const char *name)
{
	printf("%s %s\n", g_fail ? "KO" : "OK", name);
	return (g_fail != 0);
}

#endif
