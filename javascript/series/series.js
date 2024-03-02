export class Series {
  #series
  constructor(series) {
    if (this.is_valid_series(series)) this.#series = series;
  }

  slices(sliceLength) {
    if (!this.is_valid_slice(sliceLength)) 
      return;
    return [...this.#series].reduce((acc, _, index) => { 
      index + sliceLength <= this.#series.length ? 
      acc.push(this.#series.substring(index, index + sliceLength).split('').map(Number)) : acc; 
      return acc;
    }, []);
  }

  is_valid_series = series => {
    if (!series) throw new Error('series cannot be empty'); 
    return true;
  }

  is_valid_slice = slice_length => {
    if (!slice_length) throw new Error('slice length cannot be zero');
    if (slice_length < 0) throw new Error('slice length cannot be negative');
    if (this.#series.length < slice_length) 
      throw new Error('slice length cannot be greater than series length');
    return true;
  }
}
