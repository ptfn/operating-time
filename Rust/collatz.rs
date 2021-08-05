fn col(mut n: i128) {
    loop {
        if n <= 1 {
            break;
        } else if n % 2 == 0 {
            n = n / 2;
        } else if n % 2 != 0 {
            n = 3 * n + 1;
        } else {
            break;
        }
    }
}

fn main() {
    col(9876543211234)
}