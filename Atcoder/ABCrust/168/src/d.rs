fn main() {
    let (r, w) = (std::io::stdin(), std::io::stdout());
    let mut sc = IO::new(r.lock(), w.lock());

    let n = sc.read();
    let m = sc.read();
    let mut g = vec![vec![]; n];
    for _ in 0..m {
        let a: usize = sc.read();
        let b: usize = sc.read();
        g[a - 1].push(Edge::new(b - 1, 1));
        g[b - 1].push(Edge::new(a - 1, 1));
    }
    let dist = distance_nonweight(&g, 0);
    let mut ans = vec![0; n];
    for i in 1..n {
        for e in g[i].iter() {
            if dist[e.to] + 1 == dist[i] {
                ans[i] = e.to;
                break;
            }
        }
    }
    println!("Yes");
    for i in 1..n {
        println!("{}", ans[i] + 1);
    }
}

// グラフの辺
#[derive(Debug, Copy, Clone)]
struct Edge {
    to: usize,
    cost: i64,
}
impl Edge {
    pub fn new(to: usize, cost: i64) -> Edge {
        Edge { to: to, cost: cost }
    }
}

// 重みを無視したグラフの距離
fn distance_nonweight(graph: &Vec<Vec<Edge>>, start: usize) -> Vec<i32> {
    let mut res = vec![std::i32::MAX; graph.len()];
    res[start] = 0;
    let mut bfs = std::collections::VecDeque::new();
    bfs.push_back(start);
    while !bfs.is_empty() {
        let now = bfs.pop_front().unwrap();
        for e in graph[now].iter() {
            if res[now] + 1 < res[e.to] {
                res[e.to] = res[now] + 1;
                bfs.push_back(e.to);
            }
        }
    }
    res
}

pub struct IO<R, W: std::io::Write>(R, std::io::BufWriter<W>);

impl<R: std::io::Read, W: std::io::Write> IO<R, W> {
    pub fn new(r: R, w: W) -> IO<R, W> {
        IO(r, std::io::BufWriter::new(w))
    }
    pub fn write<S: ToString>(&mut self, s: S) {
        use std::io::Write;
        self.1.write(s.to_string().as_bytes()).unwrap();
    }
    pub fn read<T: std::str::FromStr>(&mut self) -> T {
        use std::io::Read;
        let buf = self
            .0
            .by_ref()
            .bytes()
            .map(|b| b.unwrap())
            .skip_while(|&b| b == b' ' || b == b'\n' || b == b'\r' || b == b'\t')
            .take_while(|&b| b != b' ' && b != b'\n' && b != b'\r' && b != b'\t')
            .collect::<Vec<_>>();
        unsafe { std::str::from_utf8_unchecked(&buf) }
            .parse()
            .ok()
            .expect("Parse error.")
    }
    pub fn vec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.read()).collect()
    }
    pub fn chars(&mut self) -> Vec<char> {
        self.read::<String>().chars().collect()
    }
}
