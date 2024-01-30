export class GradeSchool {
  _roster;
  constructor(){
    this._roster = {};
  }

  roster() {
    return JSON.parse(JSON.stringify(this._roster));
  }

  add(name, grade) {
    // check if the name is already exists
    for (const key in this._roster){
      const cur_grade = this._roster[key];
      if (cur_grade.indexOf(name) !== -1 && cur_grade.splice(cur_grade.indexOf(name), 1))
        return;
    }

    this._roster[grade] || (this._roster[grade] = []);
    this._roster[grade].push(name);
    this._roster[grade].sort();
  }

  grade(grade) {
    return (this._roster[grade] ??= []).concat();
  }
}
