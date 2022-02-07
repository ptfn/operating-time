fn main() {
    let arr = [1, 1, 0, 0, 1, 0, 0, 0];
    let mut arr2 = [0; 8];
    for i in 0 .. arr.len() {
        if arr[i] == 1 {
            arr2[i] = 0;
        } else if arr[i] == 0 {
            arr2[i] = 1;
        } else {
            break
        }
    }
    println!("{:?}", arr2);
}