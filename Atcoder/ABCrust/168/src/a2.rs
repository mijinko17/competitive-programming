use proconio::input;

fn main() {
    input! {
        n: i32,
    }
    match n % 10 {
        0 | 1 | 6 | 8 => println!("pon"),
        3 => println!("bon"),
        _ => println!("hon"),
    };
}
