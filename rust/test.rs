struct User {
    user: String,
    password: String,
}

fn main() {
    let user1 = User {
        user: String::from("test"),
        password: String::from("123"),
    };

    println!("{}\n{}", user1.user, user1.password);
}