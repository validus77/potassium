parser grammar potassium_parser;
options {   tokenVocab = potassium_lexer; }

line        : statement (NEWLINE) ;

statement   : assignment            # assigmentStantment
            | function_assignment   # functionAssigmentStantment
            | print                 # printStatment;

assignment  : LET ID ASSIGN  expression;
function_assignment : LET ID LPAREN ID* RPAREN ASSIGN  expression;

print       : PRINT LPAREN expression RPAREN;

expression  : left=expression op=(MULT|DIV) right=expression            # binaryOperation
            | left=expression op=(PLUS|MINUS) right=expression          # binaryOperation
            | function_call                                             # funcCallExpression
            | NOT expression                                            # logicalUnaryOperation
            | left=expression op=(AND|OR|EQ|LT|GT) right=expression     # logicalBinaryOperation
            | LPAREN expression RPAREN                                  # parenExpression
            | cond_expresion                                            # condExpression
            | ID                                                        # varReference
            | INTLIT                                                    # intLiteral
            | FLOATLIT                                                  # floatLiteral;

cond_expresion : IF LPAREN test_exp=expression RPAREN then_exp=expression                          #ifCond
               | IF LPAREN test_exp=expression RPAREN then_exp=expression ELSE else_exp=expression #ifElseCond;

function_call: ID LPAREN expression* RPAREN;

