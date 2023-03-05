#include "strings.h"

void
strings(void)
{
	char *str = "hi";   // string literal
	char a1[] = "abc";  // a1 is char[4] holding {'a','b','c','\0'}
	char a2[4] = "abc"; /* same as a1 */
	char a3[3] = "abc"; // holding {'a','b','c'}, missing the '\0'

	char *s = "foobar";
	s[0] = 'F'; // undefined behaviour

	// its good practise to denote them const, will save you on compile time
	char const *s1 = "foobar";
	// this would lead to compiler error
	// s1[0] = 'F';
}
