#![allow(unused_imports)]
#![allow(dead_code)]

use std::collections::*;

fn main() {
    let (r, w) = (std::io::stdin(), std::io::stdout());
    let mut sc = IO::new(r.lock(), w.lock());

    let modulo: i64 = 998244353;
    let n: i64 = sc.read();
    let m: i64 = sc.read();
    let k: i64 = sc.read();
    let comb = CombinationMod::new(n as usize, modulo);
    let mut ans: i64 = 0;
    for i in 0..=k {
        let mut add: i64 = 1;
        add = add * comb.query(n - 1, i) % modulo;
        add = add * m % modulo;
        add = add * modpow(m - 1, n - i - 1, modulo) % modulo;
        ans = (ans + add) % modulo;
    }
    if ans < 0 {
        ans = (ans + modulo) % modulo;
    }
    println!("{}", ans);
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

struct CombinationMod {
    fac: Vec<i64>,
    inv: Vec<i64>,
    inv_fac: Vec<i64>,
    modulo: i64,
}
impl CombinationMod {
    pub fn new(size: usize, modulo: i64) -> CombinationMod {
        let mut fac = vec![1; size + 1];
        let mut inv = vec![1; size + 1];
        let mut inv_fac = vec![1; size + 1];
        for i in 2..=size {
            fac[i] = fac[i - 1] * i as i64 % modulo;
            inv[i] = modulo - inv[modulo as usize % i] * (modulo / i as i64) % modulo;
            inv_fac[i] = inv_fac[i - 1] * inv[i] % modulo;
        }
        CombinationMod {
            fac: fac,
            inv: inv,
            inv_fac: inv_fac,
            modulo: modulo,
        }
    }
    fn query(&self, n: i64, r: i64) -> i64 {
        self.fac[n as usize] * self.inv_fac[r as usize] % self.modulo
            * self.inv_fac[(n - r) as usize]
            % self.modulo
    }
    fn inverse(&self, n: i64) -> i64 {
        self.inv[n as usize]
    }
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
