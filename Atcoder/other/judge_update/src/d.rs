fn main() {
    let (r, w) = (std::io::stdin(), std::io::stdout());
    let mut sc = IO::new(r.lock(), w.lock());

    let n: usize = sc.read();
    let q: usize = sc.read();
    let mut a: Vec<i32> = sc.vec(n);
    let s: Vec<i32> = sc.vec(q);
    for i in 1..n {
        a[i] = gcd(a[i], a[i - 1]);
    }
    for i in 0..q {
        let mut ok = n as i32;
        let mut no = -1;
        while ok - no > 1 {
            let mid = ((ok + no) / 2) as usize;
            let mid2 = (ok + no) / 2;
            if gcd(s[i], a[mid]) == 1 {
                ok = mid2;
            } else {
                no = mid2;
            }
        }
        let ans = if ok == n as i32 {
            gcd(s[i], a[n - 1])
        } else {
            ok + 1
        };
        println!("{}", ans);
    }
}

fn gcd(a: i32, b: i32) -> i32 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
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
