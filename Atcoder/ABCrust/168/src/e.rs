use std::collections::*;

fn main() {
    let m = 1e+9 as i64 + 7;
    let (r, w) = (std::io::stdin(), std::io::stdout());
    let mut sc = IO::new(r.lock(), w.lock());

    let n: usize = sc.read();
    let mut ab: Vec<(i64, i64)> = vec![(0, 0); n];
    for i in 0..n {
        ab[i].0 = sc.read();
        ab[i].1 = sc.read();
    }
    let mut count: BTreeMap<(i64, i64), i64> = BTreeMap::new();
    for i in 0..n {
        if ab[i] == (0, 0) {
            continue;
        }
        let v = reg(ab[i]);
        *count.entry(v).or_insert(0) += 1;
    }
    let mut used: BTreeSet<(i64, i64)> = BTreeSet::new();
    let mut ans: i64 = 1;
    for i in 0..n {
        if ab[i] == (0, 0) {
            continue;
        }
        let v = reg(ab[i]);
        let o = orth(v);
        if used.contains(&v) {
            continue;
        }
        let num_v = match count.get(&v) {
            None => 0,
            _ => count[&v],
        };
        let num_o = match count.get(&o) {
            None => 0,
            _ => count[&o],
        };
        let multi = (modpow(2, num_v, m) + modpow(2, num_o, m) - 1) % m;
        ans = ans * multi % m;
        used.insert(v);
        used.insert(o);
    }
    let zeros = ab.iter().filter(|&e| *e == (0, 0)).count() as i64;
    let mut res = (zeros + ans - 1) % m;
    if res < 0 {
        res = (res + m) % m;
    }
    println!("{}", res);
}

fn modpow(a: i64, x: i64, m: i64) -> i64 {
    if x == 0 {
        1
    } else if x % 2 != 0 {
        a * modpow(a, x - 1, m) % m
    } else {
        let half = modpow(a, x / 2, m);
        half * half % m
    }
}

fn gcd(a: i64, b: i64) -> i64 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn reg(mut v: (i64, i64)) -> (i64, i64) {
    let div = gcd(v.0, v.1);
    v.0 /= div;
    v.1 /= div;
    if v.1 < 0 {
        v.0 *= -1;
        v.1 *= -1;
    }
    if v.1 == 0 && v.0 < 0 {
        v.0 *= -1;
    }
    (v.0, v.1)
}

fn orth(v: (i64, i64)) -> (i64, i64) {
    let mut res = (-v.1, v.0);
    if res.1 < 0 {
        res.0 *= -1;
        res.1 *= -1;
    }
    if res.1 == 0 && res.0 < 0 {
        res.0 *= -1;
    }
    (res.0, res.1)
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
