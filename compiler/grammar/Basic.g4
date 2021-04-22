grammar Basic;

moduleBody: (declare|LineEnd)* EOF;

declare: /*(Public|Private|Friend)?*/ functionDecl|subDecl|varDecl|typeDecl;

typeDecl:Type name=ID LineEnd (variable? LineEnd)* End Type LineEnd;

varDecl: Dim variable (','variable)* LineEnd;

variable: name=ID As type=varType ('=' initial=exp)?;

functionDecl:Function name=ID '(' (variable (','variable)*)? ')' As returnType=ID LineEnd block+=line* End Function LineEnd;

subDecl: Sub name=ID ('(' (variable (','variable)*)? ')')? LineEnd block+=line* End Sub LineEnd;

varType: (ID);

line:statement|LineEnd;

statement:forStmt
        |foreachStmt
        |loopStmt
        |ifStmt
        |exitStmt
        |returnStmt
        |assignStmt
        |callStmt
        |varDecl
        ;

callStmt: Call ID '('(passArg(','passArg)*) ')' LineEnd
        | Call ID ('('')')? LineEnd
        | ID (passArg(','passArg)*)  LineEnd
        | ID LineEnd
        ;

innerCall: ID '(' (passArg (','passArg?)*) ')'
        | ID ('(' ')')?
        ;

passArg:value=exp                       #ArgPassValue
       |                                #ArgIgnore
       |option=ID ('='|'=:') value=exp  #ArgOptional
       ;

assignStmt: left=ID '=' right=exp LineEnd;

exitStmt:Exit exitFlag=(For|Do|Sub|Function) LineEnd;

returnStmt:Return exp LineEnd;

exp: '-' right=exp                                      #NegOp
    | left=exp op=('&'|'|')     right=exp               #BitOp
    | left=exp op=('^'|'mod')       right=exp           #PowModOp
    | left=exp op=('*'|'/'|'\\')    right=exp           #MulOp
    | left=exp op=('+'|'-')         right=exp           #PluOp
    | left=exp op=('='|'>'|'<'|'<='|'=<'|'<>'|'>='|'=>') right=exp #CmpOp
    | op='not' right=exp                                #LogicNotOp
    | left=exp op=('and'|'or'|'xor') right=exp          #LogicOp
    | innerCall                                         #InnerCallOp
    | '('exp')'                                         #Bucket
    | Integer                                           #Integer
    | Decimal                                           #Decimal
    | String                                            #String
    | ID                                                #ID
    | Boolean                                           #Boolean
    ;

foreachStmt: For Each (iterator=exp|Dim name=ID (As type=varType)?) In group=exp LineEnd block+=line* Next nextFlag=ID? LineEnd;
forStmt: For (iterator=ID|Dim iterator=ID (As type=varType)?) '=' begin=exp To end=exp (Step step=exp)? LineEnd block+=line* Next nextFlag=ID? LineEnd;

ifStmt: If condition=exp Then statement (Else elseStatement=statement)? LineEnd           #SingleLineIf
        | If ifBlock (ElseIf ifBlock)* (Else LineEnd elseBlock+=line*)? End If LineEnd    #MutiLineIf
        ;

ifBlock: condition=exp Then LineEnd block+=line* ;

loopStmt : Do While exp LineEnd block+=line* Loop LineEnd #DoWhile
        | Do Until exp LineEnd block+=line* Loop LineEnd #DoUntil
        | Do LineEnd block+=line* Loop Until exp LineEnd #LoopUntil
        | Do LineEnd block+=line* Loop While exp LineEnd #LoopWhile
        | While exp LineEnd block+=line* Wend LineEnd    #WhileWend
        ;

//-234.233e-6
//Number: [0-9]+('.'[0-9]+)?(('E'|'e') '-'? [0-9]+)?;
Integer: [0-9]+;
Decimal: [0-9]+'.'[0-9]+ | [0-9]+('E'|'e')'-'?[0-9]+;
String: '"' ~('"'|'\r'|'\n')* '"';
Boolean: T R U E | F A L S E;

Comment: '\'' ~('\r'|'\n')*  -> skip;
BlockComment: '\'*' .*? '*\'' -> skip;
LineEnd: [\n\r];
WS: [ \t]->skip;

If:I F;
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
Then:T H E N;
Else:E L S E;
Call:C A L L;
Sub:S U B;
As: A S;
ID: [a-zA-Z_][a-zA-Z0-9_]*;

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