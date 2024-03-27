#[derive(Debug)]
struct OrderDetails {
  price: usize,
  count: usize,
  id: usize
}

#[derive(Debug)]
enum Order {
  Buy(OrderDetails),
  Sell(OrderDetails),
  Cancel { id: usize }
}

fn handle_order(order: &Order) {
  match order {
    Order::Buy(details) => println!("Got buy order: {:?}", details),
    Order::Sell(details) => println!("Got buy order: {:?}", details),
    Order::Cancel { id } => println!("Got cancel for order {}", id)
  };
}

fn main() {
  let buy = Order::Buy(OrderDetails {
    price: 1,
    count: 1,
    id: 1
  });

  let sell = Order::Sell(OrderDetails {
    price: 2,
    count: 3,
    id: 4
  });

  let cancel = Order::Cancel { id: 4 };

  handle_order(&buy);
  handle_order(&sell);
  handle_order(&cancel);
}
