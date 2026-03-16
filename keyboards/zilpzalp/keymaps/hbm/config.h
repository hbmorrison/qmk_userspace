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

#pragma once

// Tell the core keymap module to use some alternative layouts:
//
// - ZILPZALP_ALT_BASE changes the inside keys on the base layer to the middle
//   and bottom keycodes rather than the top and middle ones.

#define CORE_KEYMAP_ZILPZALP_ALT_BASE

// - EXTENDED_ALT_RSYM moves the minus/underscore and equals/plus key pairs
//   together and up onto the top middle and top right of the extended right
//   symbol layer.

#define CORE_KEYMAP_EXTENDED_ALT_RSYMX
