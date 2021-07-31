fn fac(n: i64) -> i64 {
    if n > 0 {
        n * fac(n - 1)
    } else {1}
}

fn fib(n: i64) -> i64 {
    let cmb = |n: i64, k: i64| -> i64 {fac(n) / (fac(k) * fac(n - k))};
    let mut result = 0;
    let mut i = 0;
    let mut k = 1;

    loop {
        result += cmb(n-k, i);
        i += 1;
        k += 1;
        if i == n {break;}
    }
    return result
}

fn main() {
    let fib = fib(15);
    println!("{}", fib);
}