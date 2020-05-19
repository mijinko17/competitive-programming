fn main() {
    let (r, w) = (std::io::stdin(), std::io::stdout());
    let mut sc = IO::new(r.lock(), w.lock());

    let n: usize = sc.read();
    let s = sc.chars();
    let mut r: Vec<i64> = vec![0; n + 1];
    let mut g: Vec<i64> = vec![0; n + 1];
    let mut b: Vec<i64> = vec![0; n + 1];
    for i in 0..n {
        r[i + 1] = r[i] + if s[i] == 'R' { 1 } else { 0 };
    }
    for i in 0..n {
        g[i + 1] = g[i] + if s[i] == 'G' { 1 } else { 0 };
    }
    for i in 0..n {
        b[i + 1] = b[i] + if s[i] == 'B' { 1 } else { 0 };
    }
    let mut ans = 0;
    for i in 0..n {
        for j in i + 1..n {
            let d = 2 * j - i;
            if rg(s[i], s[j]) {
                ans += b[n] - b[j + 1];
                if d < n && s[d] == 'B' {
                    ans -= 1;
                }
            }
            if gb(s[i], s[j]) {
                ans += r[n] - r[j + 1];
                if d < n && s[d] == 'R' {
                    ans -= 1;
                }
            }
            if br(s[i], s[j]) {
                ans += g[n] - g[j + 1];
                if d < n && s[d] == 'G' {
                    ans -= 1;
                }
            }
        }
    }
    println!("{}", ans);
}

fn rg(c: char, d: char) -> bool {
    return (c == 'R' && d == 'G') || (c == 'G' && d == 'R');
}
fn gb(c: char, d: char) -> bool {
    return (c == 'G' && d == 'B') || (c == 'B' && d == 'G');
}
fn br(c: char, d: char) -> bool {
    return (c == 'B' && d == 'R') || (c == 'R' && d == 'B');
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
