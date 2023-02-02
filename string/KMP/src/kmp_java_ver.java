import java.util.Scanner;

class Main {
    static char[] s, p;
    static int[] nxt = new int[100000];

    public static void main(String[] args) {
        input();
        buildNxt();
        search();
        output();
    }

    static void search() {
        int tar = 0, pos = 0;

        while (tar < s.length) {
            if (s[tar] == p[pos]) {
                ++tar;
                ++pos;
            } else if (pos != 0)
                pos = nxt[pos - 1];
            else
                ++tar;
            
            if (pos == p.length) {
                System.out.println(tar - pos + 1);
                pos = nxt[pos - 1];
            }
        }
    }

    static void buildNxt() {
        int i = 1, now = 0;
        while (i < p.length) {
            if (p[i] == p[now]) {
                ++now;
                nxt[i] = now;
                ++i;
            } else if (now != 0)
                now = nxt[now - 1];
            else {
                ++i;
                nxt[i] = now;
            }
        }
    }

    static void output() {
        for (int i = 0; i < p.length; ++i)
            System.out.printf("%d", nxt[i]);
    }

    static void input() {
        Scanner in = new Scanner(System.in);

        String str, pat;

        str = in.next();
        pat = in.next();
        
        s = str.toCharArray();
        p = pat.toCharArray();

        in.close();
    }
}