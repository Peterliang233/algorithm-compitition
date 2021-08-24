/*
一个AC自动机的模板题，找到n个字符串在文本串里面出现的次数，可以出现重叠
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 800000;
int Next[N][26], fail[N], val[N], sz, n, op[N], pos[N], last[N], res[N][2];
char str[10], str2[N];

void init() {
    memset(Next[0], 0, sizeof(Next[0]));
    val[0] = 0;
    sz = 1;
}

int insert(char *s) {
    int u = 0, len = strlen(s);
    for (int i = 0; i < len; i++) {
        int k = s[i] - 'a';
        if (!Next[u][k]) {
            memset(Next[sz], 0, sizeof(Next[sz]));
            val[sz] = i + 1;
            Next[u][k] = sz++;
        }
        u = Next[u][k];
    }
    return u;
}

void getFail() {
    queue<int> Q;
    fail[0] = 0;
    for (int i = 0; i < 26; i++)
        if (Next[0][i]) {
            fail[Next[0][i]] = 0;
            Q.push(Next[0][i]);
        }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < 26; i++) {
            if (!Next[u][i])
                Next[u][i] = Next[fail[u]][i];
            else {
                fail[Next[u][i]] = Next[fail[u]][i];
                Q.push(Next[u][i]);
            }
        }
    }
}

void query(char *s) {
    int u = 0, len = strlen(s);
    for (int i = 0; i < len; i++) {
        u = Next[u][s[i] - 'a'];
        int temp = u;
        while (temp != 0) {
            res[temp][0]++;
            if (i - last[temp] >= val[temp]) {
                res[temp][1]++; 
                last[temp] = i;
            }
            temp = fail[temp];
        }
    }
}

void solve(){
    scanf("%s",str2);
    init();
    memset(res, 0, sizeof(res));
    memset(last, -1, sizeof(last));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
           scanf("%s", str);
           pos[i] = insert(str);
           op[i]=1;
    }
    getFail();
    query(str2);
    for (int i = 0; i < n; i++)
        printf("%d\n", res[pos[i]][op[i]]);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}