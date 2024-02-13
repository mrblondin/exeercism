export class Matrix {
  constructor(input) {
    this._rows = input.split('\n').map(r => r.split(' ').map(Number));

    // transpose rows to get columns
    this._columns = this._rows[0].map((_,i) => {
      return this._rows.map((row) => row[i]);
    });

    // another possible solution
    //this._columns = [];

    //for (let i = 0; i < this._rows.length; i++){
    //  for (let j = 0; j < this._rows[i].length; j++){
    //    this._columns[j] = this._columns[j] ?? []
    //    this._columns[j][i] = this._rows[i][j]
    //  }
    //}
  }

  get rows() {
    return this._rows;
  }

  get columns() {
    return this._columns;
  }
}
