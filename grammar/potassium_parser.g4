parser grammar potassium_parser;
options {   tokenVocab = potassium_lexer; }

line        : statement (NEWLINE) ;

statement   : assignment    # assigmentStantment
            | print         # printStatment;

assignment  : LET ID ASSIGN  expression;

print       : PRINT LPAREN expression RPAREN;

expression  : left=expression op=(MULT|DIV) right=expression            # binaryOperation
            | left=expression op=(PLUS|MINUS) right=expression          # binaryOperation
            | LPAREN expression RPAREN                                  # parenExpression
            | ID                                                        # varReference
            | INTLIT                                                    # intLiteral
            | FLOATLIT                                                  # floatLiteral;
