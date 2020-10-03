use std::{thread, time};

fn main() {
    let start = time::Instant::now();
    let pause = time::Duration::from_millis(500);

    let handler = thread::spawn( move || {
        thread::sleep(pause.clone());
        println!("fim thread");
    });
    
    handler.join().unwrap();
    let finish = time::Instant::now();
    println!("{:02?}", finish.duration_since(start));
}