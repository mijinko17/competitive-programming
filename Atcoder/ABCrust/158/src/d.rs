fn main() {
    let (r, w) = (std::io::stdin(), std::io::stdout());
    let mut sc = IO::new(r.lock(), w.lock());

    let mut s = sc.chars();
    let q: usize = sc.read();
    let mut front: Vec<char> = Vec::new();
    let mut back: Vec<char> = Vec::new();
    let mut parity = 0;
    for _ in 0..q {
        let t: i32 = sc.read();
        if t == 1 {
            parity += 1;
        } else {
            let f: i32 = sc.read();
            let c: char = sc.read();
            if parity % 2 == 0 {
                if f == 1 {
                    front.push(c);
                } else {
                    back.push(c);
                }
            } else {
                if f == 1 {
                    back.push(c);
                } else {
                    front.push(c);
                }
            }
        }
    }
    if parity % 2 == 1 {
        std::mem::swap(&mut front, &mut back);
        s.reverse();
    }
    front.reverse();
    let front_string: String = front.iter().collect();
    let s_string: String = s.iter().collect();
    let back_string: String = back.iter().collect();
    println!("{}{}{}", front_string, s_string, back_string);
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
