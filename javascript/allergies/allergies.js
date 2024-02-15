export class Allergies {
  #allergies;

  static codes = {
    "eggs":         1,
    "peanuts":      2,
    "shellfish":    4,
    "strawberries": 8,
    "tomatoes":    16,
    "chocolate":   32,
    "pollen":      64,
    "cats":       128
  };

  constructor(allergies = 0) {
    this.#allergies = allergies;
  }

  list = () => Object.keys(Allergies.codes).filter((allergen) => 
    this.allergicTo(allergen));

  allergicTo = allergen => 
    Boolean(Allergies.codes[allergen] & this.#allergies);
}
