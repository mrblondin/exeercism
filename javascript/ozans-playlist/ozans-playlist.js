// @ts-check
//
// The line above enables type checking for this file. Various IDEs interpret
// the @ts-check directive. It will give you helpful autocompletion when
// implementing this exercise.

/**
 * Removes duplicate tracks from a playlist.
 *
 * @param {string[]} playlist
 * @returns {string[]} new playlist with unique entries
 */
export const removeDuplicates = playlist => {
  const newPlaylist = new Set(playlist);
  return [...newPlaylist];
}

/**
 * Checks whether a playlist includes a track.
 *
 * @param {string[]} playlist
 * @param {string} track
 * @returns {boolean} whether the track is in the playlist
 */
export const hasTrack = (playlist, track) => {
  const set = new Set(playlist);
  return set.size === set.add(track).size;
}

/**
 * Adds a track to a playlist.
 *
 * @param {string[]} playlist
 * @param {string} track
 * @returns {string[]} new playlist
 */
export const addTrack = (playlist, track) => {
  const newSet = new Set(playlist);
  return [...newSet.add(track)];
}

/**
 * Deletes a track from a playlist.
 *
 * @param {string[]} playlist
 * @param {string} track
 * @returns {string[]} new playlist
 */
export const deleteTrack = (playlist, track) => {
  const newSet = new Set(playlist);
  newSet.delete(track);
  return [...newSet];
}

/**
 * Lists the unique artists in a playlist.
 *
 * @param {string[]} playlist
 * @returns {string[]} list of artists
 */
export const listArtists = playlist => {
  const artistSet =  new Set(playlist.map((track) =>
    track.slice(track.indexOf('-') + 1).trim()
  ));
  return [...artistSet];
}
