use std::{thread, time};

fn main() {
    let start = time::Instant::now();
    let mut pause = time::Duration::from_millis(5000);

    let handler1 = thread::spawn( move || {
        thread::sleep(pause.clone());
        println!("fim thread 1");
    });

    pause = time::Duration::from_millis(500);

    let handler2 = thread::spawn( move || {
        thread::sleep(pause.clone());
        println!("fim thread 2");
    });
    
    handler1.join().unwrap();
    //handler2.join().unwrap();

    let finish = time::Instant::now();
    println!("{:02?}", finish.duration_since(start));
}