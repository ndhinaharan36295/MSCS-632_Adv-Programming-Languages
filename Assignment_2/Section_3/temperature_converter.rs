use std::rc::Rc;
use std::cell::RefCell;

struct TemperatureConverter {
    count: Rc<RefCell<u32>>, // Reference-counted memory with interior mutability
}

impl TemperatureConverter {
    fn new() -> Self {
        TemperatureConverter {
            count: Rc::new(RefCell::new(0)), // Initialize with RefCell
        }
    }

    fn convert(&self, temp: f64, to_celsius: bool) -> (f64, u32) {
        let mut count = self.count.borrow_mut(); // Borrow mutably
        *count += 1; // Increment count

        let result = if to_celsius {
            (temp - 32.0) * 5.0 / 9.0
        } else {
            (temp * 9.0 / 5.0) + 32.0
        };

        (result, *count)
    }
}

fn main() {
    let converter = TemperatureConverter::new();
    let (converted1, calls1) = converter.convert(100.0, true);
    println!("Converted: {:.2}, Calls: {}", converted1, calls1);

    let (converted2, calls2) = converter.convert(0.0, false);
    println!("Converted: {:.2}, Calls: {}", converted2, calls2);
}
