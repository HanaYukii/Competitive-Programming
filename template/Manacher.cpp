// Manacher's algorithm (longest palindromic substring)
int s[maxn];
int F[maxn];
int dp[maxn];
void Manacher(int len) {
    int l = 0;
    F[l++] = -2;
    F[l++] = -1;
    for (int i = 0 ; i < len ; i++) {
        F[l++] = s[i];
        F[l++] = -1;
    }
    dp[l] = 0;
    int mx = 0, id = 0;
    for (int i = 0 ; i < l ; i++) {
        dp[i] = mx > i ? min(dp[2*id-i],mx-i) : 1;
        while (F[i + dp[i]] == F[i - dp[i]]) dp[i]++;
        if (i + dp[i] > mx) {
            id = i;
            mx = i + dp[i];
        }
    }
}
