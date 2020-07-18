parser grammar potassium_parser;
options {   tokenVocab = potassium_lexer; }

line        : statement (NEWLINE) ;

statement   : assignment            # assigmentStantment
            | function_assignment   # functionAssigmentStantment
            | print                 # printStatment;

assignment  : LET (MUT)? ID ASSIGN  expression  #initialAssigment
            | ID ASSIGN expression              #updateAssignment;

function_assignment : LET ID LPAREN ID* RPAREN ASSIGN  expression;

print       : PRINT LPAREN expression RPAREN;

expression  : LPAREN expression RPAREN                                  # parenExpression
            | block                                                     # blockExpression
            | left=expression op=(MULT|DIV|MOD) right=expression        # binaryOperation
            | left=expression op=(PLUS|MINUS) right=expression          # binaryOperation
            | NOT expression                                            # logicalUnaryOperation
            | left=expression op=(AND|OR|EQ|LT|GT) right=expression     # logicalBinaryOperation
            | cond_expresion                                            # condExpression
            | function_call                                             # funcCallExpression
            | while_loop                                                # whileStatment
            | ID                                                        # varReference
            | INTLIT                                                    # intLiteral
            | FLOATLIT                                                  # floatLiteral;

cond_expresion : IF LPAREN test_exp=expression RPAREN then_exp=expression                          #ifCond
               | IF LPAREN test_exp=expression RPAREN then_exp=expression ELSE else_exp=expression #ifElseCond;

function_call: ID LPAREN expression* RPAREN;

while_loop : WHILE LPAREN test=expression RPAREN body=expression;


block : LBRACKET NEWLINE*  ((expression | assignment) NEWLINE*)+ RBRACKET;

