fn pi(mut n: u128) -> f64 {
    let num: f64 = 4.0;
    let mut den: f64 = 1.0;
    let mut oper: f64 = 1.0;
    let mut pi:f64 = 0.0;

    loop {
        pi += oper * (num / den);
        den += 2.0;
        oper *= -1.0;
        n -= 1;
        if n == 0 {break;}
    }
    return pi
}

fn main() {
    let pi = pi(9999999);
    println!("Pi -> {}", pi);
}