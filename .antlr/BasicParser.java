// Generated from /home/yorkin/prj/visualBasic/Basic.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class BasicParser extends Parser {
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
	public static final int
		RULE_exp = 0, RULE_statement = 1, RULE_forStmt = 2, RULE_foreachStmt = 3, 
		RULE_ifStmt = 4, RULE_loopStmt = 5, RULE_loopBody = 6;
	private static String[] makeRuleNames() {
		return new String[] {
			"exp", "statement", "forStmt", "foreachStmt", "ifStmt", "loopStmt", "loopBody"
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

	@Override
	public String getGrammarFileName() { return "Basic.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public BasicParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ExpContext extends ParserRuleContext {
		public TerminalNode Number() { return getToken(BasicParser.Number, 0); }
		public ExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exp; }
	}

	public final ExpContext exp() throws RecognitionException {
		ExpContext _localctx = new ExpContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_exp);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(14);
			match(Number);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public ForStmtContext forStmt() {
			return getRuleContext(ForStmtContext.class,0);
		}
		public LoopStmtContext loopStmt() {
			return getRuleContext(LoopStmtContext.class,0);
		}
		public IfStmtContext ifStmt() {
			return getRuleContext(IfStmtContext.class,0);
		}
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_statement);
		try {
			setState(19);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case For:
				enterOuterAlt(_localctx, 1);
				{
				setState(16);
				forStmt();
				}
				break;
			case While:
			case Do:
				enterOuterAlt(_localctx, 2);
				{
				setState(17);
				loopStmt();
				}
				break;
			case If:
				enterOuterAlt(_localctx, 3);
				{
				setState(18);
				ifStmt();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ForStmtContext extends ParserRuleContext {
		public List<TerminalNode> For() { return getTokens(BasicParser.For); }
		public TerminalNode For(int i) {
			return getToken(BasicParser.For, i);
		}
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public TerminalNode To() { return getToken(BasicParser.To, 0); }
		public TerminalNode Step() { return getToken(BasicParser.Step, 0); }
		public TerminalNode Next() { return getToken(BasicParser.Next, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode Exit() { return getToken(BasicParser.Exit, 0); }
		public ForStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forStmt; }
	}

	public final ForStmtContext forStmt() throws RecognitionException {
		ForStmtContext _localctx = new ForStmtContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_forStmt);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(21);
			match(For);
			setState(22);
			exp();
			setState(23);
			match(To);
			setState(24);
			exp();
			setState(25);
			match(Step);
			setState(26);
			exp();
			setState(30);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(27);
					statement();
					}
					} 
				}
				setState(32);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
			}
			setState(35);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Exit) {
				{
				setState(33);
				match(Exit);
				setState(34);
				match(For);
				}
			}

			setState(40);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << While) | (1L << Do) | (1L << For) | (1L << If))) != 0)) {
				{
				{
				setState(37);
				statement();
				}
				}
				setState(42);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(43);
			match(Next);
			setState(44);
			exp();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ForeachStmtContext extends ParserRuleContext {
		public List<TerminalNode> For() { return getTokens(BasicParser.For); }
		public TerminalNode For(int i) {
			return getToken(BasicParser.For, i);
		}
		public TerminalNode Each() { return getToken(BasicParser.Each, 0); }
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public TerminalNode Step() { return getToken(BasicParser.Step, 0); }
		public TerminalNode In() { return getToken(BasicParser.In, 0); }
		public TerminalNode Next() { return getToken(BasicParser.Next, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode Exit() { return getToken(BasicParser.Exit, 0); }
		public ForeachStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_foreachStmt; }
	}

	public final ForeachStmtContext foreachStmt() throws RecognitionException {
		ForeachStmtContext _localctx = new ForeachStmtContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_foreachStmt);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(46);
			match(For);
			setState(47);
			match(Each);
			setState(48);
			exp();
			setState(49);
			match(Step);
			setState(50);
			match(In);
			setState(51);
			exp();
			setState(55);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(52);
					statement();
					}
					} 
				}
				setState(57);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			}
			setState(60);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Exit) {
				{
				setState(58);
				match(Exit);
				setState(59);
				match(For);
				}
			}

			setState(65);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << While) | (1L << Do) | (1L << For) | (1L << If))) != 0)) {
				{
				{
				setState(62);
				statement();
				}
				}
				setState(67);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(68);
			match(Next);
			setState(69);
			exp();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IfStmtContext extends ParserRuleContext {
		public List<TerminalNode> If() { return getTokens(BasicParser.If); }
		public TerminalNode If(int i) {
			return getToken(BasicParser.If, i);
		}
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public List<TerminalNode> Then() { return getTokens(BasicParser.Then); }
		public TerminalNode Then(int i) {
			return getToken(BasicParser.Then, i);
		}
		public TerminalNode End() { return getToken(BasicParser.End, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public List<TerminalNode> ElseIf() { return getTokens(BasicParser.ElseIf); }
		public TerminalNode ElseIf(int i) {
			return getToken(BasicParser.ElseIf, i);
		}
		public TerminalNode Else() { return getToken(BasicParser.Else, 0); }
		public IfStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifStmt; }
	}

	public final IfStmtContext ifStmt() throws RecognitionException {
		IfStmtContext _localctx = new IfStmtContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_ifStmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(71);
			match(If);
			setState(72);
			exp();
			setState(73);
			match(Then);
			setState(77);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << While) | (1L << Do) | (1L << For) | (1L << If))) != 0)) {
				{
				{
				setState(74);
				statement();
				}
				}
				setState(79);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(91);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==ElseIf) {
				{
				{
				setState(80);
				match(ElseIf);
				setState(81);
				exp();
				setState(82);
				match(Then);
				setState(86);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << While) | (1L << Do) | (1L << For) | (1L << If))) != 0)) {
					{
					{
					setState(83);
					statement();
					}
					}
					setState(88);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				}
				setState(93);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(101);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Else) {
				{
				setState(94);
				match(Else);
				setState(98);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << While) | (1L << Do) | (1L << For) | (1L << If))) != 0)) {
					{
					{
					setState(95);
					statement();
					}
					}
					setState(100);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			setState(103);
			match(End);
			setState(104);
			match(If);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LoopStmtContext extends ParserRuleContext {
		public TerminalNode Do() { return getToken(BasicParser.Do, 0); }
		public TerminalNode While() { return getToken(BasicParser.While, 0); }
		public ExpContext exp() {
			return getRuleContext(ExpContext.class,0);
		}
		public LoopBodyContext loopBody() {
			return getRuleContext(LoopBodyContext.class,0);
		}
		public TerminalNode Loop() { return getToken(BasicParser.Loop, 0); }
		public TerminalNode Until() { return getToken(BasicParser.Until, 0); }
		public TerminalNode Wend() { return getToken(BasicParser.Wend, 0); }
		public LoopStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_loopStmt; }
	}

	public final LoopStmtContext loopStmt() throws RecognitionException {
		LoopStmtContext _localctx = new LoopStmtContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_loopStmt);
		try {
			setState(135);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(106);
				match(Do);
				setState(107);
				match(While);
				setState(108);
				exp();
				setState(109);
				loopBody();
				setState(110);
				match(Loop);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(112);
				match(Do);
				setState(113);
				match(Until);
				setState(114);
				exp();
				setState(115);
				loopBody();
				setState(116);
				match(Loop);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(118);
				match(Do);
				setState(119);
				loopBody();
				setState(120);
				match(Loop);
				setState(121);
				match(Until);
				setState(122);
				exp();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(124);
				match(Do);
				setState(125);
				loopBody();
				setState(126);
				match(Loop);
				setState(127);
				match(While);
				setState(128);
				exp();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(130);
				match(While);
				setState(131);
				exp();
				setState(132);
				loopBody();
				setState(133);
				match(Wend);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LoopBodyContext extends ParserRuleContext {
		public TerminalNode Exit() { return getToken(BasicParser.Exit, 0); }
		public TerminalNode Do() { return getToken(BasicParser.Do, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public LoopBodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_loopBody; }
	}

	public final LoopBodyContext loopBody() throws RecognitionException {
		LoopBodyContext _localctx = new LoopBodyContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_loopBody);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(140);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << While) | (1L << Do) | (1L << For) | (1L << If))) != 0)) {
				{
				{
				setState(137);
				statement();
				}
				}
				setState(142);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(143);
			match(Exit);
			setState(144);
			match(Do);
			setState(148);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << While) | (1L << Do) | (1L << For) | (1L << If))) != 0)) {
				{
				{
				setState(145);
				statement();
				}
				}
				setState(150);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\63\u009a\4\2\t\2"+
		"\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\3\2\3\2\3\3\3\3\3\3\5"+
		"\3\26\n\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\7\4\37\n\4\f\4\16\4\"\13\4\3\4\3"+
		"\4\5\4&\n\4\3\4\7\4)\n\4\f\4\16\4,\13\4\3\4\3\4\3\4\3\5\3\5\3\5\3\5\3"+
		"\5\3\5\3\5\7\58\n\5\f\5\16\5;\13\5\3\5\3\5\5\5?\n\5\3\5\7\5B\n\5\f\5\16"+
		"\5E\13\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\7\6N\n\6\f\6\16\6Q\13\6\3\6\3\6\3"+
		"\6\3\6\7\6W\n\6\f\6\16\6Z\13\6\7\6\\\n\6\f\6\16\6_\13\6\3\6\3\6\7\6c\n"+
		"\6\f\6\16\6f\13\6\5\6h\n\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7"+
		"\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3"+
		"\7\3\7\3\7\3\7\5\7\u008a\n\7\3\b\7\b\u008d\n\b\f\b\16\b\u0090\13\b\3\b"+
		"\3\b\3\b\7\b\u0095\n\b\f\b\16\b\u0098\13\b\3\b\2\2\t\2\4\6\b\n\f\16\2"+
		"\2\2\u00a5\2\20\3\2\2\2\4\25\3\2\2\2\6\27\3\2\2\2\b\60\3\2\2\2\nI\3\2"+
		"\2\2\f\u0089\3\2\2\2\16\u008e\3\2\2\2\20\21\7\3\2\2\21\3\3\2\2\2\22\26"+
		"\5\6\4\2\23\26\5\f\7\2\24\26\5\n\6\2\25\22\3\2\2\2\25\23\3\2\2\2\25\24"+
		"\3\2\2\2\26\5\3\2\2\2\27\30\7*\2\2\30\31\5\2\2\2\31\32\7&\2\2\32\33\5"+
		"\2\2\2\33\34\7\'\2\2\34 \5\2\2\2\35\37\5\4\3\2\36\35\3\2\2\2\37\"\3\2"+
		"\2\2 \36\3\2\2\2 !\3\2\2\2!%\3\2\2\2\" \3\2\2\2#$\7\"\2\2$&\7*\2\2%#\3"+
		"\2\2\2%&\3\2\2\2&*\3\2\2\2\')\5\4\3\2(\'\3\2\2\2),\3\2\2\2*(\3\2\2\2*"+
		"+\3\2\2\2+-\3\2\2\2,*\3\2\2\2-.\7(\2\2./\5\2\2\2/\7\3\2\2\2\60\61\7*\2"+
		"\2\61\62\7%\2\2\62\63\5\2\2\2\63\64\7\'\2\2\64\65\7)\2\2\659\5\2\2\2\66"+
		"8\5\4\3\2\67\66\3\2\2\28;\3\2\2\29\67\3\2\2\29:\3\2\2\2:>\3\2\2\2;9\3"+
		"\2\2\2<=\7\"\2\2=?\7*\2\2><\3\2\2\2>?\3\2\2\2?C\3\2\2\2@B\5\4\3\2A@\3"+
		"\2\2\2BE\3\2\2\2CA\3\2\2\2CD\3\2\2\2DF\3\2\2\2EC\3\2\2\2FG\7(\2\2GH\5"+
		"\2\2\2H\t\3\2\2\2IJ\7.\2\2JK\5\2\2\2KO\7/\2\2LN\5\4\3\2ML\3\2\2\2NQ\3"+
		"\2\2\2OM\3\2\2\2OP\3\2\2\2P]\3\2\2\2QO\3\2\2\2RS\7\5\2\2ST\5\2\2\2TX\7"+
		"/\2\2UW\5\4\3\2VU\3\2\2\2WZ\3\2\2\2XV\3\2\2\2XY\3\2\2\2Y\\\3\2\2\2ZX\3"+
		"\2\2\2[R\3\2\2\2\\_\3\2\2\2][\3\2\2\2]^\3\2\2\2^g\3\2\2\2_]\3\2\2\2`d"+
		"\7\60\2\2ac\5\4\3\2ba\3\2\2\2cf\3\2\2\2db\3\2\2\2de\3\2\2\2eh\3\2\2\2"+
		"fd\3\2\2\2g`\3\2\2\2gh\3\2\2\2hi\3\2\2\2ij\7\37\2\2jk\7.\2\2k\13\3\2\2"+
		"\2lm\7$\2\2mn\7#\2\2no\5\2\2\2op\5\16\b\2pq\7!\2\2q\u008a\3\2\2\2rs\7"+
		"$\2\2st\7 \2\2tu\5\2\2\2uv\5\16\b\2vw\7!\2\2w\u008a\3\2\2\2xy\7$\2\2y"+
		"z\5\16\b\2z{\7!\2\2{|\7 \2\2|}\5\2\2\2}\u008a\3\2\2\2~\177\7$\2\2\177"+
		"\u0080\5\16\b\2\u0080\u0081\7!\2\2\u0081\u0082\7#\2\2\u0082\u0083\5\2"+
		"\2\2\u0083\u008a\3\2\2\2\u0084\u0085\7#\2\2\u0085\u0086\5\2\2\2\u0086"+
		"\u0087\5\16\b\2\u0087\u0088\7\6\2\2\u0088\u008a\3\2\2\2\u0089l\3\2\2\2"+
		"\u0089r\3\2\2\2\u0089x\3\2\2\2\u0089~\3\2\2\2\u0089\u0084\3\2\2\2\u008a"+
		"\r\3\2\2\2\u008b\u008d\5\4\3\2\u008c\u008b\3\2\2\2\u008d\u0090\3\2\2\2"+
		"\u008e\u008c\3\2\2\2\u008e\u008f\3\2\2\2\u008f\u0091\3\2\2\2\u0090\u008e"+
		"\3\2\2\2\u0091\u0092\7\"\2\2\u0092\u0096\7$\2\2\u0093\u0095\5\4\3\2\u0094"+
		"\u0093\3\2\2\2\u0095\u0098\3\2\2\2\u0096\u0094\3\2\2\2\u0096\u0097\3\2"+
		"\2\2\u0097\17\3\2\2\2\u0098\u0096\3\2\2\2\21\25 %*9>COX]dg\u0089\u008e"+
		"\u0096";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}