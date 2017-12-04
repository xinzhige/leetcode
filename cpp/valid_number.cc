class Solution {
public:
    int skipwhitespace(const char *p) {
        int i = 0;
        while (*(p+i) == ' ') i++;
        return i;
    }
    int skipsign(const char *p) {
        if ((*p == '+') || (*p == '-')) return 1;
        return 0;
    }
    int skipdigit(const char *p) {
        int i = 0;
        while (isdigit(*(p + i))) i++;
        return i;
    }
    bool isNumber(const char *s) {
        const char *p = s;
        if(p == nullptr) return false;
        p += skipwhitespace(p);
        p += skipsign(p);
        int n1 = skipdigit(p);
        p += n1;
        if(*p == '.') p++;
        int n2 = skipdigit(p);
        if(n1 == 0 && n2 == 0) return false;
        p += n2;
        if((*p == 'e') || (*p == 'E')) {
            p++;
            p += skipsign(p);
            int n3 = skipdigit(p);
            if(n3 == 0) return false;
            p += n3;
        }
        p += skipwhitespace(p);
        return *p == '\0';
    }
};