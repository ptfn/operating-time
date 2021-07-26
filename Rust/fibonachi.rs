fn main() {
    println!("{}", fib(10));
}

fn fib(n: i32) -> i32 {
    if n > 1 {
        fib(n-1) + fib(n-2)
    } else {
        1
    }
}