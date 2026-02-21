# Competitive Programming

演算法模板與題目練習紀錄，以 C++ 撰寫。

## 目錄結構

```
.
├── template/              # 演算法模板
│   ├── default.cpp        # 比賽預設模板
│   ├── (graph)
│   ├── (data structure)
│   ├── (string)
│   ├── (math)
│   └── (misc)
└── topic/                 # 依主題分類的題目練習
    ├── 2-sat/
    ├── blossom/
    ├── divide-and-conquer/
    ├── euler-path/
    ├── flow/
    ├── game-theory/
    ├── segment-tree/
    ├── string/
    └── sweepline/
```

---

## 演算法模板 (`template/`)

### Graph

| 檔案 | 演算法 |
|------|--------|
| [Dijkstra.cpp](template/Dijkstra.cpp) | Dijkstra 最短路徑 |
| [Dinic.cpp](template/Dinic.cpp) | Dinic 最大流 |
| [BCC.cpp](template/BCC.cpp) | 雙連通分量 (Biconnected Components) |
| [SCC.cpp](template/SCC.cpp) | 強連通分量 (Tarjan's SCC) |
| [LCA.cpp](template/LCA.cpp) | 最近公共祖先 (Binary Lifting) |
| [HeavyLight.cpp](template/HeavyLight.cpp) | 重輕鏈剖分 (HLD) |
| [Centroid.cpp](template/Centroid.cpp) | 重心剖分 |
| [EulerTour.cpp](template/EulerTour.cpp) | 尤拉路徑/迴路（multiset 版） |
| [EulerCircuit.cpp](template/EulerCircuit.cpp) | 無向圖尤拉迴路（Hierholzer，含邊定向） |
| [Diameter.cpp](template/Diameter.cpp) | 樹直徑 |
| [bipartile.cpp](template/bipartile.cpp) | 二分圖匹配 |
| [Hungarian.cpp](template/Hungarian.cpp) | 匈牙利演算法 |
| [KM.cpp](template/KM.cpp) | KM 演算法（帶權二分圖匹配） |
| [2-SAT.cpp](template/2-SAT.cpp) | 2-SAT |

### Data Structure

| 檔案 | 資料結構 |
|------|----------|
| [SegTree.cpp](template/SegTree.cpp) | 線段樹（單點修改） |
| [SegTreeLz.cpp](template/SegTreeLz.cpp) | 線段樹（懶標記） |
| [PersistSegTree.cpp](template/PersistSegTree.cpp) | 持久化線段樹（主席樹） |
| [segment-tree-beats.cpp](template/segment-tree-beats.cpp) | Segment Tree Beats |
| [BIT.cpp](template/BIT.cpp) | 樹狀陣列 (Fenwick Tree) |
| [0-1Trie.cpp](template/0-1Trie.cpp) | 0-1 Trie |

### String

| 檔案 | 演算法 |
|------|--------|
| [KMP.cpp](template/KMP.cpp) | KMP 字串匹配 |
| [Z-KMP.cpp](template/Z-KMP.cpp) | Z-function |
| [Manacher.cpp](template/Manacher.cpp) | Manacher 最長回文子串 |
| [AC.cpp](template/AC.cpp) | Aho-Corasick 自動機 |
| [stringhash.cpp](template/stringhash.cpp) | 字串雜湊 (Rolling Hash) |
| [SA.cpp](template/SA.cpp) | 後綴陣列 (Suffix Array) |

### Math

| 檔案 | 演算法 |
|------|--------|
| [Matrix.cpp](template/Matrix.cpp) | 矩陣快速冪 |
| [Combination.cpp](template/Combination.cpp) | 組合數學 (nCr + modular inverse) |

### Misc

| 檔案 | 演算法 |
|------|--------|
| [cdq.cpp](template/cdq.cpp) | CDQ 分治 |
| [cdt.cpp](template/cdt.cpp) | 整體二分 |
| [Treeiso.cpp](template/Treeiso.cpp) | 樹同構 |

---

## 題目練習 (`topic/`)

### 2-SAT (`topic/2-sat/`)

| 檔案 | 來源 |
|------|------|
| [poj3207.cpp](topic/2-sat/poj3207.cpp) | POJ 3207 |
| [poj3648.cpp](topic/2-sat/poj3648.cpp) | POJ 3648 |
| [875c.cpp](topic/2-sat/875c.cpp) | Codeforces 875C |
| [1250E.cpp](topic/2-sat/1250E.cpp) | Codeforces 1250E |
| [1218i.cpp](topic/2-sat/1218i.cpp) | Codeforces Gym 1218I |
| [100112k.cpp](topic/2-sat/100112k.cpp) | Codeforces Gym 100112K |
| [day7J.cpp](topic/2-sat/day7J.cpp) | Contest Day 7 - J |

### Blossom — 一般圖匹配 (`topic/blossom/`)

| 檔案 | 來源 |
|------|------|
| [POJ3020.cpp](topic/blossom/POJ3020.cpp) | POJ 3020 |

### Divide and Conquer — 分治 (`topic/divide-and-conquer/`)

| 檔案 | 來源 |
|------|------|
| [875d.cpp](topic/divide-and-conquer/875d.cpp) | Codeforces 875D |

### Euler Path — 尤拉路徑 (`topic/euler-path/`)

| 檔案 | 來源 |
|------|------|
| [HDU3018.cpp](topic/euler-path/HDU3018.cpp) | HDU 3018 |
| [HDU5883.cpp](topic/euler-path/HDU5883.cpp) | HDU 5883 |
| [CF723E.cpp](topic/euler-path/CF723E.cpp) | Codeforces 723E |
| [CF1361C.cpp](topic/euler-path/CF1361C.cpp) | Codeforces 1361C |

### Flow — 網路流 (`topic/flow/`)

| 檔案 | 來源 |
|------|------|
| [hdu3599.cpp](topic/flow/hdu3599.cpp) | HDU 3599 |
| [hdu3605.cpp](topic/flow/hdu3605.cpp) | HDU 3605 |
| [6808.cpp](topic/flow/6808.cpp) | HDU 6808 |

### Game Theory — 博弈論 / SG (`topic/game-theory/`)

| 檔案 | 來源 |
|------|------|
| [HDU1848.cpp](topic/game-theory/HDU1848.cpp) | HDU 1848 |
| [HDU3980.cpp](topic/game-theory/HDU3980.cpp) | HDU 3980 |

### Segment Tree — 線段樹 (`topic/segment-tree/`)

| 檔案 | 來源 |
|------|------|
| [poj3468.cpp](topic/segment-tree/poj3468.cpp) | POJ 3468 |
| [hdu1540.cpp](topic/segment-tree/hdu1540.cpp) | HDU 1540 |
| [uva11402.cpp](topic/segment-tree/uva11402.cpp) | UVA 11402 |
| [CF718C.cpp](topic/segment-tree/CF718C.cpp) | Codeforces 718C |
| [CF1252K.cpp](topic/segment-tree/CF1252K.cpp) | Codeforces 1252K |
| [cf383c.cpp](topic/segment-tree/cf383c.cpp) | Codeforces 383C |
| [1439C.cpp](topic/segment-tree/1439C.cpp) | Codeforces 1439C |
| [day3a.cpp](topic/segment-tree/day3a.cpp) | Contest Day 3 - A |

### String — 字串 (`topic/string/`)

| 檔案 | 來源 |
|------|------|
| [kmp.cpp](topic/string/kmp.cpp) | KMP 練習 |
| [manacher.cpp](topic/string/manacher.cpp) | Manacher 練習 |
| [hdu1867.cpp](topic/string/hdu1867.cpp) | HDU 1867 |
| [hdu2203.cpp](topic/string/hdu2203.cpp) | HDU 2203 |
| [hdu3336.cpp](topic/string/hdu3336.cpp) | HDU 3336 |
| [536b.cpp](topic/string/536b.cpp) | Codeforces 536B |
| [536b-z.cpp](topic/string/536b-z.cpp) | Codeforces 536B (Z-function 解法) |

### Sweepline — 掃描線 (`topic/sweepline/`)

| 檔案 | 來源 |
|------|------|
| [POJ1177.cpp](topic/sweepline/POJ1177.cpp) | POJ 1177 |
| [HDU1542.cpp](topic/sweepline/HDU1542.cpp) | HDU 1542 |
| [HDU1255.cpp](topic/sweepline/HDU1255.cpp) | HDU 1255 |
| [hdu1255-v2.cpp](topic/sweepline/hdu1255-v2.cpp) | HDU 1255（另一種寫法） |
| [TIOJ1224.cpp](topic/sweepline/TIOJ1224.cpp) | TIOJ 1224 |
| [rectangle-area-intersection.cpp](topic/sweepline/rectangle-area-intersection.cpp) | 矩形面積交 |
| [vietnam-K.cpp](topic/sweepline/vietnam-K.cpp) | Vietnam Contest - K |
