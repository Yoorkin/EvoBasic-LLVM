grammar Basic;
statements:statement*;
exp: Number;
statement:forStmt|loopStmt|ifStmt;

forStmt: For exp To exp Step exp statement* (Exit For)? statement* Next exp;
foreachStmt: For Each exp Step In exp statement* (Exit For)? statement* Next exp;
ifStmt:If exp Then statement* (ElseIf exp Then statement*)* (Else statement*)? End If;

loopStmt : Do While exp loopBody? Loop
        | Do Until exp loopBody? Loop
        | Do loopBody? Loop Until exp
        | Do loopBody? Loop While exp
        | While exp loopBody? Wend
        ;

loopBody : statement* Exit Do statement*;

//-234.233e-6
Number: '-'?[0-9]+('.'[0-9]+)?(('E'|'e') '-'? [0-9]+)?;

Comment: '\'' ~('\r'|'\n')*  -> skip;
BlockComment: '\'*' .* '*\'' -> skip;
WS: [ \n\t\r_:]->skip;

ElseIf:E L S E I F;
Wend:W E N D;
From:F O R M;
Import:I M P O R T;
Namespace:N A M E S P A C E;
Implement:I M P L E M E N T;
Type: T Y P E;
Alias:A L I A S;
Self:S E L F;
Static:S T A T I C;
Module:M O D U L E;
Public:P U B L I C;
Private:P R I V A T E;
Protected:P R O T E C T E D;
Get:G E T;
Set:S E T;
Property:P R O P E R T Y;
Var:V A R;
Dim:D I M;
Let:L E T;
Return: R E T U R N;
Function:F U N C T I O N;
Difference: D I F F E R E N C E;
Union: U N I O N;
Case:C A S E;
Select:S E L E C T;
End:E N D;
Until:U N T I L;
Loop:L O O P;
Exit:E X I T;
While: W H I L E;
Do: D O;
Each: E A C H;
To: T O;
Step:S T E P;
Next: N E X T;
In: I N;
For: F O R;
Optional: O P T I O N A L;
Byval:B Y V A L;
Byref:B Y R E F;
If:I F;
Then:T H E N;
Else:E L S E;
Call:C A L L;
Sub:S U B;
As: A S;

fragment A:('a'|'A');
fragment B:('b'|'B');
fragment C:('c'|'C');
fragment D:('d'|'D');
fragment E:('e'|'E');
fragment F:('f'|'F');
fragment G:('g'|'G');
fragment H:('h'|'H');
fragment I:('i'|'I');
fragment J:('j'|'J');
fragment K:('k'|'K');
fragment L:('l'|'L');
fragment M:('m'|'M');
fragment N:('n'|'N');
fragment O:('o'|'O');
fragment P:('p'|'P');
fragment Q:('q'|'Q');
fragment R:('r'|'R');
fragment S:('s'|'S');
fragment T:('t'|'T');
fragment U:('u'|'U');
fragment V:('v'|'V');
fragment W:('w'|'W');
fragment X:('x'|'X');
fragment Y:('y'|'Y');
fragment Z:('z'|'Z');