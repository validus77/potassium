# potassium
Potassium is really designed to be as minimal as it can be and still be Turing complete and useful enough to develop a few functions. Potassiums mainfeatures are: 
* all types are double
* print( <expression> ) : statment to output value of an expression to std out
* let <id> <- <expression> : assigns a value to a varible 
* let <func>(<arg> <arg> ... <arg>) <- <expression> : define a funtion 
* if(<expression>) <expression> else <expresion> : if condtional statment
* expression can be typical arithmetic or logical expressions or funtion calls. 

Examples:
let var <- 42
let fib(x) <- if(x < 2) x else fib(x-2) + fib(x-1)
print(fib(var))

This project build two applcation 
* potassium-s a shell that runs Potassium code at the command line, this code is JIT compiled and exectued inplace 
* potassium-c this is a more tridional compiler that outout object code files that can be linked with C/C++ applcations
