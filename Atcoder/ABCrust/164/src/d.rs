use std::collections::*;

fn main() {
    let (r, w) = (std::io::stdin(), std::io::stdout());
    let mut sc = IO::new(r.lock(), w.lock());

    let mut s = sc.chars();
    s.reverse();
    let mut sub: Vec<i64> = vec![0; s.len() + 1];
    let m: i64 = 2019;
    let mut pow: i64 = 1;
    for i in 0..s.len() {
        sub[i + 1] = (s[i].to_digit(10).unwrap() as i64 * pow + sub[i]) % m;
        pow = (pow * 10) % m;
    }
    let mut count: BTreeMap<i64, i64> = BTreeMap::new();
    let mut ans: i64 = 0;
    for e in sub.iter() {
        let rf = count.entry(*e).or_insert(0);
        ans += *rf;
        *rf += 1;
    }
    println!("{}", ans);
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
