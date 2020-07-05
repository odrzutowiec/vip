#ifndef MULTIBYTE_H
#define MULTIBYTE_H

#include <wchar.h>
#include <wctype.h>

typedef	wchar_t		RCHAR_T;
#define RCHAR_T_MAX	((1 << 24)-1)
typedef	wchar_t		CHAR_T;
#define	MAX_CHAR_T	0xffffff    /* XXXX */
typedef	u_int		UCHAR_T;
#define RCHAR_BIT	24

#define ISUPPER		iswupper
#define STRLEN		wcslen
#define STRTOL		wcstol
#define STRTOUL		wcstoul
#define SPRINTF		swprintf
#define STRCHR		wcschr
#define STRCMP		wcscmp
#define STRPBRK		wcspbrk
#define TOLOWER		towlower
#define TOUPPER		towupper
#define STRSET		wmemset

#define L(ch)		L ## ch

#define MEMCMP(to, from, n) 						    \
	memcmp(to, from, (n) * sizeof(*(to)))
#define	MEMMOVE(p, t, len)	memmove(p, t, (len) * sizeof(*(p)))
#define	MEMCPY(p, t, len)	memcpy(p, t, (len) * sizeof(*(p)))
/*
 * Like MEMCPY but return a pointer to the end of the copied bytes.
 * Glibc has a function mempcpy with the same purpose.
 */
#define MEMPCPY(p, t, len) \
	((void *)((char *)MEMCPY(p, t, len) + (len) * sizeof(*(p))))
#define SIZE(w)		(sizeof(w)/sizeof(*w))

#endif
