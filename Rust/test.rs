fn main() {
    let num: (i32,f32,u8) = (4000, 3.14, 255);
    let (x,y,z) = num;
    println!("{} {} {}",x, y, z);
}