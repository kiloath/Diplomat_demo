#[diplomat::bridge]
mod ffi {
    use std::fmt::Write;
    use encoding_rs::BIG5;

    #[diplomat::opaque]
    struct Kiloath;
    
    impl Kiloath {
        pub fn greeting(name: &DiplomatStr, write: &mut DiplomatWrite) {
            let name_str = big5_to_utf8(name);
            write!(write, "哈囉, {}", name_str).unwrap();
        }
    }
    #[diplomat::opaque]
    struct Kiloath2(String);
    impl Kiloath2 {
        pub fn new(name: &DiplomatStr) -> Box<Kiloath2> {
            Box::new(Kiloath2(big5_to_utf8(name)))
        }

        pub fn greeting(&mut self, write: &mut DiplomatWrite) {
            write!(write, "哈囉, {}", self.0).unwrap();
        }
    }
    fn big5_to_utf8(big5_bytes: &DiplomatStr) -> String {
        let (utf8_string, _, _) = BIG5.decode(big5_bytes);
        utf8_string.into_owned()
    }
}