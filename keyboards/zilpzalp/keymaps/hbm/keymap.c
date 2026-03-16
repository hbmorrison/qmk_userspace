// Copyright 2026 Hannah Blythe Morrison
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Tell the handed mods module which side of the keyboard the given key position
// is on. On the zilpzalp keyboard, keys on the left side are on even rows on
// the matrix, and keys on the right side are on odd rows.

bool handed_mods_is_left_key(keypos_t key) {
  return key.row % 2 == 0;
}
