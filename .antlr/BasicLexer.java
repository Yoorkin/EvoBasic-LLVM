// Generated from /home/yorkin/prj/visualBasic/Basic.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class BasicLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		Number=1, WS=2, ElseIf=3, Wend=4, From=5, Import=6, Namespace=7, Implement=8, 
		Type=9, Alias=10, Self=11, Static=12, Module=13, Public=14, Private=15, 
		Protected=16, Get=17, Set=18, Property=19, Var=20, Dim=21, Let=22, Return=23, 
		Function=24, Difference=25, Union=26, Case=27, Select=28, End=29, Until=30, 
		Loop=31, Exit=32, While=33, Do=34, Each=35, To=36, Step=37, Next=38, In=39, 
		For=40, Optional=41, Byval=42, Byref=43, If=44, Then=45, Else=46, Call=47, 
		Sub=48, As=49;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"Number", "WS", "ElseIf", "Wend", "From", "Import", "Namespace", "Implement", 
			"Type", "Alias", "Self", "Static", "Module", "Public", "Private", "Protected", 
			"Get", "Set", "Property", "Var", "Dim", "Let", "Return", "Function", 
			"Difference", "Union", "Case", "Select", "End", "Until", "Loop", "Exit", 
			"While", "Do", "Each", "To", "Step", "Next", "In", "For", "Optional", 
			"Byval", "Byref", "If", "Then", "Else", "Call", "Sub", "As", "A", "B", 
			"C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", 
			"Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "Number", "WS", "ElseIf", "Wend", "From", "Import", "Namespace", 
			"Implement", "Type", "Alias", "Self", "Static", "Module", "Public", "Private", 
			"Protected", "Get", "Set", "Property", "Var", "Dim", "Let", "Return", 
			"Function", "Difference", "Union", "Case", "Select", "End", "Until", 
			"Loop", "Exit", "While", "Do", "Each", "To", "Step", "Next", "In", "For", 
			"Optional", "Byval", "Byref", "If", "Then", "Else", "Call", "Sub", "As"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public BasicLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Basic.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\63\u01fd\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t"+
		" \4!\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t"+
		"+\4,\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64"+
		"\t\64\4\65\t\65\4\66\t\66\4\67\t\67\48\t8\49\t9\4:\t:\4;\t;\4<\t<\4=\t"+
		"=\4>\t>\4?\t?\4@\t@\4A\tA\4B\tB\4C\tC\4D\tD\4E\tE\4F\tF\4G\tG\4H\tH\4"+
		"I\tI\4J\tJ\4K\tK\4L\tL\3\2\5\2\u009b\n\2\3\2\6\2\u009e\n\2\r\2\16\2\u009f"+
		"\3\2\3\2\6\2\u00a4\n\2\r\2\16\2\u00a5\5\2\u00a8\n\2\3\2\3\2\5\2\u00ac"+
		"\n\2\3\2\6\2\u00af\n\2\r\2\16\2\u00b0\5\2\u00b3\n\2\3\3\3\3\3\3\3\3\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\7"+
		"\3\7\3\7\3\7\3\7\3\7\3\7\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\t\3"+
		"\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\n\3\n\3\n\3\n\3\n\3\13\3\13\3\13"+
		"\3\13\3\13\3\13\3\f\3\f\3\f\3\f\3\f\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\16\3"+
		"\16\3\16\3\16\3\16\3\16\3\16\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\20\3"+
		"\20\3\20\3\20\3\20\3\20\3\20\3\20\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3"+
		"\21\3\21\3\21\3\22\3\22\3\22\3\22\3\23\3\23\3\23\3\23\3\24\3\24\3\24\3"+
		"\24\3\24\3\24\3\24\3\24\3\24\3\25\3\25\3\25\3\25\3\26\3\26\3\26\3\26\3"+
		"\27\3\27\3\27\3\27\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\31\3\31\3\31\3"+
		"\31\3\31\3\31\3\31\3\31\3\31\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3"+
		"\32\3\32\3\32\3\33\3\33\3\33\3\33\3\33\3\33\3\34\3\34\3\34\3\34\3\34\3"+
		"\35\3\35\3\35\3\35\3\35\3\35\3\35\3\36\3\36\3\36\3\36\3\37\3\37\3\37\3"+
		"\37\3\37\3\37\3 \3 \3 \3 \3 \3!\3!\3!\3!\3!\3\"\3\"\3\"\3\"\3\"\3\"\3"+
		"#\3#\3#\3$\3$\3$\3$\3$\3%\3%\3%\3&\3&\3&\3&\3&\3\'\3\'\3\'\3\'\3\'\3("+
		"\3(\3(\3)\3)\3)\3)\3*\3*\3*\3*\3*\3*\3*\3*\3*\3+\3+\3+\3+\3+\3+\3,\3,"+
		"\3,\3,\3,\3,\3-\3-\3-\3.\3.\3.\3.\3.\3/\3/\3/\3/\3/\3\60\3\60\3\60\3\60"+
		"\3\60\3\61\3\61\3\61\3\61\3\62\3\62\3\62\3\63\3\63\3\64\3\64\3\65\3\65"+
		"\3\66\3\66\3\67\3\67\38\38\39\39\3:\3:\3;\3;\3<\3<\3=\3=\3>\3>\3?\3?\3"+
		"@\3@\3A\3A\3B\3B\3C\3C\3D\3D\3E\3E\3F\3F\3G\3G\3H\3H\3I\3I\3J\3J\3K\3"+
		"K\3L\3L\2\2M\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16"+
		"\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65\34"+
		"\67\359\36;\37= ?!A\"C#E$G%I&K\'M(O)Q*S+U,W-Y.[/]\60_\61a\62c\63e\2g\2"+
		"i\2k\2m\2o\2q\2s\2u\2w\2y\2{\2}\2\177\2\u0081\2\u0083\2\u0085\2\u0087"+
		"\2\u0089\2\u008b\2\u008d\2\u008f\2\u0091\2\u0093\2\u0095\2\u0097\2\3\2"+
		"\36\3\2\62;\4\2GGgg\7\2\13\f\17\17\"\"<<aa\4\2CCcc\4\2DDdd\4\2EEee\4\2"+
		"FFff\4\2HHhh\4\2IIii\4\2JJjj\4\2KKkk\4\2LLll\4\2MMmm\4\2NNnn\4\2OOoo\4"+
		"\2PPpp\4\2QQqq\4\2RRrr\4\2SSss\4\2TTtt\4\2UUuu\4\2VVvv\4\2WWww\4\2XXx"+
		"x\4\2YYyy\4\2ZZzz\4\2[[{{\4\2\\\\||\2\u01e9\2\3\3\2\2\2\2\5\3\2\2\2\2"+
		"\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2"+
		"\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2"+
		"\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2"+
		"\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2"+
		"\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2"+
		"\2\2A\3\2\2\2\2C\3\2\2\2\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2"+
		"M\3\2\2\2\2O\3\2\2\2\2Q\3\2\2\2\2S\3\2\2\2\2U\3\2\2\2\2W\3\2\2\2\2Y\3"+
		"\2\2\2\2[\3\2\2\2\2]\3\2\2\2\2_\3\2\2\2\2a\3\2\2\2\2c\3\2\2\2\3\u009a"+
		"\3\2\2\2\5\u00b4\3\2\2\2\7\u00b8\3\2\2\2\t\u00bf\3\2\2\2\13\u00c4\3\2"+
		"\2\2\r\u00c9\3\2\2\2\17\u00d0\3\2\2\2\21\u00da\3\2\2\2\23\u00e4\3\2\2"+
		"\2\25\u00e9\3\2\2\2\27\u00ef\3\2\2\2\31\u00f4\3\2\2\2\33\u00fb\3\2\2\2"+
		"\35\u0102\3\2\2\2\37\u0109\3\2\2\2!\u0111\3\2\2\2#\u011b\3\2\2\2%\u011f"+
		"\3\2\2\2\'\u0123\3\2\2\2)\u012c\3\2\2\2+\u0130\3\2\2\2-\u0134\3\2\2\2"+
		"/\u0138\3\2\2\2\61\u013f\3\2\2\2\63\u0148\3\2\2\2\65\u0153\3\2\2\2\67"+
		"\u0159\3\2\2\29\u015e\3\2\2\2;\u0165\3\2\2\2=\u0169\3\2\2\2?\u016f\3\2"+
		"\2\2A\u0174\3\2\2\2C\u0179\3\2\2\2E\u017f\3\2\2\2G\u0182\3\2\2\2I\u0187"+
		"\3\2\2\2K\u018a\3\2\2\2M\u018f\3\2\2\2O\u0194\3\2\2\2Q\u0197\3\2\2\2S"+
		"\u019b\3\2\2\2U\u01a4\3\2\2\2W\u01aa\3\2\2\2Y\u01b0\3\2\2\2[\u01b3\3\2"+
		"\2\2]\u01b8\3\2\2\2_\u01bd\3\2\2\2a\u01c2\3\2\2\2c\u01c6\3\2\2\2e\u01c9"+
		"\3\2\2\2g\u01cb\3\2\2\2i\u01cd\3\2\2\2k\u01cf\3\2\2\2m\u01d1\3\2\2\2o"+
		"\u01d3\3\2\2\2q\u01d5\3\2\2\2s\u01d7\3\2\2\2u\u01d9\3\2\2\2w\u01db\3\2"+
		"\2\2y\u01dd\3\2\2\2{\u01df\3\2\2\2}\u01e1\3\2\2\2\177\u01e3\3\2\2\2\u0081"+
		"\u01e5\3\2\2\2\u0083\u01e7\3\2\2\2\u0085\u01e9\3\2\2\2\u0087\u01eb\3\2"+
		"\2\2\u0089\u01ed\3\2\2\2\u008b\u01ef\3\2\2\2\u008d\u01f1\3\2\2\2\u008f"+
		"\u01f3\3\2\2\2\u0091\u01f5\3\2\2\2\u0093\u01f7\3\2\2\2\u0095\u01f9\3\2"+
		"\2\2\u0097\u01fb\3\2\2\2\u0099\u009b\7/\2\2\u009a\u0099\3\2\2\2\u009a"+
		"\u009b\3\2\2\2\u009b\u009d\3\2\2\2\u009c\u009e\t\2\2\2\u009d\u009c\3\2"+
		"\2\2\u009e\u009f\3\2\2\2\u009f\u009d\3\2\2\2\u009f\u00a0\3\2\2\2\u00a0"+
		"\u00a7\3\2\2\2\u00a1\u00a3\7\60\2\2\u00a2\u00a4\t\2\2\2\u00a3\u00a2\3"+
		"\2\2\2\u00a4\u00a5\3\2\2\2\u00a5\u00a3\3\2\2\2\u00a5\u00a6\3\2\2\2\u00a6"+
		"\u00a8\3\2\2\2\u00a7\u00a1\3\2\2\2\u00a7\u00a8\3\2\2\2\u00a8\u00b2\3\2"+
		"\2\2\u00a9\u00ab\t\3\2\2\u00aa\u00ac\7/\2\2\u00ab\u00aa\3\2\2\2\u00ab"+
		"\u00ac\3\2\2\2\u00ac\u00ae\3\2\2\2\u00ad\u00af\t\2\2\2\u00ae\u00ad\3\2"+
		"\2\2\u00af\u00b0\3\2\2\2\u00b0\u00ae\3\2\2\2\u00b0\u00b1\3\2\2\2\u00b1"+
		"\u00b3\3\2\2\2\u00b2\u00a9\3\2\2\2\u00b2\u00b3\3\2\2\2\u00b3\4\3\2\2\2"+
		"\u00b4\u00b5\t\4\2\2\u00b5\u00b6\3\2\2\2\u00b6\u00b7\b\3\2\2\u00b7\6\3"+
		"\2\2\2\u00b8\u00b9\5m\67\2\u00b9\u00ba\5{>\2\u00ba\u00bb\5\u0089E\2\u00bb"+
		"\u00bc\5m\67\2\u00bc\u00bd\5u;\2\u00bd\u00be\5o8\2\u00be\b\3\2\2\2\u00bf"+
		"\u00c0\5\u0091I\2\u00c0\u00c1\5m\67\2\u00c1\u00c2\5\177@\2\u00c2\u00c3"+
		"\5k\66\2\u00c3\n\3\2\2\2\u00c4\u00c5\5o8\2\u00c5\u00c6\5\u0081A\2\u00c6"+
		"\u00c7\5\u0087D\2\u00c7\u00c8\5}?\2\u00c8\f\3\2\2\2\u00c9\u00ca\5u;\2"+
		"\u00ca\u00cb\5}?\2\u00cb\u00cc\5\u0083B\2\u00cc\u00cd\5\u0081A\2\u00cd"+
		"\u00ce\5\u0087D\2\u00ce\u00cf\5\u008bF\2\u00cf\16\3\2\2\2\u00d0\u00d1"+
		"\5\177@\2\u00d1\u00d2\5e\63\2\u00d2\u00d3\5}?\2\u00d3\u00d4\5m\67\2\u00d4"+
		"\u00d5\5\u0089E\2\u00d5\u00d6\5\u0083B\2\u00d6\u00d7\5e\63\2\u00d7\u00d8"+
		"\5i\65\2\u00d8\u00d9\5m\67\2\u00d9\20\3\2\2\2\u00da\u00db\5u;\2\u00db"+
		"\u00dc\5}?\2\u00dc\u00dd\5\u0083B\2\u00dd\u00de\5{>\2\u00de\u00df\5m\67"+
		"\2\u00df\u00e0\5}?\2\u00e0\u00e1\5m\67\2\u00e1\u00e2\5\177@\2\u00e2\u00e3"+
		"\5\u008bF\2\u00e3\22\3\2\2\2\u00e4\u00e5\5\u008bF\2\u00e5\u00e6\5\u0095"+
		"K\2\u00e6\u00e7\5\u0083B\2\u00e7\u00e8\5m\67\2\u00e8\24\3\2\2\2\u00e9"+
		"\u00ea\5e\63\2\u00ea\u00eb\5{>\2\u00eb\u00ec\5u;\2\u00ec\u00ed\5e\63\2"+
		"\u00ed\u00ee\5\u0089E\2\u00ee\26\3\2\2\2\u00ef\u00f0\5\u0089E\2\u00f0"+
		"\u00f1\5m\67\2\u00f1\u00f2\5{>\2\u00f2\u00f3\5o8\2\u00f3\30\3\2\2\2\u00f4"+
		"\u00f5\5\u0089E\2\u00f5\u00f6\5\u008bF\2\u00f6\u00f7\5e\63\2\u00f7\u00f8"+
		"\5\u008bF\2\u00f8\u00f9\5u;\2\u00f9\u00fa\5i\65\2\u00fa\32\3\2\2\2\u00fb"+
		"\u00fc\5}?\2\u00fc\u00fd\5\u0081A\2\u00fd\u00fe\5k\66\2\u00fe\u00ff\5"+
		"\u008dG\2\u00ff\u0100\5{>\2\u0100\u0101\5m\67\2\u0101\34\3\2\2\2\u0102"+
		"\u0103\5\u0083B\2\u0103\u0104\5\u008dG\2\u0104\u0105\5g\64\2\u0105\u0106"+
		"\5{>\2\u0106\u0107\5u;\2\u0107\u0108\5i\65\2\u0108\36\3\2\2\2\u0109\u010a"+
		"\5\u0083B\2\u010a\u010b\5\u0087D\2\u010b\u010c\5u;\2\u010c\u010d\5\u008f"+
		"H\2\u010d\u010e\5e\63\2\u010e\u010f\5\u008bF\2\u010f\u0110\5m\67\2\u0110"+
		" \3\2\2\2\u0111\u0112\5\u0083B\2\u0112\u0113\5\u0087D\2\u0113\u0114\5"+
		"\u0081A\2\u0114\u0115\5\u008bF\2\u0115\u0116\5m\67\2\u0116\u0117\5i\65"+
		"\2\u0117\u0118\5\u008bF\2\u0118\u0119\5m\67\2\u0119\u011a\5k\66\2\u011a"+
		"\"\3\2\2\2\u011b\u011c\5q9\2\u011c\u011d\5m\67\2\u011d\u011e\5\u008bF"+
		"\2\u011e$\3\2\2\2\u011f\u0120\5\u0089E\2\u0120\u0121\5m\67\2\u0121\u0122"+
		"\5\u008bF\2\u0122&\3\2\2\2\u0123\u0124\5\u0083B\2\u0124\u0125\5\u0087"+
		"D\2\u0125\u0126\5\u0081A\2\u0126\u0127\5\u0083B\2\u0127\u0128\5m\67\2"+
		"\u0128\u0129\5\u0087D\2\u0129\u012a\5\u008bF\2\u012a\u012b\5\u0095K\2"+
		"\u012b(\3\2\2\2\u012c\u012d\5\u008fH\2\u012d\u012e\5e\63\2\u012e\u012f"+
		"\5\u0087D\2\u012f*\3\2\2\2\u0130\u0131\5k\66\2\u0131\u0132\5u;\2\u0132"+
		"\u0133\5}?\2\u0133,\3\2\2\2\u0134\u0135\5{>\2\u0135\u0136\5m\67\2\u0136"+
		"\u0137\5\u008bF\2\u0137.\3\2\2\2\u0138\u0139\5\u0087D\2\u0139\u013a\5"+
		"m\67\2\u013a\u013b\5\u008bF\2\u013b\u013c\5\u008dG\2\u013c\u013d\5\u0087"+
		"D\2\u013d\u013e\5\177@\2\u013e\60\3\2\2\2\u013f\u0140\5o8\2\u0140\u0141"+
		"\5\u008dG\2\u0141\u0142\5\177@\2\u0142\u0143\5i\65\2\u0143\u0144\5\u008b"+
		"F\2\u0144\u0145\5u;\2\u0145\u0146\5\u0081A\2\u0146\u0147\5\177@\2\u0147"+
		"\62\3\2\2\2\u0148\u0149\5k\66\2\u0149\u014a\5u;\2\u014a\u014b\5o8\2\u014b"+
		"\u014c\5o8\2\u014c\u014d\5m\67\2\u014d\u014e\5\u0087D\2\u014e\u014f\5"+
		"m\67\2\u014f\u0150\5\177@\2\u0150\u0151\5i\65\2\u0151\u0152\5m\67\2\u0152"+
		"\64\3\2\2\2\u0153\u0154\5\u008dG\2\u0154\u0155\5\177@\2\u0155\u0156\5"+
		"u;\2\u0156\u0157\5\u0081A\2\u0157\u0158\5\177@\2\u0158\66\3\2\2\2\u0159"+
		"\u015a\5i\65\2\u015a\u015b\5e\63\2\u015b\u015c\5\u0089E\2\u015c\u015d"+
		"\5m\67\2\u015d8\3\2\2\2\u015e\u015f\5\u0089E\2\u015f\u0160\5m\67\2\u0160"+
		"\u0161\5{>\2\u0161\u0162\5m\67\2\u0162\u0163\5i\65\2\u0163\u0164\5\u008b"+
		"F\2\u0164:\3\2\2\2\u0165\u0166\5m\67\2\u0166\u0167\5\177@\2\u0167\u0168"+
		"\5k\66\2\u0168<\3\2\2\2\u0169\u016a\5\u008dG\2\u016a\u016b\5\177@\2\u016b"+
		"\u016c\5\u008bF\2\u016c\u016d\5u;\2\u016d\u016e\5{>\2\u016e>\3\2\2\2\u016f"+
		"\u0170\5{>\2\u0170\u0171\5\u0081A\2\u0171\u0172\5\u0081A\2\u0172\u0173"+
		"\5\u0083B\2\u0173@\3\2\2\2\u0174\u0175\5m\67\2\u0175\u0176\5\u0093J\2"+
		"\u0176\u0177\5u;\2\u0177\u0178\5\u008bF\2\u0178B\3\2\2\2\u0179\u017a\5"+
		"\u0091I\2\u017a\u017b\5s:\2\u017b\u017c\5u;\2\u017c\u017d\5{>\2\u017d"+
		"\u017e\5m\67\2\u017eD\3\2\2\2\u017f\u0180\5k\66\2\u0180\u0181\5\u0081"+
		"A\2\u0181F\3\2\2\2\u0182\u0183\5m\67\2\u0183\u0184\5e\63\2\u0184\u0185"+
		"\5i\65\2\u0185\u0186\5s:\2\u0186H\3\2\2\2\u0187\u0188\5\u008bF\2\u0188"+
		"\u0189\5\u0081A\2\u0189J\3\2\2\2\u018a\u018b\5\u0089E\2\u018b\u018c\5"+
		"\u008bF\2\u018c\u018d\5m\67\2\u018d\u018e\5\u0083B\2\u018eL\3\2\2\2\u018f"+
		"\u0190\5\177@\2\u0190\u0191\5m\67\2\u0191\u0192\5\u0093J\2\u0192\u0193"+
		"\5\u008bF\2\u0193N\3\2\2\2\u0194\u0195\5u;\2\u0195\u0196\5\177@\2\u0196"+
		"P\3\2\2\2\u0197\u0198\5o8\2\u0198\u0199\5\u0081A\2\u0199\u019a\5\u0087"+
		"D\2\u019aR\3\2\2\2\u019b\u019c\5\u0081A\2\u019c\u019d\5\u0083B\2\u019d"+
		"\u019e\5\u008bF\2\u019e\u019f\5u;\2\u019f\u01a0\5\u0081A\2\u01a0\u01a1"+
		"\5\177@\2\u01a1\u01a2\5e\63\2\u01a2\u01a3\5{>\2\u01a3T\3\2\2\2\u01a4\u01a5"+
		"\5g\64\2\u01a5\u01a6\5\u0095K\2\u01a6\u01a7\5\u008fH\2\u01a7\u01a8\5e"+
		"\63\2\u01a8\u01a9\5{>\2\u01a9V\3\2\2\2\u01aa\u01ab\5g\64\2\u01ab\u01ac"+
		"\5\u0095K\2\u01ac\u01ad\5\u0087D\2\u01ad\u01ae\5m\67\2\u01ae\u01af\5o"+
		"8\2\u01afX\3\2\2\2\u01b0\u01b1\5u;\2\u01b1\u01b2\5o8\2\u01b2Z\3\2\2\2"+
		"\u01b3\u01b4\5\u008bF\2\u01b4\u01b5\5s:\2\u01b5\u01b6\5m\67\2\u01b6\u01b7"+
		"\5\177@\2\u01b7\\\3\2\2\2\u01b8\u01b9\5m\67\2\u01b9\u01ba\5{>\2\u01ba"+
		"\u01bb\5\u0089E\2\u01bb\u01bc\5m\67\2\u01bc^\3\2\2\2\u01bd\u01be\5i\65"+
		"\2\u01be\u01bf\5e\63\2\u01bf\u01c0\5{>\2\u01c0\u01c1\5{>\2\u01c1`\3\2"+
		"\2\2\u01c2\u01c3\5\u0089E\2\u01c3\u01c4\5\u008dG\2\u01c4\u01c5\5g\64\2"+
		"\u01c5b\3\2\2\2\u01c6\u01c7\5e\63\2\u01c7\u01c8\5\u0089E\2\u01c8d\3\2"+
		"\2\2\u01c9\u01ca\t\5\2\2\u01caf\3\2\2\2\u01cb\u01cc\t\6\2\2\u01cch\3\2"+
		"\2\2\u01cd\u01ce\t\7\2\2\u01cej\3\2\2\2\u01cf\u01d0\t\b\2\2\u01d0l\3\2"+
		"\2\2\u01d1\u01d2\t\3\2\2\u01d2n\3\2\2\2\u01d3\u01d4\t\t\2\2\u01d4p\3\2"+
		"\2\2\u01d5\u01d6\t\n\2\2\u01d6r\3\2\2\2\u01d7\u01d8\t\13\2\2\u01d8t\3"+
		"\2\2\2\u01d9\u01da\t\f\2\2\u01dav\3\2\2\2\u01db\u01dc\t\r\2\2\u01dcx\3"+
		"\2\2\2\u01dd\u01de\t\16\2\2\u01dez\3\2\2\2\u01df\u01e0\t\17\2\2\u01e0"+
		"|\3\2\2\2\u01e1\u01e2\t\20\2\2\u01e2~\3\2\2\2\u01e3\u01e4\t\21\2\2\u01e4"+
		"\u0080\3\2\2\2\u01e5\u01e6\t\22\2\2\u01e6\u0082\3\2\2\2\u01e7\u01e8\t"+
		"\23\2\2\u01e8\u0084\3\2\2\2\u01e9\u01ea\t\24\2\2\u01ea\u0086\3\2\2\2\u01eb"+
		"\u01ec\t\25\2\2\u01ec\u0088\3\2\2\2\u01ed\u01ee\t\26\2\2\u01ee\u008a\3"+
		"\2\2\2\u01ef\u01f0\t\27\2\2\u01f0\u008c\3\2\2\2\u01f1\u01f2\t\30\2\2\u01f2"+
		"\u008e\3\2\2\2\u01f3\u01f4\t\31\2\2\u01f4\u0090\3\2\2\2\u01f5\u01f6\t"+
		"\32\2\2\u01f6\u0092\3\2\2\2\u01f7\u01f8\t\33\2\2\u01f8\u0094\3\2\2\2\u01f9"+
		"\u01fa\t\34\2\2\u01fa\u0096\3\2\2\2\u01fb\u01fc\t\35\2\2\u01fc\u0098\3"+
		"\2\2\2\n\2\u009a\u009f\u00a5\u00a7\u00ab\u00b0\u00b2\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}