# Macros

## A string that will be expanded in the __pre compilation phase, can either be a constact, decide which part will be kept or even contain some functionality__

### Essentially, when the fragment is called, __the code will be replaced in place__

## __Two kinds of macros__

* ### __Object like, they define some value__

* ### __Function like, they perform an operation__

* #### They are defined with a set of parentheses right after the macro name

* #### They can take arguments, just like functions

```
#define DEBUG 1
#ifdef DEBUG
#define LOGFILENAME "/tmp/logfile.log"
#define LOG(str)                                                     \
	do {                                                         \
		FILE *fp = fopen(LOGFILENAME, "a");                  \
		if (fp) {                                            \
			fprintf(fp, "%s:%d %s\n", __FILE__,          \
			    __LINE__, /* don't print null pointer */ \
			    str ? str : "<null>");                   \
			fclose(fp);                                  \
		} else {                                             \
			perror("Opening '" LOGFILENAME "' failed");  \
		}                                                    \
	} while (0)
#else
// NOOP if DEBUG is not defined
#define LOG(LINE) (void)0
#endif

```

## __String like macros__

* ### Convert the expression to a string constant via the __#__ operator

* ### Concatenate via the __##__ operator

## __Pitfalls__

* ### Use __(arg)__ when invoking an argument

* ### Do not call a macro with a semicolon, __it will be expanded on its own__

* ### __Try passing concrete values__, in case of calling a function within a macro, it will be expanded as a name and thus will be called twice

* ### __Never let a macro expand on its own__

## __Generic selection__

* ### __Choose several expressions at compile time based on the type of the controlling expression__