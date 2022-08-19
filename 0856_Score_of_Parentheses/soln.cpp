#define LPAREN '('
#define RPAREN ')'

class Solution {
public:
    string buff;
    int buff_idx;
    
    char get_next() {
        return buff[buff_idx++];
    }
    
    char peek_next() {
        return buff[buff_idx];
    }

	/*
	 Rule: Exp -> E | E {E}
	 */
    int parse_exp() {
        int result = parse_e();
        // Another configuration of balanced parenthesis. Add the result
        while (peek_next() == LPAREN)
            result += parse_e();
        return result;
    }
	
	/*
	 Rule: E -> LPAREN Exp RPAREN | LPAREN RPAREN
	 */
    int parse_e() {
        int result = 0;
        if (get_next() == LPAREN) {	
            /* Parse pair */
            if (peek_next() == RPAREN) {
                get_next();
                return 1; // pair has value of 1 by definition
            } else {
				// Each subsequent level has a score multiplied by 2
                result = 2 * parse_exp();
                get_next(); // assert(get_next() == RPAREN);
                return result;
            }	
        }
        return -1; // Should never be reached.
    }

    int scoreOfParentheses(string s) {	
        buff_idx = 0;
        buff = s;
        return parse_exp();
    }
};