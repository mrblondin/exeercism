export class List {
  constructor(values = []) {
    this.values = values; 
  }

  append(alist) {
    const l_lentgh = this.length();

    for (let i = 0; i < alist.length(); i++)
      this.values[l_lentgh + i] = alist.values[i];

    return this;
  }

  concat(lists) {
    for (const list of lists.values)
      this.append(list);
    return this;
  }

  filter(filter) {
    const filtered_array = [];
    for (const value of this.values){
      if (filter(value)) 
        filtered_array.push(value)
    }
    this.values = filtered_array;
    return this;
  }

  map(map) {
    const mapped_array = [];
    for (const value of this.values){
      mapped_array.push(map(value))
    }
    this.values = mapped_array;
    return this;
  }

  length() {
    let i = 0;
    while(this.values[i]){
      i++;
    }
    return i;
  }

  foldl(func, init) {
    for (const value of this.values){
      init = func(init, value);
    }
    return init;
  }

  foldr(func, init) {
    for (let i = this.values.length - 1; i >= 0; i--){
      init = func(init, this.values[i]);
    }
    return init;
  }

  reverse() {
    const reversed_array = [];
    for (let i = this.values.length - 1, j = 0; i >= 0; i--, j++){
      reversed_array[j] = this.values[i];
    }
    this.values = reversed_array;
    return this;
  }
}
