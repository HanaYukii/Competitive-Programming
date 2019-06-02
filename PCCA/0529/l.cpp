#include <bits/stdc++.h>
using namespace std;
#define PNN pair<Node*, Node*>
#define MP make_pair
#define F first
#define S second
struct Treap {
    struct Node {
        Node *l, *r;
        int sz; 
        char v;
        bool rev;
        Node (char v) : v(v) {
            l = r = NULL;
            sz = 1; rev = false;
        }
    }*rt;
    Treap() {
        rt = NULL;
    }
    ~Treap() {
        clear(rt);
    }
    void clear(Node *u) {
        if (!u) return ;
        clear(u->l);
        clear(u->r);
        delete u;
    }
    inline int size(Node *u) {
        return u ? u->sz : 0;
    }
    inline Node*& pull(Node *&u) {
        u->sz = 1 + size(push(u->l)) + size(push(u->r));
        return u;
    }
    inline Node*& push(Node *&u) {
        if (!u) return u;
        if (u->rev) {
            if (u->l) u->l->rev ^= 1;
            if (u->r) u->r->rev ^= 1;
            swap(u->l, u->r);
            u->rev = false;
        }
        return u;
    }
    PNN split(Node *T, int x) {
        if (!T) return MP((Node*)NULL, (Node*)NULL);
        if (size(push(T)->l) < x) {
            PNN tmp = split(T->r, x - size(T->l) - 1);
            T->r = tmp.F;
            return MP(pull(T), tmp.S);
        } else {
            PNN tmp = split(T->l, x);
            T->l = tmp.S;
            return MP(tmp.F, pull(T));
        }
    }
    Node* merge(Node *T1, Node *T2) {
        if (!T1 || !T2) return T1 ? T1 : T2;
        if (rand() % (size(T1) + size(T2)) < size(T1)) {
            T1->r = merge(push(T1)->r, T2);
            return pull(T1);
        } else {
            T2->l = merge(T1, push(T2)->l);
            return pull(T2);
        }
    }
    void push_back(char c) {
        rt = merge(rt, new Node(c));
    }
    char query(int x) {
        PNN tmp_1 = split(rt, x + 1);
        PNN tmp_2 = split(tmp_1.F, x);
        char ret = tmp_2.S->v;
        rt = merge(merge(tmp_2.F, tmp_2.S), tmp_1.S);
        return ret;
    }
    void reverse(int L, int R) {
        PNN tmp_1 = split(rt, R + 1);
        PNN tmp_2 = split(tmp_1.F, L);
        tmp_2.S->rev ^= 1;
        rt = merge(merge(tmp_2.F, tmp_2.S), tmp_1.S);
    }
    void print(Node *u) {
        if (!u) return ;
        push(u);
        print(u->l);
        cout << u->v;
        print(u->r);
    }
};
int main() {
    int n, L, R; cin >> n >> L >> R; L--, R--;
    string s; cin >> s;
    Treap *sol = new Treap();
    for (auto &v : s)
        sol->push_back(v);
    int q; cin >> q; while (q--) {
        string op; cin >> op;
        if (op[0] == 'Q') {
            string pos; cin >> pos;
            if (pos[0] == 'L') {
                cout << sol->query(L);
            } else {
                cout << sol->query(R);
            }
        } else if (op[0] == 'R') {
            sol->reverse(L, R);
        } else if (op[0] == 'S') {
            string pos, dir; cin >> pos >> dir;
            if (pos[0] == 'L') {
                if (dir[0] == 'L')
                    L--;
                else
                    L++;
            } else {
                if (dir[0] == 'L')
                    R--;
                else
                    R++;
            }
        }
    }
    delete sol;
}