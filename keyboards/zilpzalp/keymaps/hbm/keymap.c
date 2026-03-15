// Tell the handed mods module which side of the keyboard the given key position
// is on. On the zilpzalp keyboard, keys on the left side are on even rows on
// the matrix, and keys on the right side are on odd rows on the matrix.

bool handed_mods_is_left_key(keypos_t key) {
  return key.row % 2 == 0;
}
