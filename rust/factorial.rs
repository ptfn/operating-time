fn main() {
    let num = 20;
    let fac_num = fac(num);
    println!("Factorial {} -> {}", num, fac_num);
}

fn fac(n: u64) -> u64 {
    if n > 0 {
        n * fac(n - 1)
    } else {1}
}