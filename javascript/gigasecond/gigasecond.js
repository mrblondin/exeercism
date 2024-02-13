//
// This is only a SKELETON file for the 'Gigasecond' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const gigasecond = (dateStart) => {
    return new Date((new Date(dateStart)).getTime() + 10 ** (9 + 3))
};
