fn main() {
    println!("{:?}", prime(100));
}

fn prime(n: u32) {
    // let mut arr = [1; n];
    for i in 1 .. arr.len() {
        for j in 1 .. arr.len() {
            let mut res = i+j+2*i*j;
            if res <= arr.len() {
                arr[res-1] = 0
            }
        }
    }
    return arr
}