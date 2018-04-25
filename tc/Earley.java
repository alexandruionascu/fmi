import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class Earley {

	public interface ProductionTerm {
	}

	public static class Terminal implements ProductionTerm {
		public final String value;

		public Terminal(String value) {
			this.value = value;
		}

		@Override
		public String toString() {
			return value;
		}

		@Override
		public boolean equals(Object other) {
			if (this == other) {
				return true;
			}
			if (other == null) {
				return false;
			}
			if (other instanceof String) {
				return value.equals((String) other);
			} else if (other instanceof Terminal) {
				return value.equals(((Terminal) other).value);
			}
			return false;
		}
	}

	public static class Production implements Iterable<ProductionTerm> {
		public final List<ProductionTerm> terms;
		public final List<Rule> rules;

		public Production(ProductionTerm... terms) {
			this.terms = Arrays.asList(terms);
			this.rules = getRules();
		}

		public Production(Object... terms) {
			this.terms = new ArrayList<ProductionTerm>(terms.length);
			for (Object item : terms) {
				if (item instanceof String) {
					this.terms.add(new Terminal((String) item));
				} else if (item instanceof ProductionTerm) {
					this.terms.add((ProductionTerm) item);
				} else {
					throw new IllegalArgumentException("Term must be ProductionTerm or String, not " + item);
				}
			}
			this.rules = getRules();
		}

		public int size() {
			return terms.size();
		}

		public ProductionTerm get(int index) {
			return terms.get(index);
		}

		@Override
		public Iterator<ProductionTerm> iterator() {
			return terms.iterator();
		}

		private List<Rule> getRules() {
			ArrayList<Rule> rules = new ArrayList<Rule>();
			for (ProductionTerm term : terms) {
				if (term instanceof Rule) {
					rules.add((Rule) term);
				}
			}
			return rules;
		}

		@Override
		public boolean equals(Object other) {
			if (this == other) {
				return true;
			}
			if (other == null || other.getClass() != getClass()) {
				return false;
			}
			return terms.equals(((Production) other).terms);
		}

		@Override
		public String toString() {
			String s = "";
			if (!terms.isEmpty()) {
				for (int i = 0; i < terms.size() - 1; i++) {
					ProductionTerm t = terms.get(i);
					if (t instanceof Rule) {
						s += ((Rule) t).name;
					} else {
						s += t;
					}
					s += " ";
				}
				ProductionTerm t = terms.get(terms.size() - 1);
				if (t instanceof Rule) {
					s += ((Rule) t).name;
				} else {
					s += t;
				}
			}
			return s;
		}
	}

	// tranzitie lambda
	public static final Production Lambda = new Production();

	public static class Rule implements ProductionTerm, Iterable<Production> {
		public final String name;
		public final ArrayList<Production> productions;

		public Rule(String name, Production... productions) {
			this.name = name;
			this.productions = new ArrayList<Production>(Arrays.asList(productions));
		}

		public void add(Production... productions) {
			this.productions.addAll(Arrays.asList(productions));
		}

		public int size() {
			return productions.size();
		}

		public Production get(int index) {
			return productions.get(index);
		}

		@Override
		public Iterator<Production> iterator() {
			return productions.iterator();
		}

		@Override
		public boolean equals(Object other) {
			if (this == other) {
				return true;
			}
			if (other == null || other.getClass() != getClass()) {
				return false;
			}
			Rule other2 = (Rule) other;
			return name.equals(other2.name) && productions.equals(other2.productions);
		}

		@Override
		public String toString() {
			String s = this.name + " -> ";
			if (!productions.isEmpty()) {
				for (int i = 0; i < productions.size() - 1; i++) {
					s += productions.get(i) + " | ";
				}
				s += productions.get(productions.size() - 1);
			}
			return s;
		}
	}

	public static class TableState {
		public final String name;
		public final Production production;
		public final int dotIndex;
		public final TableColumn startCol;
		public TableColumn endCol;

		public TableState(String name, Production production, int dotIndex, TableColumn startCol) {
			this.name = name;
			this.production = production;
			this.dotIndex = dotIndex;
			this.startCol = startCol;
			endCol = null;
		}

		public boolean isCompleted() {
			return dotIndex >= production.size();
		}

		public ProductionTerm getNextTerm() {
			if (isCompleted()) {
				return null;
			}
			return production.get(dotIndex);
		}

		@Override
		public boolean equals(Object other) {
			if (other == this) {
				return true;
			}
			if (other == null || other.getClass() != getClass()) {
				return false;
			}
			TableState other2 = (TableState) other;
			return name.equals(other2.name) && production.equals(other2.production) && dotIndex == other2.dotIndex
					&& startCol == other2.startCol;
		}

		@Override
		public String toString() {
			String s = "";
			for (int i = 0; i < production.size(); i++) {
				if (i == dotIndex) {
					s += "\u00B7 ";
				}
				ProductionTerm t = production.get(i);
				if (t instanceof Rule) {
					s += ((Rule) t).name;
				} else {
					s += t;
				}
				s += " ";
			}
			if (dotIndex == production.size()) {
				s += "\u00B7";
			}
			return String.format("%-6s -> %-20s [%d-%d]", name, s, startCol.index, endCol.index);
		}
	}

	protected static class TableColumn implements Iterable<TableState> {
		public final String token;
		public final int index;
		public final ArrayList<TableState> states;

		public TableColumn(int index, String token) {
			this.index = index;
			this.token = token;
			this.states = new ArrayList<TableState>();
		}

		/*
		 * Inseram o stare daca nu exista deja in lista.
		 * Intoarcem noua stare, sau cea deja existenta.
		 */
		public TableState insert(TableState state) {
			int index = states.indexOf(state);
			if (index < 0) {
				states.add(state);
				state.endCol = this;
				return state;
			} else {
				return states.get(index);
			}
		}

		public int size() {
			return states.size();
		}

		public TableState get(int index) {
			return states.get(index);
		}

		/*
		 * Pe masura ce parcurgem lista, vrem sa si modificam continutul.
		 */
		private class ModifiableIterator implements Iterator<TableState> {
			private int i = 0;

			@Override
			public boolean hasNext() {
				return i < states.size();
			}

			@Override
			public TableState next() {
				TableState st = states.get(i);
				i++;
				return st;
			}

			@Override
			public void remove() {
			}
		}

		@Override
		public Iterator<TableState> iterator() {
			return new ModifiableIterator();
		}

		public void print(PrintStream out, boolean showUncompleted) {
			out.printf("[%d] '%s'\n", index, token);
			out.println("---------------------------------------");
			for (TableState state : this) {
				if (!state.isCompleted() && !showUncompleted) {
					continue;
				}
				out.println(state);
			}
			out.println();
		}
	}

	public static class Node<T> implements Iterable<Node<T>> {
		public final T value;
		private List<Node<T>> children;

		public Node(T value, List<Node<T>> children) {
			this.value = value;
			this.children = children;
		}

		@Override
		public Iterator<Node<T>> iterator() {
			return children.iterator();
		}

		public void print(PrintStream out) {
			print(out, 0);
		}

		private void print(PrintStream out, int level) {
			String indentation = "";
			for (int i = 0; i < level; i++) {
				indentation += "  ";
			}
			out.println(indentation + value);
			for (Node<T> child : children) {
				child.print(out, level + 1);
			}
		}
	}

	public static class ParsingFailed extends Exception {
		public ParsingFailed(String message) {
			super(message);
		}
	}

	public static class Parser {
		protected TableColumn[] columns;
		protected TableState finalState = null;

		public Parser(Rule startRule, String text) throws ParsingFailed {
			String[] tokens = text.split(" ");
			columns = new TableColumn[tokens.length + 1];
			columns[0] = new TableColumn(0, "");
			for (int i = 1; i <= tokens.length; i++) {
				columns[i] = new TableColumn(i, tokens[i - 1]);
			}

			finalState = parse(startRule);
			if (finalState == null) {
				throw new ParsingFailed("invalid text for the given grammar");
			}
		}

		// Prima regula de start
		private static final String START_RULE = "S";

		/*
		 * Adaugam prima regula, completam tabela, daca primaregula se intinde din prima
		 * pana pe ultima coloana, intoarcem starea finala, null daca nu poate fi parsat.
		 */
		protected TableState parse(Rule startRule) {
			columns[0].insert(new TableState(START_RULE, new Production(startRule), 0, columns[0]));

			for (int i = 0; i < columns.length; i++) {
				TableColumn col = columns[i];
				for (TableState state : col) {
					if (state.isCompleted()) {
						complete(col, state);
					} else {
						ProductionTerm term = state.getNextTerm();
						if (term instanceof Rule) {
							predict(col, (Rule) term);
						} else if (i + 1 < columns.length) {
							scan(columns[i + 1], state, ((Terminal) term).value);
						}
					}
				}
				handleLambdas(col);

				// DEBUG -- afisam sau nu tabelul pe parcurs
				col.print(System.out, false);
			}

			// cautam starea de final sau null daca nu o gasim
			for (TableState state : columns[columns.length - 1]) {
				if (state.name.equals(START_RULE) && state.isCompleted()) {
					return state;
				}
			}
			return null;
		}

		private void scan(TableColumn col, TableState state, String token) {
			if (token.equals(col.token)) {
				col.insert(new TableState(state.name, state.production, state.dotIndex + 1, state.startCol));
			}
		}

		/*
		 * Functia predict, intoarcem true daca s-a modificat, altfel false.
		 */
		private boolean predict(TableColumn col, Rule rule) {
			boolean changed = false;
			for (Production prod : rule) {
				TableState st = new TableState(rule.name, prod, 0, col);
				TableState st2 = col.insert(st);
				changed |= (st == st2);
			}
			return changed;
		}

		/*
		 * Functia de complete, intoarcem true daca tabela s-a modificat, altfel false
		 */
		private boolean complete(TableColumn col, TableState state) {
			boolean changed = false;
			for (TableState st : state.startCol) {
				ProductionTerm term = st.getNextTerm();
				if (term instanceof Rule && ((Rule) term).name.equals(state.name)) {
					TableState st1 = new TableState(st.name, st.production, st.dotIndex + 1, st.startCol);
					TableState st2 = col.insert(st1);
					changed |= (st1 == st2);
				}
			}
			return changed;
		}

		/*
		 * apelam predict() si complete() atat timp cat tabela se modifica
		 * (se intampla la tranzitii lambda) 
		 */
		private void handleLambdas(TableColumn col) {
			boolean changed = true;

			while (changed) {
				changed = false;
				for (TableState state : col) {
					ProductionTerm term = state.getNextTerm();
					if (term instanceof Rule) {
						changed |= predict(col, (Rule) term);
					}
					if (state.isCompleted()) {
						changed |= complete(col, state);
					}
				}
			}
		}

		public List<Node<TableState>> getTrees() {
			return buildTrees(finalState);
		}

		private List<Node<TableState>> buildTrees(TableState state) {
			return buildTreesHelper(new ArrayList<Node<TableState>>(), state, state.production.rules.size() - 1,
					state.endCol);
		}

		private List<Node<TableState>> buildTreesHelper(List<Node<TableState>> children, TableState state,
				int ruleIndex, TableColumn endCol) {
			ArrayList<Node<TableState>> outputs = new ArrayList<Node<TableState>>();
			TableColumn startCol = null;
			if (ruleIndex < 0) {
				// am gasit intrega regula
				outputs.add(new Node<TableState>(state, children));
				return outputs;
			} else if (ruleIndex == 0) {
				// prima regula
				startCol = state.startCol;
			}
			Rule rule = state.production.rules.get(ruleIndex);

			for (TableState st : endCol) {
				if (st == state) {
					// prevenim loop infinit
					break;
				}
				if (!st.isCompleted() || !st.name.equals(rule.name)) {
					continue;
				}
				if (startCol != null && st.startCol != startCol) {
					continue;
				}
				// am gasit stare care se potriveste
				// creeam arbore pentru fiecare potrivire partiala
				for (Node<TableState> subTree : buildTrees(st)) {
					ArrayList<Node<TableState>> children2 = new ArrayList<Node<TableState>>();
					children2.add(subTree);
					children2.addAll(children);
					// incercam toate posibilitatile
					for (Node<TableState> node : buildTreesHelper(children2, state, ruleIndex - 1, st.startCol)) {
						outputs.add(node);
					}
				}
			}
			return outputs;
		}
	}
	
	public static void main(String[] args) throws Exception {
		
		/*
		* Prima gramatica: E -> a | E + E | E * E
		*/
		/*
		Rule E = new Rule("E", new Production("a"));
		Rule OP = new Rule("OP", new Production("+"), new Production("*"));
		E.add(new Production(E, OP, E));
		*/	

		String text = "a b b a a a b b";

		Rule a = new Rule("a", new Production("a"));
		Rule b = new Rule("b", new Production("b"));
		Rule c = new Rule("c", new Production("c"));

		Rule B = new Rule("B", new Production(c));
		Rule A = new Rule("A", new Production(b));
		A.add(new Production(b, A, a));
		Rule S = new Rule("S", new Production(a, A));
		S.add(new Production(a, S, B));
		
		
		
		/* Primul exemplu de pe tabla */
		Rule E  = new Rule("E", Lambda);
		E.add(new Production(a, E, b, a));
		E.add(new Production(b, E, a, E));

		Parser p = new Parser(E, text);



		/*
		 * A doua gramatica:
		 * SYM -> a 
	 	 * OP -> + | -
	     * EXPR -> SYM | EXPR OP EXPR 
		*/
	    /*	Rule SYM = new Rule("SYM", new Production("a"));
			Rule OP = new Rule("OP", new Production("+"));
			Rule EXPR = new Rule("EXPR", new Production(SYM));
			EXPR.add(new Production(EXPR, OP, EXPR));
		*/

		//System.out.printf("%d, ", p.getTrees().size());
		System.out.printf("Parse tree for '%s'\n", text);

		for (Node<TableState> tree : p.getTrees()) {
			tree.print(System.out);
			System.out.println();
			break;
		}

	}

}