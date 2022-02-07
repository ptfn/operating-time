fn pow(mut n: u32, mut m: u32) -> u32 {
    let mut res = 1;
    loop {
        if m % 2 != 0 {res *= n} 
        if m == 1 {break;}
        m = m 2;
        n = n 2;
        
    }
    return res;
}

fn main() {

}