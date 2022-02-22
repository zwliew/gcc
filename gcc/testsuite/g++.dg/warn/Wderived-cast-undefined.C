// PR c++/96765
// { dg-options "-Wderived-cast-undefined" }

struct Derived;
struct Base {
  Derived *x;
  Derived &y;
  Base();
  ~Base();
};

struct Derived : Base {};

Base::Base()
    : x(static_cast<Derived *>(this)), // { dg-warning "invalid 'static_cast'" }
      y(static_cast<Derived &>(*this)) // { dg-warning "invalid 'static_cast'" }
{ 
  static_cast<Derived *>(this); // { dg-warning "invalid 'static_cast'" }
  static_cast<Derived &>(*this); // { dg-warning "invalid 'static_cast'" }
}

Base::~Base() {
  static_cast<Derived *>(this); // { dg-warning "invalid 'static_cast'" }
  static_cast<Derived &>(*this); // { dg-warning "invalid 'static_cast'" }
}

void f1() {
  Base b;
  static_cast<Derived *>(&b); // { dg-warning "invalid 'static_cast'" }
  static_cast<Derived &>(b); // { dg-warning "invalid 'static_cast'" }
}

void f2(Base *b1, Base &b2) {
  static_cast<Derived *>(b1);
  static_cast<Derived &>(*b1);
  static_cast<Derived *>(&b2);
  static_cast<Derived &>(b2);
}

void f3(Derived *d1, Derived &d2) {
  Base *b = d1;
  static_cast<Derived *>(b);
  static_cast<Derived &>(*b);

  b = &d2;
  static_cast<Derived *>(b);
  static_cast<Derived &>(*b);
}

