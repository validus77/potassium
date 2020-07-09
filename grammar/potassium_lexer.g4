lexer grammar potassium_lexer;


/** Whitespace **/
NEWLINE     : '\r\n' | '\r' | '\n';
WS          : [\t ]+ -> skip;

/** Litternals **/
INTLIT      : '0'|[1-9][0-9]*;
FLOATLIT    : '0'|[1-9][0-9]* '.' [0-9]+;

/** Keywords **/

LET         : 'let';
PRINT       : 'print';

IF          : 'if';
ELSE        : 'else';
WHILE       : 'while';

/** Operators **/
 PLUS       : '+';
 MINUS      : '-';
 MULT       : '*';
 DIV        : '/';
 MOD        : '%';
 ASSIGN     : '<-';
 LPAREN     : '(';
 RPAREN     : ')';
 AND        : '&';
 OR         : '|';
 EQ         : '=';
 XOR        : '^';
 NOT        : '!';
 LT         : '<';
 GT         : '>';
 /** Identifiers **/

 ID         : [_]*[a-z][A-Za-z0-9_]*;



