#include <stdio.h>
#include <stdlib.h>

typedef struct Complex Complex;
typedef struct Complex * ComplexPtr;


struct Complex {
    float real;
    float imaginary;
};

void print_complex(Complex z);

// TODO: returns the real part as a float
float get_real(Complex z);
// TODO: set
float set_real(Complex * z);

Complex add_complex_by_value(Complex a, Complex b);
void add_complex_by_reference(Complex * a, Complex * b, Complex * result);

Complex mult_complex_by_value(Complex a, Complex b);
void mult_complex_by_reference(Complex a, Complex b, Complex * result);

// Make another function to subtract complex numbers, both by reference and by value
Complex sub_complex_by_value(Complex a, Complex b);
void sub_complex_by_reference(Complex a, Complex b, Complex * result);

int main()
{
    // z = 2 + 2i
    Complex z;
    z.real = 2;
    z.imaginary = 2;

    Complex h;
    h.real = 7;
    h.imaginary = -3;

    // w = 3 + 1i;
    Complex w = { .real=3, .imaginary=1 };

    Complex k = { .real=-2, .imaginary=-1 };

    // z + w
    Complex z_plus_w = add_complex_by_value(z, w);
    print_complex(z_plus_w);

//  z * w
    Complex z_mult_w;
    ComplexPtr z_mult_w_ptr = &z_mult_w;

    mult_complex_by_reference(z, w, z_mult_w_ptr);

    print_complex(z_mult_w);

    // Do subtractions here
    Complex z_sub_w = sub_complex_by_value(z, w);
    print_complex(z_sub_w);

    Complex h_sub_k;

    ComplexPtr h_sub_k_ptr = &h_sub_k;

    sub_complex_by_reference(h,k, h_sub_k_ptr);

    return 0;
}


void print_complex(Complex z) {
    printf("%4.2f + %4.2fi\n", z.real, z.imaginary);
}

Complex sub_complex_by_value(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imaginary = a.imaginary - b.imaginary;
    return result;
}

void sub_complex_by_reference(Complex a, Complex b, Complex * result) {
    result->real = a.real - b.real;
    result->imaginary = a.imaginary - b.imaginary;
}

Complex add_complex_by_value(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

void add_complex_by_reference(Complex * a, Complex * b, Complex * result) {
    result->real = a->real + b->real;
    result->imaginary = a->imaginary + b->imaginary;
}

Complex mult_complex_by_value(Complex a, Complex b) {
    Complex result;
    result.real = (a.real * b.real) - (a.imaginary * b.imaginary);
    result.imaginary = (a.real * b.imaginary) + (a.imaginary * b.real);
    return result;
}
// (a_r + a_i i)(b_r + b_i i)
void mult_complex_by_reference(Complex a, Complex b, Complex * result) {
    result->real = (a.real * b.real) - (a.imaginary * b.imaginary);
    result->imaginary = (a.real * b.imaginary) + (a.imaginary * b.real);
}
