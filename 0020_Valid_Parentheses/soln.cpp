bool isValid(char * s){
    if (strlen(s) <= 0) {
        return true;
    }
    char stack[strlen(s) + 1];
    stack[0] = '.';
    int idx = 1;
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            case '(':
            case '[':
            case '{':
                stack[idx++] = s[i];
                break;
            case ')':
                if (stack[idx-1] == '(') {
                    idx -= 1;
                } else {
                    return false;
                }
                break;
            case ']':
                if (stack[idx-1] == '[') {
                    idx -= 1;
                } else {
                    return false;
                }
                break;
            case '}':
                if (stack[idx-1] == '{') {
                    idx -= 1;
                } else {
                    return false;
                }
                break;
        }
    }
    if (idx != 1) {
        return false;
    }
    return true;
}
