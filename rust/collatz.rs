fn col(mut n: i128) -> bool {
    loop {
        if n <= 1 {
            break false;
        } else if n % 2 == 0 {
            n = n / 2;
        } else if n % 2 != 0 {
            n = 3 * n + 1;
        } else {
            break false;
        }
    }
}

fn main() {
    println!("{}", col(27));
}
