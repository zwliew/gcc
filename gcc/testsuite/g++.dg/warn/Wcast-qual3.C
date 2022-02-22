// PR c++/96765
// { dg-options "-Wcast-qual" }

struct Derived;
struct Base {
  Derived *x;
  Derived *y;
  Base();
  ~Base();
};

struct Derived : Base {};

Base::Base()
    : x(static_cast<Derived *>(this)), // { dg-warning "invalid 'static_cast'" }
      y((Derived *)this) // { dg-warning "invalid 'static_cast'" }
{ 
  static_cast<Derived *>(this); // { dg-warning "invalid 'static_cast'" }
  (Derived *)this; // { dg-warning "invalid 'static_cast'" }
}

Base::~Base() {
  static_cast<Derived *>(this); // { dg-warning "invalid 'static_cast'" }
  (Derived *)this; // { dg-warning "invalid 'static_cast'" }
}

struct Other {
  Other() {
    Base b;
    static_cast<Derived *>(&b);
    (Derived *)(&b);
  }
};
