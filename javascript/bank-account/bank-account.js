export class BankAccount {
  #enabled = false;
  #assets = 0;

  constructor() {
  }

  open() {
    if (!this.#enabled){
      this.#enabled = true;
      this.#assets = 0;
    }
    else throw new ValueError();
  }

  close() {
    if(this.is_enabled()){
      this.#enabled = false;
      this.#assets = 0;
    }
  }

  deposit = value => {
    if (!this.is_enabled())
      return 0;
    if (value <= 0)
      throw new ValueError();
    this.#assets += value;
  }

  withdraw = value => {
    if(!this.is_enabled())
      return 0;
    if (value < 0 || value > this.#assets)
      throw new ValueError();
    this.#assets -= value;
  }

  get balance() {
    return this.is_enabled() ? this.#assets : 0;
  }
  
  is_enabled = _ => {
    if (this.#enabled) return true;
    else throw new ValueError();
  }
}

export class ValueError extends Error {
  constructor() {
    super('Bank account error');
  }
}
