fn main() {
    let x = 11;
    println!("{} -> {}", x, sqr(x));
}

fn sqr(x:i32) -> i32 {
    x * x
}