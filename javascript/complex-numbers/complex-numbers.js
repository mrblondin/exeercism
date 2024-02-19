export class ComplexNumber {
  constructor(real = 0, imag = 0) {
    this._real = real;
    this._imag = imag;
  }

  get real() { return this._real; }

  get imag() { return this._imag; }

  add(cn) {
    return new ComplexNumber(this.real + cn.real, this.imag + cn.imag);
  }

  sub(cn) {
    return new ComplexNumber(this.real - cn.real, this.imag - cn.imag);
  }

  div(cn) {
    const _real = (this.real * cn.real + this.imag * cn.imag) /
                 (cn.real ** 2 + cn.imag ** 2);
    const _imag = (this.imag * cn.real - this.real * cn.imag) /
                 (cn.real ** 2 + cn.imag ** 2);
    return new ComplexNumber(_real, _imag);
  }

  mul(cn) {
    const _real = (this.real * cn.real - this.imag * cn.imag);
    const _imag = (this.imag * cn.real + this.real * cn.imag);
    return new ComplexNumber(_real, _imag);
  }

  get abs() {
    return (this.real ** 2 + this.imag ** 2) ** 0.5;
  }

  get conj() {
    return new ComplexNumber(this.real, 0 - this.imag);
  }

  get exp() {
    return new ComplexNumber(Math.exp(this.real), 0)
      .mul(new ComplexNumber(Math.cos(this.imag), Math.sin(this.imag)));
  }
}
