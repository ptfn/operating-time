fn main() {
    println!("{}", fac(10));
}

fn fac(n: i32) -> i32 {
    if n <= 0 {
        1
    } else {
        n * fac(n - 1)
    }
}