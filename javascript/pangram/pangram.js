const ALPHABET = 'abcdefghijklmnopqrstuvwxyz';

/**
 * Check if the text string is a pangram, 
 * that means containing all 26 letters of alphabet
 * @param {string} text string
 * return {bool}
 */
export const isPangram = (text) => {
  const lowerText = text.toLowerCase()
  return [...ALPHABET].every(a => [...lowerText].includes(a));
}
