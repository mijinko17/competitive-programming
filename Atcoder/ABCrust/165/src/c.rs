use std::cmp::*;
use std::collections::*;

fn main() {
    let (r, w) = (std::io::stdin(), std::io::stdout());
    let mut sc = IO::new(r.lock(), w.lock());

    let n: usize = sc.read();
    let m: i32 = sc.read();
    let q: usize = sc.read();
    let mut abcd: Vec<(usize, usize, i32, i32)> = vec![(0, 0, 0, 0); q];
    for i in 0..q {
        abcd[i].0 = sc.read();
        abcd[i].1 = sc.read();
        abcd[i].2 = sc.read();
        abcd[i].3 = sc.read();
    }
    let mut bfs: VecDeque<Vec<i32>> = VecDeque::new();
    for i in 1..=m {
        bfs.push_back(vec![i]);
    }
    let mut ans = 0;
    while !bfs.is_empty() {
        let b = bfs.pop_front().unwrap();
        if b.len() == n {
            ans = max(ans, sum(&b, &abcd));
        } else {
            let max = *b.last().unwrap();
            for i in max..=m {
                let mut vec_new = b.clone();
                vec_new.push(i);
                bfs.push_back(vec_new);
            }
        }
    }
    println!("{}", ans);
}

fn sum(v: &Vec<i32>, abcd: &Vec<(usize, usize, i32, i32)>) -> i32 {
    let mut res = 0;
    for e in abcd.iter() {
        if v[e.1 - 1] - v[e.0 - 1] == e.2 {
            res += e.3;
        }
    }
    return res;
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
